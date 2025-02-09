#include"holiday.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll findMaxAttraction(int n, int start, int d, int attraction[]){
    ll ans = 0;
    for (int l = start; l >= 0; l--){
        priority_queue<int> q;
        ll sum = 0;
        for (int r = l; r < n; r++) {
            q.push(-attraction[r]);
            sum += attraction[r];
            if (r < start){
                continue;
            }
            int k = d - min(start - 2 * l + r, 2 * r - start - l);
            if (k <= 0){
                break;
            }
            while (q.size() > k) {
                sum += q.top();
                q.pop();
            }
            ans = max(ans, sum);
        }
    }
    return ans;
}