#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 1050
using namespace std;

char g[M];
int d[M],val[M],h[M],sl[M];

bool isSafeToStay(int v, int pos)
{     
     v=v%24;     
     if(v>7 && v<18)return true;
     if(g[pos]=='*')return false;
     return true;
}

bool stopHere(int v)
{
     v=v%24;    
     if(v<7 || v>17)return true;
     return false;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,cc=0;
    scanf("%d",&t);
    getchar();
    for(int z=1;z<=t;z++)
    {              
         gets(g);
         //printf("[%s]\n",g);
         int len=strlen(g);
         memset(d,0,sizeof(d));
         memset(val,0,sizeof(val));         
         memset(sl,0,sizeof(sl)); 
         memset(h,0,sizeof(h));
                
         queue<int> q;
         q.push(0);
         
         val[0]=0;
         h[0]=6;
         sl[0]=0;
         d[0]=1;
         
         while(!q.empty())
         {
              int u=q.front();
              q.pop();
              //printf("\nHOur %d place %d val: %d\n",hour[u],u,val[u]);
              cc=0;
              //move 16 or less & sleep
              for(int i=1;i<17;i++)
              {
                  int v=u+i;
                  if(v>=len)break;
                  if(stopHere(h[u]+i) && g[v]=='*')
                  {//printf("BREAK AT %d\n",v);
                  break;}
                  if(!d[v] && g[v]!='*' && isSafeToStay(h[u]+i,v))
                  {
                     ++cc;       
                     //printf("IN %d\n",v);
                     d[v]=1;
                     val[v]=val[u]+i+8;
                     if(val[len-1])goto end;
                     h[v]=(h[u]+i+8)%24;
                     q.push(v);
                  }
              }
              //sleep
              if(!cc && sl[u]<3){
              sl[u]++;h[u]=(h[u]+8)%24;val[u]+=8;q.push(u);
              //printf("NOT %d place %d val: %d",hour[u],u,val[u]);
              }
              //if(sleep[u]==3)break;              
         }                    
         end:
         printf("Case #%d: ",z);
         if(val[len-1])printf("%d\n",val[len-1]-8);
         else printf("-1\n");
    }
    return 0;
}
