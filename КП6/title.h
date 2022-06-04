#ifndef _title_h_
#define _title_h_

typedef struct {
    char title[512];
    char artist[256];
    char top_genre[256];
    int year_released;
    int bpm;
    int dB;
    int duration;
    int popularity;
    int top_year;
    char artist_type[256];
} title;

#endif // _title_h_
