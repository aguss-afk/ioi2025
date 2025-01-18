#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<ll> arr;
int n, m;
bool getcount(ll mid){
    ll count = 1;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + arr[i] > mid){
            count++;
            sum = 0;
        }
        sum += arr[i];
    }
    return count <= m;
}
void solve(){
    ll l = 0, r = 0;
    cin >> n >> m;;
    arr.assign(n, 0);
    for(ll &x : arr){
        cin >> x;
        r += x;
        l = max(l, x);
    }
    ll ans = 0;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(getcount(mid)){
            ans = mid;
            r = mid - 1;
            continue;
        } 
        l = mid + 1;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
