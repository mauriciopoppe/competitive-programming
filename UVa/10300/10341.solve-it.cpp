#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#define E 0.0000001
using namespace std;

int p,q,r,s,t,u;
double f(double x)
{
       return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;       
}
double der(double x)
{
       return -p*exp(-x)+q*cos(x)-r*sin(x)+s/(cos(x)*cos(x))+2*t*x;  
}

double nr()
{
      if(f(0)==0)return 0;
      double val=0.5,n;
      while(1)
      {
           n=val-f(val)/der(val);
           if(fabs(val-n)<=E)return n;
           else val=n;           
      } 
}

int main()
{
    while (scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF)
    {
          if (f(0) * f(1) > 0)
             printf("No solution\n");
          else printf("%.4lf\n",nr());
    }
    return 0;
}
