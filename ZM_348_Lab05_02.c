#include <stdio.h>
#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%-5d", m1[i][j] + m2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            int sum = 0;
            for (int k = 0; k < SIZE; k++){
                sum += (m1[i][k] * m2[k][j]);
            }
            printf("%-5d", sum);
        }
        printf("\n");
    }
    printf("\n");
}

void transposeMatrix(int m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%-5d", m[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMatrix(int m[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%-5d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };
    
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1},
    };
    
    int choice;
    printf("Add Matrices (1)\nMultiply Matrices (2)\nTranspose Matrices (3)\nPrint Matrix (4)\nExit (5)\nEnter the funtion to run: ");
    scanf("%d", &choice);
    printf("\n");
    if (choice == 1){
        addMatrices(m1, m2);
        return main();
    }
    else if (choice == 2){
        multiplyMatrices(m1, m2);
        return main();
    }
    else if (choice == 3){
        printf("Which matix would you like to transpose (1 or 2): ");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 1){
            transposeMatrix(m1);
        }
        else if (choice == 2){
            transposeMatrix(m2);
        }
        else{
            printf("Invalid choice, returning to menu\n");
            choice = 0;
        }
        return main();
    }
    else if (choice == 4){
        printf("Which matix would you like to display (1 or 2): ");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 1){
            printMatrix(m1);
        }
        else if (choice == 2){
            printMatrix(m2);
        }
        else{
            printf("Invalid choice, returning to menu\n");
            choice = 0;
        }
        return main();
    }
    else if (choice == 5){
        printf("Exiting Program\n");
    }
    else{
        printf("Choice Entered was not valid\n");
        choice = 0;
        return main();
    }

    return 0;
}
