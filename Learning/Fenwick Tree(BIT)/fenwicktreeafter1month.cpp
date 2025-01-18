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
int n;
vector<int> arr;
int add(int a){
    int res = 0;
    int i = a;
    while(i >= 0){
        res += arr[i];
        i -= i & (-i);
    }
    return res;
}
int add(int a, int b){
    return add(b) - add(a - 1);
}
void update(int a, int b){
    while(a < n){
        arr[a] += b;
        a += a & -a; 
    }
}
void solve(){
    for(int i = 0; i < )    
}