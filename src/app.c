#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "backtracking/convert.h"
#include "backtracking/rotate_cube.h"

/** 
 * GROUP Y - CMSC 142 C-2L
 * 
 * @AUTHOR: [
 *  Menguito, Aleck,
 *  Milano, Angelo,
 *  Ware, Angelica
 * ]
 **/

int main() {

    int rubixcube[6][3][3]; //3D array
    int i = 0, j = 0, k = 0, direction, face;
    char temp1, temp2, temp3;
    FILE * fp;

    //white -  ascii 87 - 0
    //red - ascii 82 - 1
    //blue - ascii 66 - 2
    //orange - ascii 79 - 3
    //green - ascii 71 - 4
    //yellow -ascii 89 - 5

    fp = fopen("../res/input.txt", "r");


    while (!feof(fp)) {


        if (i == 0) {
            for (j = 0; j < 3; j++) {
                fscanf(fp, "%c%c%c\n", & temp1, & temp2, & temp3);

                rubixcube[i][j][0] = (int) temp1;
                rubixcube[i][j][1] = (int) temp2;
                rubixcube[i][j][2] = (int) temp3;

                convert( & rubixcube[i][j][0]);
                convert( & rubixcube[i][j][1]);
                convert( & rubixcube[i][j][2]);
            }
            i++;
        }
        if (i == 1) {
            for (j = 0; j < 3; j++) {
                fscanf(fp, "%c%c%c\n", & temp1, & temp2, & temp3);

                rubixcube[i][j][0] = (int) temp1;
                rubixcube[i][j][1] = (int) temp2;
                rubixcube[i][j][2] = (int) temp3;

                convert( & rubixcube[i][j][0]);
                convert( & rubixcube[i][j][1]);
                convert( & rubixcube[i][j][2]);
            }
            i++;

        }
        if (i == 2) {
            for (j = 0; j < 3; j++) {
                fscanf(fp, "%c%c%c\n", & temp1, & temp2, & temp3);

                rubixcube[i][j][0] = (int) temp1;
                rubixcube[i][j][1] = (int) temp2;
                rubixcube[i][j][2] = (int) temp3;

                convert( & rubixcube[i][j][0]);
                convert( & rubixcube[i][j][1]);
                convert( & rubixcube[i][j][2]);
            }
            i++;

        }
        if (i == 3) {
            for (j = 0; j < 3; j++) {
                fscanf(fp, "%c%c%c\n", & temp1, & temp2, & temp3);

                rubixcube[i][j][0] = (int) temp1;
                rubixcube[i][j][1] = (int) temp2;
                rubixcube[i][j][2] = (int) temp3;

                convert( & rubixcube[i][j][0]);
                convert( & rubixcube[i][j][1]);
                convert( & rubixcube[i][j][2]);
            }
            i++;

        }
        if (i == 4) {
            for (j = 0; j < 3; j++) {
                fscanf(fp, "%c%c%c\n", & temp1, & temp2, & temp3);

                rubixcube[i][j][0] = (int) temp1;
                rubixcube[i][j][1] = (int) temp2;
                rubixcube[i][j][2] = (int) temp3;

                convert( & rubixcube[i][j][0]);
                convert( & rubixcube[i][j][1]);
                convert( & rubixcube[i][j][2]);
            }
            i++;

        }
        if (i == 5) {
            for (j = 0; j < 3; j++) {
                fscanf(fp, "%c%c%c\n", & temp1, & temp2, & temp3);

                rubixcube[i][j][0] = (int) temp1;
                rubixcube[i][j][1] = (int) temp2;
                rubixcube[i][j][2] = (int) temp3;

                convert( & rubixcube[i][j][0]);
                convert( & rubixcube[i][j][1]);
                convert( & rubixcube[i][j][2]);
            }
            i++;

        }
    }

    fclose(fp);


    while (1) {

        //PRINTING OF 2D RUBIK's CUBE

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


        printf("\n");
        printf("Rotate Side (0-5): ");
        scanf("%d", & face);

        printf("1-CW or 2-CCW: ");
        scanf("%d", & direction);

        if (direction == 1) {
            rotate_cube(rubixcube, face, "CLOCKWISE");
            printf("\n\t\tCLOCKWISE\n");
        } else if (direction == 2) {
            rotate_cube(rubixcube, face, "!CLOCKWISE");
            printf("\n\t\tCOUNTER-CLOCKWISE\n");
        } else printf("No direction chosen! \n");

    }


}

//white -  ascii 87 
//red - ascii 82
//blue - ascii 66
//orange - ascii 79
//green - ascii 71
//yellow -ascii 89
