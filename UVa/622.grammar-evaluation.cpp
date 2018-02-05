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
vector<string> polish;
map<char, int> pre;

int get_value()
{
    int size = polish.size();
    stack<int> st;
    int x, y;
    for(int i = 0; i < size; ++i)    
    {
        if(!isdigit(polish[i][0]))
        {
            x = st.top(), st.pop();
            y = st.top(), st.pop();
            if(polish[i][0] == '+')
                st.push(x + y);
            else
                st.push(x * y);
        }
        else
            st.push(atoi(polish[i].c_str()));
    }
    return st.top();
}

int parse(vector<string> &token)
{
    int size = token.size(), n;
    char sas[14321];
    stack<string> st;
    if(size)
    {
       if(!isdigit(token[0][0]) && token[0] != "(")     
         return 0;
    }
    //printf
    for(int i = 0; i < size; ++i)
    {
        //printf("i = %d\n",i);    
        if(token[i][0] == ')')
        {
            if(i && (token[i - 1] == "+" || token[i - 1] == "*" || token[i - 1] == "("))
                return 0;                       
            while(st.size() && st.top() != "(")
               polish.push_back(st.top()), st.pop(); 
            if(!st.size())
               return 0;
            st.pop();
        }
        else if(token[i][0] == '(')
        {
             if(i && (token[i - 1] != "+" && token[i - 1] != "*" && token[i - 1] != "("))
                return 0;
             st.push(token[i]);
        }
        else if(token[i][0] == '+' || token[i][0] == '*')
        {
            if(i && (token[i - 1] == "+" || token[i - 1] == "*" || token[i - 1] == "("))
                return 0; 
            while(st.size() && pre[token[i][0]] < pre[st.top()[0]])
               polish.push_back(st.top()), st.pop();
            st.push(token[i]);
        }
        else if(sscanf(token[i].c_str(),"%d%s",&n,sas) && !strlen(sas))
        {
            //printf("here"); 
            if(i && (token[i - 1] != "+" && token[i - 1] != "*" && token[i - 1] != "("))
                return 0;
            int parse_int = sscanf(token[i].c_str(),"%d",&n);
            if(parse_int == 0)
               return 0;
            polish.push_back(token[i]);            
        }  
        else return 0;
    }
    while(st.size())
    {
        if(st.top() == "(")
           return 0;
        polish.push_back(st.top()), 
        st.pop(); 
    }
    return 1;
}

vector<string> split(string &w)
{
     string del = " ()*+";
     int pos;
     vector<string> sp;
     while((pos = w.find_first_of(del)) != w.npos)
     {          
          //printf("%c\n",w[pos]);
          if(pos)
             sp.push_back(w.substr(0, pos));
          while(w[pos] && !isdigit(w[pos]) && w[pos] != ' ')
          {
              string k = string(w.begin() + pos, w.begin() + pos + 1);
              sp.push_back(k);
              ++pos;
          }
          if(w[pos] == ' ')
             w = w.substr(pos + 1);
          else
             w = w.substr(pos);
     }
     if(w.size())
        sp.push_back(w);
     return sp; 
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    pre['*'] = 2;
    pre['+'] = 1;
    
    string w;
    int cas;
    scanf("%d",&cas);
    getchar();
    while(cas--)    
    {
        getline(cin, w);            
        vector<string> tokens = split(w);
        //TR(tokens,it)
        //    printf("[%s]\n",(*it).c_str());
        polish.clear();
        //printf("here");
        if(parse(tokens) && tokens.size())
        {
            //TR(polish, it)
            //  printf("[%s]\n",(*it).c_str());
            printf("%d\n",get_value());
        }
        else
            printf("ERROR\n"); 
    }
    return 0;
}
