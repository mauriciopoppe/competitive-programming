#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    char w1[10],w2[10];
    int pw[]={1,4,16,64,256,1024,4096,16384};
    int a, b, n ;
    scanf("%d",&n);
    getchar();
    printf("COWCULATIONS OUTPUT\n");
    while(n--)
    {
         gets(w1);
         gets(w2); 
         a=b=0;    
         for(int i=0;i<5;++i)
         {
             a*=10;
             b*=10;    
             if(w1[i]=='U')a+=1;
             else if(w1[i]=='C')a+=2;
             else if(w1[i]=='D')a+=3;

             if(w2[i]=='U')b+=1;
             else if(w2[i]=='C')b+=2;
             else if(w2[i]=='D')b+=3;
             
         }
         
        //convert to base 10
         int x=0,y=0,z=0,j=0;
         while(a>0)
         {
             x+=((a%10)*pw[j++]);
             a/=10;      
         }   
         
         j=0;
         while(b>0)
         {
            y+=((b%10)*pw[j++]);  
            b/=10;     
         }   
                 
         for(int k=0;k<3;k++)
         {
              gets(w1);
              if(w1[0]=='A')y=x+y;
              else if(w1[0]=='L')y*=4;
              else if(w1[0]=='R')y/=4;  
         }        
         gets(w1);
         int c=0;
         for(int i=0;i<8;++i)
         {
             c*=10;
             switch(w1[i])
             {
                  case 'U':c+=1;break;
                  case 'C':c+=2;break;
                  case 'D':c+=3;break;
             }
         }
         j=0;
         while(c>0)
         {
             z+=c%10*pw[j++];
             c/=10;
         }
         if(z==y)printf("YES\n");
         else printf("NO\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
