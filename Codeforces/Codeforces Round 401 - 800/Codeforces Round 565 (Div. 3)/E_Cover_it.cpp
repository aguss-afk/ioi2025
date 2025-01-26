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
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n);
    f2(i, m, 0){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    vector<int> dis(n, 0);
    vector<bool> vis(n, 0);
    vis[0] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        f1(i, arr[a]){
            if(vis[i]) continue;
            dis[i] = dis[a] + 1;
            vis[i] = 1;
            q.push(i);
        }
    }
    vector<int> even, odd;
    f2(i, n, 0){
        if(dis[i] & 1) odd.push_back(i + 1);
        else even.push_back(i + 1);
    }
    if(even.size() < odd.size()){
        cout << even.size() << endl;
        f1(i, even) cout << i << sp;
        cout << endl; 
        return;
    }
    cout << odd.size() << endl;
    f1(i, odd) cout << i << sp;
    cout << endl; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
