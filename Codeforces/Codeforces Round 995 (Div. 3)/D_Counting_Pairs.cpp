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
    ll n, x, y, sum = 0;
    cin >> n >> x >> y;
    vector<ll> arr(n), pos;
    set<ll> num;
    unordered_map<ll, ll> count;
    f1(i, arr){
        cin >> i;
        pos.push_back(i);
        num.insert(i);
        sum += i;
        count[i]++;
    }
    ll rlim = sum - y, llim = sum - x, ans = 0;
    sort(all(pos));
    f1(i, num){
        auto l = lower_bound(all(pos), rlim - i) - pos.begin();
        auto r = upper_bound(all(pos), llim - i) - pos.begin();
        ans += count[i] * (r - l);
        if(i >= rlim - i and i <= llim - i){
            ans -= count[i];
        }
    }
    cout << ans / 2 << endl;
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