#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 5;

void solve(){
    int n;
    cin >> n;
    vector<int> dis(n, MOD);
    deque<int> q;

    dis[1] = 1;
    q.push_front(1);

    while(!q.empty()){
        int a = q.front();
        q.pop_front();
        int n1 = (a * 10) % n;
        if(dis[a] < dis[n1]){
            dis[n1] = dis[a];
            q.push_front(n1);
        }
        int n2 = (a + 1) % n;
        if(dis[a] + 1 < dis[n2]){
            dis[n2] = dis[a] + 1;
            q.push_back(n2);
        }
    }
    cout << dis[0]; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}