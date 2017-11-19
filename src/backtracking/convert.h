#include <stdio.h>

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