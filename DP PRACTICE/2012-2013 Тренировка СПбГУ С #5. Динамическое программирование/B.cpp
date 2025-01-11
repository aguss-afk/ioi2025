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
    string x;
    cin >> x;
    vector<int> dp(n, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(dp[i] == -1){
            continue;
        }
        if(i + 1 < n){
            if(x[i + 1] == 'w'){
                dp[i + 1] = -1;
            } else if(x[i + 1] == '"'){
                dp[i + 1] = max(dp[i + 1], dp[i] + 1);
            } else {
                dp[i + 1] = max(dp[i + 1], dp[i]);
            }
        }
        if(i + 3 < n){
            if(x[i + 3] == 'w'){
                dp[i + 3] = -1;
            } else if(x[i + 3] == '"'){
                dp[i + 3] = max(dp[i + 3], dp[i] + 1);
            } else {
                dp[i + 3] = max(dp[i + 3], dp[i]);
            }
        }
        if(i + 5 < n){
            if(x[i + 5] == 'w'){
                dp[i + 5] = -1;
            } else if(x[i + 5] == '"'){
                dp[i + 5] = max(dp[i + 5], dp[i] + 1);
            } else {
                dp[i + 5] = max(dp[i + 5], dp[i]);
            }
        }
    }
    cout << dp[n - 1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("lepus.in", "r", stdin);
    freopen("lepus.out", "w", stdout);
    solve();
}