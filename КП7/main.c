#include "vector.h"
#include "matrix.h"

int main() {
    vector LB, YE;
    vectorInit(&LB); vectorInit(&YE);
    twoInt t;
    t = matrixRead(&LB, &YE);
    if(vectorGetSize(&LB) == 0){
        printf("Zero matrix are not process\n");
        return 0;
    }
    int m = t.first, n = t.second;
    matrixDivideByMax(&LB, &YE, m, n);
    printf("new matrix:\n");
    matrixPrint(&LB, &YE, m, n);
    vectorDestroy(&LB); vectorDestroy(&YE);
    return 0;
}
