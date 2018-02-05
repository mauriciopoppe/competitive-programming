#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;
typedef long long LL;
LL sw=0;

void merge(int a[], int n)
{
     if(n<64)
     {
             for(int i=1,j;i<n;i++)
             {
                 int t=a[i];
                 for(j=i-1;j>=0 && a[j]>t;j--)
                    a[j+1]=a[j];
                 a[j+1]=t;
                 sw+=i-1-j;
             }
             return;
     }
     int f=n/2;
     merge(a,f);
     merge(a+f,n-f);
     
     int *s=new int[n];
     int i=0,j=f,k=0;
     for(;i<f&&j<n;)
        if(a[j]<a[i])
        { 
          s[k++]=a[j++];
          sw+=j-k;
        }
        else s[k++]=a[i++];
     
     while(i<f)s[k++]=a[i++];
     while(j<n)s[k++]=a[j++];
     
     //copy again
     for(int i=0;i<n;i++)
       a[i]=s[i];
       
     delete []s;
}

int main()
{
    int n;
    int a[100001];
    
    while(scanf("%d",&n) && n)
    {
          for(int i=0;i<n;i++)
             scanf("%d",&a[i]); 
             
          sw=0;                  
          merge(a,n);               
          if(sw&1)printf("Marcelo\n");
          else printf("Carlos\n");
    }
    
    /*
    ifstream in;
    ofstream out;
    in.open("in.txt");
    out.open("out.txt");
    while(in>>n && n)
    {             
        for(int j=0;j<n;j++)
        //      scanf("%d",&a[j]);
              in>>a[j];
        sw=0;
        merge(a,n);    
         
        //printf("%lld\n",c);                 
        out<<LL(sw)<<endl;
    }
    in.close();
    out.close();
    */
    
    return 0;
}
