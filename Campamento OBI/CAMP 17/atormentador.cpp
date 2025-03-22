#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    queue<pair<long long,int>> q;
    q.push({n, 0});
    map<long long, int> vis;
    while(1){
        pair<long long, int> a = q.front();
        q.pop();
        if(vis.count(a.first)) continue;
        vis[a.first] = 1;
        if(!a.first){
            cout << a.second;
            return 0;
        }
        q.push({a.first * 2ll, a.second + 1});
        q.push({a.first - 1ll, a.second + 1});
        q.push({a.first + 1ll, a.second + 1});
        long long div = -1;
        for(long long i = 3; i <= a.first; i *= 3){
            if(a.first % i == 0) div = i;
        }
        if(div != -1) q.push({a.first / div, a.second + 1});
    }
}