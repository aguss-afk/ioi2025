#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << '\n';
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> derecha(n), izquierda(n), dp(n), arr(n);
    for(int &i : arr){
        cin >> i;
    }
    derecha[0] = arr[0];
    izquierda[n - 1] = arr[n - 1];
    for(int i = 1; i < n; i++){
        derecha[i] = max(derecha[i - 1], arr[i]);
        izquierda[n - i - 1] = min(izquierda[n - i], arr[n - i - 1]);
    }
    dp[n - 1] = derecha[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if(derecha[i] > izquierda[i + 1]){
            dp[i] = dp[i + 1];
            continue;
        }
        dp[i] = derecha[i];
    }
    for(const int &i : dp){
        cout << i << ' ';
    }
    cout << "\n";
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
    return 0;
}