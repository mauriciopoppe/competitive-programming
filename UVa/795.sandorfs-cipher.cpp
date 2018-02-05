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
bool copy_cipher[][6]={{0, 1, 0, 1, 0, 1},
                       {0, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 0},
                       {0, 1, 0, 0, 1 ,0},
                       {0, 0, 0, 0, 0, 1},
                       {0, 0, 0, 1, 0, 0}};

void rotate(bool m[][6])
{
     bool cp[6][6];
     for(int j = 0, x = 0; j < 6; ++j, ++x)
        for(int i = 5, y = 0; i >= 0; --i, ++y)
           cp[x][y] = m[i][j];
     F(i,6)
       F(j,6)
         m[i][j] = cp[i][j];           
}
                  
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w[200];
    char decripted[200];
    char key[7][7];
    bool cipher[6][6];
    int i,j;
    int cas = 0;
    while(gets(w))
    {
        //if(cas)NL;
        //cas = 1;          
        int size = strlen(w);          
        int partitions = size / 36;
        int c = 0;
        //to matrix
        for(int k = 0; k < partitions; ++k)
        {
            for(i = 0; i < 6; ++i)
              for(j = 0; j < 6 ; ++j)
                 key[i][j] = w[k * 36 + i * 6 + j];
            
            memcpy(cipher, copy_cipher, sizeof copy_cipher);
            
            for(i = 0; i < 6 ; ++i)
               for(j = 0; j < 6; ++j)
                  if(cipher[i][j])
                     decripted[c++] = key[i][j];
            
            //3 more times to decript
            for(int z = 0; z < 3; z++)
            {
                rotate(cipher);
                for(i = 0; i < 6 ; ++i)
                    for(j = 0; j < 6; ++j)
                       if(cipher[i][j])
                          decripted[c++] = key[i][j];                    
            }
            
        }
        reverse(decripted, decripted + c);
        while(decripted[c - 1] == '#')
           --c;
        decripted[c] = '\0';
        printf("%s\n",decripted);
    }
    return 0;
}
