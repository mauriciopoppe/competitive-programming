/*
 * 811.cpp
 *
 *  Created on: Jul 21, 2011
 *      Author: Mauricio
 */

#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define E 1e-9
#define INF 2000000000
struct point{
	double x,y;
	int value, length;
};
point p0;

int cnt;					//number of cut down trees
double total_length;		//total length of the cut down trees
int total_value;			//value of the cut down trees

vector<int> solution;		//this vector contains the best
double length_needed;		//length needed of the solution
int min_solution_value;	    //the best solution found
double extra_wood;			//wood left after building the fence

double distance_two_points(const point &p1, const point &p2)
{
     return (p2.x - p1.x) * (p2.x - p1.x)
             + (p2.y - p1.y) * (p2.y - p1.y);
}

double cross_product(const point &p1, const point &p2, const point &p3)
{
     return (p2.x - p1.x) * (p3.y - p1.y)
            - (p3.x - p1.x) * (p2.y - p1.y);
}

bool compare_angle_points(const point &p, const point &q)
{
    double cross = cross_product(p0, p, q);
    if(fabs(cross) < E)
       //p and q are collinear with p0 so return the one with lowest distance to p0
       return distance_two_points(p0, p) < distance_two_points(p0, q);
    if(cross > 0)
       //p is clockwise from q
       return true;
    return false;
}

vector<point> graham_scan(vector<point> polygon)
{
     //first let's find the smallest y_coordinate point
     //in case of a tie the smallest x_coordinate point
     int size;
     int i, j;

     size = polygon.size();
      //find the smallest point
     for(i = 1; i < size; ++i)
     {
          if(polygon[i].y < polygon[0].y ||
              (polygon[i].y == polygon[0].y && polygon[i].x < polygon[0].x))
          {
              swap(polygon[0], polygon[i]);
          }
     }

     //the smallest point is p[0]
     p0 = polygon[0];

     //sort the remaining points based on their angle with p0
     //points are sorted in cnterclockwise order from p0
     sort(polygon.begin() + 1, polygon.end(), compare_angle_points);

     //the three first sorted point form part of the convex hull
     //j is the size of the convex_hull - 1
     vector<point> convex_hull;
     j = 0;

     //build the convex hull with the remaining points
     for(i = 0; i < size; ++i, ++j)
     {
          while(j >= 2 && cross_product(convex_hull[j - 2], convex_hull[j - 1], polygon[i]) <= 0)
          {
              convex_hull.pop_back();
              --j;
          }
          convex_hull.push_back(polygon[i]);
     }
     return convex_hull;
}

void check(vector<int> &cut_down)
{
	if(total_length >= length_needed)		//i have enough wood
	{
		if(total_value <= min_solution_value)		//there's a better solution
		{
			if(total_value < min_solution_value)
			{
				min_solution_value = total_value;
				extra_wood = total_length - length_needed;
				solution = cut_down;
			}
			else if(cnt < (int)solution.size())		//it's equal but the size is smaller
			{
				solution = cut_down;
				extra_wood = total_length - length_needed;
			}
		}
	}
}

int main()
{
	int n_trees;		//number of trees
	int cases;			//number of cases
	int i,j;			//loop
	int size_ch;		//size of the convex hull
	int max;
	cases = 0;
	while(scanf("%d",&n_trees) && n_trees)
	{
		if(cases)
			printf("\n");
		cases++;
		vector<point> polygon(n_trees);
		for (i = 0; i < n_trees; ++i)
		{
			scanf("%lf %lf %d %d",&polygon[i].x, &polygon[i].y,
					&polygon[i].value, &polygon[i].length);
		}

		solution.clear();
		max = 1 << n_trees;	//max size of the subset
		min_solution_value = INF;	//first there's no best solution
		
        //printf("%d\n",max);
		for (i = 1; i < max; ++i)
		{
			cnt = 0;
			total_length = 0;
			total_value = 0;

			vector<point> temp;		//temp subset of trees to do the convex hull
			vector<int> cut_down;	//cut down trees

			for (j = 0; j < n_trees; ++j)
			{
				if(i & (1 << j))	//test this subset
				{
					temp.push_back(polygon[j]);
					++cnt;
				}
				else
				{
					total_length += polygon[j].length;
					total_value += polygon[j].value;
					cut_down.push_back(j + 1);
				}
			}

			if(cnt == 1)			//there's only one tree left
			{
				length_needed = 0;
				check(cut_down);
			}
			else if(cnt == 2) 	//two trees left
			{
				length_needed = 2.0 * sqrt(distance_two_points(temp[0], temp[1]));
				check(cut_down);
			}
			else					//the size is greater than 2 so find the convex hull
			{
				vector<point> convex_hull = graham_scan(temp);
				length_needed = 0;
				size_ch = convex_hull.size();
				for (j = 0; j < size_ch; ++j)
				{
					length_needed += sqrt(distance_two_points(convex_hull[j],
							convex_hull[(j + 1) % size_ch]));
				}
				check(cut_down);
			}
			//printf("%d\n",i);
		}
        //printf("here");
		printf("Forest %d\n",cases);
		printf("Cut these trees:");
		size_ch = solution.size();
		for (i = 0; i < size_ch; ++i)
		{
			printf(" %d",solution[i]);
		}
		printf("\nExtra wood: %.2lf\n",extra_wood);
	}
	return 0;
}
