#include "wiring.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define dbg(x) cerr << #x << ": " << x << '\n';
long long min_total_length(std::vector<int> r, std::vector<int> b) {
	set<int> red, blue;
	vector<pair<int, bool>> pos;
	for(int &i : r){
		red.insert(i);
		pos.push_back({i, 0});
	}
	for(int &i : b){
		blue.insert(i);
		pos.push_back({i, 1});
	}
	sort(pos.begin(), pos.end());
	map<int, bool> vis;
	ll ans = 0;
	for(auto &i : pos){
		if(vis.count(i.first)){
			continue;
		}
		dbg(ans);
		dbg(i.first);
		vis[i.first] = 1;
		if(i.second){
			auto it = red.lower_bound(i.first);
			if(it == red.end()){
				it = prev(it);
				ans += abs(i.first - *it);
				vis[*it] = 1;
				continue;
			} 
			if(it == red.begin()){
				ans += abs(i.first - *it);
				vis[*it] = 1;
				continue;
			} 
			int x = abs(i.first - *it);
			int y = abs(i.first - *prev(it));
			if(x < y){
				vis[*it] = 1;
				ans += abs(i.first - *it);
				continue;
			}
			vis[*prev(it)] = 1;
			ans += abs(i.first - *prev(it));
			continue;
		}
		auto it = blue.lower_bound(i.first);
		if(it == blue.end()){
			it = prev(it);
			ans += abs(i.first - *it);
			continue;
		}
		if(it == blue.begin()){
			ans += abs(i.first - *it);
			continue;
		}
		ans += min(abs(i.first - *it), abs(i.first - *prev(it)));
	}
	return ans;
}
