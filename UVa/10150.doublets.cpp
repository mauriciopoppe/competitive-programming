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

typedef vector<vector<int> > vgraph;
vector<vgraph> g(S);

string word[S][M];
int size[S],val[M],par[M],res[M];

bool check(string &wa, string &wb, int &len)
{
     int cc=0;
     for(int i=0;i<len;i++)
        if(wa[i]!=wb[i])
        {
            ++cc;
            if(cc==2)return false;            
        }
     if(cc)return true;
     return false;
}

int main()
{
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
     
     string wa,wb,wc;
     int temp,u,v,len;     
     memset(size,0,sizeof(size));
     
     while(getline(cin,wa) && !wa.empty())
     {
          temp=wa.size();
          word[temp][size[temp]++]=wa;   
     }     
     
     //build by size
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
     }
     
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
          
          memset(val,0,sizeof(val));
          memset(par,-1,sizeof(par));
          queue<int> q;
          q.push(i);
          val[i]=1;
                           
          while(!q.empty())
          {
              u=q.front();
              q.pop();
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
