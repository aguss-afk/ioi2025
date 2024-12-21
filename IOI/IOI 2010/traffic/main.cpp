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
ll sum = 0;
vector<vector<ll>> sum1, arr;
vector<ll> P;
vector<bool> vis;
ll dfs(int n){
    if(vis[n]) return 0;
    vis[n] = 1; 
    f1(i, arr[n]){
        int aux = dfs(i);
        if(aux){
            sum1[n].push_back(aux);
        }
    }
    int ans = 0;
    f1(i, sum1[n]){
        ans += i;
    }
    sum1[n].push_back(0);
    sum1[n].push_back(sum - ans - P[n]);
    return ans + P[n];
}
int LocateCentre(int n, int p[], int s[], int d[]){
    arr.assign(n, vector<ll>(0));
    sum1.assign(n, vector<ll>(0));
    f2(i, n, 0){
        P.push_back(p[i]);
        sum += P[i];
    }
    vis.assign(n, 0);
    f2(i, n - 1, 0){
        arr[s[i]].push_back(d[i]);
        arr[d[i]].push_back(s[i]);
    }
    int r = s[(n - 1) / 2];
    dfs(r);
    ll sans = -1, ans;
    f2(i, n, 0){
        ll aux = 0;
        f1(j, sum1[i]){
            aux = max(j, aux);
        }
        if(sans == -1){
            sans = aux;
            ans = i;
        }
        if(sans > aux){
            sans = aux;
            ans = i;
        } 
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("grader.in.4", "r", stdin);
    int n;
    cin >> n;
    int p[n], s[n - 1], d[n - 1];
    f2(i, n, 0){
        cin >> p[i];
    }
    f2(i, n - 1, 0){
        cin >> s[i] >> d[i];
    }
    cout << LocateCentre(n, p, s, d);
}