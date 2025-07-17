#include "magic.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> Alicia(vector<int> P) {
	int m1 = 0, m2 = 0;
	int n = P.size();
	for(int i = 0; i < n - 1; i++){
		if(P[i] < P[i + 1]) m1++;
		if(P[i] > P[i + 1]) m2++;
	}
	
}

vector<int> Beatriz(vector<int> Q) {
  	int N = (int)Q.size();
  	return vector<int>(N, 0);
}
