#include "labyrinth.h"
#include <stdio.h>
#include <stdlib.h>

Labyrinth* create_labyrinth(int width, int height) {
    Labyrinth* l = malloc(sizeof(Labyrinth));
    l->width = width;
    l->height = height;

    l->start.x = 0;
    l->start.y = 0;
    l->target.x = 0;
    l->target.y = 0;

    l->is_wall = calloc(sizeof(bool*), width);
    for(int i=0; i < width; ++i) {
        l->is_wall[i] = calloc(sizeof(bool), height);
    }

    return l;
}

void labyrinth_destroy(Labyrinth* l) {
    for(int i=0; i < l->width; ++i) {
        free(l->is_wall[i]);
    }
    free(l->is_wall);
}

Labyrinth* read_labyrinth(FILE* f) {
    int width, height;

    if(fscanf(f, "%d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Fehler: Breite/Höhe in Zeile 1 erwartet.\n");
        return NULL;
    }

    Labyrinth* l = create_labyrinth(width, height);

    for(int j=0; j < l->height; ++j)  {
        for(int i=0; i <= l->width; ++i) { // +1 wegen '\n'
            char c;

            if(fscanf(f, "%c", &c) != 1) {
                fprintf(stderr, "Fehler: Konnte Eingabedatei nicht lesen.\n");
                labyrinth_destroy(l);
                free(l);
                return NULL;
            }

            bool early_end = false;
            switch(c) {
                case '+':
                    l->is_wall[i][j] = true;
                    break;

                case ' ':
                    l->is_wall[i][j] = false;
                    break;

                case 's':
                    l->is_wall[i][j] = false;
                    l->start = (Position) {i, j};
                    break;

                case 't':
                    l->is_wall[i][j] = false;
                    l->target = (Position) {i, j};
                    break;

                case '\n': // Zeile endet frühzeitig
                    early_end = true;
                    break;

                default:
                    fprintf(stderr, "Fehler: Unbekanntes Zeichen an Position %d %d.\n", i, j);
                    labyrinth_destroy(l);
                    free(l);
                    return NULL;
            }

            if(early_end) break;
        }
    }

    return l;
}

void labyrinth_print(const Labyrinth* l, FILE* f) {
    for(int j=0; j < l->height; ++j) {
        for(int i=0; i < l->width; ++i) {
            printf("\n x:%d y:%d width:%d height:%d\n",i,j, l->width, l->height);
//            printf("\n is_wall %d",l->is_wall[i,j]);
//            printf("\n start_x %d",l->start.x);
//            printf("\n target_x %d",l->target.x);
            
            if(l->is_wall[i][j]){
                fprintf(f, "+");
            }
            else if(i == l->start.x && j == l->start.y) {
                fprintf(f, "s");
            }
            else if(i == l->target.x && j == l->target.y) {
                fprintf(f, "t");
            }
            else {
                fprintf(f, " ");
            }
        }
        printf("\n post loop fault");
        
        fprintf(f, "\n");
        printf("\n post file stream");
        
    }
    printf("\n post post loop fault");
    
}
