#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    set<ll> a1, b1;
    for(ll &i : a){
        cin >> i;
        a1.insert(i);
    } 
    for(ll &i : b){
        cin >> i;
        b1.insert(i);
    } 
    if(b1.size() == 1){
        if(a1.size() > 2){
            cout << "YES" << '\n';
            return;
        }
        cout << "NO" << '\n';
        return;
    }
    if(a1.size() == 1){
        set<ll> ans;
        for(int i = 0; i < n; i++){
            ans.insert(a[i] + b[i]);
        }
        if(ans.size() > 2){
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES" << '\n';
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
