#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#define endl "\n"
#define sp " "
#define MOD 1000000007
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)
#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;
#define INF LLONG_MAX
using namespace std;
typedef long long ll;
void solve(){
    int n;
    cin >> n;
    vector<int> ex {4, 8, 15, 16, 23, 42};
    map<int, set<int>> ma;
    f2(i, n, 0){
        int aux;
        cin >> aux;
        ma[aux].insert(i + 1);
    }
    unordered_set<int> pos;
    int ans = 0;
    while(1){
        set<int>::iterator ps;
        f1(i, ex){
            if(i == 4) ps = ma[i].begin();
            else {
                if(!ma[i].size()) continue;
                while(*ma[i].begin() < *ps and ma[i].size()) {
                    ma[i].erase(ma[i].begin());
                    ans++;
                }
                if(ma[i].size()) ps = ma[i].begin();
            }
            if(ps != ma[i].end()) pos.insert(*ps);
        }
        if(pos.size() == 6){
            f1(i, ex){
                if(ma[i].size())
                    ma[i].erase(ma[i].begin());
            }
        } else {
            f1(i, ma)
                ans += i.second.size();
            break;
        }
        pos.clear();
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
