#include <stdio.h>
#include <stdlib.h>

#include "convert.h"

int read_file () {
    int rubixcube[6][3][3];
    int i = 0, j = 0, k = 0;
    char temp1, temp2, temp3;
    FILE * fp;

    fp = fopen("../../res/input.txt", "r");

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

    return rubixcube;
}