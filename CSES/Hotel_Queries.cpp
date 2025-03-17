#include <bits/stdc++.h>

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

bool test_cases = 0;
struct segment_tree {
    vector<ll> st;
    int size;
    segment_tree(vector<ll>&arr){
        int n = arr.size();
        size = 1;
        while(size < n){
            size *= 2;
        }
        st.assign(2 * size, 0);
        build(0, 0, size, arr);
    }
    void build(int x, int lx, int rx, vector<ll>& arr){
        if(lx + 1 == rx){
            if(lx < arr.size()){
                st[x] = arr[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, arr);
        build(2 * x + 2, m, rx, arr);
        st[x] = max(st[2 * x + 1], st[2 * x + 2]);
    }
    ll getans(ll v, int x, int lx, int rx){
        if(st[x] < v){
            return 0;
        }
        if(lx + 1 == rx){
            st[x] -= v;
            return lx + 1;
        }
        int m = (lx + rx) / 2, ans = 0;
        if(st[2 * x + 1] >= v){
            ans = getans(v, 2 * x + 1, lx, m);
        } else {
            ans = getans(v, 2 * x + 2, m, rx);
        }
        st[x] = max(st[2 * x + 1], st[2 * x + 2]);
        return ans;
    }
    ll getans(ll v){
        return getans(v, 0, 0, size);
    }
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> hotel(n);
    for(ll &i : hotel){
        cin >> i;
    }
    segment_tree st(hotel);
    while(m--){
        ll a;
        cin >> a;
        ll ans = st.getans(a);
        cout << ans << ' ';
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
