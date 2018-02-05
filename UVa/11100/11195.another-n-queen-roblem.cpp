/*
 * Author: mauricio
 * Date: Mar 6, 2012
 * Problem: 11195 Another n-Queen Problem.cpp
 */
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
#define N 20
char not_allowed[N][N];
int queens_already_placed[N];
int board_size;
int total_solutions;

int generate_candidate_elements(int queens_already_placed[], int candidates[], int current_row)
{
    int i, j = 0, number_of_candidates = 0;
    //start checking all the columns (total_columns = board_size) for the current row
    for(i = 0; i < board_size; i++)
    {
    	//let's assume that the position for this new queen
    	//row = current_row and column = column is valid
    	bool is_valid = true;

    	//do not take if *
    	if(not_allowed[current_row][i] == '*')
    		continue;

    	//check if the position is valid with the queens already placed
    	for(j = 0; j < current_row && is_valid;j++)
             if(abs(j - current_row) == abs(i - queens_already_placed[j]) // check diagonal
            		 ||   //or
            	i == queens_already_placed[j])  // check same column
            	 	 is_valid = false;
          if(is_valid) 	//if the current position is valid add it to the candidates
        	  candidates[number_of_candidates++]=i;
    }
    return number_of_candidates;
}

void backtrack(int current_row)
{
     if(current_row == board_size)
         ++total_solutions;
     else
     {
          int candidates[N];
          int number_of_candidates =
        		  generate_candidate_elements(queens_already_placed, candidates, current_row);
          for(int i = 0; i < number_of_candidates; ++i)
          {
        	  //take next candidate
              queens_already_placed[current_row] = candidates[i];
              backtrack(current_row + 1);
          }
     }
}

int main()
{
	int cas = 1;
	while(scanf("%d", &board_size) && board_size)
	{
		gets(not_allowed[0]);
		for(int i = 0; i < board_size; ++i)
			gets(not_allowed[i]);
		total_solutions = 0;
		backtrack(0);
		printf("Case %d: %d\n", cas++, total_solutions);
	}
	return 0;
}
