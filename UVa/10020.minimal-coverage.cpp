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

struct seg{
       int a,b;
       bool operator<(const seg &x)
       const
       {
            if(a!=x.a)return a<x.a;
            return b>x.b;     
       }
       
       } m[100002],ans[100002],org[100002];



int main()
{
    int t,a,b,i,k;
    scanf("%d",&t);
    ++t;
    while(--t)
    {
         i=0;     
         scanf("%d",&k);
         while(scanf("%d%d",&a,&b))
         {
             if(a==0 && b==0)break;                  
             m[i].a=a;
             m[i++].b=b;                      
         }                   
         sort(m,m+i);
         
         int M=i;
         int low=0,up,sel=-1,j=0,f=0;
         while(1)
         {
             up=0;
             f=0;
             for(i=sel+1;i<M && m[i].a<=low;i++)
                 if(m[i].b>up)up=m[i].b,sel=i,f=1;
             
             if(!f)break;
             ans[j].a=m[sel].a;
             low=up=ans[j++].b=m[sel].b;
             if(low>=k || i==M)break;            
             //printf("%d %d\n",sel,low);
             //system("pause");
         }
         
         if(low>=k)
         {    
             printf("%d\n",j);
             for(int i=0;i<j;i++)
                printf("%d %d\n",ans[i].a,ans[i].b);  
         }
         else printf("0\n");
         if(t-1)printf("\n");
    }
    return 0;
}
