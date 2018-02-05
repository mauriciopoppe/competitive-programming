#include<stdio.h>

int main()
{
    int n,i,j,k,x,o,wx,wo;
    char w[3][3];
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        getchar();   
        o=x=0;                   
        for(j=0;j<3;++j)
           {
              for(k=0;k<3;++k)
              {
                  w[j][k]=getchar();
                  if(w[j][k]=='O')++o;
                  else if(w[j][k]=='X')++x;
              }
              getchar();
           }
         wo=wx=0;
          
        for(j=0;j<3;++j)
        {
            if(w[j][0]==w[j][1] && w[j][1]==w[j][2])
            {
                  if(w[j][0]=='X')++wx;            
                  else if(w[j][0]=='O')++wo;
            }
            
            if(w[0][j]==w[1][j] && w[1][j]==w[2][j])
            {
                  if(w[0][j]=='X')++wx;            
                  else if(w[0][j]=='O')++wo;
            }
        }   
        
        if(w[0][0]==w[1][1] && w[1][1]==w[2][2])
        {
             if(w[0][0]=='X')++wx;            
             else if(w[0][0]=='O')++wo;
        }
        
        if(w[0][2]==w[1][1] && w[1][1]==w[2][0])
        {
             if(w[1][1]=='X')++wx;            
             else if(w[1][1]=='O')++wo;
        }
        
        if(wx>0 && wo==0 && x==o+1)printf("yes\n");
        else if(wo>0 && wx==0 && x==o)printf("yes\n");
        else if(wo==0 && wx==0 && (x==o || x==o+1))printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
