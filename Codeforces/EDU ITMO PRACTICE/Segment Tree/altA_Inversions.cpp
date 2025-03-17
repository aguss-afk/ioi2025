#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct fenwick_tree {
    vector<int> ft;
    int n;
    fenwick_tree(int N) : n(N){
        ft.assign(n + 1, 0);
    }
    void update(int a){
        while(a <= n){
            ft[a]++;
            a += a & (-a);
        }
    }
    int sum(int a){
        int res = 0;
        while(a > 0){
            res += ft[a];
            a -= a & (-a);
        }
        return res;
    }
};
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n), ans; 
    fenwick_tree ft(n);
    for(int &i : arr){
        cin >> i;
        ans.push_back(ft.sum(n) - ft.sum(i));
        cout << ans.back() << ' ';
        ft.update(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        while(t--){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
