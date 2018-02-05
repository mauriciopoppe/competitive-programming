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

map<string, double> m;

void init()
{
     m["UTC"] = 0;
     m["GMT"] = 0;
     m["BST"] = 1;
     m["IST"] = 1;
     m["WET"] = 0;
     m["WEST"] = 1;
     m["CET"] = 1;
     m["CEST"] = 2;
     m["EET"] = 2;
     m["EEST"] = 3;
     m["MSK"] = 3;
     m["MSD"] = 4;
     m["AST"] = -4;
     m["ADT"] = -3;
     m["NST"] = -3.5;
     m["NDT"] = -2.5;
     m["EST"] = -5;
     m["EDT"] = -4;
     m["CST"] = -6;
     m["CDT"] = -5;
     m["MST"] = -7;
     m["MDT"] = -6;
     m["PST"] = -8;
     m["PDT"] = -7;
     m["HST"] = -10;
     m["AKST"] = -9;
     m["AKDT"] = -8;
     m["AEST"] = 10;
     m["AEDT"] = 11;
     m["ACST"] = 9.5;
     m["ACDT"] = 10.5;
     m["AWST"] = 8;
}

void solve(int initial_time, double diff)
{
     int new_diff = (int)(60 * diff);
     initial_time += new_diff;
     initial_time %= 1440;
     
     if(initial_time < 0)
        initial_time += 1440;
     
     if(initial_time == 0)
        puts("midnight");
     else if(initial_time == 720)
        puts("noon");
     else
     {
         string type = "";
         if(initial_time < 720)
            type = "a.m.";
         else
            type = "p.m.", initial_time -= 720;
         int hour = initial_time / 60;
         if(hour == 0)
            hour = 12;
         printf("%d:%02d %s\n", hour, initial_time % 60, type.c_str());         
     }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    init();
    string from, to;
    string date, type;
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        cin >> date;
        if(isdigit(date[0]))
           cin >> type;
        cin >> from >> to;
        
        int initial_time;
        int hour, min;
        if(isdigit(date[0]))
        {
            sscanf(date.c_str(), "%d:%d", &hour, &min);
            if(hour == 12)
               hour = 0;
            initial_time = hour * 60 + min + (type[0] == 'p' ? 720 : 0);            
        }
        else if(date[0] == 'n')
            initial_time = 720;
        else
            initial_time = 0;
                
        double diff = m[to] - m[from];
        //printf("%d %.2lf\n", initial_time, diff);
        solve(initial_time, diff);                  
    }
    return 0;
}
