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

ll pref[200];
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < 200; i++){
        if(pref[i] > n){
            cout << pref[i - 1] << sp;
            cout << i - 1 << endl;
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 1; i < 200; i++){
        pref[i] = i * (i + 1) / 2;
        pref[i] += pref[i - 1];
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}