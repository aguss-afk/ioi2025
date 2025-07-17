#include "wall.h"
#include <bits/stdc++.h>
using namespace std;
template<struct T> struct segment_tree {
	vector<T> st;
	int size;
	segment_tree(in	
};
void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]){
	for(int i = 0; i < k; i++){
		for(int j = left[i]; j <= right[i]; j++){
			if(op[i] == 1){
				if(finalHeight[j] > height[i]) continue;
				finalHeight[j] = height[i];
				continue;
			}
			if(finalHeight[j] < height[i]) continue;
			finalHeight[j] = height[i];
		}
	}	
  	return;
}

