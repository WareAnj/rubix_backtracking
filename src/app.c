#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "backtracking/print.h"
#include "backtracking/convert.h"
#include "backtracking/rotate_cube.h"
#include "backtracking/check.h"

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
    int i = 0, j = 0, k = 0, direction, face;
    char temp1, temp2, temp3;
    FILE * fp;

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

        print(rubixcube);
       
        /*

        int moves[faces+2][faces+2];    //last index is for direction
        int tos_moves[N+2]; //top of stack of moves/faces to be moved
        int dir_moves[N+2]; //top of stack of moves/faces to be moved
        int move, start;

        move = start = 0;
        tos_moves[start] = 1;   //dummy stack
        dir_moves[start] = 0;   //dummy stack

        while(tos_moves[start] > 0){ //dummy stack is not empty
            if(tos_moves[move] > 0){
                move++;
                tos_moves[move] = 0; 
                if(move != N+1){    //populate table
                    if(dir_moves[move] == 0){
                         dir_moves[move] = 2; //set direction
                    }
                   
                    for(candidate = N-1; candidate >=0; candidate --) {
                        tos_moves[move]++;
                        moves[move][tos_moves[move]] = candidate;        
                    }

                }
                else{
                    //rotate_cube(int cube[6][3][3], int face, char dir[18])
                    
                    for(i=1;i<move;i++){
                         printf("Side: %d direction: %d \n", moves[i][tos_moves[i]],dir_moves[i]);
                        if(dir_moves[i] == 2){  //clockwise
                            rotate_cube(rubixcube, moves[i][tos_moves[i]], "!CLOCKWISE");
                        }
                        
                        else{   //counter-clockwise
                            rotate_cube(rubixcube, moves[i][tos_moves[i]], "CLOCKWISE");
                        }   
                    }
                    if(check(rubixcube) == 1){

                        return;
                    }
                    //undo the rotations if answer not found
                    for(i=move-1;i>=1;i--){
                    
                        if(dir_moves[i] == 2){  //clockwise
                            rotate_cube(rubixcube, moves[i][tos_moves[i]], "CLOCKWISE");
                        }
                        
                        else{   //counter-clockwise
                            rotate_cube(rubixcube, moves[i][tos_moves[i]], "CLOCKWISE");
                    }
                    print(rubixcube);   
                }    
                    //check if solved, else back track
                }
            }

            else{   
                if(tos_moves[move] == 0){
                    sleep(10);
                    printf("PASS\n");
                    if(move != 0){
                        if(tos_moves[move] == 0){
                            move--;//move to next
                        }
                        tos_moves[move]--;
                    }    
            }
                else{
                    if(dir_moves[move] == 1){
                        move--;
                        tos_moves[move]--;
                    }
                    else{
                        dir_moves[move]--;
                    }   
                }

            }   
        }
        */



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
