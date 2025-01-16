#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

struct fenwick_tree_2d {
    vector<vector<ll>> bit;
    int n;
    fenwick_tree_2d(int n) : n(n){
        bit.assign(n + 1, vector<ll>(n + 1, 0));
    }
    void update(int a, int b, ll c){
        for(int i = a; i <= n; i += i & (-i)){
            for(int j = b; j <= n; j += j & (-j)){
                bit[i][j] += c;
            }
        }
    }
    ll getsum(int a, int b){
        ll res = 0;
        for(int i = a; i > 0; i -= i & (-i)){
            for(int j = b; j > 0; j -= j & (-j)){
                res += bit[i][j];
            }
        }
        return res;
    }
    ll getsum(int a, int b, int c, int d){
        // c and d are the lower right coordinates and a and b are the upper left coordinates
        return getsum(c, d) - getsum(c, b - 1) - getsum(a - 1, d) + getsum(a - 1, b - 1);
    }
    void print_bit(){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                cout << getsum(i, j) << " ";
            }
            cout << "\n";
        }
    }
};
void solve(){
    int n;
    cin >> n;
    fenwick_tree_2d bit(n);
    string x;
    cin >> x;
    while(x != "END"){
        if(x == "SET"){
            int a, b, c;
            cin >> a >> b >> c;
            bit.update(a + 1, b + 1, -(bit.getsum(a + 1, b + 1, a + 1, b + 1)));
            bit.update(a + 1, b + 1, c);
            cin >> x;
            continue;
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << bit.getsum(a + 1, b + 1, c + 1, d + 1) << "\n";
        cin >> x;
    }
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
