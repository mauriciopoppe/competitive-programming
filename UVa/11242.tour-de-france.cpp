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

int main()
{
    int a[20],b[20];
    int f,r;
    vector<double> v;
    while(cin>>f && f)
    {
         cin>>r;
         v.clear();             
         for(int i=0;i<f;i++)
            scanf("%d",&a[i]);        
         for(int i=0;i<r;i++)
            scanf("%d",&b[i]);
         for(int i=0;i<f;i++)
            for(int j=0;j<r;j++)
               v.push_back((double)a[i]/(double)b[j]);
         
         sort(v.begin(),v.end());
         double max=0;
         for(int i=1;i<v.size();i++)
                 if(v[i]/v[i-1]>max)max=v[i]/v[i-1];         
         printf("%.2lf\n",max);
    }
    return 0;
}
