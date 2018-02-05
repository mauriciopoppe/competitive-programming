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

struct word{
       string w;
       int sd;
       word(string a, int b):w(a),sd(b){}
       bool operator<(const word x)const
            {
                    if(sd<x.sd)return true;
                    else return false;       
            }
       };

int main()
{
    int n;
    cin>>n;
    for(int q=0;q<n;q++)
    {
        vector<word> p;   
        if(q)printf("\n");
        int r,c;
        string s;
        scanf("%d%d",&c,&r);
        for(int i=0;i<r;i++)
        {
            cin>>s;    
            int cc=0;
            for(int j=0;j<c-1;j++)
                for(int k=j+1;k<c;k++)        
                    if(s[j]>s[k])cc++;
            p.push_back(word(s,cc));
        }        
        
        stable_sort(p.begin(),p.end());
        for(int i=0;i<r;i++)
             cout<<p[i].w<<endl;        
    }
    return 0;
}
