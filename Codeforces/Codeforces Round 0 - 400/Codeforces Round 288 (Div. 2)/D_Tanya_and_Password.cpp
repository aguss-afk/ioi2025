#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define dbg(x) cerr << #x << ": " << x << '\n';
#define dbgv(v) cerr << #v << ": "; for(auto &el : v) cerr << el << " "; cerr << '\n';

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
map<string, vector<string>> graph;
vector<string> ans;
void euler(string start){
    while(!graph[start].empty()){
        string x = graph[start].back();
        graph[start].pop_back();
        euler(x);
    }
    ans.push_back(start);
}

void solve(){
    int n;
    cin >> n;
    map<string, int> out, in;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        graph[x.substr(0, 2)].push_back(x.substr(1, 2));
        out[x.substr(0, 2)]++;
        in[x.substr(1, 2)]++;
    }
    int st = 0, en = 0;
    string start = "";
    bool t = 0;
    for(auto &x : graph){
        if(out[x.first] - in[x.first] == 1){
            start = x.first;
            st++;
            continue;
        }
        if(in[x.first] - out[x.first] == 1){
            en++;
            continue;
        }
        if(in[x.first] != out[x.first]){
            t = 1;
            break;
        }
    }
    if(t or (st > 1 or en > 1)){
        cout << "NO";
        return;
    }
    if(start == ""){
        start = graph.begin() -> first;
    }
    euler(start);
    if(ans.size() != n + 1){
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for(int i = ans.size() - 1; i > 0; i--){
        cout << ans[i][0];
    }
    cout << ans[0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
