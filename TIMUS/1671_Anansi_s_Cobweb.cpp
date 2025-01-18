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
    vector<int> arr, size;
    int n, c;
    dsu(int n) : n(n){
        c = n;
        arr.assign(n, 0);
        size.assign(n, 1);
        iota(all(arr), 0);
    }
    int find(int a){
        return arr[a] = (arr[a] == a ? a : find(arr[a]));
    }
    void join(int a, int b){
        int A = find(a);
        int B = find(b);
        if(A == B){
            return;
        }
        if(size[A] > size[B]){
            swap(A, B);
        }
        arr[A] = B;
        size[B] += size[A];
        find(a);
        c--;
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> op(m);
    dsu us(n);
    for(int i = 0; i < m; i++){
        cin >> op[i].first >> op[i].second;
    }
    int q;
    cin >> q;
    vector<int> querys(q), ans;
    set<int> qu;
    for(int &x : querys){
        cin >> x;
        qu.insert(x);
    }
    reverse(all(querys));
    for(int i = 0; i < m; i++){
        if(!qu.count(i + 1)){
            us.join(op[i].first - 1, op[i].second - 1);
        }
    }
    for(int x : querys){
        ans.push_back(us.c);
        x--;
        us.join(op[x].first - 1, op[x].second - 1);
    }
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
