#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "backtracking/print.h"
#include "backtracking/rotateCube.h"
#include "backtracking/check.h"
#include "backtracking/readFile.h"

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
    
    readFile(rubixcube);
    if (!check(rubixcube)) {
        solve();
    }
}
