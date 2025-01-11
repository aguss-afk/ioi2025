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
vector<int> a, b, c;
vector<vector<int>> dp;
int n;
int dpf(int i, int d){
    if(i == n){
        return 0;
    }
    if(dp[i][d] != -1){
        return dp[i][d];
    }
    int ans = INT_MIN;
    if(d == 0){
        ans = max(ans, b[i] + dpf(i + 1, 1));
        ans = max(ans, c[i] + dpf(i + 1, 2));
    } else if(d == 1){
        ans = max(ans, a[i] + dpf(i + 1, 0));
        ans = max(ans, c[i] + dpf(i + 1, 2));
    } else if(d == 2){
        ans = max(ans, a[i] + dpf(i + 1, 0));
        ans = max(ans, b[i] + dpf(i + 1, 1));
    } else {
        ans = max(ans, a[i] + dpf(i + 1, 0));
        ans = max(ans, b[i] + dpf(i + 1, 1));
        ans = max(ans, c[i] + dpf(i + 1, 2));
    }
    return dp[i][d] = ans;
}
void solve(){
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    c.assign(n, 0);
    dp.assign(n + 1, vector<int>(4, -1));
    f2(i, n, 0){
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << dpf(0, 3);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
