#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n, m, totsum;
    cin >> n >> m;
    ll arr[n][m], versum[m] = {0}, horsum[n] = {0};
    string moves;
    cin >> moves;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            horsum[i] += arr[i][j];
            versum[j] += arr[i][j];
        }
    }
    if(n == m){
        totsum = 69;
    } else {
        totsum = 0;
    }

    int x = 0, y = 0;
    if(moves[0] == 'D'){
        arr[x][y] = totsum - horsum[x];
        versum[x] += arr[x][y];
        x++;
    } else {
        arr[x][y] = totsum - versum[y];
        horsum[x] += arr[x][y];
        y++;
    }
    for(int i = 0; i < moves.size() - 1; i++){
        if(moves[i + 1] == 'D'){
            arr[x][y] = totsum - horsum[x];
            versum[y] += arr[x][y];
            x++;
        } else {
            arr[x][y] = totsum - versum[y];
            horsum[x] += arr[x][y];
            y++;
        }
    }
    if(moves[moves.size() - 1] == 'D'){
        arr[x][y] = totsum - horsum[x];
        versum[y] += arr[x][y];
        x++;
    } else {
        arr[x][y] = totsum - versum[y];
        horsum[x] += arr[x][y];
        y++;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
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
