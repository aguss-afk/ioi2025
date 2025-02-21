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
    ll n;
    cin >> n;
    ll a, b, c;
    cin >> a >> b >> c; 
    ll tot = a + b + c;
    ll ans = n / tot;
    if(ans * tot == n){
        cout << ans * 3 << endl;
        return;
    } 
    if(ans * tot + a >= n){
        cout << ans * 3 + 1 << endl;
        return;
    }
    if(ans * tot + a + b >= n){
        cout << ans * 3 + 2 << endl;
        return;
    }
    cout << (ans + 1) * 3 << endl;

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
