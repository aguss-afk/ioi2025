#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> arr(n);
    ll sum = 0;
    for(auto &[x, y] : arr){
        cin >> x >> y;
        sum += y;
    }
    const ll INF = 1e17;
    vector<ll> dp(sum + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int v = sum; v >= arr[i].second; v--){
            dp[v] = min(dp[v], dp[v - arr[i].second] + arr[i].first);
        } 
        cout << '\n';
    }
    int ans = 0;
    for(int i = 0; i <= sum; i++){
        if(dp[i] <= m){
            ans = max(ans, i);
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
