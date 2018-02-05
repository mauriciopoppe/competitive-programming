/*
 * 10135.cpp
 *
 *  Created on: Jul 21, 2011
 *      Author: Mauricio
 */

#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define E 1e-8
#define INF 2000000000
#define PI 2*acos(0.0)
struct point{
    double x, y, ang;
    bool operator<(const point &other)const
    {
    	if(fabs(ang - other.ang) < E || fabs(ang - other.ang - 2.0 * PI) < E)
    		return x * x + y * y < other.x * other.x + other.y * other.y;
    	return ang < other.ang;
    }
};

double distance_two_points(const point &p1, const point &p2)
{
     return sqrt((p2.x - p1.x) * (p2.x - p1.x)
             + (p2.y - p1.y) * (p2.y - p1.y));
}

double cross_product(const point &p1, const point &p2, const point &p3)
{
     return (p2.x - p1.x) * (p3.y - p1.y)
            - (p3.x - p1.x) * (p2.y - p1.y);
}

bool compare_angle_points(const point &p, const point &q)
{
    if(fabs(p.x - q.x) > E)
    	return p.x < q.x;
    return p.y < q.y;
}

void solve(vector<point> &polygon)
{
	int size;
	int i, j, k;
	double perimeter;
	point origin = {0, 0, 0};
	size = polygon.size();

	//sort the polygon in base of their polar angle
	for(i = 0; i < size; ++i)
		polygon[i].ang = atan2(polygon[i].y, polygon[i].x);
	sort(polygon.begin(), polygon.end());
	
	//the best length is INF
	double best = 2000000000;

     //run N convex hull starting from point P
	for(i = 0; i < size; ++i)
	{
		vector<point> h;
		h.push_back(origin);
		h.push_back(polygon[i]);
		k = 2;
		for(j = (i + 1) % size; j != i; j = (j + 1) % size)
		{
			while(k >= 2 && cross_product(h[k - 2], h[k - 1], polygon[j]) < E)
			{
				h.pop_back();
				--k;
			}
			h.push_back(polygon[j]);
			++k;
		}

		//find the total length
		h.push_back(origin);
		perimeter = 2;
		int h_size = h.size();
		for (k = 1; k < h_size; ++k)
		{
			perimeter += distance_two_points(h[k], h[k - 1]);
		}
		best = min(best, perimeter);
	}
	//now find the real convex hull clockwise and counterclockwise
	//supposing that the origin is out of the hull
	polygon.push_back(origin);
	sort(polygon.begin(), polygon.end(), compare_angle_points);
	size++;
	double res = 2;
	for (i = 0; i < 2; i++)
	{
		vector<point> h;
		k = 0;
		for (j = 0; j < size; j++)
		{
			point p;
			if(!k)
				p = polygon[i];
			else
				p = polygon[size - 1 - j];
			while (k >= 2 && cross_product(h[k - 2], h[k - 1], p) < E)
			{
				h.pop_back();
				--k;
			}
			h.push_back(p);
		}

		int h_size = h.size();
		for (j = 1; j < h_size; j++)
			res += distance_two_points(h[j - 1], h[j]);
	}
	best = max(best, res);
	printf("%.2lf\n",best);
}

int main()
{
	int cases;				//number of cases
	int n_frogs;			//number of frogs
	point center;
	center.x = 0;
	center.y = 0;
	int i,k;
	scanf("%d",&cases);
	for (k = 0; k < cases; ++k)
	{
		if(k)
			printf("\n");
		scanf("%d",&n_frogs);
		point p;
		vector<point> polygon;
		for (i = 0; i < n_frogs; ++i)
		{
			scanf("%lf %lf", &p.x, &p.y);
			if(fabs(p.x) < E && fabs(p.y) < E)
			{
				--i;
				--n_frogs;
			}
			else
				polygon.push_back(p);
		}

		if(n_frogs == 1)
		{
			printf("%.2lf\n",2.0 * distance_two_points(center, polygon[0]) + 2.0);
			continue;
		}
		solve(polygon);
	}
	return 0;
}
