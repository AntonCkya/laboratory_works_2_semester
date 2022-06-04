#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//heapsort

void swap_float(float* a, int i, int j){
    float temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void swap_string(char array_values[512][64], int i, int j){
    char temp;
    for(int k = 0; k < 64; k++){
        temp = array_values[i][k];
        array_values[i][k] = array_values[j][k];
        array_values[j][k] = temp;
    }
    
}
void heapify(float* array_keys, char array_values[512][64], int i, int size){
    int left, right, large;
    while (2*i + 1 < size){
        left = 2*i + 1;
        right = 2*i + 2;
        large = left;
        if (right < size && array_keys[right] > array_keys[left])
            large = right;
        if (array_keys[i] >= array_keys[large])
            break;
        swap_float(array_keys, i, large);
        swap_string(array_values, i, large);
        i = large;
    }
}

void build_heap (float* array_keys, char array_values[512][64], int size){
    for (int i = size/2; i >= 0; i--)
        heapify(array_keys, array_values, i, size);
}

void heap_sort (float* array_keys, char array_values[512][64], int size){
    build_heap(array_keys, array_values, size);
    int heapsize = size;
    for (int i = 0; i < size - 1; i++){
        swap_float(array_keys, 0, size - 1 - i);
        swap_string(array_values, 0, size - 1 - i);
        heapsize--;
        heapify(array_keys, array_values, 0, heapsize);
    }
}

int binary_search(float* array, float num, int size){
    int l = 0;
    int r = size-1;
    int m;
    while (l <= r){
        m = (l + r)/2;
        if (array[m] < num){
            l = m + 1;
        }else if (array[m] >= num){
            r = m - 1;
        }
    }
    if(array[m] == num)
        return m;
    else
        return -1;
}

int main()
{
    float key;
    int number;
    
    float array_keys[512];
    char array_values[512][64];
    
    printf("enter number of elements: \n");
    scanf("%d", &number);
    printf("enter sheet:\n");
    for(int i = 0; i < number; i++){ 
        scanf("%f:%s", &array_keys[i], array_values[i]);
    }
    heap_sort(array_keys, array_values, number);
    printf("sorted sheet:\n");
    for(int i = 0; i < number; i++){
        printf("%f:%s\n", array_keys[i], array_values[i]);
    }
    printf("enter element for find:\n");
    scanf("%f", &key);
    int ans = binary_search(array_keys, key, number);
    printf("find element:\n");
    if(ans == -1)
        printf("none\n");
    else{
        while(array_keys[ans] == key)
        {
            printf("%f:%s\n", array_keys[ans], array_values[ans]);
            ans++;
        }
    }
    return 0;
}
