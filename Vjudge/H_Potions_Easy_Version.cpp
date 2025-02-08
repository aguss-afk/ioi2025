#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;
struct fenwick_tree{
    vector<ll> arr;
    int n;
    fenwick_tree(vector<ll> &a){
        n = a.size();
        arr.assign(n + 1, 0);
        for(int i = 0; i < a.size(); i++){
            if(a[i] < 0){
                update(i + 1, 0);
            } else {
                update(i + 1, a[i]);
            }
        }
    }
    void update(int a, ll b){
        while(a <= n){
            arr[a] += b;
            a += a & (-a);
        }
    }
    ll query(int a){
        ll res = 0;
        while(a > 0){
            res += arr[a];
            a -= a & (-a);
        }
        return res;
    }
};
bool res(pair<ll, int> a, pair<ll, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}
void solve(){
    ll n, ans = 0;
    cin >> n;
    vector<ll> arr(n);
    vector<pair<ll, int>> pos;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < 0){
            pos.push_back({arr[i], i + 1});
            continue;
        }
        ans++;
    }
    vector<ll> caca(n, 0);
    fenwick_tree ft(arr), check(caca);
    sort(pos.rbegin(), pos.rend());
    for(int i = 0; i < pos.size(); i++){
        ll x = ft.query(pos[i].second) + check.query(pos[i].second);
        dbg(x);
        if(ft.query(pos[i].second) + check.query(pos[i].second) + pos[i].first >= 0){
            check.update(1, pos[i].first);
            check.update(pos[i].second, -pos[i].first); 
            ans++;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
