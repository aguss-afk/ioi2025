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
    vector<vector<int>> arr, dp;
    f2(i, n, 0){
        arr.push_back(vector<int>(i + 1, 0));
        dp.push_back(vector<int>(i + 1, INT32_MIN));
    }
    f1(i, arr){
        f1(j, i){
            cin >> j;
        }
    }
    dp[0][0] = arr[0][0];
    f2(i, n - 1, 0){
        f2(j, i + 1, 0){
            if(i + 1 < n){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + arr[i + 1][j]);
                if(j <= i and j + 1 < n){
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + arr[i + 1][j + 1]);
                }
            }
        }
    }
    int ans = *max_element(all(dp[n - 1]));
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}