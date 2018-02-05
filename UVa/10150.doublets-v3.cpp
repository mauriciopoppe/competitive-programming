#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<sstream>
#define M 25200
#define S 18
using namespace std;

struct node{
       int v;
       node *next[26];
       node(){v=0;memset(next,0,sizeof(next));}
       }*trie [S];

typedef vector<vector<int> > vgraph;
vector<vgraph> g(S);

string word[S][M];
int size[S],val[M],par[M],res[M],LEN;
bool isBuilt[S][M];

void add(string &w, int &val)
{
    node *r=trie[LEN];
    for(int i=0;w[i];++i)
    {
         char t=w[i]-'a';
         if(r->next[t]==NULL)
           r->next[t]=new node();
         r=r->next[t];    
     }      
     r->v=val;
}

int findword(string &w)
{
     node *r=trie[LEN];
     for(int i=0;w[i];++i)
     {
         char t=w[i]-'a';    
         if(r->next[t]==NULL)
           return 0;
         r=r->next[t];    
     }
     if(r->v)return r->v;
     return 0;
}

bool check(string &wa, string &wb)
{
     bool cc=false;
     for(int i=0;i<LEN;i++)
        if(wa[i]!=wb[i])
        {
            cc=!cc;
            if(!cc)return false;            
        }
     if(cc)return true;
     return false;
}

int main()
{
     //freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
     
     string wa,wb,wc;
     int temp,u,v,len;     
     memset(size,0,sizeof(size));
     
     for(int i=1;i<S;i++)trie[i]=new node();
     
     while(getline(cin,wa) && !wa.empty())
     {
          LEN=temp=wa.size();
          word[temp][size[temp]++]=wa;
          add(wa,size[temp]);
     }     
     
     //build by size
     /*
     for(int i=1;i<S;i++)
     {
         g[i].resize(size[i]+1);    
         for(int j=0;j<size[i]-1;j++)
             for(int k=j+1;k<size[i];k++)
                 if(check(word[i][j],word[i][k],i))
                 {
                    g[i][j].push_back(k);
                    g[i][k].push_back(j);
                 }
     }*/
     
     for(int i=1;i<S;i++)
         g[i].resize(size[i]+1);
         
     bool cc=0;
     while(cin>>wa>>wb)
     {    
          if(cc)printf("\n");
          cc=1; 
                   
          int lenA=wa.size(),lenB=wb.size();
          if(lenA!=lenB){printf("No solution.\n");continue;}
          
          LEN=lenA;         
          //find word
          int i=findword(wa),j=findword(wb);
          if(!i || !j){printf("No solution.\n");continue;}  
          
          --i;
          --j;
          
          memset(val,0,sizeof(val));
          memset(par,-1,sizeof(par));
          queue<int> q;
          q.push(i);
          val[i]=1;
                              
          while(!q.empty())
          {
              u=q.front();
              q.pop();
              if(!isBuilt[lenA][u])
              {
                  for(int k=0;k<size[lenA];k++)
                      if(!isBuilt[lenA][k] && u!=k && check(word[lenA][k],word[lenA][u]))
                         {
                            g[lenA][k].push_back(u);
                            g[lenA][u].push_back(k);
                         }
                  isBuilt[lenA][u]=1;
              }
              
              len=g[lenA][u].size();
              for(int i=0;i<len;i++)
              {
                   v=g[lenA][u][i];
                   if(!val[v])
                   {
                       val[v]=val[u]+1;
                       par[v]=u;
                       if(v==j)goto end;                       
                       q.push(v);
                   }
              }                           
          }
          end:
          if(val[j])
          {
              int k=0;
              res[k++]=j;
              while(par[j]!=-1)
              {
                   res[k++]=par[j];
                   j=par[j];                 
              }
              for(int i=k-1;i>=0;i--)
                  printf("%s\n",word[lenA][res[i]].c_str());
          }
          else printf("No solution.\n");
    }
    return 0;
}
