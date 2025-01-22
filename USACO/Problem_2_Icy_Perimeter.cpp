#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<vector<char>> arr;
vector<vector<bool>> vis;
int n;
struct blob_of_ice {
    int area, perimeter;
};
blob_of_ice merge(blob_of_ice a, blob_of_ice b){
    return {a.area + b.area, a.perimeter + b.perimeter};
}
blob_of_ice floodfill(int i, int j){
    if(i < 0 or j < 0 or i == n or j == n){
        return {0, 1};
    }
    if(vis[i][j]){
        return {0, 0};
    }
    if(arr[i][j] == '.'){
        return {0, 1};
    }
    vis[i][j] = 1;
    blob_of_ice ans = {1, 0};
    ans = merge(ans, floodfill(i + 1, j));
    ans = merge(ans, floodfill(i - 1, j));
    ans = merge(ans, floodfill(i, j + 1));
    ans = merge(ans, floodfill(i, j - 1));
    return ans;
}

bool sort_blob(blob_of_ice a, blob_of_ice b){
    if(a.area == b.area){
        return a.perimeter < b.perimeter;
    }
    return a.area > b.area;
}
void solve(){
    cin >> n;
    arr.assign(n, vector<char>(n, ' '));
    vis.assign(n, vector<bool>(n, 0));
    for(vector<char> &i : arr){
        for(char &j : i){
            cin >> j;
        }
    }
    vector<blob_of_ice> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j] and arr[i][j] == '#'){
                blob_of_ice aux = floodfill(i, j);
                ans.push_back(aux);
            }
        }    
    }
    sort(all(ans), sort_blob);
    cout << ans[0].area << ' ' << ans[0].perimeter;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    solve();
}
