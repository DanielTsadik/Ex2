#include <stdio.h>
#include "my_mat.h"

#define INFINITE  9999999
#define MAT_SIZE  10

void getMatVal(int mat[MAT_SIZE][MAT_SIZE]) {
    for (int i =  0; i < MAT_SIZE; i++) {  
        for (int j =  0; j < MAT_SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int helpMat[MAT_SIZE][MAT_SIZE];

void make_path(int mat[MAT_SIZE][MAT_SIZE]) {
    // Initialize helpMat with values from mat
    for (int i =  0; i < MAT_SIZE; i++) {
        for (int j =  0; j < MAT_SIZE; j++) {
            helpMat[i][j] = mat[i][j];
        }
    }

    // Replace  0 with INFINITE in helpMat
    for (int i =  0; i < MAT_SIZE; i++) {
        for (int j =  0; j < MAT_SIZE; j++) {
            if (helpMat[i][j] ==  0) {
                helpMat[i][j] = INFINITE;
            }
        }
    }

    // Implement the Floyd-Warshall algorithm
    for (int k =  0; k < MAT_SIZE; k++) {
        for (int i =  0; i < MAT_SIZE; i++) {
            for (int j =  0; j < MAT_SIZE; j++) {
                if (helpMat[i][k] != INFINITE && helpMat[k][j] != INFINITE &&
                    helpMat[i][k] + helpMat[k][j] < helpMat[i][j]) {
                    helpMat[i][j] = helpMat[i][k] + helpMat[k][j];
                }
            }
        }
    }
}

int isTherePath(int mat[MAT_SIZE][MAT_SIZE], int i, int j) {
    make_path(mat);
    return helpMat[i][j] != INFINITE && helpMat[i][j] !=  0;
}

void shortestPath(int mat[MAT_SIZE][MAT_SIZE], int i, int j) {
    make_path(mat);
    if (helpMat[i][j] == INFINITE || helpMat[i][j] ==  0) {
        printf("No path exists.\n");
    } else {
        printf("Shortest path distance is %d.\n", helpMat[i][j]);
    }
}
