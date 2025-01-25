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
    int n, m;
    cin >> n >> m;
    vector<int> abc(26);
    for(int &i : abc){
        cin >> i;
    } 
    string s1, s2;
    cin >> s1 >> s2;
    int dp[s1.size() + 1][s2.size() + 1] = {0};
    for(int i = s1.size() - 1; i >= 0; i--){
        for(int j = s2.size() - 1; j >= 0; j--){
            if(s1[i] == s2[j]){
                dp[i][j] = abc[s1[i] - 97] + dp[i + 1][j + 1];
                continue;
            }
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
