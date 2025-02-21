#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    ll n, m;
    cin >> n >> m;
    ll aux = 0, x = 0, ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        pq.push(a);
    }
    while(!pq.empty()){
        ll y = pq.top() - aux, oa = y * pq.size();
        aux += y;
        if(y == -1){
            pq.pop();
            continue;
        }
        if(ans + oa >= m){
            x += m - ans;
            break;
        }
        ans += oa;
        x += oa + 1;
        pq.pop();
    }
    cout << x << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
