#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;

void solve(){
    int n;
    cin >> n;
    vector<int> a0(n), a1(n);
    multiset<int> a2;
    for(int &i : a0){
        cin >> i;
    }    
    for(int &i : a1){
        cin >> i;
    }
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        a2.insert(aux);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        multiset<int>::iterator x = a2.lower_bound(a1[i]);
        if(x != a2.end() and *x > a1[i]){
            ans++;
            a2.erase(x);
            continue;
        }
        a2.erase(a2.begin());
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
        for(int i = 0; i < t; i++){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
