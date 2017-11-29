#include <stdio.h>
#define faces 6
#define row 3
#define col 3
#define true 1
#define false 0
//checker if Rubik's cube is solved
int i, j, k;

int check(int cube[6][3][3]) {
	for( i = 0 ; i < faces ; i++ ){
		if(i == 0){
			for( j = 0 ; j < row ; j++ ){
				for( k = 0 ; k < col ; k++ ){
					if( cube[i][j][k] != i ){ return false;}
				}
			}
		}
	}

	printf("\n--CUBE SOLVED!--\n");
	return true;
};