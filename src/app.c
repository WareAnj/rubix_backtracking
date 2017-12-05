#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "backtracking/print.h"
#include "backtracking/convert.h"
#include "backtracking/rotateCube.h"
#include "backtracking/check.h"

#define N 12 //min number of steps
#define faces 6
#define row 3
#define col 3
#define true 1
#define false 0
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



        print(rubixcube);

/*
w1 - w cw - 0, CLOCKWISE
w2 - w cc - 0
r1 - r cw - 1, CLOCKWISE 
r2 - r cc - 1
b1 - b cw - 2, CLOCKWISE
b2 - b cc - 2
o1 - o cw - 3, CLOCKWISE
o2 - o cc - 3
g1 - g cw - 4, CLOCKWISE
g2 - g cc - 4
y1 - y cw - 5, CLOCKWISE
y2 - y cc - 5
*/
    int savestate[6][3][3];
    int start, move;
    int nopts[N+2]; //array of top of stacks
    int option[N+2][N+2]; //array of stacks of options
    int candidate;
    int num = 0;
    int n, m;



    for(i = 0; i < 6; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3;k++){
                savestate[i][j][k] = rubixcube[i][j][k];
            }
        }
    }


    for(n = 1; n <= 5;n++){
        move = start = 0; 
        nopts[start]= 1;
        while (nopts[start] >0){//while dummy stack is not empty
            if(nopts[move]>0){
                

                move++;
                nopts[move]=0; //initialize new move            

                if(move==n+1){ //solution found!

                    /*
                    w1 - w cw - 0, CLOCKWISE
                    w2 - w cc - 0
                    r1 - r cw - 1, CLOCKWISE 
                    r2 - r cc - 1
                    b1 - b cw - 2, CLOCKWISE
                    b2 - b cc - 2
                    o1 - o cw - 3, CLOCKWISE
                    o2 - o cc - 3
                    g1 - g cw - 4, CLOCKWISE
                    g2 - g cc - 4
                    y1 - y cw - 5, CLOCKWISE
                    y2 - y cc - 5
                    */
                        

                    //printf("\nMOVE:%d\n",move);
                    //sleep(1);
                    //print(rubixcube); //REMOVE
                    
                    for(i=1;i<move;i++){
                        if(option[i][nopts[i]] == 1){
                            printf("w cw \n");
                            rotateCube(rubixcube, 0, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 2){
                            printf("w cc \n");
                            rotateCube(rubixcube, 0, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 3){
                            printf("r cw \n");
                            rotateCube(rubixcube, 1, "CLOCKWISE");

                        }

                        if(option[i][nopts[i]] == 4){
                            printf("r cc \n");
                            rotateCube(rubixcube, 1, "!CLOCKWISE");

                        }

                        if(option[i][nopts[i]] == 5){
                            printf("b cw \n");
                            rotateCube(rubixcube, 2, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 6){
                            printf("b cc \n");
                            rotateCube(rubixcube, 2, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 7){
                            printf("o cw \n");
                            rotateCube(rubixcube, 3, "CLOCKWISE");

                        }

                        if(option[i][nopts[i]] == 8){
                            printf("o cc \n");
                            rotateCube(rubixcube, 3, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 9){
                            printf("g cw \n");
                            rotateCube(rubixcube, 4, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 10){
                            printf("g cc \n");
                            rotateCube(rubixcube, 4, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 11){
                            printf("y cw \n");
                            rotateCube(rubixcube, 5, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 12){
                            printf("y cc \n");
                            rotateCube(rubixcube, 5, "!CLOCKWISE");
                        }
                    }

                        //printf("%2i",option[i][nopts[i]]);

                    //print(rubixcube);

                    if(check(rubixcube) == 1){
                        //return the 'moves'
                        for(i = 0;i < move;i++){
                        }
                        
                        print(rubixcube);
                        printf("SOLVED");
                        sleep(1000);
                    }

                    else{
                        //UNDO MOVES
                            for(i = 0; i < 6; i++){
                                for(j = 0; j < 3; j++){
                                    for(k = 0; k < 3;k++){
                                        rubixcube[i][j][k] = savestate[i][j][k];
                                    }
                                }
                            }
                    }

                    num++;
                    printf("---------------------------------------------\n");
                    //dirpts[move]--;
                }
                else { //populates options
                    for(candidate = N; candidate >=1; candidate --) {
                        nopts[move]++;
                        option[move][nopts[move]] = candidate;
                        //printf("nopts[move] %i candidate %i:\n", nopts[move], candidate);           
                    }
                }

            }
            else {
                move--;
                nopts[move]--;  
                
                
            }
        }

        printf("\n--  NEW --\n");
    }
    
}


    /*    


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
        

    */



