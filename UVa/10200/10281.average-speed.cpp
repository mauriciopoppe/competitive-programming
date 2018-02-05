#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

int main()
{
    int h,m,s,bh,bm,bs,speed,nspeed;
    char w[20];
    double sum=0,time;
    int c=0;
    while(gets(w))
    {
         int input=sscanf(w,"%d:%d:%d %d",&h,&m,&s,&speed);
         
         if(h<bh || (h==bh && m<bm) || (h==bh && m==bm && s<bs))
              h+=24;
         time=((h-bh)*3600+(m-bm)*60.0+(s-bs))/3600.0;
         sum+=nspeed*time;     
         bh=h;
         bm=m;
         bs=s;
               
         if(input==4)
               nspeed=speed;
         
         if(c==0)sum=0;
         
         if(input==3)
               printf("%02d:%02d:%02d %.2lf km\n",h,m,s,sum);              
         ++c;                                                                 
    }
    return 0;
}
