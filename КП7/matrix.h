#ifndef __matrix_h__
#define __matrix_h__

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
#include "vector.h"
 
typedef struct {
    int first;
    int second;
} twoInt; 
 
twoInt matrixRead (vector *LB, vector *YE);
twoInt maxElement (vector *LB, vector *YE, int m);
void matrixDivideByMax (vector *LB, vector *YE, int m, int n);
void matrixPrint (vector *LB, vector *YE, int m, int n);

#endif //__matrix_h__
