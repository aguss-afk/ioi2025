#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n, MOD = 998244353;
    cin >> n;
    vector<int> dp(4, 0);
    dp[0] = 1;
    while(n--){
        int x;
        cin >> x;
        if(x == 2){ 
            dp[x] *= 2;
        }
        dp[x] += dp[x - 1];
        dp[x] %= MOD;
    }
    cout << dp[3] << '\n';
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
