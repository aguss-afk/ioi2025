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
    ll n, m, ans = INF;
    cin >> n >> m; 
    vector<ll> arr(n), spice(n);
    f2(i, n, 0){
        cin >> arr[i] >> spice[i];
    }
    multiset<ll> currspice;
    ll r = 0, l = 0, sum = 0;
    while(r < n){
        currspice.insert(spice[r]);
        sum += arr[r];
        while(sum >= m and l < r){
            ans = min(ans, *prev(currspice.end()));
            currspice.erase(currspice.find(spice[l]));
            sum -= arr[l];
            l++;
        }
        r++;
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    solve();
}
