#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    vector<int>::iterator x = min_element(arr.begin(), arr.end()); 
    int pos = x - arr.begin() + 1;
    cout << n - 1 << '\n';
    for(int i = 0; i < n; i++){
        if(i == pos - 1){
            continue;
        }
        cout << pos << ' ' << i + 1 << ' ' << *x << ' ' << *x + abs(pos - 1 - i) << '\n';
    }
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
