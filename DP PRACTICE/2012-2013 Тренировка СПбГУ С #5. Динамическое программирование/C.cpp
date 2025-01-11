#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    dp[0][0] = 1;
    f2(i, n, 0){
        f2(j, m, 0){
            if(!dp[i][j]){
                continue;
            }
            if(i + 2 < n and j + 1 < m){
                dp[i + 2][j + 1] += dp[i][j];
            }
            if(i + 1 < n and j + 2 < m){
                dp[i + 1][j + 2] += dp[i][j];
            }
        }
    } 
    cout << dp[n - 1][m - 1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
    solve();
}