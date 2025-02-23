#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int n, ans = 1000000, k = 0;
    cin >> n;
    for(int i = 0; i < 9; i++){
        string s = to_string(n - i);
        int aux = 0;
        for(char &x : s){
            if(x <= '7'){
                aux = max(aux, x - '0');
            }
        }
        if(i >= 7 - aux){
            cout << i << "\n";
            return;
        }
    }
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
