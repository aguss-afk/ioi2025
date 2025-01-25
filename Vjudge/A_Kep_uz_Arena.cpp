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
    string x;
    cin >> x; 
    char y;
    int count = 0, ans = 0;
    int n = x.size();
    vector<pair<char, int>> vec;
    for(int i = 0; i < n; i++){
        y = x[i];
        if(y == 'L'){
            continue;
        }
        if(!vec.empty() and y == vec.back().first){
            vec.back().second += 1;
            continue;
        }
        vec.push_back({y, 1});
    }
    for(int i = vec.size() - 1; i >= 0; i--){
        if(vec[i].first == 'D'){
            if(i == vec.size() - 1 or i == 0){
                ans += vec[i].second;
                continue;
            }
            if(vec[i].second > 2 or count < 2){
                if(count < 3){
                    ans += count * 2;
                } else {
                    ans += count * 3 - 2;
                }
                ans += vec[i].second;
                count = 0;
            }
            continue;
        }
        count += vec[i].second;
    }
    //for(auto p : vec){
    //    cout << p.first << ' ' << p.second << '\n';
    //}
    if(count < 3){
        ans += count * 2;
    } else {
        ans += count * 3 - 2;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
