#include<iostream>
using namespace std;
int main()
{
    int h,d,f,day;
    double r,rf,u;
    while(1)
    {
        cin>>h>>u>>d>>f;
        if(h+u+d+f==0)break;        
        r=0;
        rf=f*u/100.0;
        day=0;
        while(1)
        {
            day++;
            if(u>=0)r+=u;
            if(r>h)break;
            r-=d;
            if(r<0)break;
            u-=rf;
        //    cout<<r<<"\n";
        }
        if(r>0) cout<<"success on day "<<day<<"\n";
        else cout<<"failure on day "<<day<<"\n";
    }    
return 0;   
}
