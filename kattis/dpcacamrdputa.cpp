#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << '\n';
using namespace std;
int main(){
    int n;
    cin >> n;
    const int INF = INT_MAX;
    vector<int> dp(n + 1, INF);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i / 2; j++){
            dp[i] = min(dp[i], dp[i - j] + dp[j]);
        } 
        for(int j = 2; j * j <= i; j++){
            if(!(i % j)){
                dp[i] = min(dp[i], dp[i / j] + dp[j]);
            }
        } 
        string x = to_string(i);
        for(int j = 0; j < x.size() - 1; j++){
            if(x[j + 1] == '0'){
                continue;
            }
            int a = stoi(x.substr(0, j + 1)), b = stoi(x.substr(j + 1));
            dp[i] = min(dp[i], dp[a] + dp[b]);
        }
    }
    cout << dp[n];
    return 0;
}