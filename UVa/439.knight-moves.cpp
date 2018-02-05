#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 65
using namespace std;

vector<vector<int> > g(65);
int val[M],dx[]={-2,-2,-1,1,-1,1,2,2},dy[]={-1,1,2,2,-2,-2,-1,1},x,y;
bitset<M> d;

bool check(int &i, int &j)
{
     if(i>0 && j>0 && j<9 && i<9)return true;
     return false;
}

void print(int t)
{
     for(int i=1;i<=t;i++)
     {
         printf("Node %d,%d:",i,g[i].size());
         for(int j=0;j<g[i].size();j++)
           printf(" %d",g[i][j]);
         printf("\n");    
     }
}

int main()
{
    map<string,int> m;
    string w,w2;
    char temp[3];
    temp[2]='\0';
    
    int cc=1,u,v,len;
    for(int i=1;i<9;i++)
       for(int j=1;j<9;j++)
       {
           temp[0]=i+'a'-1;
           temp[1]=j+'0';
           w=string(temp);
           if(!m[w])m[w]=cc++;
           //cout<<w<<endl;
           //cout<<endl;
           for(int k=0;k<8;k++)
           {
               x=i+dx[k];
               y=j+dy[k];
               if(check(x,y))
               {
                   temp[0]=x+'a'-1;
                   temp[1]=y+'0';
                   w2=string(temp);
                   if(!m[w2])m[w2]=cc++;
                   g[m[w]].push_back(m[w2]);
                   //cout<<w2<<endl;
               }
           }      
           //system("pause");

       }
    
    //print(64);
    while(cin>>w>>w2)
    {
         fill(val,val+M,-1);
         d.reset();         
         //printf("%d")
         int s=m[w2];         
         queue<int> q;
         q.push(m[w]);
         val[q.front()]=0;
         d[q.front()]=1;            
         
         while(!q.empty())
         {
              u=q.front();
              q.pop();            
              len=g[u].size();
              for(int i=0;i<len;i++)
              {
                  v=g[u][i];
                  if(!d[v])
                  {
                      d[v]=1;
                      val[v]=val[u]+1;
                      if(v==s)goto end;
                      q.push(v);                           
                  }    
              }            
         }            
         
         end:
         printf("To get from %s to %s takes %d knight moves.\n",w.c_str(),w2.c_str(),val[s]);    
    }
    
    return 0;
}
