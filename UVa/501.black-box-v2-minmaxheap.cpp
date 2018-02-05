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
int number[40000], query[40000];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int n, q;
    scanf("%d", &cas);
    for(int z = 0; z < cas; ++ z)
    {
        if(z)putchar(10);    
        scanf("%d%d", &n ,&q);
        for(int i = 0; i < n; ++i)
           scanf("%d", &number[i]);
        
        priority_queue<int, vector<int>, greater<int> > min_heap;
        priority_queue<int, vector<int>, less<int> > max_heap;
        
        int max_size = 1;
        int current = 0;
        int j = 0;
        for(int i = 0; i < q; ++i)
        {
           scanf("%d", &query[i]);
           while(j < query[i])
           {
               //printf("> %d %d\n", current, max_size);    
               if(current < max_size)
                   max_heap.push(number[j++]),
                   ++current;
               else
               {
                   //printf("%d %d\n", number[j], max_heap.top());
                   //SP;
                   if(number[j] < max_heap.top())
                   {
                       min_heap.push(max_heap.top());
                       max_heap.pop();
                       max_heap.push(number[j++]);         
                   }
                   else
                       min_heap.push(number[j++]);
               }
           }
           
           while(current < max_size)
           {
               max_heap.push(min_heap.top());
               min_heap.pop();
               ++current;     
           }
           //printf("size = %d %d\n", max_heap.size(), max_size);
           printf("%d\n", max_heap.top());
           ++max_size;
           while(min_heap.size() && current < max_size)
           {
               max_heap.push(min_heap.top());
               min_heap.pop();
               ++current;     
           }           
        }
    }
    return 0;
}
