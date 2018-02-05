#include <stdio.h>
#include <string.h>
#define SIZE 26
 
struct node{
       bool cnt;
       node *edges[SIZE];
       node()
       {
           cnt = 0;
           memset(edges, 0, sizeof edges);
       }
} *root;

int size;

int insert_word(char *q)
{
     int i;
     node *ptr = root;
     for(i = 0; q[i]; ++i)
     {
         char c = q[i] - 'a';  
         if(!ptr->edges[c])
             ptr->edges[c] = new node();
         ptr = ptr->edges[c];
     }
     ptr->cnt = 1;
     return i;
}
 
bool find_word(char *q)
{
     node *ptr = root;  
     for(size = 0; q[size]; ++size)
     {
         char c = q[size] - 'a';
         if(!ptr->edges[c])
             return 0;
         ptr = ptr->edges[c];
     }
     if(ptr->cnt) return 1;
     return 0;
}


static int ins(char *p, char *q)
{
	int k;

	for (k = 0; *p;) {
		if (*p != *q) {
			q++;
			if (++k > 1) return 0;
		} else {
			p++;
			q++;
		}
	}

	return 1;
}

static int rep(char *p, char *q)
{
	int k;

	for (k = 0; *p;)
		if (*p++ != *q++ && ++k > 1) return 0;

	return 1;
}

static int get(char *s)
{
	while (gets(s)) {         
        if(s[0] == '\0')
           continue;
        if(s[0] == '#')
		   return 0;
        size = insert_word(s);                 
		return size;
	}
	return 0;
}

int main()
{
    static char dict[16384][16], w[16];
	static char len[16384];
    int ndict, t;
	int i, x;
	for (scanf("%d", &t); t--;) {
        root = new node();
		for (ndict = 0; len[ndict] = get(dict[ndict]); ndict++);

		while (gets(w) && w[0] != '#') {
			if (find_word(w)) {
				printf("%s is correct\n", w);
				continue;
			}
            size = strlen(w);
			printf("%s:", w);
			for (i = 0; i < ndict; i++) {
				if ((size == (len[i] + 1) && ins(dict[i], w)) ||
				    (size == (len[i] - 1) && ins(w, dict[i])) ||
				    (len[i] == size && rep(dict[i], w)))
					printf(" %s", dict[i]);
			}
			printf("\n");
		}

		if (t)
			printf("\n");
	}

	return 0;
}
