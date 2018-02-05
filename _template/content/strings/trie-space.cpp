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

struct node{
       int count;
       map<char, node*> edges;
       node()
       {
           count = 0;
       }
} *root;

void insert_word(char *q)
{
     int i;
     //tree iterator
     node *ptr = root;  
     for(i = 0; q[i] != '\0'; ++i)
     {
         //if there's no edge, build the edge  
         if(ptr->edges.find(q[i]) == ptr->edges.end())
             ptr->edges[q[i]] = new node();
         
         //advance to the next node
         ptr = ptr->edges[q[i]];
     }
     //flag that states that a word ends here
     ptr->count++;
}

int find_word(char *q)
{
     int i;
     node *ptr = root;  
     for(i = 0; q[i] != '\0'; ++i)
     {
         //if there's no edge return false  
         if(ptr->edges.find(q[i]) == ptr->edges.end())
             return false;
         //advance to the next node
         ptr = ptr->edges[q[i]];
     }
     //if it's a word in the trie
     if(ptr->count)
        return true;
     //the word is not in the trie
     return false;
}

char w[500];
int main()
{
    //build the root
    root = new node();
    while(gets(w))
        insert_word(w);          
    while(gets(w))
        printf("%d\n",find_word(w));
    SP;
    return 0;
}
