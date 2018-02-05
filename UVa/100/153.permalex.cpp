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
int f[35];
int d[35];
//17,18..
int let[26],s,run;
string w,x,un;

LL pw(int i, int k)
{
    LL r=1;      
    while(k--)
       r*=(LL)i;
    return r;      
}

LL nPr(char n, int k)
{
    //F(i,26)printf("%d ",let[i]);NL;       
    let[n-'a']--;
    //F(i,26)printf("%d ",let[i]);NL;
    //NL;
    memset(f,0,sizeof(f));
    memset(d,0,sizeof(d));
    LL up=1,down=1;
    for(int i=2;i<=k;i++)
       f[i]=1;
    F(i,26)
      if(let[i]>1)// divide let[i]!
      {
           for(int j=2;j<=let[i];j++)
              d[j]++;
      }
    
    /*F(i,30)printf("%d ",f[i]);NL;
    F(i,30)printf("%d ",d[i]);NL;
    SP;*/
    
    for(int i=2;i<=30;i++)
    {
        if(d[i])
        {    
            for(int j=2;j<=30;j++)
                while(d[i] && f[j] && j%i==0)
                {
                     f[j]--;
                     d[i]--;
                     f[j/i]++;   
                }
        }
    }/*
    F(i,30)printf("%d ",f[i]);NL;
    F(i,30)printf("%d ",d[i]);NL;
    SP;*/
    for(int i=2;i<=30;i++)
    { 
        if(f[i])up=up*pw(i,f[i]);
        if(d[i])down=down*pw(i,d[i]);
    }
    let[n-'a']++;
    //printf("%lld %lld = %lld\n",up,down,up/down);
    //SP;
    return (LL)up/down;
}

int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);

    while(cin>>w && w!="#")
    {
         memset(let,0,sizeof let);        
         int ss=w.size();
         F(i,ss)let[w[i]-'a']++;
         //get unique

         run=w.size();
         
         LL r=0;
         for(int i=0;i<run;i++)
         {    
              un="";
              F(j,26)
                  if(let[j])un+=(char)(j+'a');           
              int s=un.size();
              //cout<<un<<endl;
              
              for(int j=0;j<s;j++)
                 if(un[j]==w[i])break;
                 else r+=nPr(un[j],run-i-1);
              let[w[i]-'a']--;
              //printf("%d\n",r);
              //SP;
         }
         printf("%10lld\n",r+1);
    }
    return 0;
}
