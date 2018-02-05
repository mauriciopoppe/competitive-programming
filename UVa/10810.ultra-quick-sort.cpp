#include<iostream>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#define S 500001
using namespace std;

int a[S];
typedef long long LL;
LL c=0;    

/* Sorts first n elements of array a[] in non-decreasing order. */
 void merge(int a[],int n)
{
	int i, j, k;
 
	/* For small arrays, insertion sort is much faster */
	if (n < 64) {
        for (i=0;i<n-1;i++) {
			for (j = 1; j<n;j++)    
                if(a[j]<a[j-1])
                  {swap(a[j],a[j-1]);c++;}
        }
		return;
	}
 
	int f = n / 2;		/* f = number of elements in first half */
 
        /* Recursively sort both halves */
	merge(a, f);
	merge(a+f, n-f);
 
        /* Merge */
	int *s = new int[n];	/* temporary array to keep the sorted sequence */
 
	for (i = 0, j = f, k = 0; i < f && j < n;)
	{
        if(a[j] < a[i])
        {
             s[k++]=a[j++];
             c+=j-k;
        }
        else
             s[k++]=a[i++];
    }         
 
	while (i < f) s[k++] = a[i++];
	while (j < n) s[k++] = a[j++];
 
	for (i = 0; i < n; i++) a[i] = s[i];
	delete[] s;
}

int main()
{
    int n;
    
    
    while(scanf("%d",&n) && n)
    {             
        for(int j=0;j<n;j++)
          scanf("%d",&a[j]);
        c=0;
        merge(a,n);    
         
        printf("%lld\n",c);                 
    }
    
    /*
    ifstream in;
    ofstream out;
    in.open("in.txt");
    out.open("out.txt");
    while(in>>n && n)
    {             
        for(int j=0;j<n;j++)
        //      scanf("%d",&a[j]);
              in>>a[j];
        c=0;
        merge(a,n);    
         
        //printf("%lld\n",c);                 
        out<<LL(c)<<endl;
    }
    in.close();
    out.close();
    */
    return 0;
}
