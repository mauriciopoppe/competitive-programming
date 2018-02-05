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
#define M 205
using namespace std;

vector<vector<int> > g;
int size[M],val[M];
bitset<M> d;

bool check(string &wa, string wb, int &len)
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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    map<string,int> m;
    map<string,int>::iterator it;
    
    vector<int> aux;
    int n,j,len,v,u;
    string wa,wb,wc;
    scanf("%d",&n);
    for(int z=0;z<n;z++)
    {
         if(z)printf("\n");   
         j=1;     
         memset(size,0,sizeof(size));
         g.clear();
         g.resize(M);
         m.clear();
         
         while(cin>>wa && wa[0]!='*')
         {
              if(!m[wa])
              {                       
                  size[j]=wa.size();                                                   
                  for(it=m.begin();it!=m.end();it++)
                  {
                      if(size[it->second]==size[j] && check(wa,it->first,size[j]))
                      {
                          g[it->second].push_back(j);   
                          g[j].push_back(it->second);
                      }    
                  }
                  m[wa]=j++;              
              }
         }     
         getchar();
         
         while(getline(cin,wc) && wc.size())
         {
              stringstream ss(wc);
              ss>>wa>>wb;

              int search=m[wb];
              d.reset();
              fill(val,val+M,-1);
              
              queue<int> q;
              q.push(m[wa]);
              d[q.front()]=1;
              val[q.front()]=0;
                               
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
                           if(v==search)goto end; 
                           q.push(v);    
                       }   
                  }             
              }   
              
              end:      
              cout<<wa<<" "<<wb<<" "<<val[search]<<endl;                                
         }     
    }
    return 0;
}
