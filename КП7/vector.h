#ifndef __vector_h__ 
#define __vector_h__

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <malloc.h>
 
typedef struct {
    int size;
    int bufferSize; 
    int first;
    int* buffer;
} vector;

void vectorInit (vector *v);
void vectorDestroy (vector *v);
int vectorGetSize (vector *v);
int vectorGetBufferSize (vector *v);
int* vectorGetBuffer (vector *v);
int vectorGetFirstIndex (vector *v);
bool vectorGrowBuffer (vector *v);
bool vectorCutBuffer (vector *v);
bool vectorSetSize (vector *v, int newSize);
bool vectorPushBack (vector *v, int value);
bool vectorPushFront (vector *v, int value);
int vectorPeekFront (vector *v);
int vectorPeekBack (vector *v);
int vectorPopFront (vector *v);
int vectorPopBack (vector *v);
int vectorGet (vector *v, int index);
void vectorSet (vector *v, int index, int value);
void vectorPrint (vector *v);
bool vectorIn (vector *v, int value);

#endif //__vector_h__
