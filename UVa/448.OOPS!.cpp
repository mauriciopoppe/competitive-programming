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
#define M 10000000
char w[M];
int bin[18];
string solve(int i)
{
    stringstream ss;
    int size = 0;
    memset(bin, 0, sizeof bin);
    for(int k = i + 3; k >= i; --k)
    {
        int number = 0;
        if(isalpha(w[k]))
           number = w[k] - 'A' + 10;
        else
           number = w[k] - '0';
        for(int j = 0; j < 4; ++j)
        {
           bin[size++] = number % 2;
           number /= 2;
        }
    }
    
    int mode = bin[size - 1] * 2 + bin[size - 2];
    
    if(mode == 0)
       ss << "R";
    else if(mode == 1)
       ss << "$";
    else if(mode == 2)
       ss << "PC+";
    
    int number = 0;
    for(int i = 0; i < size - 2; ++i)
       number += (bin[i] << i);
    ss << number;
    return ss.str();
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char c;
    int size = 0;
    while((c = getchar()) != EOF)
       if(isalnum(c))
          w[size++] = c;
    
    for(int i = 0; i < size;)
    {
        switch(w[i])
        {
             case '0':
                  printf("ADD %s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str());
                  i += 9;
             break;
             case '1':
                  printf("SUB %s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str());
                  i += 9;                  
             break;
             case '2':
                  printf("MUL %s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str());
                  i += 9;                  
             break;
             case '3':
                  printf("DIV %s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str());
                  i += 9;                  
             break;
             case '4':
                  printf("MOV %s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str());
                  i += 9;                  
             break;
             case '5':
                  printf("BREQ %s\n", solve(i + 1).c_str());
                  i += 5;                                    
             break;
             case '6':
                  printf("BRLE %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;
             case '7':
                  printf("BRLS %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;
             case '8':
                  printf("BRGE %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;
             case '9':
                  printf("BRGR %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;
             case 'A':
                  printf("BRNE %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;
             case 'B':
                  printf("BR %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;
             case 'C':
                  printf("AND %s,%s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str(),
                                       solve(i + 9).c_str());
                  i += 13;                                    
             break;
             case 'D':
                  printf("OR %s,%s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str(),
                                       solve(i + 9).c_str());
                  i += 13;                                    
             break;
             case 'E':
                  printf("XOR %s,%s,%s\n", solve(i + 1).c_str(), 
                                       solve(i + 5).c_str(),
                                       solve(i + 9).c_str());
                  i += 13;                                    
             break;
             case 'F':
                  printf("NOT %s\n", solve(i + 1).c_str());
                  i += 5;               
             break;

        }
    }
    //SP;
    return 0;
}
