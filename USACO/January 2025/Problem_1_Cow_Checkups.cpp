#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> posi(n + 1);
    for(int &i : a){
        cin >> i;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        posi[b[i]].push_back(i);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(auto &j : posi[a[i]]){
            ll x = min(i, j);
            ll y = max(i, j);
            if(j == i){
                ans += (x + 1) * (x) / 2;
                ans += (n - y - 1) * (n - y) / 2;
            } 
            ans += min(x, n - y - 1);
            ans++;
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}