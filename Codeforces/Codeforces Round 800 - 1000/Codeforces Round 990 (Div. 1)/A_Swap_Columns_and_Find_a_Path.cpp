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
    ll n, sum = 0;
    cin >> n;
    vector<ll> a1(n), a2(n);
    f1(i, a1){
        cin >> i;
    }
    f1(i, a2){
        cin >> i;
    }
    ll ans = -INF; 
    f2(i, n, 0){
        ll aux = a1[i] + a2[i];
        f2(j, n, 0){
            if(j != i){
                aux += max(a1[j], a2[j]);
            }
        }
        ans = max(aux, ans);
    }
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
