#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map < string, vector < pair < int, string > > > data, datax;

int main(){
    
    string s, a, b;
    int n, p; cin >> n; getline(cin, s);
    while(n-- && getline(cin, s)){
   istringstream sin(s);
   if(isspace(s[0])) sin >> p >> b;
   else sin >> a >> p >> b;
   if(a[0] == '*') datax[a.substr(1)].push_back(make_pair(p, b));
   else data[a].push_back(make_pair(p, b));
    }
    
    set < string > down;
    while(cin >> a >> b && a != "X")
   if(a == "D") down.insert(b);
   else if(a == "U") down.erase(b);
   else if(a == "A"){
       cout << b << " => ";
       vector < pair < int, string > > all;
       if(data.count(b)) all = data[b];
       for(int i = 0; i <= (int)b.size(); i++)
      if(datax.count(b.substr(i))){
          vector < pair < int, string > > &add = datax[b.substr(i)];
          for(int i = 0; i < (int)add.size(); i++)
         all.push_back(add[i]);
      }
       sort(all.begin(), all.end());
       string ans = "";
       for(int i = 0; i < (int)all.size(); i++)
      if(!down.count(all[i].second)){
          ans = all[i].second;
          break;
      }
       if(ans.size()) cout << ans;
       cout << endl;
   }
    

    return 0;
}
