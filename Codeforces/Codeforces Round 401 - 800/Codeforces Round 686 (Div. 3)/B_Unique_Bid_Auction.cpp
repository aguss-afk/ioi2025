#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
/*
GAY EL QUE LO LEA
bro? 🤨
*/
void solve(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, pair<ll, ll>> ma;
    f2(i, n, 0){
        ll aux;
        cin >> aux;
        ma[aux].second = i;
        ma[aux].first++; 
    }
    ll ans = -1, pos = 0;
    f1(i, ma){
        if(i.second.first == 1){
            if(ans == -1){
                ans = i.second.first;
                pos = i.second.second;
            } else {
                if(i.first < ans){
                    ans = i.first;
                    pos = i.second.second;
                }
            }
        }
    }
    if(ans == -1) cout << -1 << endl;
    else cout << pos + 1 << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--)
        solve();
}