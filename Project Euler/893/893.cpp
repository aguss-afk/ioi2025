#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
void solve(){
    vector<int> dp(1e6 + 1, MOD), num = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    ll ans = 0;
    for(int i = 0; i < 10; i++){
        dp[i] = num[i];
    }
    for(int i = 1; i < 1e6 + 1; i++){
        string x = to_string(i);
        int aux = 0;
        for(char j : x){
            aux += num[j - '0'];
        }
        dp[i] = min(dp[i], aux);
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                dp[i] = min(dp[i], dp[j] + dp[i / j] + 2);
            }
        }
    }
    for(int i = 1; i < 1e6; i++){
        if(dp[i] > 17){
            continue;
        }
        for(int j = 1; j < 1e6; j++){
            if(i + j > 1e6){
                break;
            }
            dp[i + j] = min(dp[i + j], dp[i] + dp[j] + 2);
        }
    }
    for(int &x : dp){
        ans += x;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}