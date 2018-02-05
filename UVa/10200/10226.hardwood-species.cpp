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
    
    string c;
    scanf("%d",&n);
    getchar();
    getchar();
    for(int q=0;q<n;q++)
    {
        if(q)printf("\n");    
        map<string,int> m;    
        int t=0;
        while(getline(cin,c) && c.size()>0)          
        {
            //printf("%d ---here\n",strlen(c));                
            m[c]++;               
            t++;               
        }  
        
        for(map<string,int>::iterator i=m.begin();i!=m.end();i++)
             printf("%s %.4lf\n",i->first.c_str(),(double)((double)i->second/(double)t)*100);             
    }
    return 0;
}
