#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n, k, ans = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    unordered_set<int> vis;
    pair<int, char> act = {0, ' '};
    for(int i = 0; i + k <= n / 2; i++){
        act = {0, ' '};
        unordered_map<char, int> a;
        unordered_set<int> pos;
        pos.insert(i);
        pos.insert(i + k);
        pos.insert(n - i - 1);
        pos.insert(n - i - 1 - k);
        bool t = 0;
        for(auto &ga : pos){
            a[str[ga]]++;
            if(vis.count(ga)){
                act = {a[str[ga]], str[ga]};
                t = 1;
            }
            vis.insert(ga);
        }
        if(!t){
            for(auto &j : a){
                act = max(act, {j.second, j.first});
            }
        }
        for(auto &ga : pos){
            if(str[ga] != act.second){
                ans++;
                str[ga] = act.second;
            }
        }
        dbg(str);
        dbg(ans);
    }
    bool t = 1;
    for(int i = 0; i < n - k; i++){
        if(str[i] != str[i + k] or str[n - i - 1] != str[i]){
            cout << i << ' ';
            cout << str[i] << ' ' << str[i + k] << ' ' << str[n - i - 1] << ' ' << str[n - k - i - 1];
            return;
        }
    }
    cout << ans << '\n';
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
