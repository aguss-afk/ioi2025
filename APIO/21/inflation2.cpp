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
    void update(int a, ll b){
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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    //fen_tree ft(n);
    map<ll, int> nose;
    ll ans = 0;
    for(ll &i : arr) {
        cin >> i;
        nose[i]++;
        ans += i;
    }
    for(int i = 0; i < n; i++){
        //ft.update(i + 1, arr[i]);
    }   
    int q;
    cin >> q;
    while(q--){
        string x;
        cin >> x;
        if(x == "INFLATION"){
            ll y;
            cin >> y;
            ans += y * n;
            map<ll, int> nose2;
            for(auto i : nose){
                nose2[i.first + y] = i.second;
            }
            nose.clear();
            for(auto i : nose2){
                nose[i.first] = i.second;
            }
        } else {
            ll y, z;
            cin >> y >> z;
            ans += (z - y) * nose[y];
            nose[z] += nose[y];
            nose.erase(y);
        }
        //cout << ft.getsum(n) << '\n';
        cout << ans << '\n';
    }
}






