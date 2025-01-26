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
int n, m;
bool check(int i, int j){
    if(i < 0 or j < 0 or i >= n or j >= m){
        return 0;
    }
    if(arr[i][j] != 'B' and arr[i][j] != 'G'){
        return 1;
    }
    return 0;
}
void floodfillB(int i, int j){
    if(check(i + 1, j)){
        arr[i + 1][j] = '#';
    }
    if(check(i - 1, j)){
        arr[i - 1][j] = '#';
    }
    if(check(i, j + 1)){
        arr[i][j + 1] = '#';
    }
    if(check(i, j - 1)){
        arr[i][j - 1] = '#';
    }
}

int floodfillG(int i, int j){
    if(i < 0 or j < 0){
        return 0;
    }
    if(i >= n or j >= m){
        return 0;
    }
    if(vis[i][j] or arr[i][j] == '#' or arr[i][j] == 'B'){
        return 0;
    }
    if(i == n - 1 and j == m - 1){
        return 1;
    }
    vis[i][j] = 1;
    int ans = 0;
    ans += floodfillG(i, j + 1);
    ans += floodfillG(i, j - 1);
    ans += floodfillG(i + 1, j);
    ans += floodfillG(i - 1, j);
    return ans;
}

int floodfillB2(int i, int j){
    if(i < 0 or j < 0){
        return 0;
    }
    if(i >= n or j >= m){
        return 0;
    }
    if(vis[i][j] or arr[i][j] == '#'){
        return 0;
    }
    if(i == n - 1 and j == m - 1){
        return 1;
    }
    vis[i][j] = 1;
    int ans = 0;
    ans += floodfillB2(i, j + 1);
    ans += floodfillB2(i, j - 1);
    ans += floodfillB2(i + 1, j);
    ans += floodfillB2(i - 1, j);
    return ans;
}
void solve(){
    cin >> n >> m;
    arr.assign(n, vector<char>(m, 0));
    vis.assign(n, vector<bool>(m, 0));
    for(vector<char> &i : arr){
        for(char &j : i){
            cin >> j;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] and arr[i][j] == 'B'){
                floodfillB(i, j);
            }
        }
    }
    bool t = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] and arr[i][j] == 'G'){
                if(!floodfillG(i, j)){
                    t = 0;
                    break;
                }
            }
        }
    }
    vis.assign(n, vector<bool>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] and arr[i][j] == 'B'){
                if(floodfillB2(i, j)){
                    t = 0;
                    break;
                }
            }
        }
    }
    if(t){
        cout << "Yes" << '\n';
        return;
    }
    cout << "No" << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
