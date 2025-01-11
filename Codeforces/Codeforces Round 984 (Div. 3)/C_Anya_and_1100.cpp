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
    string x;
    cin >> x;
    int q;
    cin >> q;
    set<int> idx;
    bool t = 1;
    if(x.size() < 4){
        t = 0;
    } else {
        for(int i = 0; i < x.size() - 3; i++){
            if(x.substr(i, 4) == "1100"){
                idx.insert(i);
            }
        }
    }
    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        x[a] = (b ? '1' : '0');
        if(!t){
            cout << "NO" << endl;
            continue;
        }
        vector<int> del;
        for(auto i = idx.lower_bound(a - 5); i != idx.upper_bound(a); ++i){
            if(x.substr(*i, 4) != "1100"){
                del.push_back(*i);
            }
        }
        for(int i = max(a - 3, 0); i <= min(a, (int)x.size() - 4); i++){
            if(x.substr(i, 4) == "1100"){
                idx.insert(i);
            }
        }
        //f1(i, idx){
        //    cout << i << sp;
        //}
        //cout << endl;
        f1(i, del){
            idx.erase(i);
        }
        if(idx.size()){
            cout << "YES" << endl;\
            continue;
        }
        cout << "NO" << endl;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
