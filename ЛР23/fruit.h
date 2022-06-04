#ifndef FRUIT_H
#define FRUIT_H

typedef enum {
    apple = 0,
    avocado,
    orange,
    raspberry,
    blackberry,
    pineapple,
    pear,
    peanut,
    watermelon,
    grape,
    melon,
    blueberry,
    cherry,
    banana,
    lemon,
    grapefruit,
    kiwi,
    walnut,
    mango,
    tangerine,
    beer,
    rot = -1
} fruit;
char* stringByFruit (fruit num);
fruit fruitByString (char* str);
void fruitPrint();

#endif //FRUIT_H
