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

struct p{
       int a;
       string b;
       p(int x,string y){a=x;b=y;}
       bool operator<(p x)const{return x.a>a;}
       };
       
vector<p> v;

int main()
{
    string a,b,a1,b1;
    int n;
    cin>>n;
    getchar();
    getchar();
    for(int q=0;q<n;++q)
    {
            if(q)printf("\n");
            v.clear();
            getline(cin,a,'\n');
            getline(cin,b,'\n');
            
            stringstream ss(a),ss1(b);            
            while(ss>>a1 && ss1>>b1)
            {
                 int i=atoi(a1.c_str());
                 v.push_back(p(i,b1));        
            }
            sort(v.begin(),v.end());
            int l=v.size();
            for(int i=0;i<l;++i)
                printf("%s\n",v[i].b.c_str());        
            if(q!=n-1)getchar();
    }
    //system("pause");

    return 0;
}
