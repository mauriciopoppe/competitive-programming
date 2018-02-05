#include<iostream>
#include<bitset>
using namespace std;
bitset<3001> b;

int main()
{
    int n,a,t;
    while(cin>>n)    
    {
        b.reset();
        cin>>a;
        for(int i=1;i<n;i++)
        {
                cin>>t;
                int x=a-t>=0?a-t:t-a;
                b.set(x);
                a=t;        
        }                   
        
        bool f=true;
        for(int i=1;i<=n-1;i++)
           if(!b.test(i)){f=false;break;}
        
        if(f)printf("Jolly\n");
        else printf("Not jolly\n");    
    }
}
