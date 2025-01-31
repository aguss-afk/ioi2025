#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
int n;
vector<int> arr;
vector<vector<int>> dp;

int f(int i, int j){
    if(i > j){
        return 0;
    }
    if(i == j){
        return 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = f(i + 1, j) + 1;
    if(i + 1 < n and arr[i] == arr[i + 1]){
        dp[i][j] = min(dp[i][j], 1 + f(i + 2, j));
    }
    for(int k = i + 2; k <= j; k++){
        if(arr[i] == arr[k]){
            dp[i][j] = min(dp[i][j], f(i + 1, k - 1) + f(k + 1, j));
        }
    }
    return dp[i][j];
}

void solve(){
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<int>(n, -1));
    for(int &i : arr){
        cin >> i;
    }
    cout << f(0, n - 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
