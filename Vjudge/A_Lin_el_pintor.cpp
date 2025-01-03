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

void solve(){
    ll n, m, h;
    cin >> n >> m >> h;
    set<ll> rows, columns;
    map<ll, ll> ans;
    vector<vector<ll>> qs;
    f2(i, n, 0){
        qs.push_back({1, i + 1, 0});
    }
    f2(i, m, 0){
        qs.push_back({2, i + 1, 0});
    }
    f2(i, h, 0){
        ll a, b, c;
        cin >> a >> b >> c;
        qs.push_back({a, b, c});
    } 
    reverse(all(qs));
    f2(i, qs.size(), 0){
        ll a, b, c;
        a = qs[i][0];
        b = qs[i][1];
        c = qs[i][2];
        if(a == 1){
            if(rows.count(b)){
                continue;
            }
            ans[c] += m - columns.size();
            rows.insert(b);
            continue;
        }
        if(columns.count(b)){
            continue;
        }
        ans[c] += n - rows.size();
        columns.insert(b);
    }
    ll siz = 0;
    f1(i, ans){
        if(i.second){
            siz++;
        }
    }
    cout << siz << endl;
    f1(i, ans){
        if(i.second){
            cout << i.first << sp << i.second << endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
