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
char m[][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int number[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int size[1000];
char w[1000], decoded[1000];
int temp[3];
char get_size[5];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    for(int i = 999; i >= 0; --i)
    {
       sprintf(get_size,"%03d",i);
       //printf("%s\n",get_size);
       size[i] = number[get_size[0] - '0'] + number[get_size[1] - '0'] + number[get_size[2] - '0'];
       //printf("%d -> %d\n",i,size[i]);
    }
    int cas  = 0;
    while(gets(w))
    {
        if(cas)NL;
        cas = 1;          
        int length = strlen(w);
        for(int i = 0; i < length; ++i)
           w[i] = w[i] - 'A' + 'a';
        decoded[length] = '\0';
        for(int i = 999; i >=0 ; --i)
        {
            if(size[i] == length)
            {
                 //printf("%d %d\n",i ,size[i]);
                 int c = 2;
                 for(int k = i; c >= 0; k /= 10)
                     temp[c--] = k % 10;                           
                 //printf("%d %d %d\n",temp[0], temp[1], temp[2]);
                 int ind = 0;
                 for(int k = 0; k < 3; ++k)
                 {
                     for(int j = 0; j < number[temp[k]]; ++j)
                     {
                         int x = w[ind] - m[temp[k]][j];
                         if(x > 0) x -= 26;
                         decoded[ind++] = x + 'A' + 25;
                     }
                 }
                 printf("%s -> %s%s%s\n", decoded, m[temp[0]], m[temp[1]], m[temp[2]]);
            }
        }
    }
    return 0;
}
