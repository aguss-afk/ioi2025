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
    int n;
    cin >> n;
    vector<int> arr(n), dp(n + 1, INT32_MIN);
    f1(i, arr){
        cin >> i;
    }
    dp[0] = 0;
    f2(i, n + 1, 1){
        if(i - 1 >= 0){
            dp[i] = max(dp[i - 1] + arr[i - 1], dp[i]);
        }
        if(i - 2 >= 0){
            dp[i] = max(dp[i - 2] + arr[i - 1], dp[i]);
        }
    }
    cout << dp[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    solve();
}