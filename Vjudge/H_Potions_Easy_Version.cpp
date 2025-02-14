#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ans += x;
        q.push(x);
        while(ans < 0){
            ans -= q.top();
            q.pop();
        }
    }
    cout << q.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
