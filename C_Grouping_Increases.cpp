#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n, x, y = 10000000;
    cin >> n;
    vector<int> arr(n), b, c;
    for(int &i : arr){
        cin >> i;
    } 
    b.push_back(arr[0]);
    c.push_back(10000000);
    x = b.back();
    for(int i = 1; i < n; i++){
        if(arr[i] <= x or arr[i] > y){
            if(x == b.back()){
                b.push_back(arr[i]);
            } else {
                c.push_back(arr[i]);
            }
        } else {
            if(y == b.back()){
                b.push_back(arr[i]);
            } else {
                c.push_back(arr[i]);
            }
        }
        x = min(b.back(), c.back());
        y = max(b.back(), c.back());
    }
    int ans = 0;
    for(int i = 0; i < b.size() - 1; i++){
        ans += (b[i + 1] > b[i]);
    }
    for(int i = 0; i < c.size() - 1; i++){
        ans += (c[i + 1] > c[i]);
    }
    cout << ans << '\n';
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
