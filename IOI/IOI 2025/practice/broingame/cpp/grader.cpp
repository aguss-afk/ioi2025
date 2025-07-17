#include "boringgame.h"
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <vector>

namespace {
const int CALLS_CNT_LIMIT = 150;
const long long MAXGUESS = 1'000'000'000'000'000'000LL;

int calls_cnt;
int T, t;
std::vector<long long> S, G;
std::vector<int> K, C;

void quit(const char* message) {
  printf("%s\n", message);
  exit(0);
}
} // namespace

bool ask(long long x) {
  calls_cnt++;
  if (calls_cnt > CALLS_CNT_LIMIT)
    quit("Too many calls");
  if (x < 1ll || x > MAXGUESS)
    quit("Invalid argument");

  return (x <= S[t]) ^ (K[t] < calls_cnt);
}

int main() {
  assert(1 == scanf("%d", &T));
  S.resize(T), K.resize(T);
  for (int i = 0; i < T; i++)
    assert(2 == scanf("%lld %d", &S[i], &K[i]));
  fclose(stdin);

  G.assign(T, 0), C.assign(T, 0);
  for (t = 0; t < T; ++t) {
    calls_cnt = 0;
    G[t] = play_game();
    C[t] = calls_cnt;
  }

  for (t = 0; t < T; ++t)
    printf("%lld %d\n", G[t], C[t]);

  fclose(stdout);

  return 0;
}
