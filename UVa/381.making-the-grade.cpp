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
int score[35][15];
int bonus[35], abst[35];
double st_avg[35];
char grade[35];
int main()
{
    int cas;
    int st, exams;
    scanf("%d", &cas);
    puts("MAKING THE GRADE OUTPUT");
    while(cas--)
    {
        scanf("%d%d", &st, &exams);
        for(int i = 0; i < st; ++i)
        {
            for(int j = 0; j < exams; ++j)
               scanf("%d", &score[i][j]);
            sort(score[i], score[i] + exams, greater<int>());
            scanf("%d%d", &bonus[i], &abst[i]);
        }
        
        if(exams > 2)
           --exams;
        double mean = 0, sd;
        for(int i = 0; i < st; ++i)
        {
            st_avg[i] = 0;
            for(int j = 0; j < exams; ++j)
               st_avg[i] += score[i][j],
               mean += score[i][j];
            st_avg[i] /= exams;
        }
        mean /= (double)(exams * st);
        
        double sum = 0;
        for(int i = 0; i < st; ++i)
           sum += (st_avg[i] - mean) * (st_avg[i] - mean);
        sd = sqrt(sum / (double)(st));
        if(sd < 1) sd = 1.0;
        //printf("%lf %lf\n", mean, sd);
        
        //adjust average
        for(int i = 0; i < st; ++i)
           st_avg[i] += (bonus[i] / 2) * 3;
        
        //calc grade
        for(int i = 0; i < st; ++i)
           if(st_avg[i] >= sd + mean) grade[i] = 'A';
           else if(st_avg[i] >= mean) grade[i] = 'B';
           else if(st_avg[i] >= mean - sd) grade[i] = 'C';
           else grade[i] = 'D';
        
        for(int i = 0; i < st; ++i)
           if(abst[i] == 0)
           {
               if(grade[i] != 'A')
                  grade[i]--;
           }
           else
           {
               int sub = abst[i] / 4;
               grade[i] += sub;
               if(grade[i] > 'F') 
                  grade[i] = 'F';
           }
        
        double avg_grade = 0;
        for(int i = 0; i < st; ++i)
           avg_grade += 4 - (grade[i] - 'A');
        printf("%.1lf\n", avg_grade / (double) st);
    }
    puts("END OF OUTPUT");
    return 0;
}
