/*************************************************************************
 * Copyright (C) 2008 by liukaipeng                                      *
 * liukaipeng at gmail dot com                                           *
 *************************************************************************/
/* @JUDGE_ID 00000 10044 C++ "Erdos Number" */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <limits>
using namespace std;
void get_authors(vector<string> const& papers, 
                 vector<vector<size_t> >& authors,
                 map<string, size_t>&namelist)
{
  for (int i = 0; i < papers.size(); ++i) {
    string const&p = papers[i];
    for (int fb, fe = 0, lb, le = 0; p[fe] != ':' && p[le] != ':'; ) {
      fb = p.find_first_not_of(" ,", le);
      fe = p.find_first_of(" ,:", fb);
      lb = p.find_first_not_of(" ,", fe);
      le = p.find_first_of(" ,:", lb);
      if (fb == string::npos || fe == string::npos || 
          lb == string::npos || le == string::npos) {
        break;
      }
      string name = p.substr(fb, fe-fb) + ", " + p.substr(lb, le-lb);
      map<string, size_t>::iterator it = namelist.find(name);
      if (it == namelist.end()) {
        it = namelist.insert(it, make_pair(name, namelist.size()));
      }
      authors[i].push_back(it->second);
    }
  }
}
void get_coauthors(vector<vector<size_t> > const& authors,
                   vector<vector<size_t> >& coauthors)
{
  for (int i = 0; i < authors.size(); ++i) {
    vector<size_t> const& a = authors[i];
    if (a.empty()) {
      continue;
    }
    for (int a1 = 0; a1 < a.size() - 1; ++a1) {
      for (int a2 = a1 + 1; a2 < a.size(); ++a2) {
        coauthors[a[a1]].push_back(a[a2]);
        coauthors[a[a2]].push_back(a[a1]);
      }
    }
  }
}
void get_erdos_numbers(vector<vector<size_t> > const& coauthors, 
                       vector<int>& erdos_numbers, size_t s)
{
  vector<bool> visited(coauthors.size());
  queue<pair<size_t, int> > q;
  size_t v = s;
  int d = 0;
  q.push(make_pair(v, d));
  visited[v] = true;
  while (!q.empty()) {
    s = q.front().first;
    d = q.front().second;
    q.pop();
    erdos_numbers[s] = d;
    for (int i = 0; i < coauthors[s].size(); ++i) {
      v = coauthors[s][i];
      if (!visited[v]) {
        q.push(make_pair(v, d+1));
        visited[v] = true;
      }
    }
  }
}
void put_erdos_numbers(vector<string> const& names,
                       map<string, size_t> const& namelist, 
                       vector<int> const& erdos_numbers)
{
  for (int i = 0; i < names.size(); ++i) {
    if (!names[i].empty()) {
      map<string, size_t>::const_iterator it = namelist.find(names[i]);
      if (it != namelist.end() && erdos_numbers[it->second] != -1) {          
        cout << names[i] << " " << erdos_numbers[it->second] << "\n";
      } else {
        cout << names[i] << " infinity\n";
      }
    } else {
      cout << "\n";
    }
  }
}
int main(int argc, char *argv[])
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

  int scenarios;
  cin >> scenarios;
  for (int s = 1; s <= scenarios; ++s) {
    int p, n;
    cin >> p >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> papers(p);
    for (int i = 0; i < p; ++i) {
      getline(cin, papers[i]);
    }
    map<string, size_t> namelist; /* map author name to author id */
    vector<vector<size_t> > authors(p); 
    get_authors(papers, authors, namelist);
    vector<vector<size_t> > coauthors(namelist.size());
    get_coauthors(authors, coauthors);
    vector<int> erdos_numbers(namelist.size(), -1);
    map<string, size_t>::const_iterator it = namelist.find("Erdos, P.");
    get_erdos_numbers(coauthors, erdos_numbers, it->second);
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, names[i]);
    }
    cout << "Scenario " << s << "\n";
    put_erdos_numbers(names, namelist, erdos_numbers);
  }
  return 0;
}
