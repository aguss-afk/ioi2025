#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
vector<double> x, v;
int n;
bool f(double mid){
    double lml = x[0] - mid * v[0];
    double rml = x[0] + mid * v[0];
    for(int i = 1; i < n; i++){
        lml = max(x[i] - mid * v[i], lml);
        rml = min(x[i] + mid * v[i], rml);
    }
    return lml <= rml; 
}

void solve(){
    cin >> n;
    x.assign(n, 0.);
    v.assign(n, 0.);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> v[i];
    }
    double l = 0., r = 1e9;
    while(r - l > 1e-6){
        double mid = l + (r - l) / 2.;
        if(f(mid)){
            r = mid;
            continue;
        }
        l = mid;
    }
    cout << fixed << setprecision(6) << r;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
