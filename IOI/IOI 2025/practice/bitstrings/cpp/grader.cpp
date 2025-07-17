#include "bitstrings.h"
#include <cassert>
#include <cstdio>
#include <string>

namespace {

void run_part1() {
  char tmp[101];
  assert(1 == scanf("%100s", tmp));
  std::string S = tmp;
  fclose(stdin);

  int K = count_duplicated(S);

  printf("%d\n", K);
  fclose(stdout);
}

void run_part2() {
  char tmp[101];
  assert(1 == scanf("%100s", tmp));
  std::string T = tmp;
  fclose(stdin);

  std::string S;
  if (T == "weakest")
    S = find_weakest();
  else if (T == "strongest")
    S = find_strongest();

  printf("%s\n", S.c_str());

  fclose(stdout);
}

} // namespace

int main() {
  int part;
  assert(1 == scanf("%d", &part));
  if (part == 1)
    run_part1();
  else if (part == 2)
    run_part2();

  return 0;
}
