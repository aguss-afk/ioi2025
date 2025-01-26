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

ll n, sum;
vector<ll> arr;
bool f(ll x){
    //cout << arr[n / 2] << sp << (sum + x) / (2 * n) << sp << x <<  endl;
    return arr[n / 2] <= (sum + x) / (2 * n);
}
void solve(){
    cin >> n;
    arr.assign(n, 0);
    sum = 0;
    ll r = 1e17;
    f1(i, arr){
        cin >> i;
        sum += i;
    }
    if(n == 1 or n == 2){
        cout << -1 << endl;
        return;
    }
    sort(all(arr));
    ll l = 0;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    raya();
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
