#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<sstream>
using namespace std;

int main()
{
    int h,m,s,cc,sum;
    string w;
    double res;
    while(getline(cin,w,'\n'))
    {
         h=atoi(w.substr(0,2).c_str());
         m=atoi(w.substr(2,2).c_str());
         s=atoi(w.substr(4,2).c_str());
         cc=atoi(w.substr(6,2).c_str());  
         //printf("%d %d %d %d\n",h,m,s,cc);                        
         
         sum=(s+m*60+h*3600)*100+cc;
         res=(sum*125.0)/108.0;         
         printf("%07d\n",int(res));
    }
    return 0;
}
