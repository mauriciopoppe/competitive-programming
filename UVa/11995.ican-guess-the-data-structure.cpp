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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    bool imp,queueb,stackb,pqb;
    int n,op,num;
    long start=clock();
    while(scanf("%d",&n)!=EOF)
    {
         imp=0;
         queueb=stackb=pqb=1;
         queue<int> q;
         stack<int> s;
         priority_queue<int,vector<int>, less<int> > pq;
         F(i,n)
         {
              scanf("%d%d",&op,&num);
              if(!imp)
              {
                   if(queueb)
                   {
                          if(op==1)
                              q.push(num);
                          else if(op==2 && q.empty()){imp=1;continue;}                          
                          else
                          {
                              if(q.front()!=num)queueb=0;
                              q.pop();
                          }                                 
                   }
                   if(stackb)
                   {
                          if(op==1)
                              s.push(num);
                          else if(op==2 && s.empty()){imp=1;continue;}
                          else
                          {
                              if(s.top()!=num)stackb=0;
                              s.pop();
                          }                                 
                   }   
                   if(pqb)
                   {
                          if(op==1)
                              pq.push(num);
                          else if(op==2 && pq.empty()){imp=1;continue;}                              
                          else
                          {
                              if(pq.top()!=num)pqb=0;
                              pq.pop();
                          }                                 
                   }    
                   if(pqb+stackb+queueb==0)imp=1;                                    
              }
         }
         //printf("here");
         if(imp)printf("impossible");
         else if(pqb+stackb+queueb>1)printf("not sure");
         else if(pqb)printf("priority queue");
         else if(stackb)printf("stack");
         else printf("queue");
         NL;
    }
    //printf("%ld\n",clock()-start);
    return 0;
}
