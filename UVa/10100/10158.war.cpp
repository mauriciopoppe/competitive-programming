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

#define MAXV 20000  
  
#define SET_FRIENDS 1  
#define SET_ENEMIES 2  
#define ARE_FRIENDS 3  
#define ARE_ENEMIES 4  
  
#define NO 0  
#define YES 1  
#define ERROR (-1)  
  
int root[MAXV]; 
 
int find_set(int x)  
{  
    return (root[x] == x) ? x : (root[x] = find_set(root[x]));  
}  

void make_set(int &people)  
{  
    int size = people * 2; 
    for (int i = 0; i < size; i++)  
        root[i] = i;  
}  
  
void set_friends(int &x, int &y, int &people)  
{  
    int xRoot = find_set(x);  
    int yRoot = find_set(y);  
    int xEnemyRoot = find_set(x + people);  
    int yEnemyRoot = find_set(y + people);  
  
    if (xRoot == yEnemyRoot || yRoot == xEnemyRoot)  
        printf("%d\n", ERROR);  
    else  
    {  
        root[yRoot] = xRoot;  
        root[yEnemyRoot] = xEnemyRoot;  
    }  
}  
  
void set_enemies(int x, int y, int people)  
{  
    int xRoot = find_set(x);  
    int yRoot = find_set(y);  
    int xEnemyRoot = find_set(x + people);  
    int yEnemyRoot = find_set(y + people);  
  
    if (xRoot == yRoot)  
        printf("%d\n", ERROR);   
    else  
    {
        root[xEnemyRoot] = yRoot;  
        root[yEnemyRoot] = xRoot;  
    }  
}  

void are_friends(int x, int y)  
{  
    cout << (find_set(x) == find_set(y) ? YES : NO) << endl;  
}  
   
void are_enemies(int x, int y, int people)  
{  
    int xRoot = find_set(x);  
    int yRoot = find_set(y);  
    int xEnemyRoot = find_set(x + people);  
    int yEnemyRoot = find_set(y + people);  
  
    if (xRoot == yEnemyRoot || yRoot == xEnemyRoot)  
        printf("%d\n", YES);
    else  
        printf("%d\n", NO);
}  
  
int main()  
{  
    int people, c, x, y;    
    scanf("%d", &people);
    make_set(people);    
    while (scanf("%d%d%d", &c, &x, &y) && (c || x || y))  
    {  
        switch (c)  
        {  
            case SET_FRIENDS:  
                set_friends(x, y, people);  
                break;  
  
            case SET_ENEMIES:  
                set_enemies(x, y, people);  
                break;  
  
            case ARE_FRIENDS:  
                are_friends(x, y);  
                break;  
  
            case ARE_ENEMIES:  
                are_enemies(x, y, people);  
                break;  
        }  
    }  
    return 0;  
}  
