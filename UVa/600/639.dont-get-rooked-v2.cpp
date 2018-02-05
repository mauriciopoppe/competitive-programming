#include <iostream>  
using namespace std;  
  
char chess[4][4];  
char tempChess[4][4];  
int everyPos[70000][16];  
int c;  
  

void print_subset(int n, int s)  
{  
    for (int i = 0; i < n; i++) {  
        if (s & (1 << i)) everyPos[c][i] = 1;  
        else everyPos[c][i] = 0;  
    }  
    c++;  
}  
  
  
void findAllPos(int n) {  
    for (int i = 0; i < 1 << n; i++) {  
        print_subset(n, i);  
    }  
}  
  

int checkRowColumn(int row, int column, int n) {  
    int i;  
    int ok = 1;  
    for (i = column - 1; i >= 0 && tempChess[row][i] != 'X'; i--) {  
        if (tempChess[row][i] == '*') {  
            ok = 0;  
            break;  
        }  
    }  
    if (ok == 0) return 0;  
      
    for (i = column + 1; i < n && tempChess[row][i] != 'X'; i++) {  
        if (tempChess[row][i] == '*') {  
            ok = 0;  
            break;  
        }  
    }  
    if (ok == 0) return 0;  
      
    for (i = row - 1; i >= 0 && tempChess[i][column] != 'X'; i--) {  
        if (tempChess[i][column] == '*') {  
            ok = 0;  
            break;  
        }  
    }  
    if (ok == 0) return 0;  
      
    for (i = row + 1; i < n && tempChess[i][column] != 'X'; i++) {  
        if (tempChess[i][column] == '*') {  
            ok = 0;  
            break;  
        }  
    }  
    if (ok == 0) return 0;  
    return 1;  
}  
  
int checkLegal(int k, int n) {  
    int count = 0;  
    int i;  
    int row;  
    int column;  

    for (i = 0; i < n * n; i++) {  
        row = i / n;  
        column = i % n;  
        if (everyPos[k][i] == 1 && tempChess[row][column] == '.') {  
            count++;  
            tempChess[row][column] = '*';  
        }  
    }  

    int ok = 1;  
    for (i = 0; i < n * n; ++i) {  
        row = i / n;  
        column = i % n;  
        if (tempChess[row][column] == '*' && checkRowColumn(row, column, n) == 0) {  
            ok = 0;  
            break;  
        }  
    }   
    if (ok) {  
        return count;  
    } else {  
        return 0;  
    }  
}  
  
int main()  
{  
    int n;  
    while (cin >> n) {  
        if (n == 0) break;  
        int i, j;  
        for (i = 0; i < n; i++) {  
            for (j = 0; j < n; j++) {  
                cin >> chess[i][j];  
            }  
        }  
        c = 0;  
        findAllPos(n * n);  
        int max = -1;  
        for (i = 0; i < c; i++) {  
            memcpy(tempChess, chess, sizeof(chess));  
            int temp = checkLegal(i, n);  
            if (temp > max) max = temp;  
        }  
        cout << max << endl;  
    }  
    return 0;  
}  
