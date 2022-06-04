#include <stdio.h>
#include "title.h"
int main(int argc, char * argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Ошибка, некорректное число аргументов");
        return 100;
    }
    
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    title t;

    while(fscanf(in, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%[^\n]", t.title, t.artist, t.top_genre,
                 &t.year_released, &t.bpm, &t.dB, &t.duration, &t.popularity,
                 &t.top_year, t.artist_type) == 10)
    {
        if (fwrite(&t, sizeof(t), 1, out) != 1) {
            fprintf(stderr, "Ошибка в файле");
            return 101;
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}
