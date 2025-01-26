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
    string x;
    cin >> x; 
    string ans;
    string aux;
    ll j = min(9ll, (ll)x.size());
    for(int i = 0; i < j; i++){
        aux.push_back(x[i]);
    }
    while(!aux.empty()){
        pair<ll, ll> au;
        for(int i = 0; i < aux.size(); i++){
            ll aj = aux[i] - '0' - i;
            if(aj > au.first){
                au = {aj, i};
            }
        }
        ans.push_back(au.first + '0');
        aux.erase(aux.begin() + au.second);
        if(j < x.size()){
            aux.push_back(x[j++]);
        }
    }
    cout << ans << endl;
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
