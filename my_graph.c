
#include <stdio.h>
#include "my_mat.h" 

int main(){
    int mat[matSize][matSize];
    char c;
    scanf("%c", &c);
    while(c != 'A'){
         scanf("%c", &c);
    }
    //get matrix from the user
    getMatVal(mat);
    while(c != 'D'){
        if(c == 'A')
            //if A then we want to restart the matrix values and get a new input
            getMatVal(mat);
        if(c == 'B'){
            int i, j;
            scanf("%d %d", &i, &j);
            if(isTherePath(mat, i, j)){
                printf("True\n");
            }
            else{
                printf("False\n");
            }
        }
        if(c == 'C'){
            int i, j;
            scanf("%d %d", &i, &j);
            shortestPath(mat, i, j);
        }
        scanf("%c", &c);
    }
    return 0;
}
