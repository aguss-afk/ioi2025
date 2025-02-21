#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
void solve(){
    ll n, m;
    cin >> n >> m;
    ll ans = 0, mo = 0;
    f2(i, n, 0){
        ll aux;
        cin >> aux;
        ans += aux / 2;
        mo += aux % 2;
    }
    if(m > ans){
        m -= ans;
        ans *= 2;
        if(m >= mo)
            ans += mo;
        else ans += (m * 2) - mo;
        cout << ans << endl;
        return;
    }
    cout << ans * 2 << endl; 
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
