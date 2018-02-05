#include<stdio.h>
#include<math.h>

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

Point A, B, C, D, E, F, O(0, 0);
int main(){
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y
        , &D.x, &D.y, &E.x, &E.y, &F.x, &F.y)){

        if(A == O && B == O && C == O && D == O && E == O && F == O)
            break;

        double A_t = fabs(area(D, E, F)) * 0.5;
        double base = dist(A, B);
        double height = A_t / base;

        double angle = acos(dot(C - A, B - A) / (C - A).mod() / (B - A).mod());
        angle = fabs(angle);
        double side = height / sin(angle);

        Point ARG = (C - A).unit();
        double needed = dist(A + ARG * side, A);
        Point H = A + ARG * needed;
        Point G = B + ARG * needed;
        //printf("%lf %lf\n", height * (base_prime + base), A_t);

        printf("%.3lf %.3lf %.3lf %.3lf\n", G.x, G.y, H.x, H.y);
    }
	return 0;
}
