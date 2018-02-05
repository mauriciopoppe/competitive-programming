#include<iostream>
#include<algorithm>
#define M 10001
using namespace std;

int num[M],val[M],inc[M],de[M],next[M];

int main()
{
    int n,c;
    cin>>n;
    for(int q=1;q<=n;q++)    
    {
        cin>>c;
        for(int i=0;i<c;i++)
           cin>>num[i];
        
        int maxI=0,maxD=0;
        
        for(int i=0;i<c;i++)
           {
                cin>>val[i];
                de[i]=inc[i]=val[i];
                if(val[i]>maxI)maxI=maxD=val[i];
           }   
        
        for(int i=0;i<c-1;i++)
        {
           for(int j=i+1;j<c;j++)
              {
                   if(num[j]>num[i] && inc[i]+val[j]>inc[j])
                   {
                         inc[j]=inc[i]+val[j];           
                         if(inc[j]>maxI)maxI=inc[j];           
                   }
                   if(num[j]<num[i] && de[i]+val[j]>de[j])
                   {
                         de[j]=de[i]+val[j];           
                         if(de[j]>maxD)maxD=de[j];                  
                   }
              }
        }
       if(maxI>=maxD)printf("Case %d. Increasing (%d). Decreasing (%d).\n",q,maxI,maxD); 
       else printf("Case %d. Decreasing (%d). Increasing (%d).\n",q,maxD,maxI);           
    }
}
