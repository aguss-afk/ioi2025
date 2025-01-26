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
    ll r, g, b, ans = 0;
    cin >> r >> g >> b;
    ll ma = max(r, max(g, b));
    if(r != ma){
        if(g == ma) swap(g, r);
        else swap(b, r);
    }
    ll mi = min(g, b);
    if(b != mi) swap(b, g);
    // r max b min
    ll p1 = r, p2 = g;
    if(b + g > r){
        ll x = r - g;
        g += x;
        b -= x;
        r += b / 2;
        g += b / 2;
    } else {
        ans += b;
        r -= b;
    }
    ans += min(r, g);
    cout << ans << endl;
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
