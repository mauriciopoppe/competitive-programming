/*
 * 681.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: Mauricio
 */

#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

struct point{
    int x,y;
};
point p0;
point convex_hull[1000], polygon[1000];

int distance_two_points(const point &p1, const point &p2)
{
     return (p2.x - p1.x) * (p2.x - p1.x)
             + (p2.y - p1.y) * (p2.y - p1.y);
}

int cross_product(const point &p1, const point &p2, const point &p3)
{
     return (p2.x - p1.x) * (p3.y - p1.y)
            - (p3.x - p1.x) * (p2.y - p1.y);
}

bool compare_angle_points(const point &p, const point &q)
{
    int cross = cross_product(p0, p, q);
    if(cross == 0)
       //p and q are collinear with p0 so return the one with lowest distance to p0
       return distance_two_points(p0, p) < distance_two_points(p0, q);
    if(cross > 0)
       //p is counterclockwise from q
       return true;
    return false;
}

void graham_scan(int size)
{
     //first let's find the smallest y_coordinate point
     //in case of a tie the smallest x_coordinate point
     int i, j;

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
     sort(polygon + 1, polygon + size, compare_angle_points);

     //the three first sorted point form part of the convex hull
     //j is the size of the convex_hull - 1
     convex_hull[0] = polygon[0];
     convex_hull[1] = polygon[1];
     j = 2;

     //build the convex hull with the remaining points
     for(i = 2; i < size; ++i, ++j)
     {
          while(j >= 2 && cross_product(convex_hull[j - 2], convex_hull[j - 1], polygon[i]) <= 0)
          {
              --j;
          }
          convex_hull[j] = polygon[i];
     }
     
     printf("%d\n",j + 1);
	 for (i = 0; i < j; ++i)
	 {
 		 printf("%d %d\n", convex_hull[i].x , convex_hull[i].y);
 	 }
 	 printf("%d %d\n", convex_hull[0].x , convex_hull[0].y);

}

int main()
{
	int n_points;		//number of points
	int cases;			//number of cases;
	int size;			//size of the convex hull
	int i,j;
	scanf("%d",&cases);
	printf("%d\n",cases);
	for (j = 0; j < cases; ++j)
	{
		if(j)
		{
			scanf("%d",&i);
			printf("-1\n");
		}
		scanf("%d",&n_points);
		for (i = 0; i < n_points; ++i)
		{
			scanf("%d %d", &polygon[i].x, &polygon[i].y);
		}
        graham_scan(n_points); 
	}
	return 0;
}
