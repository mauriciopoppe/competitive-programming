#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;
 
void print(int cham[6][2],int c)
{
     printf("\n");
     for(int i=0;i<c;i++)
     printf("%d %d\n",cham[i][0],cham[i][1]);
     printf("\n");     
}

int main()
{
    int c,n,i,j,k;
    int a[21];
    int cham[6][2],cas=0;
    
    while(scanf("%d%d",&c,&n)!=EOF)
    {
          memset(cham,0,sizeof(cham));
          memset(a,0,sizeof(a)); 
          
          double prom=0;                                          
          for(i=0;i<n;++i)
              scanf("%d",&a[i]),prom+=a[i]; 
          prom/=c;
         
          sort(a,a+c*2);
          k=0;
          i=0;
          j=c*2-1;
          while(i<j)
          {
              cham[k][0]=a[i++];
              cham[k++][1]=a[j--];                
          }          
          
          double im=0;
          printf("Set #%d\n",++cas);
          for(int i=0;i<c;i++)
          {    
              im+=fabs(cham[i][0]+cham[i][1]-prom); 
              printf(" %d:",i);
              if(cham[i][0])printf(" %d",cham[i][0]);
              if(cham[i][1])printf(" %d",cham[i][1]);
              printf("\n");
          }
          printf("IMBALANCE = %.5lf\n\n",im);
    }
    return 0;
}
