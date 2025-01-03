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
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> count(2 * n + 1, 0);
    map<int, int> ma;
    f1(i, arr){
        cin >> i.first >> i.second;
        if(i.first == i.second){
            ma[i.first]++;
            count[i.first] = 1;
        }
    }
    for(int i = 1; i < count.size(); i++){
        count[i] += count[i - 1];
    }
    f1(i, arr){
        if(i.first != i.second){
            if(i.second - i.first + 1 == count[i.second] - count[i.first - 1]){
                cout << 0;
                continue;
            }
            cout << 1;
            continue;
        }
        if(ma[i.first] > 1){
            cout << 0;
            continue;
        }
        cout << 1;
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}