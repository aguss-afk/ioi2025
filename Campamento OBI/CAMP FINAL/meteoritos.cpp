#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << #x << ": " << x << '\n';
vector<vector<int>> arr;
int n, m;
bool dfs(int a, int b, vector<vector<bool>> &vis){
    if(a >= n or b >= m) return 0;
    if(arr[a][b]) return 0;
    if(a == n - 1 and b == m - 1) return 1;
    if(vis[a][b]) return 0;
    vis[a][b] = 1;
    if(dfs(a + 1, b, vis) or dfs(a, b + 1, vis)){
        return 1;
    }
    return 0;
}
int main(){
    cin >> n >> m;
    arr.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        cin >> a >> b;
        a--;
        b--;
        arr[a][b] = 1;
        bool ans = dfs(0, 0, vis);
        cout << ans << '\n';
        if(!ans){
            arr[a][b] = 0;  
        }
    }
}