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

int digits[][9] = {{0, 0, 0, 0, 0, 1, 0, 0, 1},  //1
                   {0, 1, 0, 0, 1, 1, 1, 1, 0},  //2
                   {0, 1, 0, 0, 1, 1, 0, 1, 1},  //3
                   {0, 0, 0, 1, 1, 1, 0, 0, 1},  //4
                   {0, 1, 0, 1, 1, 0, 0, 1, 1},  //5
                   {0, 1, 0, 1, 1, 0, 1, 1, 1},  //6
                   {0, 1, 0, 0, 0, 1, 0, 0, 1},  //7
                   {0, 1, 0, 1, 1, 1, 1, 1, 1},  //8
                   {0, 1, 0, 1, 1, 1, 0, 1, 1},  //9
                   {0, 1, 0, 1, 0, 1, 1, 1, 1}};  //0;

char w[3][28];
int numbers[9][9];
vector<int> solutions;

void print()
{
        for(int i = 0; i < 9; ++i){
           for(int j = 0; j < 9; ++j)
           printf("%d ", numbers[i][j]);NL;}     
}

int change(int from, int to)
{
    for(int i = 0; i < 9; ++i)
       if(digits[to][i] - numbers[from][i] < 0)
          return 0;
    return 1;
}

int get_value(int row)
{
    for(int i = 0; i < 10; ++i)    
    {
       int j = 0;     
       for(j = 0; j < 9; ++j)
           if(digits[i][j] != numbers[row][j])
              break;
       if(j == 9)
          return (i + 1) % 10;
    }   
    return -1;
}

int valid()
{
    int total = 0;
    for(int i = 0; i < 9; ++i)
    {
        int k = get_value(i);
        if(k == -1)
        {
           //printf("%d\n", i);  
           return -1;
        }
        total += k * (9 - i);
    }
    return total;
}

int solve()
{
    //check if the number is an original number
    solutions.clear();
    int k = valid();
    if(k >= 0 && k % 11 == 0)
    {
        int total = 0; 
        for(k = 0; k < 9; ++k) 
           total = total * 10 + get_value(k);
        solutions.push_back(total);
        goto end;
    }        
    //try to change each number        
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 10; ++j)
            if(change(i, j))
            {
                         
                int copy_numbers[9][9];
                memcpy(copy_numbers, numbers, sizeof numbers);
                for(k = 0; k < 9; ++k)
                    numbers[i][k] = digits[j][k];
                k = valid();
                //printf("%d -> %d [%d]\n", i, j, k);
                //print();
                //SP;
                if(k >= 0 && k % 11 == 0)
                {
                    int total = 0; 
                    for(k = 0; k < 9; ++k) 
                       total = total * 10 + get_value(k);
                    solutions.push_back(total);
                }
                memcpy(numbers, copy_numbers, sizeof copy_numbers);                                
            }
    }
    end:
    k = solutions.size();
    if(k > 1)
       puts("ambiguous");
    else if(k == 0)
       puts("failure");
    else if(k == 1)
       printf("%09d\n", solutions[0]);
}

int main()
{
    int cas;
    scanf("%d", &cas);
    gets(w[0]);
    while(cas--)
    {        
        for(int i = 0; i < 3; ++i)
            gets(w[i]);
        memset(numbers, 0, sizeof numbers);
        int k = 0;
        for(int k = 0; k < 9; ++k)
            for(int i = 0; i < 3; ++i)
               for(int j = 0; j < 3; ++j)
                  if(w[i][k * 3 + j] != ' ')
                     numbers[k][i * 3 + j] = 1;
        //weird!! first line has 26 characters
        numbers[8][2] = 0;
        //print();
        k = solve();
    }
    return 0;
}
