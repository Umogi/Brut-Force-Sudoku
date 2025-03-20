#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

#define SIZE 9

int sudokuOriginal[SIZE][SIZE] = {
    {0, 7, 9,/**/ 1, 3, 2,/**/ 0, 8, 5},
    {0, 6, 0,/**/ 5, 9, 0,/**/ 7, 0, 0},
    {5, 0, 8,/**/ 7, 0, 0,/**/ 2, 1, 0},

    {0, 0, 0,/**/ 8, 0, 0,/**/ 9, 0, 0},
    {7, 0, 6,/**/ 3, 4, 0,/**/ 0, 0, 0},
    {8, 0, 1,/**/ 2, 0, 0,/**/ 4, 0, 3},

    {0, 8, 7,/**/ 0, 0, 0,/**/ 3, 0, 0},
    {9, 0, 3,/**/ 0, 0, 0,/**/ 5, 0, 8},
    {2, 5, 0,/**/ 0, 0, 0,/**/ 1, 9, 0}
};

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printSudoku(int array[SIZE][SIZE]) {
    system("cls");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(array[i][j] == sudokuOriginal[i][j]){
                setColor(7);
            }else{
                setColor(2);
            }
            
            if (array[i][j] == 0) {
                printf(". ");
            }else{  
                printf("%d ", array[i][j]);
            }    
        }
        printf("\n");
    }
}

bool horizontal(int x, int sudoku[SIZE][SIZE]){
    /*
    for (int i = 0; i < SIZE; i++){
        printf("%d, ", sudoku[x][i]);
    }
    Sleep(10000);
    */
    for (int i = 0; i < 9; i++){
        for (int j = i + 1; j < 9; j++){
            if (sudoku[x][i] != 0 && sudoku[x][j] != 0){
                if (sudoku[x][i] == sudoku[x][j]){
                    return false;
                }
            }
        }
    }

    return true;
}

bool vertical(int y, int sudoku[SIZE][SIZE]){
    /*
    for (int i = 0; i < SIZE; i++){
        printf("%d, ", sudoku[i][y]);
    }
    Sleep(10000);
    */
    for (int i = 0; i < 9; i++){
        for (int j = i + 1; j < 9; j++){
            if (sudoku[i][y] != 0 && sudoku[j][y] != 0){
                if (sudoku[i][y] == sudoku[j][y]){
                    return false;
                }
            }
        }
    }

    return true;
}

bool square(int x, int y, int sudoku[SIZE][SIZE]){
    int temp[9];
    int z = 0;

    int v = (x / 3) * 3;
    int h = (y / 3) * 3;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            temp[z++] = sudoku[i + v][j + h];
        }
    }

    for (int i = 0; i < 9; i++){
        for (int j = i + 1; j < 9; j++){
            if (temp[i] != 0 && temp[j] != 0){
                if (temp[i] == temp[j]){
                    return false;
                }
            }
        }
    }

    return true;
}


int main(int argc, char const *argv[]){
    
    printf("Sudoku Solver\n\n");

    int tempSudoku[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tempSudoku[i][j] = sudokuOriginal[i][j];
        }
    }

    int i = 0;
    int j = 0;

    int flag = 0;
    bool forward = true;

    printSudoku(tempSudoku);
    
    while (i < SIZE){
        while (j < SIZE){ 
            if (sudokuOriginal[i][j] == 0 && forward){
                for (int n = tempSudoku[i][j] + 1; n < 10; n++){
                    tempSudoku[i][j] = n;
                    printSudoku(tempSudoku);

                    if(square(i, j, tempSudoku) && horizontal(i, tempSudoku) && vertical(j, tempSudoku)){
                        flag = 0;
                        j++;
                        break;
                    }
                    
                    flag = 1;
                }

                if (flag == 1){
                    forward = !forward;
                }

            }else if (sudokuOriginal[i][j] == 0 && !forward){
                tempSudoku[i][j] = 0;
                do{
                    j--;
                    if (j < 0) {
                        i--;
                        j = SIZE - 1;
                    }
                } while (sudokuOriginal[i][j] != 0);

                forward = !forward;

            }else if (sudokuOriginal[i][j] != 0 && forward){
                j++;
            }else if (sudokuOriginal[i][j] != 0 && !forward){
                j--;
            }
        }
        i++;
        j = 0;
    }

    return 0;
}
