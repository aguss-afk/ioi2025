#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

const int k = 25;
struct sparse_table {
    vector<vector<pair<ll, ll>>> sp, spmax;
    pair<ll, ll> f(pair<ll, ll> a, pair<ll, ll> b){
        if(a.first == b.first){
            return a.second > b.second ? a : b;
        } 
        return min(a, b);
    }
    pair<ll, ll> f2(pair<ll, ll> a, pair<ll, ll> b){
        if(a.first == b.first){
            return a.second < b.second ? a : b;
        } 
        return max(a, b);
    }
    sparse_table(vector<ll> &arr){
        sp.assign(k + 1, vector<pair<ll, ll>>(arr.size() + 1, {INF, INF}));
        spmax.assign(k + 1, vector<pair<ll, ll>>(arr.size() + 1, {INF, INF}));
        for(int i = 0; i < arr.size(); i++){
            sp[0][i] = {arr[i], i};
            spmax[0][i] = {arr[i], i};
        }
        for(int i = 1; i <= k; i++){
            for(int j = 0; j + (1 << i) <= arr.size(); j++){
                sp[i][j] = f(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
                spmax[i][j] = f2(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int lg2(int i) {
       return i ? 63 - __builtin_clzll(i) : -1;
    }
    pair<ll, ll> query(int l, int r){
        int i = lg2(r - l + 1);
        pair<ll, ll> ans = f(sp[i][l], sp[i][r - (1 << i) + 1]);
        return ans;
    }
    pair<ll, ll> qmax(int l, int r){
        int i = lg2(r - l + 1);
        pair<ll, ll> ans = f2(spmax[i][l], spmax[i][r - (1 << i) + 1]);
        return ans;
    }
};
void solve(){
    int n, q;
    cin >> n;
    vector<ll> arr(n);
    for(ll &i : arr){
        cin >> i;
    }
    cin >> q;
    sparse_table sp(arr);
    while(q--){
        int l, r, ans = 0;
        cin >> l >> r;
        l--;
        r--;
        while(1){
            pair<ll, ll> res = sp.query(l, r);
            l = sp.query(l, r).second;
            ans++;
            if(r == l){
                break;
            }
            l++;
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
