#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> y(n);
    for(int &i : y){
        cin >> i;
    }     
    string x;
    x += to_string(y[0]);
            x += to_string(y[i]);
        }
    }
    n = x.size();
    for(int i = 0; i < x.size(); i++){
        for(int j = i + 1; j < x.size(); j++){
            string y = x.substr(i, j - i + 1);
            string aux = x.substr(j + 1, j - i + 1);
            dbg(y);
            dbg(x);
            dbg(aux);
            if(aux == y and aux.size() == y.size()){
                x.erase(x.begin() + j + 1, x.begin() + i + 2 * j + 2);
                int a = j + 1;
                int b = 2 * j + 2 + i;
                dbg(a);
                dbg(b);
            }
            dbg(x);
        }
    }
    cout << (x.size() <= m ? "YES" : "NO") << '\n';
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