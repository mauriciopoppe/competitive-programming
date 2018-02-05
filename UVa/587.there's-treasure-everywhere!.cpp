#include<stdio.h>
#include<string.h>
#include<math.h>
#define PI acos(0)
char w[50], str[5000];
double x, y;
double num;
double dist;
void solve()
{
    if(!strcmp(w, "N"))
        y += num;
    else if(!strcmp(w, "E"))
        x += num;
    else if(!strcmp(w, "S"))
        y -= num;
    else if(!strcmp(w, "W"))
        x -= num; 
    else
    {
        num = num * sin(PI / 2.0);
        if(!strcmp(w, "NW"))
            y += num, x -= num;
        else if(!strcmp(w, "NE"))
            y += num, x += num;
        else if(!strcmp(w, "SE"))
            x += num, y -= num;        
        else
            x -= num, y -= num;
    }
}

int main()
{   
    int cas = 1, temp; 
    while(gets(str) && str[0] != 'E')
    {
        char *ptr = strtok(str, ".,");
        x = y = dist = 0;
        while(ptr)
        {
            sscanf(ptr,"%d%s", &temp, w);
            num = (double)temp;
            dist += num;
            solve();
            ptr = strtok(NULL, ".,");
        }
        printf("Map #%d\n",cas++);
        printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
        printf("The distance to the treasure is %.3lf.\n\n",sqrt(x * x + y * y));
    }
    return 0;
}
