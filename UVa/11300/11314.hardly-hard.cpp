#include<stdio.h>
#include<stdlib.h>
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
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define sci(d) scanf("%d", &d)
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
using namespace std;

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point

struct Point
{
    double x, y;
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b)
{
    return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}
bool operator <(const Point &a, const Point &b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

//### FUNCIONES BASICAS #############################################################

double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); }
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; }
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); }

Point pa, pb, pc, pd;
double mn;

int main(){
    int cas;
    double ax, ay, bx, by;
    double start, end, m1, m2;
    scanf("%d", &cas);
    while(cas--){
        scanf("%lf%lf%lf%lf", &ax, &ay, &bx, &by);
        pa = Point(ax, ay), pb = Point(bx, by);
        pc = Point(-bx, by), pd = Point(ax, -ay);
        printf("%.3lf\n", dist(pa, pb) + dist(pc, pd));
    }
    return 0;
}
