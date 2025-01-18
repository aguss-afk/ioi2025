#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

struct dsu {
    vector<int> arr;
    vector<pair<int, int>> rep;
    int n;
    dsu(int n) : n(n){
        arr.assign(n, 0);
        iota(all(arr), 0);
    }
    
    int find(int a){
        return arr[a] = (arr[a] == a ? a : find(arr[a]));
    }
    void unite(int a, int b){
        int a2 = find(a);
        int b2 = find(b);
        if(a2 == b2){
            rep.push_back({a, b});
            return;
        }
        arr[a2] = b2;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> op(n - 1);
    dsu us(n);
    for(auto &[x, y] : op){
        cin >> x >> y;
        x--;
        y--;
        us.unite(x, y);
    }
    cout << us.rep.size() << '\n';
    while(!us.rep.empty()){
        cout << us.rep.back().first + 1 << " " << us.rep.back().second + 1 << " " << us.rep.back().first + 1 << " ";
        for(int i = 0; i < n; i++){
            if(us.find(i) != us.find(us.rep.back().first)){
                cout << i + 1 << '\n';
                us.unite(i, us.rep.back().first);
                break;
            }
        } 
        us.rep.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
