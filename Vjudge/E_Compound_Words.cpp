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
    string x;
    set<string> ans;
    vector<string> str;
    while(cin >> x){
        str.push_back(x);
    }
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < str.size(); j++){
            if(j != i){
                ans.insert(str[i] + str[j]);
            }
        }
    }
    for(string y : ans){
        cout << y << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
