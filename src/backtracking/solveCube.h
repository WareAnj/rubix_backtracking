#include <stdio.h>

#include "rotateCube.h"

#define N 12
#define maxmoves 6

void solveCube (int rubixcube[6][3][3]) {

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


    for(n = 1; n <= maxmoves;n++){
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
                        
                    
                    for(i=1;i<move;i++){
                        if(option[i][nopts[i]] == 1){
                            //printf("w cw \n");
                            rotateCube(rubixcube, 0, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 2){
                            //printf("w cc \n");
                            rotateCube(rubixcube, 0, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 3){
                            //printf("r cw \n");
                            rotateCube(rubixcube, 1, "CLOCKWISE");

                        }

                        if(option[i][nopts[i]] == 4){
                            //printf("r cc \n");
                            rotateCube(rubixcube, 1, "!CLOCKWISE");

                        }

                        if(option[i][nopts[i]] == 5){
                            //printf("b cw \n");
                            rotateCube(rubixcube, 2, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 6){
                            //printf("b cc \n");
                            rotateCube(rubixcube, 2, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 7){
                            //printf("o cw \n");
                            rotateCube(rubixcube, 3, "CLOCKWISE");

                        }

                        if(option[i][nopts[i]] == 8){
                            //printf("o cc \n");
                            rotateCube(rubixcube, 3, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 9){
                            //printf("g cw \n");
                            rotateCube(rubixcube, 4, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 10){
                            //printf("g cc \n");
                            rotateCube(rubixcube, 4, "!CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 11){
                            //printf("y cw \n");
                            rotateCube(rubixcube, 5, "CLOCKWISE");
                        }

                        if(option[i][nopts[i]] == 12){
                            //printf("y cc \n");
                            rotateCube(rubixcube, 5, "!CLOCKWISE");
                        }
                    }

                    //printf("%2i",option[i][nopts[i]]);

                    //print(rubixcube);

                    if(check(rubixcube) == 1){
                        //return the 'moves'
                        for(i = 0;i < move;i++){
	                        if(option[i][nopts[i]] == 1){
	                            //printf("w cw \n");
	                           printf("Move %d: rotateCube(cube, WHITE, CLOCKWISE)", i)
	                        }

	                        if(option[i][nopts[i]] == 2){
	                            //printf("w cc \n");
	                           printf("Move %d: rotateCube(cube, WHITE, !CLOCKWISE)", i);
	                        }

	                        if(option[i][nopts[i]] == 3){
	                            //printf("r cw \n");
	                           printf("Move %d: rotateCube(cube, RED, CLOCKWISE)", i)

	                        }

	                        if(option[i][nopts[i]] == 4){
	                            //printf("r cc \n");
	                           printf("Move %d: rotateCube(cube, RED, !CLOCKWISE)", i);

	                        }

	                        if(option[i][nopts[i]] == 5){
	                            //printf("b cw \n");
	                           printf("Move %d: rotateCube(cube, BLUE, CLOCKWISE)", i)
	                        }

	                        if(option[i][nopts[i]] == 6){
	                            //printf("b cc \n");
	                           printf("Move %d: rotateCube(cube, BLUE, !CLOCLWISE)", i);
	                        }

	                        if(option[i][nopts[i]] == 7){
	                            //printf("o cw \n");
	                           printf("Move %d: rotateCube(cube, ORANGE, CLOCKWISE)", i)

	                        }

	                        if(option[i][nopts[i]] == 8){
	                            //printf("o cc \n");
	                           printf("Move %d: rotateCube(cube, ORANGE, !CLOCKWISE)", i);
	                        }

	                        if(option[i][nopts[i]] == 9){
	                            //printf("g cw \n");
	                           printf("Move %d: rotateCube(cube, GREEN, CLOCKWISE)", i)
	                        }

	                        if(option[i][nopts[i]] == 10){
	                            //printf("g cc \n");
	                           printf("Move %d: rotateCube(cube, GREEN, !CLOCKWISE)", i);
	                        }

	                        if(option[i][nopts[i]] == 11){
	                            //printf("y cw \n");
	                           printf("Move %d: rotateCube(cube, YELLOW, CLOCKWISE)", i)
	                        }

	                        if(option[i][nopts[i]] == 12){
	                            //printf("y cc \n");
	                           printf("Move %d: rotateCube(cube, YELLOW, !CLOCKWISE)", i);
	                        }                        	
                        }
                        
                        printf("SOLUTION FOUND");
                    	print(rubixcube);
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
