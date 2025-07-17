#include <bits/stdc++.h>
#include "aplusb.h"
using namespace std;
vector<int> a, b;
void initialize(vector<int> A, vector<int> B) {
  a = A;
  b = B;
}

int answer_question(int i, int j) {
  return a[i] + b[j];
}
