#include <bits/stdc++.h>
using namespace std;
#define dbgv(x) cerr << #x << ": "; for(auto &i : x) cerr << i << ' '; cerr << "\n";
#define dbg(x) cerr << #x << ": " << x << '\n';
int main(){
    int n;
    cin >> n;
    vector<int> arr(n), dp(n, INT_MAX);
    for(int &i : arr){
        cin >> i;
    }   
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(i + 1 < n){
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(arr[i + 1] - arr[i]));
        } if(i + 2 < n){
            dp[i + 2] = min({
                dp[i + 2],
                dp[i] + abs(arr[i + 2] - arr[i]),
            });
        }
    }
    cout << dp[n - 1];
}