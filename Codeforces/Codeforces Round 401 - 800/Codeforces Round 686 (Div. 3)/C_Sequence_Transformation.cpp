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
    ll ans = INF;
    map<ll, vector<ll>> ma;
    f2(i, n, 0){
        ll aux;
        cin >> aux;
        ma[aux].push_back(i);
    }
    f1(i, ma){
        ll aux = 0;
        f2(j, i.second.size() - 1, 0){
            if(i.second[j + 1] == i.second[j] + 1) continue;
            aux++;
        }
        if(*i.second.begin() != 0) aux++;
        if(*i.second.rbegin() != n - 1) aux++;
        ans = min(aux, ans);
    }
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}