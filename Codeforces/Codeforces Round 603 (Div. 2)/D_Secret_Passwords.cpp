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
vector<int> arr, siz;
int find(int a){
    if(arr[a] == a){
        return a;
    }
    return arr[a] = find(arr[a]);
}
void unite(int a, int b){
    int A = find(a);
    int B = find(b);
    if(A == B){
        return;
    }
    if(siz[A] > siz[B]){
        swap(A, B);
    }
    arr[A] = B;
    siz[B] += siz[A];
}
void solve(){
    int n;
    cin >> n;
    arr.resize(n);
    iota(all(arr), 0);
    siz.assign(n, 1);
    map<char, vector<int>> ma;
    f2(i, n, 0){
        string x;
        cin >> x;
        f1(j, x){
            ma[j].push_back(i);
        }
    }
    f1(i, ma){
        if(i.second.size() > 1){
            f2(j, i.second.size() - 1, 0){
                unite(i.second[j], i.second[j + 1]);
            }
        }
    }
    set<int> se;
    f1(i, arr){
        i = find(i);
        se.insert(i);
    }
    cout << se.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
