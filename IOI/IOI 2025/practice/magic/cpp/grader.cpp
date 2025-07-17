#include "magic.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
 
int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> P(N, 0);
  for (int i = 0; i < N; i++) {
    assert(1 == scanf("%d", &P[i]));
  }

  fclose(stdin);

  std::vector<int> Q = Alicia(P);

  int S = (int)Q.size();
  printf("%d\n", S);
  for (int i = 0; i < S; i++) {
    printf("%d%c", Q[i], " \n"[i == S - 1]);
  }

  std::vector<int> B = Beatriz(Q);

  int T = (int)B.size();
  printf("%d\n", T);
  for (int i = 0; i < T; i++) {
    printf("%d%c", B[i], " \n"[i == T - 1]);
  }

  fclose(stdout);

  return 0;
}
