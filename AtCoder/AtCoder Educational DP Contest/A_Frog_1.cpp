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
    vector<int> arr(n), dp(n + 1, 0);
    f1(i, arr){
        cin >> i;
    }
    dp[1] = 0;
    dp[2] = abs(arr[1] - arr[0]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + abs(arr[i - 1] - arr[i - 2]), dp[i - 2] + abs(arr[i - 1] - arr[i - 3]));
    }
    cout << dp[n];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
