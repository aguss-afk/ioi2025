#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[1][1] = 1;
    const int MOD = 1e9 + 7;
    for(vector<char> &i : arr){
        for(char &j : i){
            cin >> j;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i - 1][j - 1] == '#'){
                continue;
            }
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    } 
    cout << dp[n][m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
