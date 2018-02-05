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

char notes[][3] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", 
                   "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

int size[] = {1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2,
              1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2};

map<string, bool> major, minor;

void init()
{
    int x, y, z; 
    string w;
    for(int i = 0; i < 12; ++i)
    {
        //major cord
        x = i, y = x + 4, z = x + 7;
        w = string(notes[x], notes[x] + size[x]) + " " +
            string(notes[y], notes[y] + size[y]) + " " +
            string(notes[z], notes[z] + size[z]);
        major[w] = 1;
        
        //minor cord
        x = i, y = x + 3, z = x + 7;
        w = string(notes[x], notes[x] + size[x]) + " " +
            string(notes[y], notes[y] + size[y]) + " " +
            string(notes[z], notes[z] + size[z]);
        minor[w] = 1;
        //cout << w << endl;
    }
}

string bemol_to_sharp(string bemol)
{   
    if(bemol[0] == 'A')return "G#";
    stringstream ss;
    ss << (char)(bemol[0] - 1);
    ss << "#";
    return ss.str();
}

int main()
{
    init();
    vector<string> v(3);
    while(cin >> v[0] >> v[1] >> v[2])
    {
        string total = v[0] + " " + v[1] + " " + v[2];
        v[0][0] = toupper(v[0][0]);
        v[1][0] = toupper(v[1][0]);
        v[2][0] = toupper(v[2][0]);

        if(v[0][1] && v[0][1] == 'b')
           v[0] = bemol_to_sharp(v[0]);
        if(v[1][1] && v[1][1] == 'b')
           v[1] = bemol_to_sharp(v[1]);
        if(v[2][1] && v[2][1] == 'b')
           v[2] = bemol_to_sharp(v[2]);
        
        //cout << v[0] << " " << v[1] << " " << v[2] << endl;
        
        sort(v.begin(), v.end());
        int f = 0;
        string t, start;
        do
        {
            start = v[0];   
            t = v[0] + " " + v[1] + " " + v[2];
            if(major[t]) f = 1;
            if(minor[t]) f = 2;
        }while(next_permutation(v.begin(), v.end()) && !f);
        
        if(f == 1)
           printf("%s is a %s Major chord.\n", total.c_str(), start.c_str());
        else if(f == 2)
           printf("%s is a %s Minor chord.\n", total.c_str(), start.c_str());
        else
           printf("%s is unrecognized.\n", total.c_str());
        
        
    }
    return 0;
}
