#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), pref(n + 1);
    unordered_set<int> p;
    map<int, vector<int>> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        p.insert(arr[i]);
        x[arr[i]].push_back(i);
        pref[i + 1] = p.size();
    }
    ll ans = 0;
    for(auto &[x, y] : x){
        if(y.size() >= 2){
            int aux = pref[y[y.size() - 2]];
            if(y.size() > 2){
                aux--;
            }
            ans += aux;
        }
    }
    cout << ans;
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
