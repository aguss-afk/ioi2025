#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> arr;
vector<vector<int>> dis;
vector<vector<bool>> vis;
pair<int, int> osopendejo, casadelosopendejo;
vector<pair<int, int>> abejasputas;

int n, s;
void multibfs(){
    queue<pair<int, int>> bfs;
    for(const pair<int, int> &i : abejasputas){
        bfs.push({i.first, i.second});
    }
    while(!bfs.empty()){
        pair<int, int> a = bfs.front();
        bfs.pop();
        if(a.first < 0 or a.second < 0 or a.first == n or a.second == n) continue;
        if(vis[a.first][a.second]) continue;
        if(arr[a.first][a.second] == 'T' or arr[a.first][a.second] == 'D' or arr[a.first][a.second] == 'O') continue;
        vis[a.first][a.second] = 1;
        dis[a.first][a.second]++;
        bfs.push({a.first + 1, a.second});
        bfs.push({a.first - 1, a.second});
        bfs.push({a.first, a.second + 1});
        bfs.push({a.first, a.second - 1});
    } 
}

void solve(){
    cin >> n >> s;
    arr.assign(n, vector<char>(n, ' ')); 
    vis.assign(n, vector<bool>(n, 0)); 
    dis.assign(n, vector<int>(n, 1e9)); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'M'){
                osopendejo = {i, j};
                continue;
            } 
            if(arr[i][j] == 'H'){
                abejasputas.push_back({i, j});
                dis[i][j] = 0;
                continue;
            }
            if(arr[i][j] == 'D'){
                casadelosopendejo = {i, j};
                continue;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}