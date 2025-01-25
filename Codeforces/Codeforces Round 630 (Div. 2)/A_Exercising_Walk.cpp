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
    int a, b, c, d, x, y, x1, x2, y1, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    if((!(x - x1) and !(x - x2)) and (a or b)){
        cout << "No" << '\n';
        return;
    }
    if((!(y - y1) and !(y - y2)) and (c or d)){
        cout << "No" << '\n';
        return;
    }
    if(x - a + b < x1 or x + b - a > x2){
        cout << "No" << '\n';
        return;
    }
    if(y - c + d < y1 or y + d - c > y2){
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
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
