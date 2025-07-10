#include <bits/stdc++.h>
#include "magic.h"
using namespace std;
vector<int> Alicia(vector<int> P) {
	for(int i = 0; i < (int)P.size(); i++){
		if(P[i] == 1){
			P[i] = -1;
		}
	}
	return P;
}

vector<int> Beatriz(vector<int> Q) {
	vector<int> ans = Q;
	for(int &i : ans){
		if(i == -1) i = 1;
	}
	return ans;
}
