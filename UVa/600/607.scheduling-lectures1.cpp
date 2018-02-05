#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define INF 1000000000
#define M 1024
using namespace std;

int total1[M],total2[M],dif[M],acu[M],t[M],cov[M],m,d;

int main()
{
    freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);

    int i,j,k,*total,*next,cc=0,n,l,c;
    
    dif[0]=0;
    for(i=11,j=1;i<M;++i,++j)
       dif[i]=j*j;
    
    while(scanf("%d",&n) && n)
    {
         if(cc)printf("\n");
         ++cc;                
         scanf("%d%d",&l,&c);
         acu[0]=0;
         for(i=1;i<=n;i++)
           scanf("%d",&t[i]), acu[i]=acu[i-1]+t[i];         
         for(i=1;i<=10;i++)dif[i]=-c;
         
         for(i=1;i<=n;i++)
         {
             for(j=i;j<=n;j++)
                if(acu[j]-acu[i-1]>l)break;
             cov[i]=j-i;             
         }
         
         for(i=1,m=0;i<=n;m++)
             i+=cov[i];
         
         total=total1;
         next=total2;
         
         for(i=0;i<=n;i++)
            total[i]=INF;
         total[n+1]=0;
         
         //printf("here");
         for(k=0;k<m;k++)
         {
              for(i=1;i<=n;i++)
              {
                  next[i]=INF;
                  for(j=1;j<=cov[i];j++)
                  {
                      d=dif[ l-acu[i+j-1]+acu[i-1] ] + total[i+j];
                      if(d<next[i])next[i]=d;                  
                  }             
              }                    
              
              //swap pointers
              total=next;
              if(next==total1)next=total2;
              else next=total1;              
         }
                        
         printf("Case %d:\n",cc);
         printf("Minimum number of lectures: %d\nTotal dissatisfaction index: %d\n",m,total[1]);                
    }
    
    return 0;
}
