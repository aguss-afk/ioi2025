#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
string ch(string &x){
    string str = "";
    for(char &i : x){
        if(i == '1') continue;
        if(i == '0') str.clear();
        if(i != '+') i = '2';
        str += i;
    }
    return str;
}
void solve(){
    int n, ans = 0;
    string x, y;
    cin >> n >> x >> y;
    x = ch(x);
    y = ch(y);
    vector<vector<vector<int>>> dp(x.size() + 1, vector<vector<int>>(y.size() + 1, vector<int>(2)));
    auto upd = [&](int a, int b, int c, int d){
        if(a <= x.size() and b <= y.size()){
            dp[a][b][c] = (dp[a][b][c] + d) % MOD;
        }
    };
    dp[0][0][0] = 1;
    for(int i = 0; i <= x.size(); i++){
        for(int j = 0; j <= y.size(); j++){
            for(int k = 0; k < 2; k++){
                int c = dp[i][j][k];
                if(!c) continue;
                if(i == x.size() and j == y.size()){
                    ans = (ans + c) % MOD;
                    continue;
                }
                upd(i, j + 1, 1, c);
                if(!k){
                    upd(i + 1, j, 0, c);
                    continue;
                }
                if(i < x.size() and y[j - 1] != x[i]){
                    upd(i + 1, j, 0, c);
                }
            }
        }
    }
    cout << ans << '\n';
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
