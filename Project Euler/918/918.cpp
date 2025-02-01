#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
ll calc(ll a){
    ll ans = 0;
    if(a == 1){
        return 1;
    }
    if(a & 1){
        ans = calc((a - 1) / 2) - 3 * calc((a + 1) / 2);
        return ans;
    } 
    ans = 2 * calc(a / 2);
    return ans;
}

void solve(){
    cout << 4 - calc(500000000000);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}