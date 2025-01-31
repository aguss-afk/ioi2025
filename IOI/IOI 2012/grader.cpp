
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define inbuf_len 1 << 16
#define outbuf_len 1 << 16

void Init(int N);
int CountCritical();
void Link(int a, int b);

int main() {
  int tmp;

  /* Set input and output buffering */
  char *inbuf, *outbuf;
  inbuf = (char*) malloc(inbuf_len * sizeof(char));
  outbuf = (char*) malloc(outbuf_len * sizeof(char));
  tmp = setvbuf(stdin, inbuf, _IOFBF, inbuf_len);
  tmp = setvbuf(stdout, outbuf, _IOFBF, outbuf_len);

  int N, L;
  tmp = scanf("%d %d", &N, &L);
  assert(tmp == 2);
  Init(N);

  int i;
  for (i = 0; i < L; i++) {
    int A, B;
    tmp = scanf("%d", &A);
    if (A == -1) {
      int critical;
      critical = CountCritical();
      printf("%d\n", critical);
    } else {
      tmp = scanf("%d", &B);
      assert(tmp == 1);
      Link(A, B);
    }
  }

  return 0;

}
