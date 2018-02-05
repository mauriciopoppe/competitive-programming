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

struct single_map{
       int from, to, value;
};

int k, size;
map<string, int> map_names;
vector<string> names(1);
vector<single_map> record;
vector<int> available(1);

int wc_match(const char *text, const char *pattern)
{
    if(!*text && !*pattern) return 1;
    if(!*text || !*pattern) return 0;
    if(*text == '*')
       return wc_match(text, pattern + 1) || wc_match(text + 1, pattern + 1) || wc_match(text + 1, pattern);
    else
       return *text == *pattern && wc_match(text + 1, pattern + 1);
}

int add_to_map(string &address)
{
    if(map_names[address])
       return map_names[address];
    else
    {
       map_names[address] = k++;
       names.push_back(address);
       available.push_back(1);
       return k - 1;
    }    
}

string find_string_of(int i)
{    
    return names[i];
}

int try_to_find(string &translate)
{
    for(int i = 1; i < size; ++i)
       if(translate == names[i]) 
          return i;
    return 0;   
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    string line, address, str_value, alias;
    int val;
    single_map r;
    
    scanf("%d", &cas);
    getline(cin, line);
    
    k = 1;
    for(int i = 0; i < cas; ++i)
    {
        getline(cin, line);
        if(line[0] == ' ')
        {
            stringstream ss(line);
            ss >> str_value;
            val = atoi(str_value.c_str());
            ss >> alias;
            
            //add record
            r.from = add_to_map(address);
            r.to = add_to_map(alias);
            r.value = val;
            
            record.push_back(r);
        }
        else
        {
            stringstream ss(line);
            ss >> address;
            ss >> str_value;
            val = atoi(str_value.c_str());
            ss >> alias;
            
            //add record
            r.from = add_to_map(address);
            r.to = add_to_map(alias);
            r.value = val;
            
            record.push_back(r);
        }
    }
    size = names.size();
    char op[5];
    string translate;
    while(scanf("%s", op) && op[0] != 'X')
    {
        cin >> translate;
        if(op[0] == 'A')
        {
            int best = 999999999, i = -1;
            printf("%s =>", translate.c_str());
            for(int j = 1; j < size; ++j)
            {
                if(available[j] && wc_match(names[j].c_str(), translate.c_str()))
                {
//                    printf
                    TR(record, it)
                        if(it->from == j && available[it->to] && it->value < best)
                             best = it->value, i = it->to;
                }
            }
            if(best != 999999999)
                   printf(" %s", find_string_of(i).c_str());
            NL;                
        }
        
        else if(op[0] == 'D')
        {
            int from_value = try_to_find(translate);
            //printf("%d\n", from_value);
            if(from_value) 
               available[from_value] = 0;
        }
        else if(op[0] == 'U')
        {
            int from_value = try_to_find(translate);
            if(from_value) 
               available[from_value] = 1;
        }
    }
    return 0;
}
