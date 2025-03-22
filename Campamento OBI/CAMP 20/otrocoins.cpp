#include <bits/stdc++.h>
using namespace std;
#define dbgv(x) cerr << #x << ": "; for(auto &i : x) cerr << i << ' '; cerr << "\n";
#define dbg(x) cerr << #x << ": " << x << '\n';
vector<int> coins, dp;
const int MOD = 1000000007;
int noseeldp(int coin){
    if(coin < 0){
        return 0;
    }
    if(coin == 0){
        return 1;
    }
    if(dp[coin]) return dp[coin];
    for(int &i : coins){
        dp[coin] += noseeldp(coin - i) % MOD;
        dp[coin] %= MOD;
    }
    return dp[coin];
}

int main(){
    int a, b;
    cin >> a >> b;
    coins.assign(a, 0);
    for(int &i : coins) cin >> i;
    dp.assign(b + 1, 0);
    cout << noseeldp(b);
}