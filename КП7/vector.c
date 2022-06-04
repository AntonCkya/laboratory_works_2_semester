
#include "vector.h"

void vectorInit (vector *v){
    v->bufferSize = 0;
    v->size = 0;
    v->first = 0;
    v->buffer = NULL;
}
void vectorDestroy (vector *v){
    v->bufferSize = 0;
    v->size = 0;
    v->first = 0;
    free(v->buffer);
}
int vectorGetSize (vector *v){
    return v->size;
}

int vectorGetBufferSize (vector *v){
    return v->bufferSize;
}
int* vectorGetBuffer (vector *v){
    return v->buffer;
}
int vectorGetFirstIndex (vector *v){
    return v->first;
}

bool vectorGrowBuffer (vector *v){
    int newBufferSize = v->bufferSize * 2;
    int newFirst = newBufferSize - v->bufferSize + v->first;
    if (v->bufferSize == 0){
        newBufferSize = 4;
        newFirst = 0;
    }
    int *newBuffer = realloc(v->buffer, newBufferSize * sizeof(int));
    if (newBuffer == NULL)
        return false;
    for (int i = 0; i < v->bufferSize; i++)
        newBuffer[(i + newFirst) % newBufferSize] = newBuffer[(i + v->first) % v->bufferSize];
    v->buffer = newBuffer;
    v->bufferSize = newBufferSize;
    v->first = newFirst;
    return true;
}
bool vectorCutBuffer (vector *v){
    int newBufferSize = v->bufferSize / 2;
    if (v->first + v->size <= newBufferSize){
        int *newBuffer = realloc(v->buffer, newBufferSize * sizeof(int));
        if (newBuffer == NULL)
            return false;
        v->bufferSize = newBufferSize;
        v->buffer = newBuffer;
        return true;
    }
    int maxId;
    if (v->first + v->size > v->bufferSize) {
        maxId = v->bufferSize - 1;
    } else {
        maxId = v->first + v->size - 1;
    }
    int newFirst = newBufferSize - maxId + v->first + 1;
    for (int i = 0; i < maxId - v->first; i++)
        v->buffer[i + newFirst] = v->buffer[v->first + 1];
    int *newBuffer = realloc(v->buffer, newBufferSize * sizeof(int));
    if (newBuffer == NULL)
        return false;
    v->bufferSize = newBufferSize;
    v->buffer = newBuffer;
    v->first = newFirst;
    return true;
}
bool vectorSetSize (vector *v, int newSize){
    while (v->bufferSize < newSize){
        if (!vectorGrowBuffer(v))
            return false;
    }
    v->size = newSize;
    return true;
}

bool vectorPushBack (vector *v, int value){
    if (v->size >= v->bufferSize){
        if (!vectorGrowBuffer(v))
            return false;
    }
    v->buffer[(v->first + v->size) % v->bufferSize] = value;
    v->size++;
    return true;
}
bool vectorPushFront (vector *v, int value){
    if (v->size >= v->bufferSize){
        if (!vectorGrowBuffer(v))
            return false;
    }
    v->buffer[(v->first - 1 + v->bufferSize) % v->bufferSize] = value;
    v->first = (v->first - 1 + v->bufferSize) % v->bufferSize;
    v->size++;
    return true;
}
int vectorPeekFront (vector *v){
    return v->buffer[v->first];
}
int vectorPeekBack (vector *v){
    return v->buffer[(v->first + v->size - 1) % v->bufferSize];
}
int vectorPopFront (vector *v){
    int value = v->buffer[v->first];
    v->first = (v->first + 1 + v->bufferSize) % v->bufferSize;
    v->size--;
    if (v->size * 4 <= v->bufferSize){
        vectorCutBuffer(v);
    }
    return value;
}
int vectorPopBack (vector *v){
    int value = v->buffer[(v->first + v->size - 1) % v->bufferSize];
    v->size--;
    if (v->size * 4 <= v->bufferSize){
        vectorCutBuffer(v);
    }
    return value;
}
int vectorGet (vector *v, int index){
    return v->buffer[(v->first + index) % v->bufferSize];
}
void vectorSet (vector *v, int index, int value){
    v->buffer[(v->first + index) % v->bufferSize] = value;
}
void vectorPrint (vector *v){
    for(int i = 0; i < vectorGetSize(v); i++){
        printf("%d ", vectorGet(v, i));
    }
    printf("\n");
}
bool vectorIn (vector *v, int value){
    for (int i = 0; i < vectorGetSize(v); i++){
        if (vectorGet(v, i) == value)
            return true;
    }
    return false;
}
