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
    ll n;
    cin >> n;
    ll ans = 0;
    map<ll, ll> ma;
    vector<ll> arr(n);
    fen_tree ft(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans += arr[i];
        ft.update(i + 1, arr[i]);
        ma[arr[i]]++;
    }
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        if(str == "INFLATION"){
            ll a;
            cin >> a;
            ans += n * a;
            ft.update(1, n * a);
            //map<ll, ll> ma2;
            //for(auto &i : ma){
                //cout << i.first << ' ' << i.second << '\n';
                //ma2[i.first + a] = i.second;
            //}
            //dbg(ans);
            //for(auto &i : ma2){
                //cout << i.first << ' ' << i.second << '\n';
            //}
            //ma.clear();
            //copy(ma2.begin(), ma2.end(), ma.begin());
            //ma = ma2;
        } else {
            ll a, b;
            cin >> a >> b;
            ans -= a * ma[a];
            ans += b * ma[a];
            //dbg((b - a) * ma[a]);
            ft.update(1, (b - a) * ma[a]);
            //for(auto &i : ma){
                //cout << i.first << ' ' << i.second << '\n';
            //}
           /*  dbg(ans);
            dbg(ma[b]);
            dbg(ma[a]); */
            if(a != b){
                ma[b] += ma[a];
                ma.erase(a);
            }
            //for(auto &i : ma){
                //cout << i.first << ' ' << i.second << '\n';
            //}
        }
        cout << ft.getsum(n) << '\n';
    }
}