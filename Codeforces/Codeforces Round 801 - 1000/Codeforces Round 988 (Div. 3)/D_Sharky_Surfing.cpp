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
    ll n, m, L, actpow = 1, ans = 0, pos = 0;
    cin >> n >> m >> L;    
    vector<pair<int, int>> hurdles(n), powups(m);
    f1(i, hurdles){
        cin >> i.first >> i.second;
    }
    f1(i, powups){
        cin >> i.first >> i.second;
    }
    priority_queue<ll> unused;
    f1(i, hurdles){        
        for(; pos < m and powups[pos].first < i.first; pos++){
            unused.push(powups[pos].second);
        }
        ll dis = i.second - i.first + 1;
        while(unused.size() and actpow <= dis){
            actpow += unused.top();
            unused.pop();
            ans++;
        }
        if(actpow <= dis){
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
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