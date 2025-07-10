#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "quality.h"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
	int ans = INT_MAX;
	indexed_set nose;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			nose.insert(Q[i][j]);
		}
	}
	ans = min(ans, *nose.find_by_order((H * W) / 2));
	int x = (R - H + 1) * (C - W + 1) - 1;
	int l = 0, u = 0;
	bool derecha = true;
	while(x--){
		if((derecha and l + W == C) or (!derecha and !l)){
			for(int i = 0; i < W; i++){
				nose.erase(Q[u][l + i]);
				nose.insert(Q[u + H][l + i]);
			}
			ans = min(ans, *nose.find_by_order((H * W) / 2));
			u++;
			derecha = !derecha;
			continue;
		}
		if(derecha){
			for(int i = 0; i < H; i++){
				nose.erase(Q[u + i][l]);
				nose.insert(Q[u + i][l + W]);
			}
			l++;
			ans = min(ans, *nose.find_by_order((H * W) / 2));
			continue;
		}
		for(int i = 0; i < H; i++){
			nose.erase(Q[u + i][l + W - 1]);
			nose.insert(Q[u + i][l - 1]);
		}
		l--;
		ans = min(ans, *nose.find_by_order((H * W) / 2));
	}
	return ans;
}
