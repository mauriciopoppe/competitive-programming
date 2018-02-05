#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int cases=1;
    while(1)
    {
         int a,b;
         vector<int> v,c;
         cin>>a;
         if(a<0)break;
         
         v.push_back(a);
         c.push_back(1);
         while(1)
         {
             cin>>b;        
             if(b<0)break;        
             v.push_back(b);
             c.push_back(1);
         }
         int max=1;
         for(int i=0;i<v.size()-1;i++)
            for(int j=i+1;j<v.size();j++)
               if(v[j]<=v[i])
                  if(c[i]+1>c[j])
                    {
                    c[j]=c[i]+1;
                    if(c[j]>max)max=c[j];}

         if(cases != 1) cout<<endl;
         printf("Test #%d:\n",cases++);
         printf("  maximum possible interceptions: %d\n",max);         
    }    
}
