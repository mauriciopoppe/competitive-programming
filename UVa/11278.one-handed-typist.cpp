#include <stdio.h>
#include <string.h>
#define REP(i, a, b) for (i=a ; i<b ; i++)
#define FILE freopen("input.txt","r",stdin)
char *ns = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
char *nsr = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'";
char *s = "~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char *sr = "~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
 
char tab[256];
int main() {
 
    int I, LEN1 = strlen(sr), LEN2 = strlen(nsr);
    char ch;
 
    REP(I, 0, LEN1) {
        tab[s[I]] = sr[I];
    }
    REP(I, 0, LEN2) {
        tab[ns[I]] = nsr[I];
    }
 
    while (scanf("%c",&ch)==1) {
 
        if (ch=='\n') putchar('\n');
        else if (ch==' ') putchar(' ');
        else {
            putchar(tab[ch]);
        }
 
    }
 
    return 0;
}
