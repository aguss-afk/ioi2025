#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &i : arr){
        cin >> i;
    }
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--){
        int aux = 0;
        for(int j = 0; j <= i; j++){
            aux += arr[i][j] - '0';
        }
        int zercount = 0;
        for(int j = 0; j < n; j++){
            if(zercount == aux and !ans[j]){
                ans[j] = i + 1;
                break;
            }
            if(!ans[j]){
                zercount++;
            }
        }
    }
    for(int &i : ans){
        cout << i << ' ';
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
