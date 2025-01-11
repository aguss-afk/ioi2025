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
using i64 = long long;
int n, m, ul, dl, ll, rl;
pair<int, int> next_pos(pair<int, int> aux){
    if(aux.first == ul){
        if(aux.second + 1 >= rl){
            aux.first++;
        } else {
            aux.second++;
        }
    } else if(aux.second == rl - 1){
        if(aux.first + 1 >= dl){
            aux.second--;
        } else {
            aux.first++;
        }
    } else if(aux.first == dl - 1){
        if(aux.second - 1 < ll){
            aux.first--;
        } else {
            aux.second--;
        }
    } else if(aux.second == ll){
        if(aux.first - 1 < ul){
            aux.second++;
        } else {
            aux.first--;
        }
    }
    return aux;
}
void solve(){
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    f1(i, arr){
        f1(j, i){
            cin >> j;
        }
    }
    ul = 0, dl = n, ll =  0, rl = m;
    int ans = 0;
    while(ul != dl and ll != rl){
        pair<int, int> p1, p2, p3, p4, act;
        act = {ul, ll};
        for(int i = 0; i < 2 * (dl - ul + rl - ll - 2); i++){
            p1 = act;
            p2 = next_pos(p1);
            p3 = next_pos(p2);
            p4 = next_pos(p3);
            //dbg(p1.first);
            //dbg(p1.second);
            //dbg(p2.first);
            //dbg(p2.second);
            //dbg(p3.first);
            //dbg(p3.second);
            //dbg(p4.first);
            //dbg(p4.second);
            if(
                arr[p1.first][p1.second] == '1' and
                arr[p2.first][p2.second] == '5' and
                arr[p3.first][p3.second] == '4' and
                arr[p4.first][p4.second] == '3'
            ){
                ans++;
            }
            act = next_pos(act);
        }
        ul++;
        dl--;
        ll++;
        rl--;
    }
    cout << ans << endl;
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
