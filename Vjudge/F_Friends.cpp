#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
vector<int> arr, siz;
int maxsize;
int find(int a){
    return arr[a] = (arr[a] == a ? a : find(arr[a]));
}
void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return;
    }
    if(siz[a] > siz[b]){
        swap(a, b);
    }
    arr[a] = b;
    siz[b] += siz[a];
    maxsize = max(maxsize, siz[b]);
}
void solve(){
    int n, m;
    cin >> n >> m;
    arr.resize(n);
    iota(all(arr), 0);
    siz.assign(n, 1);
    maxsize = 1;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        unite(a, b);
    }
    cout << maxsize << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
