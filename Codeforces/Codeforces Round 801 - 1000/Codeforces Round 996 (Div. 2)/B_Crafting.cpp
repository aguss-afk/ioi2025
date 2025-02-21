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
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    f1(i, a){
        cin >> i;
    } 
    f1(i, b){
        cin >> i;
    }
    ll men = 0, ma = INT_MAX;
    for(int i = 0; i < n; i++){
        a[i] -= men;
        if(a[i] < b[i]){
            if(a[i] + ma < b[i]){
                cout << "NO" << endl;
                return;
            }
            men += b[i] - a[i];
            a[i] = b[i];
        }
        ma = min(ma, a[i] - b[i]);
    }
    cout << "YES" << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
