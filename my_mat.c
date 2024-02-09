#include <stdio.h>
#include "my_mat.h"

#define INFINITE  9999999 // we suppose that there's no edge's bigger than this number
#define MATRIX_SIZE  10 
// we get the input and intialize the matrix 
void getMatVal(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int row =  0; row < MATRIX_SIZE; row++) {
        for (int col =  0; col < MATRIX_SIZE; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }
}
// this is a global matrix which I know to be of Matrix_size
int helperMatrix[MATRIX_SIZE][MATRIX_SIZE]; 

int isTherePath(int matrix[MATRIX_SIZE][MATRIX_SIZE], int startIndex, int endIndex) {    
    // Copy the original matrix to the helper matrix
    for (int row =  0; row < MATRIX_SIZE; row++) {
        for (int col =  0; col < MATRIX_SIZE; col++) {
            if (row != col && matrix[row][col] ==  0) {
                helperMatrix[row][col] = INFINITE
            } 
            helperMatrix[row][col] = matrix[row][col];
        }
    }
    
    // Initialize the helper matrix with infinite values where the original has zero
    // for (int row =  0; row < MATRIX_SIZE; row++) {
    //     for (int col =  0; col < MATRIX_SIZE; col++) {
    //         if (row != col && helperMatrix[row][col] ==  0) {
    //             helperMatrix[row][col] = INFINITE;
    //         }
    //     }
    // }
    
    // Apply Floyd-Warshall algorithm to find shortest paths
    for (int k =  0; k < MATRIX_SIZE; k++) {
        for (int i =  0; i < MATRIX_SIZE; i++) {
            for (int j =  0; j < MATRIX_SIZE; j++) {
                if (helperMatrix[i][k] + helperMatrix[k][j] < helperMatrix[i][j]) {
                    helperMatrix[i][j] = helperMatrix[i][k] + helperMatrix[k][j];
                }
            }
        }
    }
    
    // Return whether a path exists between start and end index
    if (startIndex == endIndex) {
        return  0;
    }
    return (helperMatrix[startIndex][endIndex] != INFINITE && helperMatrix[startIndex][endIndex] !=  0);
}

void shortestPath(int matrix[MATRIX_SIZE][MATRIX_SIZE], int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        printf("-1\n");
        return;
    }
    isTherePath(matrix, startIndex, endIndex);
    int shortestPathValue = helperMatrix[startIndex][endIndex];
    if (!shortestPathValue || shortestPathValue == INFINITE) {
        printf("-1\n");
    } else {
        printf("%d\n", shortestPathValue);
    }
}
