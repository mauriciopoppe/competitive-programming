#include<stdio.h>
#include<stdlib.h>
char line[10000001]={0};
void Goldbach (int n)
{
  int a;
   for(a=3;a<=n/2;a=a+2)
      if(line[a]==0&&line[n-a]==0)
        {printf(" %d %d",a,n-a);break;}
}
main()
{
 int a,b,top=0;
 for(a=3;a<3162;a=a+2)
   if(line[a]==0)
      for(b=3;a*b<=10000000;b=b+2)
       line[a*b]=1;
 int n;
 while(scanf("%d",&n)==1)
  {
     if((n%2==0&&n-4<4)||(n%2==1&&n-5<4))
       {printf("Impossible.\n");continue;}
     if(n%2==0) {printf("2 2");n=n-4;}
     else {printf("2 3");n=n-5;}
     
     if(n==4) printf(" 2 2");
     else if (n==5) printf(" 2 3");
     else 
       Goldbach (n);
     printf("\n");
  }
 return 0;
}
