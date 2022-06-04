#include <stdio.h>
#include <string.h>
#include "fruit.h"

char* stringByFruit (fruit num){
    static char* fruits[] = {
            "apple",
            "avocado",
            "orange",
            "raspberry",
            "blackberry",
            "pineapple",
            "pear",
            "peanut",
            "watermelon",
            "grape",
            "melon",
            "blueberry",
            "cherry",
            "banana",
            "lemon",
            "grapefruit",
            "kiwi",
            "walnut",
            "mango",
            "tangerine",
            "beer"
    };
    if (num >= 0)
        return fruits[num];
    return "rot";
}
fruit fruitByString (char* str){
    static char* fruits[] = {
            "apple",
            "avocado",
            "orange",
            "raspberry",
            "blackberry",
            "pineapple",
            "pear",
            "peanut",
            "watermelon",
            "grape",
            "melon",
            "blueberry",
            "cherry",
            "banana",
            "lemon",
            "grapefruit",
            "kiwi",
            "walnut",
            "mango",
            "tangerine",
            "beer"
    };
    for (int i = 0; i < 21; i++){
        if (strcmp(fruits[i], str) == 0)
            return i;
    }
    return -1;
}
void fruitPrint(){
    static char* fruits[] = {
            "apple",
            "avocado",
            "orange",
            "raspberry",
            "blackberry",
            "pineapple",
            "pear",
            "peanut",
            "watermelon",
            "grape",
            "melon",
            "blueberry",
            "cherry",
            "banana",
            "lemon",
            "grapefruit",
            "kiwi",
            "walnut",
            "mango",
            "tangerine",
            "beer"
    };
    for (int i = 0; i < 21; i++){
        printf("%s\n", fruits[i]);
    }
}
