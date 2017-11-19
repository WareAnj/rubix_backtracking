#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * GROUP Y - CMSC 142 C-2L
 * 
 * @AUTHOR: [
 *  Menguito, Aleck,
 *  Milano, Angelo,
 *  Ware, Angelica
 * ]
 **/

int convert(int * color);
void rotate_cube(int cube[6][3][3], int face, char dir[]);

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

    fp = fopen("input.txt", "r");


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

int convert(int * color) {
    switch ( * color) {
        case 87:
            *
            color = * color - 87;
            break;
        case 82:
            *
            color = * color - 81;
            break;
        case 66:
            *
            color = * color - 64;
            break;
        case 79:
            *
            color = * color - 76;
            break;
        case 71:
            *
            color = * color - 67;
            break;
        case 89:
            *
            color = * color - 84;
            break;
        default:
            printf("Error! Invalid color!\n");
            break;
    }

};

void rotate_cube(int cube[6][3][3], int face, char dir[18]) {
    int i, temp[3];

    switch (face) {

        case 0:

            if (strcmp(dir, "CLOCKWISE") == 0) {
                temp[0] = cube[1][0][0];
                temp[1] = cube[1][0][1];
                temp[2] = cube[1][0][2];

                for (i = 1; i < 4; ++i) {
                    cube[i][0][0] = cube[i + 1][0][0];
                    cube[i][0][1] = cube[i + 1][0][1];
                    cube[i][0][2] = cube[i + 1][0][2];
                }

                cube[4][0][0] = temp[0];
                cube[4][0][1] = temp[1];
                cube[4][0][2] = temp[2];

            } else {
                temp[0] = cube[4][0][0];
                temp[1] = cube[4][0][1];
                temp[2] = cube[4][0][2];

                for (i = 4; i > 1; --i) {
                    cube[i][0][0] = cube[i - 1][0][0];
                    cube[i][0][1] = cube[i - 1][0][1];
                    cube[i][0][2] = cube[i - 1][0][2];
                }

                cube[1][0][0] = temp[0];
                cube[1][0][1] = temp[1];
                cube[1][0][2] = temp[2];
            }

            break;
        case 1:

            if (strcmp(dir, "CLOCKWISE") == 0) {
                temp[0] = cube[0][0][0];
                temp[1] = cube[0][1][0];
                temp[2] = cube[0][2][0];

                cube[0][0][0] = cube[4][0][2];
                cube[0][1][0] = cube[4][1][2];
                cube[0][2][0] = cube[4][2][2];

                cube[4][0][2] = cube[5][0][0];
                cube[4][1][2] = cube[5][1][0];
                cube[4][2][2] = cube[5][2][0];

                cube[5][0][0] = cube[2][0][0];
                cube[5][1][0] = cube[2][1][0];
                cube[5][2][0] = cube[2][2][0];

                cube[2][0][0] = temp[0];
                cube[2][1][0] = temp[1];
                cube[2][2][0] = temp[2];


            } else {

                temp[0] = cube[0][0][0];
                temp[1] = cube[0][1][0];
                temp[2] = cube[0][2][0];

                cube[0][0][0] = cube[2][0][0];
                cube[0][1][0] = cube[2][1][0];
                cube[0][2][0] = cube[2][2][0];

                cube[2][0][0] = cube[5][0][0];
                cube[2][1][0] = cube[5][1][0];
                cube[2][2][0] = cube[5][2][0];

                cube[5][0][0] = cube[4][0][2];
                cube[5][1][0] = cube[4][1][2];
                cube[5][2][0] = cube[4][2][2];

                cube[4][0][2] = temp[0];
                cube[4][1][2] = temp[1];
                cube[4][2][2] = temp[2];

            }

            break;

        case 2:

            if (strcmp(dir, "CLOCKWISE") == 0) {
                temp[0] = cube[0][2][0];
                temp[1] = cube[0][2][1];
                temp[2] = cube[0][2][2];

                cube[0][2][0] = cube[1][0][2];
                cube[0][2][1] = cube[1][1][2];
                cube[0][2][2] = cube[1][2][2];

                cube[1][0][2] = cube[5][0][0];
                cube[1][1][2] = cube[5][0][1];
                cube[1][2][2] = cube[5][0][2];

                cube[5][0][0] = cube[3][0][0];
                cube[5][0][1] = cube[3][1][0];
                cube[5][0][2] = cube[3][2][0];

                cube[3][0][0] = temp[0];
                cube[3][1][0] = temp[1];
                cube[3][2][0] = temp[2];


            } else {

                temp[0] = cube[3][0][0];
                temp[1] = cube[3][1][0];
                temp[2] = cube[3][2][0];

                cube[3][0][0] = cube[5][0][0];
                cube[3][1][0] = cube[5][0][1];
                cube[3][2][0] = cube[5][0][2];

                cube[5][0][0] = cube[1][0][2];
                cube[5][0][1] = cube[1][1][2];
                cube[5][0][2] = cube[1][2][2];

                cube[1][0][2] = cube[0][2][0];
                cube[1][1][2] = cube[0][2][1];
                cube[1][2][2] = cube[0][2][1];

                cube[0][2][0] = temp[0];
                cube[0][2][1] = temp[1];
                cube[0][2][2] = temp[2];

            }

            break;

        case 3:

            if (strcmp(dir, "CLOCKWISE") == 0) {
                temp[0] = cube[0][0][2];
                temp[1] = cube[0][1][2];
                temp[2] = cube[0][2][2];

                cube[0][0][2] = cube[2][0][2];
                cube[0][1][2] = cube[2][1][2];
                cube[0][2][2] = cube[2][2][2];

                cube[2][0][2] = cube[5][0][2];
                cube[2][1][2] = cube[5][1][2];
                cube[2][2][2] = cube[5][2][2];

                cube[5][0][2] = cube[4][0][0];
                cube[5][1][2] = cube[4][1][0];
                cube[5][2][2] = cube[4][2][0];

                cube[4][0][0] = temp[0];
                cube[4][1][0] = temp[1];
                cube[4][2][0] = temp[2];

            } else {

                temp[0] = cube[4][0][0];
                temp[1] = cube[4][1][0];
                temp[2] = cube[4][2][0];

                cube[4][0][0] = cube[5][0][2];
                cube[4][1][0] = cube[5][1][2];
                cube[4][2][0] = cube[5][2][2];

                cube[5][0][2] = cube[2][0][2];
                cube[5][1][2] = cube[2][1][2];
                cube[5][2][2] = cube[2][2][2];

                cube[2][0][2] = cube[0][0][2];
                cube[2][1][2] = cube[0][1][2];
                cube[2][2][2] = cube[0][2][2];

                cube[0][0][2] = temp[0];
                cube[0][1][2] = temp[1];
                cube[0][2][2] = temp[2];

            }

            break;
        case 4:

            if (strcmp(dir, "CLOCKWISE") == 0) {
                temp[0] = cube[3][0][2];
                temp[1] = cube[3][1][2];
                temp[2] = cube[3][2][2];

                cube[3][0][2] = cube[5][2][0];
                cube[3][1][2] = cube[5][2][1];
                cube[3][2][2] = cube[5][2][2];

                cube[5][2][0] = cube[1][0][0];
                cube[5][2][1] = cube[1][1][0];
                cube[5][2][2] = cube[1][2][0];

                cube[1][0][0] = cube[0][0][2];
                cube[1][1][0] = cube[0][1][2];
                cube[1][2][0] = cube[0][2][2];

                cube[0][0][0] = temp[0];
                cube[0][0][1] = temp[1];
                cube[0][0][2] = temp[2];

            } else {
                temp[0] = cube[0][0][0];
                temp[1] = cube[0][0][1];
                temp[2] = cube[0][0][2];

                cube[0][0][0] = cube[1][0][0];
                cube[0][0][1] = cube[1][1][0];
                cube[0][0][2] = cube[1][2][0];

                cube[1][0][0] = cube[5][2][0];
                cube[1][1][0] = cube[5][2][1];
                cube[1][2][0] = cube[5][2][2];

                cube[5][2][0] = cube[3][0][2];
                cube[5][2][1] = cube[3][1][2];
                cube[5][2][2] = cube[3][2][2];

                cube[3][0][2] = temp[0];
                cube[3][1][2] = temp[1];
                cube[3][2][2] = temp[2];

            }

            break;

        case 5:

            if (strcmp(dir, "CLOCKWISE") == 0) {
                temp[0] = cube[4][2][0];
                temp[1] = cube[4][2][1];
                temp[2] = cube[4][2][2];

                for (i = 4; i > 1; --i) {
                    cube[i][2][0] = cube[i - 1][2][0];
                    cube[i][2][1] = cube[i - 1][2][1];
                    cube[i][2][2] = cube[i - 1][2][2];
                }

                cube[1][2][0] = temp[0];
                cube[1][2][1] = temp[1];
                cube[1][2][2] = temp[2];
            } else {
                temp[0] = cube[1][2][0];
                temp[1] = cube[1][2][1];
                temp[2] = cube[1][2][2];

                for (i = 1; i < 4; ++i) {
                    cube[i][2][0] = cube[i + 1][2][0];
                    cube[i][2][1] = cube[i + 1][2][1];
                    cube[i][2][2] = cube[i + 1][2][2];
                }

                cube[4][2][0] = temp[0];
                cube[4][2][1] = temp[1];
                cube[4][2][2] = temp[2];


            }

            break;
    }
}
