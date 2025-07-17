#include "nile.h"
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> calculate_costs(vector<int> w, vector<int> a, vector<int> b, vector<int> e) {
	int n = w.size();
	ll sumb = accumulate(b.begin(), b.end(), 0ll);
	vector<ll> ret;
	for(const int &i : e){
		if(i == 1 and n % 2){
			ll minans = LLONG_MAX;
			for(int i = 0; i < n; i += 2){
				minans = min(minans, sumb - b[i] + a[i]);
			}
			ret.push_back(minans);
			continue;
		}
		if(n % 2){
			ll minans = LLONG_MAX;
			for(int i = 0; i < n; i++){
				minans = min(minans, sumb - b[i] + a[i]);
			}
			ret.push_back(minans);
			continue;
		}
		ret.push_back(sumb);
	}
	return ret;
}
