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
    ll n, b, c;
    cin >> n >> b >> c;
    if(n == 1){
        if(!c){
            cout << 0 << endl;
            return;
        }
        cout << 1 << endl;
        return;
    }
    if(c >= n){
        cout << n << endl;
        return;
    }
    if(!b){
        if(n > c + 2){
            cout << -1 << endl;
            return;
        }
        if(n < c + 1){
            cout << n << endl;
            return;
        } 
        cout << n - 1 << endl;
        return;
    }
    ll x = ((n - 1) - c) / b + 1;
    cout << n - x << endl;
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
