#include <stdio.h>
 //printing
int i, j, k;

void print(int rubixcube[6][3][3]) {
        printf("\n\n");

        for (j = 0; j < 3; j++) {
            printf("\t\t%d %d %d \n", rubixcube[0][j][0], rubixcube[0][j][1], rubixcube[0][j][2]);
        }
        printf("\n");

        for (j = 0; j < 3; j++) {
            for (i = 1; i < 5; i++) {
                printf("\t%d %d %d ", rubixcube[i][j][0], rubixcube[i][j][1], rubixcube[i][j][2]);
            }
            printf("\n");
        }

        printf("\n");

        for (j = 0; j < 3; j++) {
            printf("\t\t%d %d %d \n", rubixcube[5][j][0], rubixcube[5][j][1], rubixcube[5][j][2]);
        }

};