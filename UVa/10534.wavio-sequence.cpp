#include<iostream>
#include<algorithm>
#include<vector>
#define min(a,b) (a<b?a:b)
using namespace std;

void LIS(vector<int> &a, vector<int> &ans)
{
     vector<int> b(a.size());
     b[0]=a[0];
     ans[0]=1;
     int n=1;
     
     for(int i=1;i<a.size();i++)
     {
          int l=(int)(lower_bound(b.begin(),b.begin()+n,a[i])-b.begin());
          //system("pause");

          if(l==n)
              b[n++]=a[i];
          else
              b[l]=a[i];
          ans[i]=l+1;
     }     
}

int main()
{
    int n;
    while(cin>>n)
    {
         vector<int> a(n);        
         for(int i=0;i<n;i++)
            cin>>a[i];
         
         vector<int> inc(n),dec(n);
         LIS(a,inc);
        
         reverse(a.begin(),a.end());
         LIS(a,dec);
         
         reverse(dec.begin(),dec.end());
         
         //printf("dec last=%d\n",de[n-1]);
         int mx=1;
         for(int i=0;i<n;i++)
             mx=max(mx,min(dec[i],inc[i]));
         
         printf("%d\n",mx*2-1);
    }        
}
