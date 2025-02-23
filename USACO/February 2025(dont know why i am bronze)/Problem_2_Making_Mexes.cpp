#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> pref(200002, {0, 0});
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        pref[aux + 1].second++;
    }
    for(int i = 0; i <= n; i++){
        if(!pref[i + 1].second){
            pref[i + 1].first++;
        }
        pref[i + 1].second += pref[i].second;
        pref[i + 1].first += pref[i].first;
    }
    cout << pref[1].second << '\n';
    for(int i = 2; i <= n + 1; i++){
        cout << max(pref[i].second - pref[i - 1].second, pref[i - 1].first) << '\n';
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
