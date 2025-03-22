#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> arr, vis;

bool ff(int i, int j){
    if(i < 0 or j < 0) return 1;
    if(i >= n or j >= m) return 1;
    if(arr[i][j] == 0) return 1;
    if(vis[i][j]) return 1;
    vis[i][j] = 1;
    bool t = true;
    t &= ff(i, j + 1);
    t &= ff(i, j - 1);
    t &= ff(i + 1, j);
    t &= ff(i - 1, j);
    if(!i or !j or i == n - 1 or j == m - 1) return 0;
    return t;
}

int main(){
    cin >> n >> m;
    arr.assign(n, vector<int>(m, 0));
    vis.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j =  0; j < m; j++){
            if(!vis[i][j] and arr[i][j]){
                if(ff(i, j)) ans++;
            }
        }
    }
    cout << ans;
}