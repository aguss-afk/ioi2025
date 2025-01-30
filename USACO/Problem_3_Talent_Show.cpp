#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;

void solve(){
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> w(n), t(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> t[i];
        sum += t[i];
    } 
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, MOD));
    int ans = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j >= t[i - 1]){
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - t[i - 1]] + w[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int j = 1; j <= sum; j++){
        if(dp[n][j] >= m){
            ans = max(ans, (1000 * j) / dp[n][j]);
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    solve();
}
