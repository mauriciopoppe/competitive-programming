#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<functional>
#include<numeric>
#include<utility>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define NL printf("\n")
typedef long long LL;

string get(int a)
{
      string res="";
      int w=a/13;
      switch(w)
      {
           case 0:res+="C";break;    
           case 1:res+="D";break;
           case 2:res+="S";break;
           case 3:res+="H";break;
      }
      w=a%13;
      switch(w)
      {
           case 0:res+="2";break;    
           case 1:res+="3";break;
           case 2:res+="4";break;
           case 3:res+="5";break;
           case 4:res+="6";break;
           case 5:res+="7";break;
           case 6:res+="8";break;
           case 7:res+="9";break;
           case 8:res+="T";break;
           case 9:res+="J";break;
           case 10:res+="Q";break;
           case 11:res+="K";break;
           case 12:res+="A";break;                      
      }
      return res;
}

int main()
{
    string from,f,s;
    map<char,int> m;
    m['C']=0;
    m['D']=1;
    m['S']=2;
    m['H']=3;
    
    m['2']=0;
    m['3']=1;
    m['4']=2;
    m['5']=3;
    m['6']=4;
    m['7']=5;
    m['8']=6;
    m['9']=7;
    m['T']=8;
    m['J']=9;
    m['Q']=10;
    m['K']=11;
    m['A']=12;
    while(1)
    {
        cin>>from;
        if(from=="#")break;    
        int start=-1;
        switch(from[0])
        {
             case 'N':start=0;break;
             case 'E':start=1;break;
             case 'S':start=2;break;
             case 'W':start=3;break;                           
             
        }
        cin>>f>>s;
        vector<vector<int> > v;
        v.resize(4);
        F(i,26)
        {
            start=(start+1)%4;    
            v[start].PB(m[f[i*2]]*13+m[f[i*2+1]]);
            //printf("%c%c %d\n",f[i*2],f[i*2+1],m[f[i*2]]*13+m[f[i*2+1]]);
        }
        
        F(i,26)
        {
            start=(start+1)%4;
            v[start].PB(m[s[i*2]]*13+m[s[i*2+1]]);           
        }
        
        F(i,4)sort(ALL(v[i]));
        
        int f=0;
        printf("S: ");
        F(i,13)
        {
            if(f)printf(" ");   
            cout<<get(v[2][i]);
            f=1;
        }   
        NL;
        f=0;
        printf("W: ");
        F(i,13)
        {
            if(f)printf(" ");   
            cout<<get(v[3][i]);
            f=1;
        }   
        NL;
        f=0;
        printf("N: ");
        F(i,13)
        {
            if(f)printf(" ");   
            cout<<get(v[0][i]);
            f=1;
        }   
        NL;
        f=0;
        printf("E: ");
        F(i,13)
        {
            if(f)printf(" ");   
            cout<<get(v[1][i]);
            f=1;
        }  
        NL; 

    }
    return 0;
}
