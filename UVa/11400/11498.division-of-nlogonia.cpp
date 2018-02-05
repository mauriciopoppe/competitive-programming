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
    int n;
    while(1)
    {
        cin>>n;
        if(!n)break;
        int cx,cy,x,y;
        cin>>cx>>cy;
        
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            x-=cx;
            y-=cy;
            
            if(!x || !y)printf("divisa\n");
            else if(x>0){
                 if(y>0)printf("NE\n");
                 else printf("SE\n");
                 }
            else
            {
                      if(y>0)printf("NO\n");
                      else printf("SO\n");
            }
        }        
    }
    return 0;
}
