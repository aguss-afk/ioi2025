#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), ans(n + 1), pref(n + 1);
    for(int &i : a){
        cin >> i;
    }
    for(int &i : b){
        cin >> i;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]){
            pref[i + 1]++;
        }
        pref[i + 1] += pref[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int aux = 0;
                dbg(i);
                dbg(j);
            for(int k = 0; k <= (j - i) / 2; k++){
                dbg(a[j - k]);
                dbg(b[i + k]);
                if(a[j - k] == b[i + k] or a[i + k] == b[j - k]){
                    aux++;
                }
            }
            aux += pref[i] + pref[n] - pref[j + 1];
            dbg(aux);
            ans[aux]++;
        }
    }
    for(int &i : ans){
        cout << i << '\n';
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
