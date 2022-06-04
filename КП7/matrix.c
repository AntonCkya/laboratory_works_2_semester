#include "matrix.h"
#include "vector.h"

twoInt matrixRead (vector *LB, vector *YE){
    int count = 0, value, m, n;
    printf("the width and height of the matrix:\n");
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &value);
            if (value != 0){
                vectorPushBack(LB, count);
                vectorPushBack(YE, value);
            }
            count++;
        }
    }
    twoInt t;
    t.first = m;
    t.second = n;
    return t;
}
twoInt maxElement (vector *LB, vector *YE, int m){
    int mx = 0;
    int mxIndex = -1, mxPrevIndex = -1;
    for (int i = 0; i < vectorGetSize(YE); i++){
        if (abs(vectorGet(YE, i)) > abs(mx)){
            mx = vectorGet(YE, i);
        }
    }
    for (int i = 0; i < vectorGetSize(YE); i++){
        if (vectorGet(YE, i) == mx){
            if (mxIndex == -1)
                mxIndex = vectorGet(LB, i) % m;
            else if (mxIndex < vectorGet(LB, i) % m){
                mxPrevIndex = mxIndex;
                mxIndex = vectorGet(LB, i) % m;
            }
            else if ((mxPrevIndex < vectorGet(LB, i) % m) && (vectorGet(LB, i) % m != mxIndex)){
                mxPrevIndex = vectorGet(LB, i) % m;
            }
        }
    }
    twoInt t;
    if (mxIndex == 0 || (mxIndex > 0 && mxPrevIndex == -1)){
        t.first = mx;
        t.second = mxIndex;
    }
    else {
        t.first = mx;
        t.second = mxPrevIndex;
    }
    return t;
}
void matrixDivideByMax (vector *LB, vector *YE, int m, int n){
    twoInt t = maxElement(LB, YE, m);
    int mx = t.first, column = t.second;
    for (int i = 0; i < vectorGetSize(YE); i++){
        if (vectorGet(LB, i) % m == column)
            vectorSet(YE, i, vectorGet(YE, i) / mx);
    }
}
void matrixPrint (vector *LB, vector *YE, int m, int n){
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if ((i * m + j) != vectorGet(LB, count))
                printf("0 ");
            else {
                printf("%d ", vectorGet(YE, count));
                count++;
            }
        }
        printf("\n");
    }
}
