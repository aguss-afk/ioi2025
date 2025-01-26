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
    string x;
    cin >> x;
    if(x[0] == 's') {
        x[0] = '.';
    }
    if(x[n - 1] == 'p'){
        x[n - 1] = '.';
    }
    ll s = 0, p = 0;
    f1(i, x){
        if(i == 's'){
            s++;
        }
        if(i == 'p'){
            p++;
        }
    }
    if(!p and !s){
        cout << "YES" << endl;
        return;
    }
    if(p and s){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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
