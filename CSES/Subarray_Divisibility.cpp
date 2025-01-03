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
    ll n, ans = 0;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> pref;
    ll sum = 0;
    pref[0] = 1;
    f1(i, arr){
        cin >> i;
        sum += i;
        for(int i = 1; sum >= n * i; i++){
            ans += pref[sum - n * i];
        }
        pref[sum]++;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}