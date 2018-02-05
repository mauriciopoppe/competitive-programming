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
#define M 25145
#define S 17
using namespace std;

typedef vector<vector<int> > vgraph;
vector<vgraph> g(S);

string word[S][M];
int size[S],par[M],res[M],LEN;
bool isBuilt[S][M];

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
     
     while(getline(cin,wa) && !wa.empty())
     {
          temp=wa.size();
          word[temp][size[temp]++]=wa;   
     }
     
     for(int i=1;i<S;i++)
         g[i].resize(size[i]+1);
         
     bool cc=0;
     while(cin>>wa>>wb)
     {    
          if(cc)printf("\n");
          cc=1; 
                   
          int lenA=wa.size(),lenB=wb.size();
          if(lenA!=lenB){printf("No solution.\n");continue;}
                   
          //find word
          int i=0,j=0;
          for(i=0;i<size[lenA];i++)
             if(word[lenA][i]==wa)break;
          if(i==size[lenA]){printf("No solution.\n");continue;}  
          
          for(j=0;j<size[lenB];j++)
             if(word[lenB][j]==wb)break;
          if(j==size[lenB]){printf("No solution.\n");continue;} 
          
          LEN=lenA;
          
          memset(par,-1,sizeof(par));
          queue<int> q;
          q.push(i);
          par[i]=i;
                              
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
                   if(par[v]==-1)
                   {
                       par[v]=u;
                       if(v==j)goto end;                       
                       q.push(v);
                   }
              }                           
          }
          end:
          if(par[j]>=0)
          {
              int k=0;
              res[k++]=j;
              while(1)
              {
                   if(j==par[j])break;
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
