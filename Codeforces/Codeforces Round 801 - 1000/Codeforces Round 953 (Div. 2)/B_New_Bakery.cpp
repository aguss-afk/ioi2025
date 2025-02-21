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
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = 0;
    ll x = b - a + 1;
    if(a > b){
        cout << n * a << endl;
        return;
    }
    if(x > n){
        x = n;
        ans = x * (b + 1) - (x * (x + 1)) / 2;
    } else 
        ans = (n - x) * a + x * (b + 1) - (x * (x + 1)) / 2;
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
