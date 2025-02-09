#include"holiday.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(x) cerr << #x << ": "; for(auto i : x) cerr << i << ' '; cerr << '\n';
struct element {
    ll val;
    int count;
};

struct segment_tree {
    vector<element> st;
    vector<ll> val;
    int size;
    element merge(element e1, element e2){
        return {e1.val + e2.val, e1.count + e2.count};
    }
    segment_tree(int n, vector<ll> &attraction){
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.resize(size * 2);
        val.resize(n);
        copy(attraction.begin(), attraction.end(), val.begin());
        build(attraction, 0, 0, size);
    }
    void build(vector<ll> &arr, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = {0, 0};
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(arr, 2 * x + 1, lx, m);
        build(arr, 2 * x + 2, m, rx);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    void set_as_active(int i, int x, int lx, int rx){
        if(lx + 1 == rx){
            if(lx < val.size()){
                st[x] = {val[lx], 1};
            }
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set_as_active(i, 2 * x + 1, lx, m);
        } else {
            set_as_active(i, 2 * x + 2, m, rx);
        }
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }
    void set_as_active(int i){
        set_as_active(i, 0, 0, size);
    }
    ll query(int x, int lx, int rx, int k){
        if(k <= 0){
            return 0;
        }
        if(lx + 1 == rx or st[x].count <= k){
            return st[x].val;
        }
        int m = (lx + rx) / 2;
        if(st[2 * x + 1].count >= k){
            return query(2 * x + 1, lx, m, k);
        } 
        return query(2 * x + 1, lx, m, st[2 * x + 1].count) + query(2 * x + 2, m, rx, k - st[2 * x + 1].count);
    }
    ll query(int k){
        return query(0, 0, size, k);
    }
    void print(bool k){
        for(int i = 0; i < 2 * size; i++){
            if(k){
                cout << st[i].val << ' ';
                continue;
            }
            cout << st[i].count << ' ';
        }
        cout << '\n';
    }
};

long long int findMaxAttraction(int n, int start, int d, int attraction[]) {
    vector<pair<ll, int>> vec(n);
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        vec[i] = {attraction[i], i};
    }
    sort(vec.rbegin(), vec.rend());
    map<int, int> in;
    for(int i = 0; i < n; i++){
        arr[i] = vec[i].first;
        in[vec[i].second] = i;
    }
    segment_tree st(n, arr);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        st.set_as_active(in[i]);
        ans = max(ans, st.query(d - i));
    }
    return ans;
}

void solve(){
    int N, start, d;
    cin >> N >> start >> d;
    int attraction[N];
    for(int i = 0; i < N; i++){
        cin >> attraction[i];
    }
    cout << findMaxAttraction(N, start, d, attraction);    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}