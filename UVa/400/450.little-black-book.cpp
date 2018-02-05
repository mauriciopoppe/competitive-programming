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
#define M 100
struct person{
       char title[M], first_name[M], last_name[M],
            home_address[M], department[M], home_phone[M],
            work_phone[M], campus_box[M];
       bool operator<(const person &other)const
       {
            return strcmp(last_name, other.last_name) < 0;
       }
} p;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char line[5000];
    char dep[M];
    int cas;
    scanf("%d", &cas);
    gets(line);
    int i = 0;
    vector<person> people;
    while(cas--)
    {
        gets(dep);
        while(gets(line) && strlen(line))
        {
             char *ptr = strtok(line, ",");
             strcpy(p.title, ptr);
             ptr = strtok(NULL, ",");
             strcpy(p.first_name, ptr);
             ptr = strtok(NULL, ",");
             strcpy(p.last_name, ptr);
             ptr = strtok(NULL, ",");
             strcpy(p.home_address, ptr);
             ptr = strtok(NULL, ",");
             strcpy(p.home_phone, ptr);
             ptr = strtok(NULL, ",");
             strcpy(p.work_phone, ptr);
             ptr = strtok(NULL, ",");
             strcpy(p.campus_box, ptr);
             //ptr = strtok(NULL, ",");
             strcpy(p.department, dep);
             people.push_back(p);
             ++i;
        }
    }
    sort(ALL(people));
    for(int k = 0; k < i; ++k)
    {
        puts("----------------------------------------");
        printf("%s %s %s\n", people[k].title, people[k].first_name, people[k].last_name);
        printf("%s\n", people[k].home_address);
        printf("Department: %s\n", people[k].department);
        printf("Home Phone: %s\n", people[k].home_phone);
        printf("Work Phone: %s\n", people[k].work_phone);
        printf("Campus Box: %s\n", people[k].campus_box);
    }
    return 0;
}
