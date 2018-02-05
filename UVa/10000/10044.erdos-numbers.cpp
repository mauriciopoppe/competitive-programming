#include<iostream>
#include<string>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#define M 10000

using namespace std;
vector<vector<int> > g;
int d[M],len,v,u;

void parse(string &w)
{
     while(w[0]==' ')w.erase(0,1);
     while(w[w.size()-1]==' ')w=w.substr(0,w.size()-1);
}

void split(string &w, vector<string> &word)
{   
    for (int fb,fe=0,lb,le=0;w[fe]!=':'&&w[le]!=':';) 
    {
        fb=w.find_first_not_of(" ,",le);
        fe=w.find_first_of(" ,:",fb);
        lb=w.find_first_not_of(" ,",fe);
        le=w.find_first_of(" ,:", lb);
        if(fb==string::npos || fe==string::npos || 
          lb==string::npos || le==string::npos) break;
        string name = w.substr(fb, fe-fb) + ", " + w.substr(lb, le-lb);
        word.push_back(name);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    string w,wa,wb,wc;
    int t,p,que,cc;
    scanf("%d",&t);
    map<string,int> m;
    string erdos="Erdos, P.";
    
    for(int z=1;z<=t;z++)
    {
        printf("Scenario %d\n",z);    
        m.clear();
        g.clear(); 
        g.resize(5010);                                    
        cc=1;
        scanf("%d%d",&p,&que);
        getchar();
        
        for(int i=0;i<p;i++)
        {
            getline(cin,w);      
            //cout<<w<<endl;                                      
            vector<string> words;
            split(w,words);
            
            //for(int k=0;k<words.size();k++)
            //   printf("{%s}\n",words[k].c_str());
            
            int size=words.size();
            for(int j=0;j<size-1;j++)
            {
                if(!m[words[j]])m[words[j]]=cc++;
                
                for(int k=j+1;k<size;k++)
                {
                    if(!m[words[k]])m[words[k]]=cc++;                                                     
                    g[m[words[j]]].push_back(m[words[k]]);
                    g[m[words[k]]].push_back(m[words[j]]);     
                }    
            }        
        }     
        for(int i=0;i<que;i++)
        {  
            getline(cin,w);
            
            printf("%s ",w.c_str());
            memset(d,0,sizeof(d));
            int s=m[w];
            if(!s){printf("infinity\n");continue;}
            
            queue<int> q;
            q.push(m[erdos]);
            d[q.front()]=1;
            
            while(!q.empty())
            {
                 u=q.front();
                 q.pop();
                 int size=g[u].size();
                 for(int k=0;k<size;k++)
                 {
                     v=g[u][k];
                     if(!d[v])
                     {
                         d[v]=d[u]+1;
                         if(v==s)goto end;
                         q.push(v);      
                     }    
                 }           
            }                
            end:
                
                if(d[s])
                   printf("%d\n",d[s]-1);
                else printf("infinity\n");
        }                                  
    }
    return 0;
}
