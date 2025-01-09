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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1, 1);
    iota(rall(arr), 1); 
    stack<int> s;
    for(int i = n; i >= 1; i--){
        s.push(arr[i]);
    }
    while(m--){
        int x;
        cin >> x;
        cout << s.top() - arr[x] << sp;
        arr[x] = s.size();
        s.pop();
        s.push(arr[x]);
    }
    cout << endl;
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
