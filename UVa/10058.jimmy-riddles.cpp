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
map<string, bool> noun;
map<string, bool> verb;
vector<vector<string> > action;
vector<string> split(string &w, string &del)
{
     vector<string> token;
     if(w[w.size() - 1] == ',')
        token.push_back("");
     int pos;
     while((pos = w.find_first_of(del)) != w.npos)
     {
         token.push_back(w.substr(0, pos));
         w = w.substr(pos + 1);       
     }
     if(w.size())
         token.push_back(w.substr(0));
     return token;       
}

vector<vector<string> > get_tokens(vector<string> &s)
{
    int i = 0;
    int size = s.size();
    vector<vector<string> > token(size);
    F(j, size)
    {
        stringstream ss(s[j]);
        string buf;
        while(ss >> buf)
             token[i].push_back(buf);    
        ++i;
    } 
    return token;
}

int check_actor(int &i, int start, int end)
{
    if(start > end)
       return 0;
    if(start == end)
       return noun[action[i][start]];
    if(start + 1 == end)    
    {
        //printf("%s %s %d\n",action[i][start].c_str(),action[i][end].c_str(), noun[action[i][end]]);
       return (action[i][start] == "a" || action[i][start] == "the") && 
               noun[action[i][end]];
    }
    return 0;
}

int check_active(int &i, int start, int end)
{
    //split by "and"
    int f = 1;
    int k;
    int from = start;
    int size = action[i].size();
    for(k = start; k <= end && f; ++k)
    {
         if(action[i][k] == "and")
         {                         
              //printf("%d %d %d\n",from,k-1,check_actor(i, from, k - 1));                     
              f = check_actor(i, from, k - 1);
              from = k + 1;         
         }
    }
    if(f)
        f = check_actor(i, from, end);
    return f;
}

int is_verb(string &w)
{
    TR(verb, it)
    {
        if(w.size() >= 4 && w.find(it->first) == 0)
        {
            int i;        
            for(i = 4; w[i]; ++i)
                if(w[i] != 's') 
                   break;
            if(!w[i])       
               return 1;
        }
    }
    return 0;
}

int check_action(int &i)
{
    int size = action[i].size();
    int pos = -1;
    int cnt = 0;
    for(int j = 0; j < size; ++j)
       if(is_verb(action[i][j]))
          pos = j, ++cnt;
    
    if(cnt != 1 || pos == size - 1 || pos == 0)
       return 0;
    
    //printf("[%s]\n",action[i][pos].c_str());
    //printf("%d %d  -  %d %d\n", 0,pos - 1, pos +1 , size - 1);
    return check_active(i, 0, pos - 1) && check_active(i, pos + 1, size - 1);
}

int solve()
{
    int f = 1;
    int size = action.size();
    for(int i = 0; i < size && f; ++i)
        f = check_action(i);
    return f;
}

int main()
{
    noun["tom"] = noun["jerry"] = noun["goofy"] = noun["mickey"] = 
    noun["jimmy"] = noun["dog"] = noun["cat"] = noun["mouse"]  = 1;
    verb["hate"] = verb["love"] = verb["know"] = verb["like"] = verb["VERB"] = 1;
    //verb["hates"] = verb["loves"] = verb["knows"] = verb["likes"] = verb["VERBs"] = 1;
    string w;
    string comma = ",";
    while(getline(cin, w))
    {
         vector<string> s = split(w, comma);
         action = get_tokens(s);
         /*TR(action, it)
         {
             int size = (*it).size();
            F(i,size)
               printf("[%s] ",(*it)[i].c_str());        
            NL;        
         }*/
         if(w.size() && solve())
            printf("YES I WILL\n");
         else
            printf("NO I WON'T\n");
    }
    return 0;
}
