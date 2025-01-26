#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
vector<ll> comp, sizec, minc, arr;
ll n;
ll find(ll a){
    return comp[a] = (a == comp[a] ? a : find(comp[a]));
}
void unioncomp(ll A, ll B){
    ll a = find(A);
    ll b = find(B);
    if(sizec[a] < sizec[b]) swap(a, b);
    comp[b] = a;
    minc[a] = min(minc[b], minc[a]);
    sizec[a] += sizec[b];
}
void createcomp(ll a){
    comp[a] = a;
    sizec[a] = 1;
    minc[a] = arr[a];
    if(a > 0 and comp[a - 1] != -1) unioncomp(a, comp[a - 1]);
    if(a < n - 1 and comp[a + 1] != -1) unioncomp(a, comp[a + 1]);
}
void solve(){
    cin >> n; 
    arr.assign(n, 0);
    comp.assign(n, -1);
    sizec.assign(n, 0);
    minc.assign(n, 0);
    f1(i, arr) cin >> i;
    vector<pair<ll, ll>> cop;
    f2(i, n, 0)
        cop.push_back({arr[i], i});
    sort(cop.begin(), cop.end());
    ll curr = cop.back().second;
    ll q = 1;
    createcomp(curr);
    ll io = n;
    vector<ll> ans;
    while(io--){
        while(q <= sizec[find(curr)]){
            ans.push_back(minc[find(curr)]);
            q++;
        }
        cop.pop_back();
        if(cop.size()){
            createcomp(cop.back().second);
            curr = cop.back().second;
        }
    }
    f1(i, ans) cout << i << sp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
