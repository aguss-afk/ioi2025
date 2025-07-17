#include "stations.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> label(int n, int k, vector<int> u, vector<int> v) {
	vector<int> labels(n);
	for (int i = 0; i < n; i++) {
		labels[i] = i;
	}
	return labels;
}

int find_next_station(int s, int t, vector<int> c) {
	return c[0];
}
