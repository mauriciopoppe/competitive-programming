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
int vote[101][10];
int valid[101];
int level[101];
int c[10];
int valid_candidate[10];
int main()
{
    int candidates, n_votes;
    int cas = 1;
    while(scanf("%d%d", &candidates, &n_votes) && candidates + n_votes != 0)
    {
        int total_valid = n_votes;
        int total_candidates = candidates;
        memset(valid, 1, sizeof valid);
        for(int i = 0; i < n_votes; ++i)
        {
            bool b[candidates + 10];
            memset(b, 0, sizeof b);
            for(int j = 0; j < candidates; ++j)
               scanf("%d", &vote[i][j]);
            
            for(int j = 0; j < candidates; ++j)
               if(vote[i][j] < 1 || vote[i][j] > candidates || b[vote[i][j]]) 
                  valid[i] = 0;
               else
                  b[vote[i][j]] = 1;
            
            if(!valid[i]) --total_valid;
        }
        //printf("%d\n", total_valid);
        int votes_to_win = total_valid / 2 + 1;
        memset(level, 0, sizeof level);
        memset(valid_candidate, 1, sizeof valid_candidate);
        vector<int> in_tie;
        int win = 0, tie = 0;
        while(1)
        {
            memset(c, 0, sizeof c);
            for(int i = 0; i < n_votes; ++i)
               if(valid[i])
                  ++c[vote[i][level[i]]];
            
            //check win
            for(int i = 1; i <= total_candidates; ++i)
               if(valid_candidate[i] && c[i] >= votes_to_win)
               {
                  win = i;
                  break;
               }
            if(win)break;
            
            //check tie
            if(total_valid % candidates == 0)
            {
                in_tie.clear();
                int votes_to_tie = total_valid / candidates;
                int i = 1;
                for(i = 1; i <= total_candidates; ++i)
                   if(valid_candidate[i])
                   {
                      if(c[i] != votes_to_tie)
                         break;
                      else
                         in_tie.push_back(i);
                   }
                         
                if(i > total_candidates)
                {
                   tie = 1;         
                   break;
                }
            }
            
            //kill the loser
            int loser = -1, votes = 999999999;
            for(int i = 1; i <= total_candidates; ++i)
               if(valid_candidate[i])
                  if(c[i] < votes)
                     loser = i, votes = c[i];
            
            //printf("%d %d\n", loser, votes);
            valid_candidate[loser] = 0;
            --candidates;
            for(int i = 0; i < n_votes; ++i)
               if(valid[i] && vote[i][level[i]] == loser)
               {
                  ++level[i];
                  if(level[i] == total_candidates)
                     valid[i] = 0, --total_valid;
               }
        }
        printf("Election #%d\n", cas++);
        if(total_valid != n_votes)
           printf("   %d bad ballot(s)\n", n_votes - total_valid);
        
        if(win)
           printf("   Candidate %d is elected.\n", win);
        else if(tie)
        {
           printf("   The following candidates are tied:");
           TR(in_tie, it)
              printf(" %d", *it);
           NL;
        }
    }
    return 0;
}
