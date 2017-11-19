#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
