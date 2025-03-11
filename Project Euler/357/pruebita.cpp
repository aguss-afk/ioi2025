#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<bool> criba(1e8 + 10, 1);
void solve(){
    criba[0] = criba[1] = 0;
    ll ans = 1;
    for(ll i = 2; i <= 1e8; i++){
        if(criba[i] and i * i <= 1e8){
            for(ll j = i * i; j <= 1e8; j += i){
                criba[j] = 0;
            }
        }
        if(!(i & 1)){
            bool t = 1;
            for(int x = 1; x <= (int)sqrt(i); x++){
                if(i % x == 0){
                    if(!criba[i / x + x]){
                        t = 0;
                        break;
                    }
                }
            }
            if(t) ans += i;
        }
    }
    cout << ans;
}
int main(){
    solve();
}