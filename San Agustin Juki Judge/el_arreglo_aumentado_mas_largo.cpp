#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define all(x) x.begin(), x.end()
#define MOD 1000000007
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
    ll ans = 0, aux = n, x = 0;
    while(aux <= m){
        aux += x;
        ans++;
        x++;
    }
    ans--;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--)
        solve();
}