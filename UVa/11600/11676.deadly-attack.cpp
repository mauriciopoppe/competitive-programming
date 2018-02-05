/*
 * 11676.cpp
 *
 *  Created on: Jul 19, 2011
 *      Author: Mauricio
 */

#include<stdio.h>
#include<math.h>
#define E 1e-4
#define PI acos(-1)
enum{LEFT, CENTER, RIGHT};
struct point{
	double x,y;
};

struct line{
	double y,x,b;
};

struct circle{
	double rad;
	double x,y;
};

circle c;
line l1,l2;

point beam,p1,p2;
point temp,q1,q2;

double direction, spread;
double d_a, d_b;
double side_a, side_b;
double area_a, area_b;
double angle;
int where_a, where_b;

double cross_product(point &z1, point &z2)
{
    return z1.x * z2.y - z2.x * z1.y;       
}

double dot_product(point &z1, point &z2)
{
    return z1.x * z2.x + z1.y * z2.y;       
}

double length(point &p1, point &p2)
{
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) +
			(p2.y - p1.y) * (p2.y - p1.y));
}

double dot_product_3points(point &p1, point &p2, point &p3)
{
	return (p2.x - p1.x) * (p3.x - p1.x) +
			(p2.y - p1.y) * (p3.y - p1.y);
}

double cross_product_3points(point &p1, point &p2, point &p3)
{
     point p2_a, p3_a;
     p2_a.x = p2.x - p1.x;
     p2_a.y = p2.y - p1.y;
     p3_a.x = p3.x - p1.x;
     p3_a.y = p3.y - p1.y;
     return p2_a.x * p3_a.y - p2_a.y * p3_a.x;
}

void build_main_line(point &beam, double direction, line &l)
{
	if(direction == 90 || direction == 270)
	{
		l.y = 0;
		l.x = 1;
		l.b = -beam.x;
	}
	else if(direction == 0 || direction == 180)
	{
		l.y = 1;
		l.x = 0;
		l.b = beam.y;
	}
	else
	{
		direction = direction * PI / 180.0;
		l.y = 1;
		l.x = tan(direction);
		l.b = beam.y - l.x * beam.x;
	}
}

void get_direction_point(line &l, double direction, point &beam, point &p)
{
	int sum;   //max segment lenght = 1500 
	if(direction == 0 || direction == 180)
	{
		if(direction == 0)
			sum = 1500;
		else
			sum = -1500;
		p.y = beam.y;
		p.x = beam.x + sum;
	}
	else if(direction == 90 || direction == 270)
	{
		if(direction == 90)
			sum = 1500;
		else
			sum = -1500;
		p.x = beam.x;
		p.y = beam.y + sum;
	}
	else if(direction < 90 || direction > 270)
	{
		p.x = beam.x + 1500;
		p.y = l.x * p.x + l.b;
	}
	else
	{
		p.x = beam.x - 1500;
		p.y = l.x * p.x + l.b;
	}
}

double distance_line_point(point &z1, point &z2, point &z3)
{
    //p1 is point A
    //p2 is point B
    //p3 is point C
    //line segment AB is composed of two points p1 and p2
    //line segment AC is composed of two points p1 and p3
    point AB;
    point AC;
    AB.x = z2.x - z1.x;
    AB.y = z2.y - z1.y;
    AC.x = z3.x - z1.x;
    AC.y = z3.y - z1.y;
    
    double cross;             //cross product of p1p2 and p1p3
    return fabs( cross_product(AB, AC) / length(z1, z2));
}

double distance_segment_point(point &z1, point &z2, point &z3)
{
    //line segment AB is composed of two points p1 and p2
    //first let's assume that the point is in between
    double distance;
    distance = distance_line_point(z1, z2, z3);
    
    point AB;
    point BC;
    AB.x = z2.x - z1.x;
    AB.y = z2.y - z1.y;
    BC.x = z3.x - z2.x;
    BC.y = z3.x - z2.y;
    if(dot_product(AB,BC) > 0)
    {
        distance = length(z2, z3);
    }
    
    point BA;
    point AC;
    BA.x = z1.x - z2.x;
    BA.y = z1.y - z2.y;
    AC.x = z3.x - z1.x;
    AC.y = z3.x - z1.y;
    if(dot_product(BA, AC) > 0)
    {
        distance = length(z1, z3);
    }
    return fabs(distance);
}

int circle_line_intersection(circle &c1, line &l, point &p4_a, point &p4_b)
{
    double a, b, c;
    //printf("%lf = %lf + %lf\n",l.y,l.x,l.b);
    if(l.y)
    {
        a = 1 + l.x * l.x;
        b = 2 * (l.x * l.b - l.x * c1.y - c1.x);
        c = c1.x * c1.x + c1.y * c1.y + l.b * l.b - 2 * l.b * c1.y - c1.rad * c1.rad;
        double det = b * b - 4 * a * c;
        if(fabs(det) > E && det < 0)
            return 0;
        p4_a.x = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
        p4_b.x = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);

        //for the line
        p4_a.y = p4_b.y = l.b;
        if(l.x != 0)
        {
             p4_a.y = l.x * p4_a.x + l.b;
             p4_b.y = l.x * p4_b.x + l.b;
        }
    }
    else
    {
        a = 1;
        b = -2 * c1.y;
        c = c1.y * c1.y - c1.rad * c1.rad + c1.x * c1.x + l.b * l.b + 2 * l.b * c1.x;
        double det = b * b - 4 * a * c;
        if(fabs(det) > E && det < 0)
            return 0;

        p4_a.y = (-b + sqrt(b * b - 4 * a * c)) / (2.0 * a);
        p4_b.y = (-b - sqrt(b * b - 4 * a * c)) / (2.0 * a);

        //for the line
        p4_a.x = p4_b.x = -l.b;
        if(l.y != 0)
        {
             p4_a.x = (p4_a.y - l.b) / l.x;
             p4_b.x = (p4_b.y - l.b) / l.x;
        }
    }
    return 2;
}

void calc_area_A()
{
	//calc the remaining A area
	circle_line_intersection(c,l1,q1,q2);
	//printf("%lf %lf\n", q1.x, q1.y);
	//printf("%lf %lf\n", q2.x, q2.y);

	if(where_a == CENTER)
	{
		area_a = PI * c.rad * c.rad * 0.5;
	}
	else
	{
		angle = acos(dot_product_3points(temp,q1,q2) /
				(length(q1, temp) * length(q2, temp)));
		//calc the area of the sector - the area of the triangle
		/*
		printf("AAAA\n");
		printf("angle %lf %lf\n",angle,angle*180/PI);
		printf("length %lf %lf\n", length(q1, temp), length(q2,temp));
		printf("dot %lf\n",dot_product_3points(temp,q1,q2));
		*/
		area_a = angle * c.rad * c.rad * 0.5;
		area_a -= fabs(cross_product_3points(temp,q1,q2)) * 0.5;
		if(where_a == RIGHT)
			area_a = PI * c.rad * c.rad - area_a;
	}
}

void calc_area_B()
{
	//calc the remaining A area
	circle_line_intersection(c,l2,q1,q2);
	if(where_b == CENTER)
	{
		area_b = PI * c.rad * c.rad * 0.5;
	}
	else
	{
		angle = acos(dot_product_3points(temp,q1,q2) /
				(length(q1, temp) * length(q2, temp)));
		//calc the area of the sector - the area of the triangle
        /*
        printf("BBBB\n");
		printf("angle %lf %lf\n",angle,angle*180/PI);
		printf("length %lf %lf\n", length(q1, temp), length(q2,temp));
		printf("dot %lf\n",dot_product_3points(temp,q1,q2));
        */
		area_b = angle * c.rad * c.rad * 0.5;
		area_b -= fabs(cross_product_3points(temp,q1,q2)) * 0.5;
		if(where_b == LEFT)
			area_b = PI * c.rad * c.rad - area_b;
	}
}

void solve()
{
	temp.x = c.x;
	temp.y = c.y;

	//see where the lines are located respect to the center

	//check if line 1 is on which side from the center
	side_a = cross_product_3points(beam, p1, temp);
	//printf("%lf\n",side_a);
	if(fabs(side_a) < E)
	{
		where_a = CENTER;
		if(dot_product_3points(beam, p1, temp) < 0)
		{
		   where_a = LEFT;
           //printf("where_a = %d\n",where_a);
        }
    }
	else if(side_a > 0)
		where_a = RIGHT;
	else
		where_a = LEFT;

	//check if line 2 is on which side from the center
	side_b = cross_product_3points(beam, p2, temp);
	if(fabs(side_b) < E)
	{
		where_b = CENTER;
        if(dot_product_3points(beam, p2, temp) < 0)
		   where_b = RIGHT;
    }
	else if(side_b > 0)
		where_b = RIGHT;
	else
		where_b = LEFT;
    
    //printf("wheres %d %d\n",where_a, where_b);
    
	double distance_center_a = distance_segment_point(beam,p1,temp);
	double distance_center_b = distance_segment_point(beam,p2,temp);
    
    //printf("distance a = %lf\n",distance_center_a);
    //printf("distance b = %lf\n",distance_center_b);

	//if the beam can't destroy the wall because it's far from the wall
	if((where_b == LEFT && (fabs(distance_center_b - c.rad) < E || distance_center_b > c.rad) ) ||
		(where_a == RIGHT && (fabs(distance_center_a - c.rad) < E || distance_center_a > c.rad) ))
	{
        //printf("Far from the wall\n");
		printf("0.0\n");
		return;
	}

	//maybe the beam destroys the whole wall
	if((where_a == LEFT && (fabs(distance_center_a - c.rad) < E || distance_center_a > c.rad) ) &&
		(where_b == RIGHT && (fabs(distance_center_b - c.rad) < E || distance_center_b > c.rad) ))
	{
		printf("%.1lf\n",c.rad*c.rad*PI);
		return;
	}

	//the left line is far from the circle
	//while the right line intersect the circle
	if(where_a == LEFT && (fabs(distance_center_a - c.rad) < E || distance_center_a > c.rad) )
	{
        //printf("Left line far\n");
		calc_area_B();
		printf("%.1lf\n",fabs(PI * c.rad * c.rad - area_b));
		return;
	}

	//the right line is far from the circle
	//while the left line intersect the circle
	if(where_b == RIGHT && (fabs(distance_center_b - c.rad) < E || distance_center_b > c.rad) )
	{
        //printf("Right line far\n");
		calc_area_A();
		printf("%.1lf\n",fabs(PI * c.rad * c.rad - area_a));
		return;
	}

	//both lines intersect the circle
	//printf("Both lines\n");
	calc_area_A();
	calc_area_B();
	printf("%.1lf\n", fabs(PI * c.rad * c.rad - area_a - area_b));
}

int main()
{
	while(scanf("%lf%lf%lf",&c.x,&c.y,&c.rad))
	{
		if(c.x == 0 && c.y == 0 && c.rad == 0)
			break;
		scanf("%lf%lf%lf%lf",&beam.x, &beam.y, &direction, &spread);

		d_a = direction + spread * 0.5;
		if(d_a > 360)
			d_a -= 360.0;

		d_b = direction - spread * 0.5;
		if(d_b < 0)
			d_b += 360.0;

		//printf("%lf %lf\n",d_a, d_b);

		build_main_line(beam, d_a, l1);
		build_main_line(beam, d_b, l2);
        /*
        printf("%lf = %lf %lf\n",l1.y,l1.x,l1.b);
        printf("%lf = %lf %lf\n",l2.y,l2.x,l2.b);
        printf("\n");
        */
		get_direction_point(l1, d_a, beam, p1);
		get_direction_point(l2, d_b, beam, p2);
        /*
        printf("%lf %lf\n",p1.x, p1.y); 
        printf("%lf %lf\n",p2.x, p2.y); 
        printf("\n");*/
		solve();
	}
	return 0;
}
