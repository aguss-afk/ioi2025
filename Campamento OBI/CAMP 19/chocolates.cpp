#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << ": " << x << '\n';
int main(){
    ll n, m, xd = 0;
    cin >> n >> m;
    vector<pair<ll, ll>> idk(m);
    for(int i = 0; i < m; i++) cin >> idk[i].first;
    for(int i = 0; i < m; i++){
        cin >> idk[i].second;
        xd += idk[i].second;
    }
    if(xd < n){
        cout << -1;
        return 0;
    }
    sort(idk.begin(), idk.end());
    ll s = 0, e = 0, sum = idk[0].second, dis = LLONG_MAX;
    while(e < m and s < m){
        if(sum >= n){
            if(idk[e].first > 0 and idk[s].first < 0){
                dis = min(dis, 2 * min(abs(idk[e].first), abs(idk[s].first)) + max(abs(idk[e].first), abs(idk[s].first)));
            } else {
                dis = min(dis, abs(min(idk[s].first, 0ll) - max(idk[e].first, 0ll)));
            }
        } 
        if(e != m - 1 and sum < n){
            e++;
            sum += idk[e].second;
        } else {
            sum -= idk[s++].second;
        }
    }
    cout << dis;
}