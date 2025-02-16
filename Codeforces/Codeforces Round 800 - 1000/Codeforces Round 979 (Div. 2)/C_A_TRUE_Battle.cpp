#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int x;
    cin >> x;
    string y;
    cin >> y;
    for(int i = x - 2; i > 0; i--){
        if(y[i + 1] == '0' and y[i] == '1' and y[i - 1] == '0'){
            y[i] = '0';
        }
    }    
    for(int i = 0; i < x; i++){
        if(y[i] == '1'){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
