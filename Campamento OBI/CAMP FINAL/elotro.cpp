#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << ": " << x << '\n';

struct fen_tree {
    vector<ll> fen;
    int n;
    fen_tree(int N) : n(N), fen(N + 1){};
    int x(int a){
        return a & -a;
    }
    void update(ll a, ll b){
        while(a <= n){
            fen[a] += b;
            a += x(a);
        }
    }
    ll getsum(int a){
        ll res = 0;
        while(a > 0){
            res += fen[a];
            a -= x(a);
        }
        return res;
    }
};


int main(){
    ll n, ans = 0;
    cin >> n;
    cin >> ans;
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        if(str == "INFLATION"){
            ll in;
            cin >> in;
            ans += in;
        } else {
            ll n1, n2;
            cin >> n1 >> n2;
            if(ans == n1) ans = n2;
        }
        cout << ans << '\n';
    }
}