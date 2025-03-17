#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 1;

void solve(){
    int k;
    cin >> k;
    vector<int> arr;
    ll ans = 0, x = k, aux;
    while(x){
        aux = 0;
        for(int i = 1; i < 448; i++){
            if(i * (i - 1) <= 2 * x){
                aux = i;
            }
        }
        x -= aux * (aux - 1) / 2;
        ans += aux;
        arr.push_back(aux);
    }
    cout << ans << '\n';
    ll y = 0, xi = 0;
    for(int &i : arr){
        for(int j = 0; j < i; j++){
            cout << y << ' ' << ++xi << '\n';
        }
        y++;
        xi += 5000;
    }
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
