#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> val;
vector<vector<ll>> arr;
ll dfs(int curr, int dep, int prev = -1){
    ll ans = 0;
    for(ll &i : arr[curr]){
        if(i != prev){
            ans += dfs(i, dep + 1, curr);
        }
    }
    return ans + val[curr] * dep;
}
int main(){
    int n;
    cin >> n;
    ll ans = 0;
    arr.assign(n, vector<ll>());
    val.assign(n, 0);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    for(int i = 0; i < n; i++){
        ans = max(dfs(i, 1), ans);
    }   
    cout << ans;
}