#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct point{
       int x,y;
       point(int a, int b){x=a;y=b;}
       bool operator<(const point &a)const
       {
            if(x!=a.x)return x<a.x;
            else return y<a.y;     
       }
       };

char w[10];
int main()
{
    vector<point> blue,red;
    int t,p,f,x,y;
    scanf("%d",&t);
    ++t;
    while(--t)
    {
        blue.clear();
        red.clear();
        scanf("%d %d",&p,&f);
        for(int i=0;i<p;++i)
        {
             scanf("%d %d %s",&x,&y,w);
             if(strcmp(w,"red")==0)red.push_back(point(x,y));
             else blue.push_back(point(x,y));        
        }            
        
        int rs=red.size(),bs=blue.size();
        int M=min(rs,bs);
        if(M<f)
        {
             printf("Impossible\n");
             continue;                
        }
        
        sort(blue.begin(),blue.end());
        sort(red.begin(),red.end());
        
        for(int i=0;i<bs;i++)
           printf("[%d,%d] ",blue[i].x,blue[i].y);
        printf("\n");
        for(int i=0;i<rs;i++)
           printf("[%d,%d] ",red[i].x,red[i].y);
        printf("\n");
        
        
        double m=0;
        double d;
        for(int i=0;i<bs;i++)
        {
             for(int j=i+1;j<rs;j++)   
             {
                     d=sqrt((blue[i].x-red[j].x)*(blue[i].x-red[j].x)+(blue[i].y-red[j].y)*(blue[i].y-red[j].y));   
                     m=max(d,m);        
             }
        }
        
        printf("%.0lf\n",m);
    }
    return 0;
}
