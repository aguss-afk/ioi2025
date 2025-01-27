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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    ll sum = 0, ans = 0;
    f2(i, n, 0){
        ll aux;
        cin >> aux;
        m[aux]++;
        sum++;
    }
    vector<ll> sorted;
    f1(i, m){
        sorted.push_back(i.second);
    }
    sort(rall(sorted));
    ll i = 0;
    while(sum - sorted[i] > k){
        sum -= sorted[i++];
        ans++;
    }
    cout << ++ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
