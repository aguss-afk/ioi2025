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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> x(m);
    unordered_set<ll> ks;
    f1(i, x){
        cin >> i;
    } 
    ll sum = 0, tot = n * (n + 1) / 2;
    f2(i, k, 0){
        ll aux;
        cin >> aux;
        ks.insert(aux);
    }
    if(k + 1 < n){
        f2(i, m, 0){
            cout << 0;
        }
        cout << endl;
        return;
    }
    if(k == n){
        f2(i, m, 0){
            cout << 1;
        }
        cout << endl;
        return;
    }
    f1(i, x){
        if(!ks.count(i)){
            cout << 1;
            continue;
        }
        cout << 0;
    }
    cout << endl;
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
