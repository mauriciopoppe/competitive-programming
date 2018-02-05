#include<stdio.h>
int main()
{   
    int cas;
    int h, m;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d:%d", &h, &m);
        int hh, mm;
        if(h >= 12) h -= 12;
        
        if(h == 12 && m == 0 || h == 0 && m == 0)
           puts("12:00");
        else
        {
           hh = 11 - h;
           mm = 60 - m;
           if(mm == 60) mm = 0, ++hh;
           if(hh == 0) hh = 12;
           printf("%02d:%02d\n", hh, mm);
        }
    }
    return 0;
}
