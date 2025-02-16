#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    string str1, str2;
    cin >> str1 >> str2;
    vector<vector<int>> dp((int)str1.size() + 1, vector<int>((int)str2.size() + 1, 0));
    for(int i = 1; i <= (int)str1.size(); i++){
        for(int j = 1; j <= (int)str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = (int)str1.size(), j = (int)str2.size();
    string ans;
    while(dp[i][j] and i and j){
        if(dp[i - 1][j] == dp[i][j]){
            i--;
            continue;
        } 
        if(dp[i][j - 1] == dp[i][j]){
            j--;
            continue;
        }
        if(str1[i - 1] == str2[j - 1]){
            ans.push_back(str1[i - 1]);
        }
        i--;
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
