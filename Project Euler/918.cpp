#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
ll resp = 0;
vector<int> arr(1e4, 0);
ll calc(ll a){
    ll ans = 0;
    if(a == 1){
        resp += 1;
        cout << a << ' ';
        return 1;
    }
    if(a & 1){
        ans = calc((a - 1) / 2) - 3 * calc((a + 1) / 2);
        resp += ans;
        cout << ans << ' ';
        return ans;
    } 
    ans = 2 * calc(a / 2);
    resp += ans;
    cout << ans << ' ';
    return ans;
}

ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res *= a;
        }
        a *= a;
        b >>= 1;
    }
    return res;
} 

void solve(){
    vector<ll> arr(1e4), pref(1e4, 0);
    arr[1] = 1;
    for(int i = 1; i < 1e3; i++){
        arr[2 * i] = 2 * arr[i];
        arr[2 * i + 1] = arr[i] - 3 * arr[i + 1];
        pref[i] += arr[i] + pref[i - 1];
    }
    for(int i = 1; i < 161; i++){
        cout << i << ". " << arr[i] << ' ' << pref[i] << '\n';
    }
    ll l = 3, r = 60;
    //while(l + 1 < r){
    //    ll m = l + (r - l) / 2;
    //    ll a = 1e12;
    //    dbg(m);
    //    dbg(binpow(2, m));
    //    dbg(a);
    //    if(binpow(2, m) >= a){
    //        r = m;
    //    } else {
    //        l = m;
    //    }
    //}
    //cout << r << endl;
    ll a = 1e12;
    while(1){
        a /= 2;
        if(a & 1) break;
    }
    dbg(a);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}