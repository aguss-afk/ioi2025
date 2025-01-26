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
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n), qu(q), pref(n + 1);
    ll sum = 0;
    f1(i, arr){
        cin >> i;
    }
    f2(i, n + 1, 1){
        pref[i] = arr[i - 1] + pref[i - 1];
    }
    f1(i, qu) cin >> i;
    map<ll, ll> a;
    a[0] = 0;
    ll ma = 0;
    f2(i, n + 1, 1){
        ma = max(ma, arr[i - 1]);
        a[ma] = i;
    }
    f1(i, qu){
        auto y = a.upper_bound(i);
        y--;
        cout << pref[y -> second] << sp;
    }
    cout << endl;
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
