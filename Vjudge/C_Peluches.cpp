#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 998244353;
const ll INF = 1e18 + 5;

void solve(){
    int q, n;
    cin >> q >> n;
    vector<ll> dp(5005, 0);
    dp[0] = 1;
    while(q--){
        char a;
        int b;
        cin >> a >> b;
        if(a == '+'){
            for(int i = n; i >= b; i--){
                dp[i] += dp[i - b];
                dp[i] %= MOD;
            } 
        } else {
            for(int i = b; i <= n; i++){
                dp[i] += (MOD - dp[i - b]);
                dp[i] %= MOD;
            }
        }
        cout << dp[n] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
