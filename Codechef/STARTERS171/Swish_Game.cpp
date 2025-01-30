#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int m, k;
    string str;
    cin >> m >> k >> str;
    int s = 0, p = 0;
    for(char &x : str){
        if(x == 'S'){
            s++;
            continue;
        }
        p++;
    }
    if(s >= k or str[m - 1] == 'S'){
        cout << m << '\n';
        return;
    }
    cout << k - s + m - 1 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
