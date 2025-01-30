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
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<string> t{"RGB", "RBG", "GBR", "GRB", "BRG", "BGR"}; 
    vector<int> ans(6, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            if(str[i] != t[j][i % 3]){
                ans[j]++;
            }
        }
    }
    cout << *min_element(all(ans)) << '\n';
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
