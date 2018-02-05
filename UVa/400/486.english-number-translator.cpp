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
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    map<string,int> number;
    map<string,int> mult;
    number["zero"] = 0, number["one"] = 1, number["two"] = 2, number["three"] = 3, number["four"] = 4,
    number["five"] = 5, number["six"] = 6, number["seven"] = 7, number["eight"] = 8, number["nine"] = 9,
    number["ten"] = 10, number["eleven"] = 11, number["twelve"] = 12, number["thirteen"] = 13, number["fourteen"] = 14,
    number["fifteen"] = 15, number["sixteen"] = 16, number["seventeen"] = 17, number["eighteen"] = 18,
    number["nineteen"] = 19, number["twenty"] = 20, number["thirty"] = 30, number["forty"] = 40, number["fifty"] = 50,
    number["sixty"] = 60, number["seventy"] = 70, number["eighty"] = 80, number["ninety"] = 90;
    
    string w;
    while(getline(cin, w))
    {
        vector<string> s;
        stringstream ss(w);
        string buf;
        int million = -1, thousand = -1;
        int size = 0;
        while(ss>>buf)
        {
           if(buf == "million")
              million = size;
           else if(buf == "thousand")
              thousand = size;
           size++;
           s.push_back(buf);
        }
        int n = 0;
        int f = 0;
        int i = 0;
        if(s[0] == "negative")
           f = 1, i = 1;
        int temp = 0;
        int j = 1;
        
        if(million != -1)
        {
            for(;i < million; ++i)
            {
                if(number[s[i]])
                  temp += number[s[i]];
                else
                  temp *= 100;
            }
            n += temp * 1000000;
            temp = 0;
            i = million + 1;
        }
        
        if(thousand != -1)
        {
            for(;i < thousand; ++i)
            {
                if(number[s[i]])
                  temp += number[s[i]];
                else
                  temp *= 100;
            }
            n += temp * 1000;
            i = thousand + 1;  
            temp = 0;         
        }
        for(;i < size; ++i)
        {
            if(number[s[i]])
              temp += number[s[i]];
            else
              temp *= 100;
        }
        n += temp;
        printf("%s%d\n",f?"-":"",n);        
    }
    return 0;
}
