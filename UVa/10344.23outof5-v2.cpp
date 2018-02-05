#include<stdio.h>
long a[6],t[6];
bool can,used[6];
void dfs2(long dep,long now)
{
    if(can) return;
    if(dep>5)
    {
       if(now==23)
         can=true;
       return;
    }
    dfs2(dep+1,now+t[dep]);
    dfs2(dep+1,now-t[dep]);
    dfs2(dep+1,now*t[dep]);
}
void dfs1(long dep)
{
    if(can) return;
    if(dep>5)
    {
       dfs2(2,t[1]);
       return;
    }
    for(long i=1;i<=5;i++)
      if(!used[i])
      {
         used[i]=true;
         t[dep]=a[i];
         dfs1(dep+1);
         used[i]=false;
      }
}
int main()
{
    /*
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    //*/
    while(scanf("%ld%ld%ld%ld%ld",&a[1],&a[2],&a[3],&a[4],&a[5])==5)
    {
       long sum=0;
       for(long i=1;i<=5;i++) sum+=a[i];
       if(sum==0) break;
       
       can=false;
       dfs1(1);
       if(can) printf("Possible\n");
       else printf("Impossible\n");
    }
return 0;
}
