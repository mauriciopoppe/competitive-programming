#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<sstream>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define NL printf("\n")
#define SP system("pause")
#define IMAX 2147483647
#define TR(container, it) \
      for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
typedef long long LL;
#define MAXN 10000050
int size;					//size of the string
int t;  					//pow 2 helper
int best;

/*
 * suffix array SA holds the starting indexes of all suffixes in a sorted way
 * such that the suffix starting at SA[i] is lexicographically lower than
 * the suffix starting at SA[i + 1]
 */
int SA[MAXN];

/*
 * SA_inverse is the inverse of the suffix array
 * SA_inverse describes the position 'j' in the suffix array of a suffix starting at SA[i]
 */
int SA_inverse[MAXN];

/*
 * lcp is the longest common prefix between suffixes starting at SA[i] and SA[i + 1]
 */
int lcp[MAXN];
int n_str;
/*
 * str is the initial string concatenated with '$'
 */
char str[MAXN];
char word_number[MAXN];
char word[2000005];
void fix_index(int *begin, int *end)
{
   int position;			//partial position
   int new_position;		//new position of the suffix starting at SA[i]
   	   	   	   	   	   	   	//this position goes from old_position up to
   	   	   	   	   	   	    //old_position + bucket_size
   int old_position;		//old position of this suffix starting at SA[i] i = begin..end
   int i;					//loop
   int difference;			//difference between this suffix and the next in the bucket
   int bucket_size;			//number of suffixes to be correctly positioned

   position = SA_inverse[*begin + t];
   bucket_size = end - begin;
   difference = 0;
   old_position = begin - SA;

   for(i = 0; i < bucket_size; i++)
   {
	  //compare the positions of the suffixes SA[i + t] i = begin..end
	  //if they are the same that means that they still have the t-th character in common
	  //but if they are different we know that the difference is the number of
	  //positions advanced from *begin
      if (((new_position = SA_inverse[*begin + t]) != position) &&
    		  !(old_position <= position && new_position < old_position + bucket_size))
      {
         position = new_position;
         difference = i;
      }
      //store the new position of the suffix starting at SA[i] i = begin..end
      //in the SA_inverse array
      SA_inverse[*(begin++)] = old_position + difference;
   }
}

//compare the t-th element of the suffixes
bool comp(int i, int j)
{
   return SA_inverse[i + t] < SA_inverse[j + t];
}

void suffix_array() {
   int i, j;				//loop
   int counting[256];		//help to do counting sort
   t = 1;					//t is the number of already checked characters
   	   	   	   	   	   	   	//t is a power of 2
   memset(counting, 0, sizeof counting);

   //counting the occurrences of every first character from
   //all suffixes of the string str
   for(i = 0; i < size; ++i)
	   ++counting[int(str[i])];

   //get prefix sums
   //from this we can deduce that the number of suffixes
   //that start with the character i is equal to counting[i] - counting[i - 1]
   //and that the number of sorted suffixes that must go before this
   //bucket is equal to counting[i - 1]
   for(i = 1; i < 256; ++i)
	   counting[i] += counting[i - 1];

   //after doing the counting sort for each starting character of every suffix
   //we have the suffixes partially sorted in buckets according to the same
   //starting character, therefore we assign to every suffix that belongs
   //to a common bucket starting with some initial character a sequential number
   //that goes from counting[i] - 1 to counting[i - 1] inclusive
   for(i = 0; i < size; ++i)
	   SA[--counting[int(str[i])]] = i;

   //initially for all suffixes starting with the same letter we know that
   //they all belong to the bucket j and the bucket j is of size k where
   //k is the number of suffixes that start with the same character
   //therefore the inverse of the suffix array will hold the same number
   //for all k common suffixes that start with the same starting character
   //and that number is equal to the number of sorted suffixes that must go
   //before this bucket of suffixes
   for(i = size - 1; i >= 0; i--)
	   SA_inverse[i] = counting[int(str[i])];

   //now for every bucket sort it by the first t starting characters
   //where t is a power of 2
   for(t = 1; t < size; t *= 2)
   {
      for(i = 0, j = 1; i < size; i = j++)
      {
    	 //get the bucket that start with the same first t characters
         while(j < size && SA_inverse[SA[j]] == SA_inverse[SA[i]])
        	 ++j;
         if (j - i > 1)
         {
        	//sort this bucket according to the first t characters
            sort(SA + i, SA + j, comp);
            //update SA_inverse so that it holds the the correct position
            //of the suffixes starting at SA[k] k = i..j
            fix_index(SA + i, SA + j);
         }
      }
   }
}

void build_lcp()
{
	int tam = 0;		//initially no common characters
	int i, j;			//loop
	for(i = 0; i < size; i++)
		if (SA_inverse[i] > 0)	//check only for the suffixes that have a predecessor
		{
			//get the previous suffix from the SA
			j = SA[SA_inverse[i] - 1];

			//check starting from the character at position tam in the string
			while(str[i + tam] == str[j + tam])
				++tam;
            
            best = max(best, tam);
            
			//LCP is the common characters from suffix[j] and suffix[i]
			lcp[SA_inverse[i] - 1] = tam;

			//we know that the next suffix must share at least tam - 1 characters
			//only if tam is bigger than zero
			if (tam > 0)
				--tam;
		}
	//size of the last suffix is zero
	lcp[size - 1] = 0;
}

bool bsearch(int length_to_find)
{
    int i, j;
    int cnt;
    bool check[10];
    for(i = 1; i < size; i = j + 1)
    {
        while(i < size && lcp[i] < length_to_find)
           ++i;
        if(i == size)
           break;
        cnt = 0;
        memset(check, 0, sizeof check);
        for(j = i; lcp[j] >= length_to_find; ++j)
           if(!check[word_number[SA[j]]])
           {
                check[word_number[SA[j]]] = 1;
                ++cnt;                     
           }
        if(!check[word_number[SA[j]]])
           ++cnt;
        //printf("%d %d\n", cnt, j);
        if(cnt == n_str)
           return 1;
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cas;
    int mn, j;
    int word_size;
    scanf("%d", &cas);
    while(cas--)
    {        
         scanf("%d", &n_str);
         gets(word);
         mn = MAXN;
         size = 0;
         for(int i = 0; i < n_str; ++i)
         {
              gets(word);
              for(j = 0; word[j]; ++j)
                  str[size] = word[j],
                  word_number[size++] = i + 1; 
              str[size++] = (char) (i + '$');
              mn = min(j, mn);
         }
         
         suffix_array();
         build_lcp();
         /*
         printf("size %d, mn %d\n",size,mn);
         
         for(int i=0;i<size;i++)
           printf("%d %s\n",SA[i],str+SA[i]);

           for(int i=0;i<size;i++)
        	   printf("%2d ",lcp[i]);
           NL;
           
           for(int i = 0; i < size; ++i)
               printf("%2d ",word_number[SA[i]]);
           NL;
         SP;*/
         
         int low = 1, up = mn + 1, mid, best = -1;
         while(low <= up)
         {
             mid = (low + up) >> 1;
             if(bsearch(mid))
                low = mid + 1, best = mid;
             else
                up = mid - 1;
         }
         printf("%d\n", best);
    }
    return 0;
}
