#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m), dp(m + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        arr[i].assign(a, 0);
        for(int &j : arr[i]){
            cin >> j;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++){
        for(int &k : arr[i - 1]){
            for(int j = k; j <= n; j++){
                if(dp[i - 1][j - k]){
                    dp[i][j] = dp[i - 1][j - k];
                }
            }
        }
    }
    for(int i = n; i >= 0; i--){
        if(dp[m][i]){
            cout << i << '\n';
            return;
        }
    }
    cout << "no solution\n";
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
