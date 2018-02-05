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
char str[1000];
char w[1000];
vector<int> number;
vector<char> operand;
string last;

void print()
{
     int size = operand.size();
     for(int i = 0; i < size; ++i)    
     {
        printf("%d", number[i]);
        printf(" %c ",operand[i]);     
     }
     printf("%d", number[size]);
     printf(" = %s\n",last.c_str());
}

void calc(int &x, int &i)
{
     operand.erase(operand.begin() + i);
     number.erase(number.begin() + i, number.begin() + i + 2);
     number.insert(number.begin() + i, x);
}

int main()
{
    int i,j;
    int f;
    while(gets(str))
    {
         //kill this "operand,+"
         number.clear();
         operand.clear();
         j = 0;
         f = 1;
         
         //split the initial string
         //by spaces
         for(i = 0; str[i] ; ++i)
         {
            if(isspace(str[i]))
               continue;   
            if(!isalnum(str[i]))
            {
               if(!f)
               {
                   w[j++] = ' ';
                   w[j++] = str[i];
                   w[j++] = ' ';
                   f = 1; 
               }
               else
                  w[j++] = str[i], f = 0;
            }
            else 
               w[j++] = str[i], f = 0; 
         }
         w[j] = '\0';
         
         //split the string into numbers and operands
         char *ptr = strtok(w, " ");         
         number.push_back(atoi(ptr));     
         ptr = strtok(NULL, " ");
         while(strcmp(ptr, "="))
         {              
              operand.push_back(ptr[0]); 
              ptr = strtok(NULL, " ");
              number.push_back(atoi(ptr));     
              ptr = strtok(NULL, " ");
         }
         ptr = strtok(NULL, " ");
         int size_last = strlen(ptr), size;
         last = string(ptr, ptr + size_last);

         print();
         while((size = operand.size()))
         {    
              //search for *     
              for(i = 0; i < size; ++i)
                 if(operand[i] == '*' || operand[i] == '/')
                   break;
              if(i != size)
              {
                   int x;
                   if(operand[i] == '*')
                      x = number[i] * number[i + 1];                   
                   else
                      x = number[i] / number[i + 1];                   
                   calc(x, i);
                   print();
                   continue;
              }
              
              //search for +     
              for(i = 0; i < size; ++i)
                 if(operand[i] == '+' || operand[i] == '-')
                   break;
              if(i != size)
              {
                   int x;
                   if(operand[i] == '+')
                      x = number[i] + number[i + 1];                   
                   else
                      x = number[i] - number[i + 1];                                      
                   calc(x, i);
                   print();
                   continue;
              }
         }                 
         NL;       
    }
    return 0;
}
