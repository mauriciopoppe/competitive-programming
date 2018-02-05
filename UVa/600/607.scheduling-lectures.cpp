#include <stdio.h>

#define INF 1000000000

int t[1024], cum[1024], cov[1024], dif[1024], m, n, len, c, s;
int total1[1024], total2[1024];

int main()
{
	int a, i, j, k, r, *total, *next;
	
	//precalc differences
	dif[0]=0;
	for (i = 11, j=1 ; i < 1020; ++i,++j)
		dif[i] = j * j;
		
	for (s = 0; scanf("%d %d %d", &n, &len, &c) == 3 && n; s++) 
    {
        if(s)printf("\n");
		for (i = 1; i <= n; i++)
			scanf("%d", &t[i]);
			
		for (i = 1; i <= 10; i++)
			dif[i] = -c;
		
        //cumulative array	
        cum[0]=0;
		for (i = 1; i <= n; i++)
			cum[i]=cum[i-1]+t[i];
			
		for(i=1;i<=n;i++) 
        {
            for(j=i;j<=n;j++)    
				if (cum[j]-cum[i - 1]>len)break;
			cov[i] = j - i;
			printf("[%d] cum=%d %d\n",i,cum[i],cov[i]);
		}
      
        //find the total lectures needed
		for (i = 1, m = 0; i <= n; m++)
		    i += cov[i];
		    
		total = total1;
		next = total2;
        
        //total ammount needed is INF first
		for (i = 0; i <= n; i++)
			total[i] = INF;
		total[n + 1] = 0;

		for (k = 1; k <= m; k++) 
        {
			for (i = 1; i <= n; i++) 
            {
                printf("ITER %d:\n",i);
				next[i] = INF;
				for (j = 1; j <= cov[i]; j++) 
                {
					r = dif[ len - cum[i+j-1] + cum[i-1] ] +  total[i + j];
					printf("dif - %d %d\n",len - cum[i+j-1] + cum[i-1],dif[len - cum[i+j-1] + cum[i-1]]);
					printf("%d %d\n",r,r-total[i+j]);
					if (r < next[i])
						next[i] = r;
				}
				for(a=0;a<=n;a++)printf("%d ",next[a]);printf("\n");
			}
            
            for(a=0;a<=n;a++)printf("%d ",next[a]);printf("\n");
            for(a=0;a<=n;a++)printf("%d ",total2[a]);printf("\n");
            
			total = next;
			for(a=0;a<=n;a++)printf("%d ",total[a]);printf("\n");
			next = (next == total1) ? total2 : total1;
			for(a=0;a<=n;a++)printf("%d ",next[a]);printf("\n");
			for(a=0;a<=n;a++)printf("%d ",total[a]);printf("\n");
		}

		printf("Case %d:\n",s+1);
        printf("Minimum number of lectures: %d\nTotal dissatisfaction index: %d\n",m,total[1]);

	}

	return 0;
}
