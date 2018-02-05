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
char cw[105];
struct cat{
       string s;
       int mx,points;
       map<string,bool> m;
};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas,categ,key,mx,size;
    string w,x;
    scanf("%d",&cas);
    while(cas--)
    {
         scanf("%d",&categ);
         vector<cat> v;
         v.resize(categ);
         F(i,categ)
         {
             cin>>v[i].s;
             scanf("%d%d",&key,&v[i].mx);
             v[i].points=0;
             F(j,key)
             {
                  cin>>x;
                  if(!v[i].m[x]) 
                     v[i].m[x]=1;
             }
         }
         /*TR(words,it)
           printf("%s,%s ",it->first.c_str(),it->second.c_str());
           NL;*/
         getchar();
         while(gets(cw) && (size=strlen(cw)))
         {
              char temp[105];
              strcat(cw, " ");
              int k=0;
              for(char *p=cw;*p;p++)
              {
                   if(isalpha(*p))temp[k++]=*p;
                   else
                   {
                       if(k)
                       {
                            x=string(temp,temp+k);
                            F(j,categ) 
                               if(v[j].m[x])
                                  v[j].points++, v[j].m[x]=0;
                            k=0;
                       }
                   }
              }
         }
         bool f=0;
         F(i,categ)
         {
               if(v[i].points>=v[i].mx)
               {
                    if(f)printf(",");
                    f=1;
                    printf("%s",v[i].s.c_str());                      
               }
         }
         if(!f)printf("SQF Problem.");
         NL;
         
    }
    return 0;
}
