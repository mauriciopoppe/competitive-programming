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
#define M 100001
struct node{
       char c;
       node *next, *back;
       node(char x){c=x;next=back=NULL;}
       };

void push_front(node *&n, char &x)
{
     if(n==NULL){n=new node(x);return;}
     node *t=new node(x);
     t->next=n, n->back=t, n=t;
}

void push_back(node *&n, char &x)
{
     if(n==NULL){n=new node(x);return;}     
     node *t=new node(x);
     n->next=t, t->back=n, n=t;
}

int main()
{
    char c;
    char w[100005],end[100005];
    while(gets(w))
    {
         int s=strlen(w);
         bool f=0,hasTail=0;
         node *head[2], *tail[2];
         //test [a][v]
         //if(tail[0]==NULL)printf("null\n");
         F(i,s)
         {
              //printf("%d\n",i); 
              if(w[i]==']')
              {
                  if(hasTail)
                  {
                      while(1)
                      {
                           if(tail[1]==NULL)break;
                           if(head[0]==NULL)head[0]=head[1]=new node(tail[1]->c);
                           else push_front(head[0],tail[1]->c);
                           tail[1]=tail[1]->back;
                      }       
                      tail[0]=tail[1];
                      hasTail=0;
                  }
                  f=0;
              }
              else if(w[i]=='[')
              {
                  if(hasTail)
                  {
                      while(1)
                      {
                           if(tail[1]==NULL)break;
                           if(head[0]==NULL)head[0]=head[1]=new node(tail[1]->c);
                           else push_front(head[0],tail[1]->c);
                           tail[1]=tail[1]->back;
                      }
                      //if(tail[0]==NULL && tail[1]==NULL)printf("xD");
                      tail[0]=tail[1];
                      hasTail=0;
                  }
                  f=1;
              }
              else
              {
                  if(!f)
                  {
                        if(head[0]==NULL)head[0]=head[1]=new node(w[i]);
                        else push_back(head[1],w[i]);
                  }
                  else
                  {
                        if(tail[0]==NULL)tail[0]=tail[1]=new node(w[i]);
                        else push_back(tail[1],w[i]);
                        hasTail=1;
                  }
              }
              //printf("%c %c\n",head[0]->c,head[1]->c);
              //if(tail[0]==NULL)printf("tail is null\n");
              //SP;
         }
         //printf("here\n");
         char *i=end;

         while(1)
         {
              if(tail[0]==NULL)break;
              *i++=tail[0]->c;
              tail[0]=tail[0]->next;
         }         
         
         while(1)
         {
              if(head[0]==NULL)break;
              *i++=head[0]->c;
              head[0]=head[0]->next;
         }                
         *i='\0';  
         printf("%s\n",end);         
    }   
    return 0;
}
