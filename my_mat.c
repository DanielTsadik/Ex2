#include <stdio.h>
#include "my_mat.h"

//we suppose that no edge is bigger than 9999999
#define infinite 9999999
#define matSize 10

//After being called by A or the Defult we asj from the user input  
void getMatVal(int mat[matSize][matSize]) {
    for (int i = 0; i < matSize; i++) { 
        for (int j = 0; j < matSize; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
int helpMat[matSize][matSize];

// this functions uses make_path and then checks if there's a way from i -> j
int isTherePath (int mat[matSize][matSize], int i, int j){
    make_path(mat,i,j);
    if(i == j){
        return 0;
    }
    if(helpMat[i][j] == infinite || helpMat[i][j] == 0){
        return 0;
    }
    return 1;
}
//sae like isTherePath but now it returns the path
void shortestPath (int mat[matSize][matSize], int i, int j){
    if(i == j){
        printf("-1\n");
        return;
    }
    make_path(mat,i,j);
    
    if(helpMat[i][j] == infinite || helpMat[i][j] == 0)
        printf("-1\n");
    else{
        printf("%d\n", helpMat[i][j]);
    }
}
void make_path(int mat[matSize][matSize], int i, int j){
    if(i == j){
        printf("-1\n");
        return;
    }
        
    // int helpMat[matSize][matSize];
    for(int k = 0; k < matSize; k++){
        for(int l = 0; l < matSize; l++){
            helpMat[k][l] = mat[k][l];
        }
    }
    for(int x = 0; x < matSize; x++){
        for(int y = 0; y < matSize; y++){
            if(x != y && helpMat[x][y] == 0)
                helpMat[x][y] = infinite;
        }
    }
    for (int x = 0; x < matSize; x++) {
        for (int y = 0; y < matSize; y++) {
            for (int z= 0; z < matSize; z++) {
                if (helpMat[y][x] + helpMat[x][z] < helpMat[y][z])
                    helpMat[y][z] = helpMat[y][x] + helpMat[x][z];
            }
        }
    }
}

