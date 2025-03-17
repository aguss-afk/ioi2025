#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
int INF = 1000000000;
int k = 17;
pair<int, int> f2(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        if(a.second < b.second){
            return a;
        }
        return b;
    }
    if(a.first > b.first){
        return a;
    }
    return b;
}
pair<int, int> f1(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        if(a.second > b.second){
            return a;
        } 
        return b;
    }
    if(a.first < b.first){
        return a;
    }
    return b;
}
struct sparse_table {
    vector<vector<pair<int, int>>> st1, st2;
    int n;
    sparse_table(const vector<int>&arr) : n(arr.size()){
        st2.assign(k + 1, vector<pair<int, int>>(n, {INF, 0}));
        st1.assign(k + 1, vector<pair<int, int>>(n, {0, 0}));
        for(int i = 0; i < arr.size(); i++){
            st2[0][i] = {arr[i], i};
            st1[0][i] = {arr[i], i};
        }
        build();
    }
    int log2_floor(int i) {
        return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
    }
    void build(){
        for (int i = 1; i <= k; i++){
            for (int j = 0; j + (1 << i) <= n; j++){
                st1[i][j] = f2(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
                st2[i][j] = f1(st2[i - 1][j], st2[i -1][j + (1 << (i - 1))]);
            }
        }
    }
    pair<int, int> leftmost_max_query(int l, int r){
        int i = log2_floor(r - l + 1);
        return f2(st1[i][l], st1[i][r - (1 << i) + 1]);
    }
    pair<int, int> rightmost_min_query(int l, int r){
        int i = log2_floor(r - l + 1);
        return f1(st2[i][l], st2[i][r - (1 << i) + 1]);
    }
};
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr){
        cin >> i;
    }
    sparse_table st(arr);
    int q;
    cin >> q;
    while(q--){
        int a, b, ans = 0;
        cin >> a >> b;
        a--;
        b--;
        while(a <= b){
            pair<int, int> minimum = st.rightmost_min_query(a, b);
            if(a == minimum.second){
                ans++;
            } else {
                pair<int, int> maximum = st.leftmost_max_query(a, minimum.second - 1);
                if(maximum.first == minimum.first){
                    ans += minimum.second - a + 1;
                } else {
                    ans += maximum.second - a + 1;
                }
            }
            a = minimum.second + 1;
        }
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(test_cases){
        int t;
        cin >> t;
        for(int i = 0; i < t; i++){
            solve();
        }
        return 0;
    }
    solve();
    return 0;
}
