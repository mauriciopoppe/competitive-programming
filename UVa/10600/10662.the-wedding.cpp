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

struct place{
     int price;
     int able[25];  
} T[25], R[25], H[25];

int main()
{
    int t, r, h;
    while(scanf("%d%d%d", &t, &r, &h) != EOF)
    {
         //travel agency
         for(int i = 0; i < t; ++i)
         {
             scanf("%d", &T[i].price);
             for(int j = 0; j < r; ++j)
                 scanf("%d", &T[i].able[j]);    
         }                 
         //restaurant
         for(int i = 0; i < r; ++i)
         {
             scanf("%d", &R[i].price);
             for(int j = 0; j < h; ++j)
                 scanf("%d", &R[i].able[j]);    
         }                 
         //hotel
         for(int i = 0; i < h; ++i)
         {
             scanf("%d", &H[i].price);
             for(int j = 0; j < t; ++j)
                 scanf("%d", &H[i].able[j]);    
         }                 
         
         int mn = IMAX;
         int x = -1, y = -1, z = -1;
         for(int i = 0; i < t; ++i)
         {
             for(int j = 0; j < r; ++j)
             {
                 if(!T[i].able[j])
                 {
                     for(int k = 0; k < h; ++k)
                         if(!R[j].able[k] && !H[k].able[i])
                         {
                             // printf("%d %d %d = %d\n", i + 1, j + 1, k + 1, 
                               //          T[i].price + R[j].price + H[k].price);
                              int total = T[i].price + R[j].price + H[k].price;
                              if(total < mn)
                                 x = i, y = j, z = k, mn = total;
                              //SP;
                         }
                 } 
             }
         }
         if(x == -1)
            puts("Don't get married!");
         else
            printf("%d %d %d:%d\n", x, y, z, mn);
    }
    return 0;
}
