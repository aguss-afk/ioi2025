#include <stdio.h>
#include <stdlib.h>
#include "quality.h"

static int R,C,H,W,Q[3001][3001],i,j,ans;
int main(){
   scanf("%d%d%d%d",&R,&C,&H,&W);
   for (i=0;i<R;i++) for (j=0;j<C;j++) scanf("%d",&Q[i][j]);
   ans = rectangle(R,C,H,W,Q);
   printf("%d\n",ans);
   return 0;
}
