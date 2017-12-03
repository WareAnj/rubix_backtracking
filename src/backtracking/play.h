#include <stdio.h>

#include "print.h"
#include "rotateCube.h"

void play (int rubixcube[6][3][3], int face, int direction) {
    while (1) {
        print(rubixcube);

        printf("\n");
        printf("Rotate Side (0-5): ");
        scanf("%d", & face);

        printf("1-CW or 2-CCW: ");
        scanf("%d", & direction);

        if (direction == 1) {
            rotateCube(rubixcube, face, "CLOCKWISE");
            printf("\n\t\tCLOCKWISE\n");
        } else if (direction == 2) {
            rotateCube(rubixcube, face, "!CLOCKWISE");
            printf("\n\t\tCOUNTER-CLOCKWISE\n");
        } else printf("No direction chosen! \n");
    }
}
