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
    vector<vector<ll>> dp(8, vector<ll>(8, INF)), arr(8, vector<ll>(8));
    f1(i, arr){
        f1(j, i){
            cin >> j;
        }
    }
    dp[7][0] = 0;
    for(int i = 7; i >= 0; i--){
        f2(j, 8, 0){
            if(i - 1 >= 0){
                dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + arr[i - 1][j]);
            }
            if(j + 1 < 8){
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + arr[i][j + 1]);
            }
            if(i - 1 >= 0 and j + 1 < 8){
                dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + arr[i - 1][j + 1]);
            }
        }
    }
    cout << dp[0][7];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);
    solve();
}