#include "dna.h"
#include <bits/stdc++.h>

#define _USE_MATH_DEFINES
#define INF LLONG_MAX
#define MOD 1000000007

#define endl "\n"
#define sp " "

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define f1(i, x) for(auto &i : x)
#define f2(i, x, j) for(ll i = j; i < x; i++)

#define raya() cout << endl << "====================================" << endl
#define dbg(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
vector<int> a1, t1, c1;
vector<int> a2, t2, c2;
vector<int> diff;
string A, B;
void init(string a, string b) {
	A = a;
	B = b;
	int n = a.size();
	a1.assign(n + 1, 0);
	t1.assign(n + 1, 0);
	c1.assign(n + 1, 0);
	a2.assign(n + 1, 0);
	t2.assign(n + 1, 0);
	c2.assign(n + 1, 0);
	diff.assign(n + 1, 0);
	for(int i = 0; i < n; i++){
		if(a[i] == 'A') a1[i + 1]++;
		if(a[i] == 'T') t1[i + 1]++;
		if(a[i] == 'C') c1[i + 1]++;
		if(b[i] == 'A') a2[i + 1]++;
		if(b[i] == 'T') t2[i + 1]++;
		if(b[i] == 'C') c2[i + 1]++;
		if(a[i] != b[i]) diff[i + 1]++;
		a1[i + 1] += a1[i];
		t1[i + 1] += t1[i];
		c1[i + 1] += c1[i];
		a2[i + 1] += a2[i];
		t2[i + 1] += t2[i];
		c2[i + 1] += c2[i];
		diff[i + 1] += diff[i];
	}
}

int get_distance(int x, int y){
	bool t = 1;
	x++;
	y++;
	if(a1[y] - a1[x - 1] != a2[y] - a2[x - 1]){
		t = 0;
	}
	if(t1[y] - t1[x - 1] != t2[y] - t2[x - 1]){
		t = 0;
	}
	if(c1[y] - c1[x - 1] != c2[y] - c2[x - 1]){
		t = 0;
	}
	if(!t){
		return -1;
	}
	int z = diff[y] - diff[x - 1];
	return (z + 1) / 2;
}
