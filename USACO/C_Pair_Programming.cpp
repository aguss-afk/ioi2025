#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
unordered_set<ll> ans;
vector<pair<int, bool>> i1, i2;

void interleave(int ind1, int ind2, ll num){
    if(ind1 == i1.size() and ind2 == i2.size()){
        ans.insert(num);
    }
    if(ind1 < i1.size()){
        if(i1[ind1].second){
            interleave(ind1 + 1, ind2, num + i1[ind1].first);
        } else {
            interleave(ind1 + 1, ind2, num * i1[ind1].first);
        }
    }
    if(ind2 < i2.size()){
        if(i2[ind2].second){
            interleave(ind1, ind2 + 1, num + i2[ind2].first);
        } else {
            interleave(ind1, ind2 + 1, num * i2[ind2].first);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    for(char i : s1){
        if(i == '+'){
            i1.push_back({1, 1});
            continue;
        }
        i1.push_back({i - '0', 0});
    }
    for(char i : s2){
        if(i == '+'){
            i2.push_back({1, 1});
            continue;
        }
        i2.push_back({i - '0', 0});
    }
    interleave(0, 0, 0);
    cout << ans.size() % MOD << '\n';
    i1.clear();
    i2.clear();
    ans.clear();
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
