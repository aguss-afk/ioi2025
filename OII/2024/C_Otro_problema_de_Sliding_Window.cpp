#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<int> arr;
vector<ll> prefsum;

void solve(){
    int n, m;
    cin >> n >> m;
    arr.assign(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i + 1];
    }
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if((b - a + 1) & 1){
            if(arr[b] > m){
                cout << 0;
                continue;
            }
            b--;
        }
        bool t = 1;
        for(int i = a; i < (b + a + 1) / 2; i++){
            //cout << i << ' ';
            //cout << arr[i] + arr[b - i + a] << ' ';
            if(arr[i] + arr[b - i + a] > m){
                cout << 0;
                t = 0;
                break;
            }
        }
        if(!t){
            continue;
        }
        cout << 1;
    } 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
