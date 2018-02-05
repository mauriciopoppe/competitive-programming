#include<iostream>
#include<bitset>
using namespace std;
bitset<3651> b;
int main()
{
    int t,n,p,d;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>p;
        b.reset();
        for(int i=0;i<p;i++)
        {
            cin>>d;
            for(int j=d;j<=n;j+=d)        
                b.set(j);
        }
        p=0;
        for(int i=0;i<=n;i++)
        {
           if(i%7!=6 && i%7!=0)
               if(b.test(i))p++;               
        }     
        cout<<p<<endl;          
    }       
}
