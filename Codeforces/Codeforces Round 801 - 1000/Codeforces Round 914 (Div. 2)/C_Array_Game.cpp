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
    int n, k;
    cin >> n >> k;
    ll minarr = INF, mindiff = INF;
    vector<ll> arr(n);
    f1(i, arr){
        cin >> i;
        minarr = min(minarr, i);
    } 
    if(k > 2){
        cout << 0 << endl;
        return;
    }
    vector<ll> diff;
    f2(i, n - 1, 0){
        f2(j, n, i + 1){
            diff.push_back(abs(arr[j] - arr[i]));
            mindiff = min(mindiff, abs(arr[j] - arr[i]));
        }
    }
    ll ans = min(mindiff, minarr);
    if(k == 1){
        cout << ans << endl;
        return;
    }
    sort(all(arr));
    f1(i, diff){
        auto x = lower_bound(all(arr), i);
        if(*x == i){
            cout << 0 << endl;
            return;
        }
        ll aux = abs(*x - i);
        if(x != arr.begin()){
            auto y = x;
            y--;
            aux = min(abs(*y - i), aux);
        }
        ans = min(ans, aux);
    }
    cout << ans << endl;
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
