#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define M 32001
char pos[101][M],neg[101][M];
int lastP[101][M],lastN[101][M];
int v[101];
char op[101];
int main()
{
    int cas,n,k;
    scanf("%d",&cas);
    memset(pos[0],0,sizeof pos[0]);
    while(cas--)
    {
         scanf("%d",&n);
         for(int i=0;i<=n;i++)
            scanf("%d",&v[i]);
         pos[0][v[0]]='n';
         //printf("%c %d\n",pos[0][0],pos[0][0]);
         /*if(pos[0][v[0]])printf("Yes");
         if(pos[0][0])printf("Yes");*/

         for(int i=1;i<n;i++)
         {
              //printf("Enter\n");
              memset(pos[i],0,sizeof pos[i]);
              memset(neg[i],0,sizeof neg[i]);
              F(j,M)
              {
                   if(pos[i-1][j])
                   {
                         //printf("%d\n",j);         
                         if((k=j+v[i])<M)                     //sum
                         {      
                             pos[i][k]='+';
                             lastP[i][k]=j;         
                         }
                         k=j-v[i];
                         if(k>=0)                             //sub
                             pos[i][k]='-',lastP[i][k]=j;
                         else
                             neg[i][abs(k)]='-', lastN[i][abs(k)]=-j;
                         
                         k=j*v[i];                            //mul
                         if(k<M)pos[i][k]='*', lastP[i][k]=j;
                         
                         if(j%v[i]==0)
                            k=j/v[i], pos[i][k]='/', lastP[i][k]=j;
                   }
                   
                   if(neg[i-1][j])
                   {
                         if((k=j+v[i])<M)                     //sub
                         {      
                             neg[i][k]='-';
                             lastN[i][k]=j;         
                         }
                         k=j-v[i];
                         if(k>=0)                             //sum
                             neg[i][k]='+',lastN[i][k]=j;
                         else
                             pos[i][abs(k)]='+', lastP[i][abs(k)]=-j;
                         
                         k=j*v[i];                            //mul
                         if(k<M)neg[i][k]='*', lastN[i][k]=j;
                         
                         if(j%v[i]==0)
                            k=j/v[i], neg[i][k]='/', lastN[i][k]=j;
                   }
              }
 
              /*F(k,36)printf("%d ",lastP[i][k]);NL;
              F(k,36)printf("%c ",pos[i][k]);NL;
              SP;*/
         }
         if(pos[n-1][v[n]])
         {
               int k=v[n], ind=n-1;
               int s=0;
               bool f=1;
               while(ind>0)
               {
                     //printf("%d %d\n",k,lastP[ind][k]);
                     //SP;
                     if(f)
                     {
                          op[s++]=pos[ind][k];
                          if(lastP[ind][k]>=0)k=lastP[ind][k];
                          else k=-lastP[ind][k], f=0;
                     }
                     else
                     {
                          op[s++]=neg[ind][k];
                          if(lastN[ind][k]>=0)k=lastN[ind][k];
                          else k=-lastN[ind][k], f=1;                         
                     }
                     --ind;
               }
               printf("%d",v[0]);
               for(int i=1;i<n;i++)
                  printf("%c%d",op[s-i],v[i]);
               printf("=%d\n",v[n]);
         }
         else printf("NO EXPRESSION\n");
         pos[0][v[0]]=0;
    }
    return 0;
}
