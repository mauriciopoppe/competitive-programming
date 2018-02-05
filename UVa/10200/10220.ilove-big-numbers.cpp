#include <stdio.h>

int val[1001], p[10000], psize = 0;

int main(){
  int i, j, n;

  p[0] = 1;
  val[0] = 1;
  for(i = 1; i <= 1000; i++)
  {
    for(j = 0; j <= psize; j++)
      p[j] *= i;
      
    for(j = 0; j <= psize; j++)
    {
      p[j+1] += p[j]/10;
      p[j] %= 10;
      val[i] += p[j];
    }
    while(p[psize+1]){
      psize++;
      p[psize+1] += p[psize]/10;
      p[psize] %= 10;
      val[i] += p[psize];
    }
  }

  while(scanf("%d", &n)==1){
    printf("%d\n", val[n]);
  }
  return 0;
}
