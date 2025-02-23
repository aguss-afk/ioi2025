#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m)); 
    unordered_map<int, int> ma;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i and arr[i][j] == arr[i - 1][j]){
                ma[arr[i][j]] = 2;
            }
            if(i < n - 1 and arr[i][j] == arr[i + 1][j]){
                ma[arr[i][j]] = 2;
            }
            if(j and arr[i][j] == arr[i][j - 1]){
                ma[arr[i][j]] = 2;
            }
            if(j < m - 1 and arr[i][j + 1] == arr[i][j]){
                ma[arr[i][j]] = 2;
            }
            if(!ma.count(arr[i][j])){
                ma[arr[i][j]] = 1;
            }
        }
    }
    int ans = 0, sum = 0;
    for(auto &[x, y] : ma){
        ans = max(ans, y);
        sum += y;
    }
    cout << sum - ans << '\n';
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
