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
vector<int> a, t, c, ac, ca, ta, ct, at, tc;
vector<int> diff;
void init(string x, string y) {
	int n = x.size();
	a.assign(n + 1, 0);
	t.assign(n + 1, 0);
	c.assign(n + 1, 0);
	at.assign(n + 1, 0);
	ac.assign(n + 1, 0);
	tc.assign(n + 1, 0);
	ta.assign(n + 1, 0);
	ca.assign(n + 1, 0);
	ct.assign(n + 1, 0);
	diff.assign(n + 1, 0);
	for(int i = 0; i < n; i++){
		if(x[i] == 'A') a[i + 1]++;
		if(x[i] == 'T') t[i + 1]++;
		if(x[i] == 'C') c[i + 1]++;
		if(y[i] == 'A') a[i + 1]--;
		if(y[i] == 'T') t[i + 1]--;
		if(y[i] == 'C') c[i + 1]--;
		if(x[i] == 'A' and y[i] == 'T') at[i + 1]++;
		if(x[i] == 'A' and y[i] == 'C') ac[i + 1]++;
		if(x[i] == 'T' and y[i] == 'C') tc[i + 1]++;
		if(y[i] == 'A' and x[i] == 'T') ta[i + 1]++;
		if(y[i] == 'A' and x[i] == 'C') ca[i + 1]++;
		if(y[i] == 'T' and x[i] == 'C') ct[i + 1]++;
		if(x[i] != y[i]) diff[i + 1]++;
		a[i + 1] += a[i];
		t[i + 1] += t[i];
		c[i + 1] += c[i];
		diff[i + 1] += diff[i];
		at[i + 1] += at[i];
		ac[i + 1] += ac[i];
		tc[i + 1] += tc[i];
		ta[i + 1] += ta[i];
		ca[i + 1] += ca[i];
		ct[i + 1] += ct[i];
	}
}

int get_distance(int x, int y){
	bool z = 1;
	x++;
	y++;
	if(a[y] - a[x - 1]){
		z = 0;
	}
	if(t[y] - t[x - 1]){
		z = 0;
	}
	if(c[y] - c[x - 1]){
		z = 0;
	}
	if(!z){
		return -1;
	}
	int n = diff[y] - diff[x - 1], ans = 0;
	int mat, mac, mtc;
	mat = min(at[y] - at[x - 1], ta[y] - ta[x - 1]);
	mac = min(ac[y] - ac[x - 1], ca[y] - ca[x - 1]);
	mtc = min(tc[y] - tc[x - 1], ct[y] - ct[x - 1]);
	n -= 2 * (mat + mac + mtc);
	ans += mat + mac + mtc; 
	return n / 3 * 2 + ans;
}
