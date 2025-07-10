#include "dungeons.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> s, p, w, l;
void init(int N, vector<int> S, vector<int> P, vector<int> W, vector<int> L) {
	n = N;
	s = S;
	p = P;
	w = W;
	l = L;
	return;
}

long long simulate(int x, int z) {
	int actdun = x, actpow = z;
	while(actdun != n){
		if(actpow >= s[actdun]){
			actpow += s[actdun];
			actdun = w[actdun];
			continue;
		} 
		actpow += p[actdun];
		actdun = l[actdun];
	}
	return actpow;
}

