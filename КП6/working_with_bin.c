#include <stdio.h>
#include "title.h"
#include <string.h>
#include <stdlib.h>

int year_to_number(char * year){
    if(year == NULL)
        return 2016;
    int nyear = 0;
    int i = 0;
    while(year[i] != '\0'){
        if(year[i] < '0' || year[i] > '9')
            return 2016;
        nyear += year[i] - '0';
        nyear *= 10;
        i++;
    }
    nyear /= 10;
    if(nyear > 2019 || nyear < 2010)
        return 2016;
    return nyear;
    
}

int main(int argc, char * argv[])
{
    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Ошибка, некорректное число аргументов");
        return 100;
    }
    
    float average_pop = 0, count_pop = 0;
    title t;
    int user_year_released = year_to_number(argv[2]); 
    
    // Найти средний bpm и dB у песен, у которых популярность выше средней.
    // Вывести название песни и артиста, у которой популярность ближе всего к средней, вышедшей в 2016 году
    
    FILE *in = fopen(argv[1], "r");
    // average_pop
    while (fread(&t, sizeof(t), 1, in) == 1) {
        count_pop++;
        average_pop = (average_pop * ((count_pop - 1) / count_pop)) + ((float)t.popularity / count_pop);
    }
    printf("average popularity: %f\n", average_pop);
    fseek(in, 0, SEEK_SET);
    // average_bpm/dB
    float average_dB = 0, count_dB = 0;
    float average_bpm = 0, count_bpm = 0;
    while (fread(&t, sizeof(t), 1, in) == 1) {
        if ((float)t.popularity >= average_pop){
            count_bpm++; count_dB++;
            average_bpm = (average_bpm * ((count_bpm - 1) / count_bpm)) + ((float)t.bpm / count_bpm);
            average_dB = (average_dB * ((count_dB - 1) / count_dB)) + ((float)t.dB / count_dB);
        }
    }
    printf("average bpm: %f\n", average_bpm);
    printf("average dB: %f\n", average_dB);
    fseek(in, 0, SEEK_SET);
    // song
    char average_title[512], average_artist[256];
    float diff_by_average = average_pop;
    int artist_pop;
    while (fread(&t, sizeof(t), 1, in) == 1) {
        if(abs((float)t.popularity - average_pop) < diff_by_average && t.year_released == user_year_released){
            strcpy(average_title, t.title);
            strcpy(average_artist, t.artist);
            diff_by_average = abs((float)t.popularity - average_pop);
            artist_pop = t.popularity;
        }
    }
    printf("year: %d\n", user_year_released);
    printf("average song: %s\n", average_title);
    printf("average artist: \n%s\n", average_artist);
    printf("it's popularity: %d\n", artist_pop);
    fclose(in);
    return 0;
}

