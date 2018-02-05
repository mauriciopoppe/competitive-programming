#include<stdio.h>
#include<string.h>
#define M 30
int main()
{    
    int score[M], bonus[M], ball[M];
    int start[M];
    int spare[M], strike[M];
    char w[100];
    while(gets(w) && w[0] != 'G')
    {
        int size = strlen(w);
        memset(spare, 0, sizeof spare);
        memset(strike, 0, sizeof strike);
        
        int i, play, n_ball;
        for(i = 0, play = 0, n_ball = 0; i < size; i += 2, ++n_ball)
           if(w[i] == 'X')
           {
               strike[play] = 1;
               ball[n_ball] = 10;
               score[play] = 10;
               start[play] = n_ball;
               ++play;
           }
           else
           {
               score[play] = ball[n_ball] = w[i] - '0';
               start[play] = n_ball;
               i += 2;
               ++n_ball;
               if(w[i] == '/')
               {
                   spare[play] = 1;
                   ball[n_ball] = 10 - ball[n_ball - 1];
                   score[play] = 10;  
               }
               else
                   score[play] += (ball[n_ball] = w[i] - '0');
               ++play;
           }
        
        int total = 0;
        
        for(i = 0; i < 10; ++i)
        {
           bonus[i] = 0;     
           if(strike[i])
              bonus[i] = ball[start[i + 1]] + ball[start[i + 1] + 1];
           else if(spare[i])
              bonus[i] = ball[start[i + 1]];
           total += score[i] + bonus[i];
        }
        
        printf("%d\n", total);
    }
    return 0;
}
