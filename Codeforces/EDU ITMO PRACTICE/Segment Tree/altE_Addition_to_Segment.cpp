#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct fenwick_tree {
    vector<ll> ft;
    int n;
    fenwick_tree(int N) : n(N){
        ft.assign(n + 2, 0);
    }
    void update(int a, ll b){
        while(a <= n){
            ft[a] += b;
            a += a & (-a);
        }
    }
    ll getsum(int a){
        ll res = 0;
        while(a > 0){
            res += ft[a];
            a -= a & (-a);
       }
       return res;
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    fenwick_tree ft(n + 1);
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int b, c;
            ll d;
            cin >> b >> c >> d;
            ft.update(b + 1, d);
            ft.update(c + 1, -d);
            continue;
        }
        int b;
        cin >> b;
        cout << ft.getsum(b + 1) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
