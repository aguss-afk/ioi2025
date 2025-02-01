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
vector<ll> binse;
ll lowbound(ll val){
    ll l = 0, r = binse.size() - 1;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;
        if(binse[mid] >= val){
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
bool srt(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}
void solve(){
    int n;
    cin >> n;
    binse.assign(n, -1);
    vector<pair<pair<int, int>, int>> arr(n);
    vector<ll> ans(n);
    f2(i, n, 0){
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].first.second += arr[i].first.first;
        arr[i].second = i;
    }  
    sort(all(arr), srt);
    binse[0] = arr[0].first.second;
    ans[0] = arr[0].second;
    f2(i, arr.size(), 1){
        ll pos = lowbound(arr[i].first.second);
        if(binse[pos] < arr[i].first.second) pos--;
        binse[pos + 1] = arr[i].first.second;
        ans[arr[i].second] = pos + 1;
    }
    f1(i, ans) cout << i << sp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}