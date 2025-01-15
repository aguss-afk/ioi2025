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

struct bit {
    vector<ll> tree;
    int n;
    bit(int n) : n(n){
        tree.assign(n + 1, 0);
    }
    void update(int a, int b){
        while(a <= n){
            tree[a] += b;
            a += a & (-a);
        } 
    }
    ll add(int a){
        ll res = 0;
        while(a > 0){
            res += tree[a];
            a -= a & (-a);
        }
        return res;
    }
    ll add(int a, int b){
        return add(b) - add(a - 1);
    }
};

struct dsu {
    int n;
    vector<ll> dis, siz;
    dsu(int n) : n(n) {
        dis.assign(n, 0);
        siz.assign(n, 1);
        iota(all(dis), 0);
    }
    int find(int a){
        if(dis[a] == a){
            return a;
        }
        return dis[a] = find(dis[a]);
    }
    void unite(int a, int b){
        int A = find(a);
        int B = find(b);
        if(A == B) return;
        if(siz[A] > siz[B]){
            swap(A, B);
        }
        siz[B] += siz[A];
        dis[A] = B;
        find(a);
    }
};