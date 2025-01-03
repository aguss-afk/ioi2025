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
    string a, b;
    cin >> a >> b;
    map<char, int> let;
    for(int i = 0; i < b.size() - 1;i++){
        let[b[i]] = i + 1;
    }
    bool t = 0;
    string ans;
    ll ansl = INF;
    for(int i = 1; i < a.size(); i++){
        if(let.count(a[i])){
            int len = i + 1 + b.size() - let[a[i]];
            if(len < ansl){
                ans = a.substr(0, i + 1);
                ans.append(b.substr(let[a[i]], b.size() - let[a[i]]));
                ansl = len;
            }
        }
    }
    if(ansl == INF){
        cout << -1;
        return;
    }
    cout << ans; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
