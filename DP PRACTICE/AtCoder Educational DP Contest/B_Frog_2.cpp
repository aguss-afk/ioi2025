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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), dp(n, INT32_MAX);
    f1(i, arr){
        cin >> i;
    } 
    dp[0] = 0;
    f2(i, n, 0){
        f2(j, k + 1, 1){
            if(j + i < n){
                dp[i + j] = min(dp[i + j], dp[i] + abs(arr[j + i] - arr[i]));
            }
        } 
    }
    cout << dp[n - 1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
