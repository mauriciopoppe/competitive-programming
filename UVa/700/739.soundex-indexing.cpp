#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;
/*
Code	 Key Letters and Equivalents
1	B, P, F, V
2	C, S, K, G, J, Q, X, Z
3	D, T
4	L
5	M, N
6	R
*/
int main()
{
    char w[25];
    char res[25];
    int v[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
    printf ("         NAME                     SOUNDEX CODE\n");
    while(scanf("%s",w)!=EOF)
    {
         fill(res,res+25,'0');
         res[0]=w[0];
         int len=strlen(w),j=1,ant=v[w[0]-'A'];
         for(int i=1;i<len;i++)
         {   
                 int t=w[i]-'A';              
                 if(v[t]!=0 && ant!=v[t])
                        res[j++]=(char)(v[t]+48);
                 ant=v[t];                       
         }
         res[4]='\0';
         printf("%9s%s","",w);
         for(int i=0;i<25-len;i++)printf(" ");
         printf ("%c%c%c%c\n",res[0],res[1],res[2],res[3]);

    }
    printf ("                   END OF OUTPUT\n");
    return 0;
}
