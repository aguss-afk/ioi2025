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
/*
    Pinche pendejada
*/
void solve(){
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> arr(n);
    ll sum = 0, ma = 0;
    f1(i, arr){
        cin >> i;
        ma = max(ma, i);
        sum += i;
    }
    ll x = ceil((double)sum / (double)m);
    cout << max(ma, x) << endl; 
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
