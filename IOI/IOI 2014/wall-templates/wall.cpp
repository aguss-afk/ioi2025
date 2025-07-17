#include "wall.h"
#include <bits/stdc++.h>
#define dbg(x) cerr << #x << ": " << x << "\n";
using namespace std;
struct node{
	int maxval, minval;
};
node DEFAULT = {0, INT_MAX};
struct segment_tree {
	vector<node> st;
	int sz;
	segment_tree(int n) {
		sz = 1;
		while(sz < n){
			sz *= 2;
		}
		st.assign(sz * 2, DEFAULT);
	}
	void mini(int l, int r, int val){
		mini(l, r, 0, 0, sz, val);
	}
	void maxi(int l, int r, int val){
		maxi(l, r, 0, 0, sz, val);
	}
	void idk(int x){
		if(x >= sz - 1) return;
		st[2 * x + 1].minval = min(st[2 * x + 1].minval, st[x].minval);
		st[2 * x + 1].minval = max(st[2 * x + 1].minval, st[x].maxval);
		st[2 * x + 1].maxval = min(st[2 * x + 1].maxval, st[x].minval);
		st[2 * x + 1].maxval = max(st[2 * x + 1].maxval, st[x].maxval);

		st[2 * x + 2].minval = min(st[2 * x + 2].minval, st[x].minval);
		st[2 * x + 2].minval = max(st[2 * x + 2].minval, st[x].maxval);
		st[2 * x + 2].maxval = min(st[2 * x + 2].maxval, st[x].minval);
		st[2 * x + 2].maxval = max(st[2 * x + 2].maxval, st[x].maxval);
	}
	void mini(int l, int r, int x, int lx, int rx, int val){
		if(lx >= r or rx <= l) return;
		if(lx >= l and rx <= r){
			st[x].minval = min(st[x].minval, val);
			st[x].maxval = min(st[x].maxval, val);
			return;
		} 
		idk(x);
		st[x] = DEFAULT;
		int m = (lx + rx) / 2;
		mini(l, r, 2 * x + 1, lx, m, val);
		mini(l, r, 2 * x + 2, m, rx, val);
	}
	void maxi(int l, int r, int x, int lx, int rx, int val){
		if(lx >= r or rx <= l) return;
		if(lx >= l and rx <= r){
			st[x].minval = max(st[x].minval, val);
			st[x].maxval = max(st[x].maxval, val);
			return;
		} 
		idk(x);
		st[x] = DEFAULT;
		int m = (lx + rx) / 2;
		maxi(l, r, 2 * x + 1, lx, m, val);
		maxi(l, r, 2 * x + 2, m, rx, val);
	}
	int get_value(int i, int x, int lx, int rx, node &curr){
		curr.maxval = max(curr.maxval, st[x].maxval);
		curr.minval = min(curr.minval, st[x].minval);
		if(lx + 1 == rx){
			return curr.maxval;
		}
		int m = (lx + rx) / 2;
		if(i < m){
			return get_value(i, 2 * x + 1, lx, m, curr);
		}
		return get_value(i, 2 * x + 2, m, rx, curr);
	}
	int get_value(int i){
		node curr = DEFAULT;
		return get_value(i, 0, 0, sz, curr);
	}
	void print(){
		for(node x : st) cout << x.maxval << ' ' << x.minval << '\n';
	}
};
void buildWall(int n, int k, int op[], int l[], int r[], int h[], int fh[]){
	segment_tree st(n);
	for(int i = 0; i < k; i++){
		if(op[i] == 2){
			st.mini(l[i], r[i] + 1, h[i]);
		} else {
			st.maxi(l[i], r[i] + 1, h[i]);
		}
	}
	for(int i = 0; i < n; i++){
		fh[i] = st.get_value(i);
	}
  	return;
}

