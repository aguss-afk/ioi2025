#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for(vector<char> &i : arr){
        for(char &j : i){
            cin >> j;
        }
    }
    int ans = 0;
    for(int i = 0; i < m - 1; i++){
        if(arr[n - 1][i] != 'R') ans++;
    }
    for(int i = 0; i < n - 1; i++){
        if(arr[i][m - 1] != 'D') ans++;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
