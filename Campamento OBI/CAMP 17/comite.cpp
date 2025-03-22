#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<pair<int, int>>> arr;
vector<int> dis;
vector<bool> vis;

void dijkstra(){
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0] = 0;
    while(!q.empty()){
        int a = q.top().second;
        q.pop();
        if(vis[a]) continue;
        vis[a] = 1;
        for(pair<int, int> &pa : arr[a]){
            int x = pa.first, y = pa.second;
            if(dis[a] + y < dis[x]){
                dis[x] = dis[a] + y;
                q.push({-dis[x], x});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    n++;
    arr.resize(n, vector<pair<int, int>>());
    dis.assign(n, 100000000);
    vis.assign(n, 0);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    for(int i = 0; i < n; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    dijkstra();
    for(int i = 1; i < dis.size(); i++){
        if(dis[i] == 100000000){
            cout << -1 << ' ';
            continue;
        }
        cout << dis[i] << ' ';
    }
}
