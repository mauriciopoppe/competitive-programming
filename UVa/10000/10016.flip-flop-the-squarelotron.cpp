#include<stdio.h>
int m[101][101];
int k, n;

void swap(int *i, int *j)
{
     int t = *i;
     *i = *j;
     *j = t; 
}

void upside_down()
{
     int i, j;
     for(i = k, j = n - 1 - k; i < j; ++i, --j)
        swap(&m[i][k], &m[j][k]),
        swap(&m[i][n - 1 - k], &m[j][n - 1 - k]);
     for(i = k + 1; i < n - 1 - k; ++i)
        swap(&m[k][i], &m[n - 1 - k][i]);
}

void left_right()
{
     int i, j;
     for(i = k + 1, j = n - 2 - k; i < j; ++i, --j)
        swap(&m[k][i], &m[k][j]),
        swap(&m[n - 1 - k][i], &m[n - 1 - k][j]);
     for(i = k; i < n - k; ++i)
        swap(&m[i][k], &m[i][n - 1 - k]);
}

void main_diagonal()
{
     int i;
     for(i = k; i < n - k; ++i)
        swap(&m[k][i], &m[i][k]);
     for(i = k; i < n - k; ++i)
        swap(&m[n - 1 - k][i], &m[i][n - 1 - k]);
     swap(&m[k][n - 1 - k], &m[n - 1 - k][k]);
}

void inverse_diagonal()
{
     int i, j;
     for(i = k, j = n - 1 - k; i < n - k; ++i, --j)
        swap(&m[i][n - 1 - k], &m[k][j]);
     for(i = k, j = n - 1 - k; i < n - k; ++i, --j)
        swap(&m[i][k], &m[n - 1 - k][j]);
     swap(&m[k][k], &m[n - 1 - k][n - 1 - k]);
}

void print_board()
{
     int i, j;
       for(i = 0; i < n; ++i)
       {
          for(j = 0; j < n; ++j)
          {
              if(j) putchar(' ');
              printf("%d", m[i][j]);
          }
          putchar(10);
       }     
}

int main()
{
    int cas;
    int flip_to_apply, i, j;
    scanf("%d", &cas);
    while(cas--)
    {
       scanf("%d", &n); 
       for(i = 0; i < n; ++i)
          for(j = 0; j < n; ++j)
             scanf("%d", &m[i][j]);
       
       int levels = (n + 1) >> 1;
       int flips;
       for(k = 0; k < levels; ++k)
       {
           scanf("%d", &flips);
           for(i = 0; i < flips; ++i)
           {
               scanf("%d", &flip_to_apply);
               switch(flip_to_apply)
               {
                    case 1:
                         upside_down();
                         break;
                    case 2:
                         left_right();
                         break;
                    case 3:
                         main_diagonal();
                         break;
                    case 4:
                         inverse_diagonal();
                         break;          
               }
           }           
       }
       print_board();
    }
    return 0;
}
