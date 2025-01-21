#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
int n, k;
vector<ll> arr;

bool f(ll m){
    int p = 0, noc = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] - arr[p] >= m){
            p = i;
            noc++;
        }
    }
    return noc >= k;
}

void solve(){
    cin >> n >> k;
    arr.assign(n, 0);
    for(ll &x : arr){
        cin >> x;
    }
    ll l = 0, r = 1e9, ans = 0;
    while(l + 1 < r){
        ll m = l + (r - l) / 2;
        if(f(m)){
            l = m;
            continue;
        } 
        r = m;
    }
    cout << l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
