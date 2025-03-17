#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;
ll MOD = 1000000;
vector<vector<ll>> dp(101, vector<ll>(101, -1));
ll calc(int a, int b){
    if(b == 1){
        return dp[a][b] = 1;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    ll ans = 0;
    for(int i = 0; i <= a; i++){
        ans += calc(a - i, b - 1);
        ans %= MOD;
    }
    return dp[a][b] = ans;
}
void solve(int a, int b){
    cout << calc(a, b) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int a, b;
        cin >> a >> b;
        while(a and b){
            solve(a, b);
            cin >> a >> b;
        }
        return 0;
    }
    solve(0, 0);
    return 0;
}
