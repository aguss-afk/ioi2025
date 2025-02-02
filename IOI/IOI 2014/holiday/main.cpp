#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
int n;
vector<ll> arr;
vector<vector<ll>> dp;
ll ans = 0;

int iz(int d, int curr){
    if(d <= 0
}

ll findans(int N, int start, int d, int attractions[]){
    n = N;
    arr.assign(n, 0);
    copy(attractions, attractions + n, arr.begin());

    return ans;
}

void solve(){
    int N, start, d;
    cin >> N >> start >> d;
    int attractions[N];
    for(int i = 0; i < N; i++){
        cin >> attractions[i];
    }
    cout << findans(N, start, d, attractions);

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}