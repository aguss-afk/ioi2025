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
    ll n, x, y, ans = 0;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<pair<bool, int>> diff;
    f2(i, n, 0){
        if(a[i] != b[i]){
            diff.push_back({1, i});
        }
    }
    if(diff.size() % 2){
        cout << -1 << endl;
        return;
    } else if(!diff.size()){
        cout << 0 << endl;
        return;
    }
    if(y <= x){
        int i = 0;
        if(diff.size() == 2){
            if(diff[0].second == diff[1].second - 1){
                if(x > 2 * y){
                    ans += 2 * y;
                } else {
                    ans += x;
                }
            } else {
                ans += y;
            }
            cout << ans << endl;
            return;
        }
        f2(i, diff.size() - diff.size() / 2, 0){
            if(diff[i].first){
                diff[i].first = 0;
                diff[i + diff.size() / 2].first = 0;
                ans += y;
            }
        }
    } else {
        vector<ll> dp(diff.size());
        dp[0] = 0;
        dp[1] = min((diff[1].second - diff[0].second) * x, y);
        f2(i, diff.size(), 2){
            dp[i] = dp[i - 2] + min(y, (diff[i].second - diff[i - 1].second) * x);
            if(i % 2){
                dp[i] = min(dp[i - 1] + y, dp[i]);
            } else {
                dp[i] = min(dp[i - 1], dp[i]);
            }
        }
        //f1(i, dp) cout << i << sp;
        //cout << endl; 
        ans = dp[diff.size() - 1]; 
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
