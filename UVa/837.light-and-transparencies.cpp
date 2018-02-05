#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
using namespace std;

struct point{
       double x1,x2,v;
       point(double a,double b,double z){x1=a;x2=b;v=z;}
       };

int main()
{
    int n;
    cin>>n;
    for(int q=0;q<n;q++)
    {
        if(q!=0)printf("\n");
        vector<point> v;
        set<double> aux;
        
        int p;
        double x1,y1,x2,y2,t;
        cin>>p;
        for(int i=0;i<p;i++)
        {
                cin>>x1>>y1>>x2>>y2>>t;     
                if(x1==-0)x1=0;
                if(x2==-0)x2=0;
                aux.insert(x1);
                aux.insert(x2);
                if(x1<x2)v.push_back(point(x1,x2,t));
                else v.push_back(point(x2,x1,t));                
        }            
        
        vector<double> inX(aux.size());
        copy(aux.begin(),aux.end(),inX.begin());
        sort(inX.begin(),inX.end());
        
        printf("%d\n",aux.size()+1);
        printf("-inf %.3lf 1.000\n",inX[0]);
        for(int j=1;j<inX.size();j++)
        {
                double res=1.0;
                for(int k=0;k<v.size();k++)
                   {
                       if(inX[j]>v[k].x1 && inX[j]<=v[k].x2)
                          res*=v[k].v;                       
                   }
                printf("%.3lf %.3lf %.3lf\n",inX[j-1],inX[j],res);        
        }
        printf("%.3lf +inf 1.000\n",inX[inX.size()-1]);
            
    }
    return 0;
}
