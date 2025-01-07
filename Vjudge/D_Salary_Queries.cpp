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
ll N;
vector<int> bit;
vector<ll> val;
ll add(int a){
    ll res = 0;
    while(a > 0){
        res += bit[a];
        a -= a & (-a);
    }
    return res;
}
void update(int a, ll b){
    while(a <= N){
        bit[a] += b;
        a += a & (-a);
    }
}
int getind(ll a){
    int index = upper_bound(all(val), a) - val.begin();
    return index;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    f1(i, arr){
        cin >> i;
        val.push_back(i);
    }
    vector<pair<char, pair<int, int>>> queries(m);
    f1(i, queries){
        cin >> i.first >> i.second.first >> i.second.second;
        if(i.first == '!'){
            val.push_back(i.second.second);
        }
    }
    sort(all(val));
    val.erase(unique(all(val)), val.end());
    N = val.size();
    bit.assign(N + 1, 0);
    f1(i, arr){
        update(getind(i), 1);
    }
    f1(i, queries){
        if(i.first == '!'){
            update(getind(arr[i.second.first - 1]), -1);
            update(getind(i.second.second), 1);
            arr[i.second.first - 1] = i.second.second;
            continue;
        } else {
            int a = getind(i.second.second), b = getind(i.second.first - 1);
            cout << add(a) - add(b) << endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
