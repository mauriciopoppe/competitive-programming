#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<sstream>
using namespace std;

struct team{
       int t,ps,time;
       team(int a=0, int b=0, int c=0):t(a),ps(b),time(c){}
       bool operator<(const team &x)const
              {
                   if(ps!=x.ps)return ps>x.ps;
                   else if(ps==x.ps && time!=x.time)return time<x.time;     
                   else return t<x.t;
              }
       };

int main()
{
    char line[20];
    int n,t,p,time;
    char out;
    cin>>n;
    getchar();
    getchar();
    for(int q=0;q<n;++q)
    {
        int m[101][10];
        int wa[101][10];
        int c[101][10];
        
        for(int i=0;i<101;i++)
        {
            memset(m[i],0,sizeof(m[i]));
            memset(c[i],0,sizeof(c[i]));
            memset(wa[i],0,sizeof(wa[i]));
        }
        
        string s;
        if(q)printf("\n");
        while(gets(line) && strlen(line))
        {
             sscanf(line,"%d %d %d %c",&t,&p,&time,&out);
             m[t][0]=1;
             if(out=='I')
                  wa[t][p]++;                               

             if(out=='C' && !c[t][p])
             {
                  m[t][p]=time+wa[t][p]*20;            
                  c[t][p]=1;
             }
        }     
        
        vector<team> v;
        int ttime=0,ps=0;
        for(int i=1;i<101;i++)
        {
            if(m[i][0])
            {
                ttime=ps=0;
                for(int j=1;j<10;j++) 
                   if(c[i][j])
                      {
                             ttime+=m[i][j];
                             ps++; 
                      }       
                v.push_back(team(i,ps,ttime));
            }            
        }   
        
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
           printf("%d %d %d\n",v[i].t,v[i].ps,v[i].time);
    
        //printf("here");    
    }
    return 0;
}
