#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

void solve(){
    int n;    
    cin >> n;
    int x = 0;
    bool t = 0;
    for(int i = 0; i < n; i++){
        if(!((x++) % 2)){
            t = !t;
        }
        if(t){
            cout << 'b';
        } else {
            cout << 'a';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
