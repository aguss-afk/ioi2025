#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << ": " << x << '\n';
int lg = 20;
vector<vector<int>> up;
vector<vector<pair<int, int>>> arr;
vector<int> depth;
vector<ll> dis;

int dfs(int curr, int prev){
    up[curr][0] = prev;
    for(int i = 1; i <= lg; i++){
        up[curr][i] = up[up[curr][i - 1]][i - 1];
    }
    for(auto &i : arr[curr]){
        if(i.first == prev) continue;
        depth[i.first] = depth[curr] + 1ll;
        dis[i.first] = dis[curr] + i.second;
        dfs(i.first, curr);
    }
}

int lca(int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    int dif = depth[b] - depth[a];
    for(int i = 0; i <= lg; i++){
        if(dif & (1 << i)){
            b = up[b][i];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = 20; i >= 0; i-- ){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

pair<ll, int> calc_dis(int a, int b){
    int ellca = lca(a, b);
    return {dis[a] + dis[b] - 2ll * dis[ellca], depth[a] + depth[b] - 2 * depth[ellca]};
}

int main(){
    int n, k;
    cin >> n >> k;
    arr.assign(n, vector<pair<int, int>>());
    up.assign(n, vector<int>(lg + 1, 0));
    depth.assign(n, 0);
    dis.assign(n, 0);
    int a, b, c;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b >> c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j].first << ' ' << arr[i][j].second << '\n';
        }
    }
    dfs(0, 0);
    int ans = -1;
    for(int i = 0; i + 1 < n; i++){
        for(int j = i + 1; j < n; j++){
            pair<int, int> y = calc_dis(i, j);
            if(y.first == k){
                if(ans == -1){
                    ans = y.second;
                } else {
                    ans = min(ans, y.second);
                }
            }
        }
    }
    cout << ans;
}