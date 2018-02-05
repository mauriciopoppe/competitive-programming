#include<stdio.h>
#include<string.h>
typedef long long LL;
LL v[21]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800LL,87178291200LL,1307674368000LL,20922789888000LL,355687428096000LL,6402373705728000LL,121645100408832000LL,2432902008176640000LL};
int b[26];
char c[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; 

int find(int num)
{
     int counter=-1,j=0;     
     for(;j<26;++j)     
     {
        if(b[j])
        {
                ++counter;   
                if(!(counter^num))break;
        }
     }
     b[j]=0;
     return j;
}

int main()
{         
           freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);           
    char w1[26];
    LL shift;     
    int n,j,num,i,length;
    scanf("%d",&n);
    ++n;
    while(--n)
    {
        scanf("%s%lld",w1,&shift);                
        ++shift;
        length=strlen(w1),i=0;

        for(;i<length;++i)              
           b[w1[i]-97]=1;
        i=-1;
     
        if(length>1)
        {     
            while(1)
            {
                j=length-1,num=(shift-1)/v[j],--length;
                if(shift>=v[j])shift-=num*v[j];
                w1[++i]=c[find(num)];
                if(!(length^1))break;  
            }
            j=0,w1[++i]=c[find(0)];
        }
        puts(w1),memset(b,0,sizeof(b));      
    }
    return 0;
}
