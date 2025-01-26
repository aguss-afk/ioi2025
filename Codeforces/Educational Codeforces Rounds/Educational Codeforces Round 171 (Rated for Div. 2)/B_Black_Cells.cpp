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
    int n;
    cin >> n;
    vector<ll> arr(n);
    f1(i, arr){
        cin >> i;
    }    
    if(n % 2){
        ll ans = INF, ma;
        for(int i = 0; i < n; i += 2){
            if(i != 0 and i < n - 1 and arr[i] - arr[i - 1] == 1 and arr[i + 1] - arr[i] == 1){
                continue;
            }
            ma = 1;
            for(int j = i - 1; j >= 0; j -= 2){
                ma = max(arr[j] - arr[j - 1], ma);
            }
            for(int j = i + 1; j < n; j += 2){
                ma = max(arr[j + 1] - arr[j], ma);
            }
            ans = min(ans, ma);
        }
        cout << ans << endl;
        return;
    }
    ll ma = 0;
    for(int i = 0; i < n - 1; i += 2){
        ma = max(ma, arr[i + 1] - arr[i]);
    }
    cout << ma << endl;
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
