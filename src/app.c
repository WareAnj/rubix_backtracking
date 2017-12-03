#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "backtracking/print.h"
#include "backtracking/rotate_cube.h"
#include "backtracking/check.h"
#include "backtracking/read_file.h"

#define N 6 //min number of steps
#define faces 6
#define row 3
#define col 3
#define true 1
#define false 0
int i, j, k, candidate;
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
    int direction, face;
    
    read_file(rubixcube);

    while (1) {

        print(rubixcube);

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
