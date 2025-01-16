#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
struct fenwick_tree {
    vector<ll> bit;
    int n;
    fenwick_tree(int n) : n(n){
        bit.assign(n + 1, 0);
    }
    ll getsum(int a){
        ll res = 0;
        while(a > 0){
            res += bit[a];
            a -= a & (-a);
        }
        return res;
    }
    void update(int a, int b){
        while(a <= n){
            bit[a] += b;
            a += a & (-a);
        }
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    fenwick_tree bit(n); 
    queue<pair<int, int>> notis;
    map<int, queue<int>> indnoti;
    vector<bool> mark(3e5 + 1);
    int i = 0;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            bit.update(b, 1);
            notis.push({b, i});
            indnoti[b].push(i);
            i++;
        } else if(a == 2){
            while(!indnoti[b].empty()){
                mark[indnoti[b].front()] = 1;
                indnoti[b].pop();
            }
            bit.update(b, - bit.getsum(b) + bit.getsum(b - 1));
        } else {
            while(!notis.empty() and notis.front().second < b){
                int i = notis.front().second;
                int x = notis.front().first;
                notis.pop();
                if(mark[i] == false){
                    mark[i] = true;
                    indnoti[x].pop();
                    bit.update(x, -1);
                }
            }

        }
        cout << bit.getsum(n) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
