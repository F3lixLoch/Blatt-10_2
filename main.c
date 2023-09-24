#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define RESULT_MSG "Von [%d, %d] nach [%d, %d] gelangt man mit %d Schritten.\n"

Position move(Position from, Position movement) {
    return (Position) {from.x + movement.x, from.y + movement.y};
}

bool position_equal(Position p, Position q) {
    return (p.x == q.x) && (p.y == q.y);
}

/* Erzeugt ein 2d-int-Array arr[0...width-1][0...height-1] auf dem Heap
 * und initialisiert es mit default_val. */
int** create_array_2d(int width, int height, int default_val) {
    // TODO Implementieren Sie diese Funktion
    return NULL;
}

/* Gegenstück zu create_array_2d; gibt den von arr belegten Speicher wieder frei */
void destroy_array_2d(int** arr, int width) {
    // TODO Implementieren Sie diese Funktion
}

/* Liefert true zurück, falls Position p nicht betreten werden kann
 * (weil p außerhalb des Spielfeldes liegt oder durch eine Wand blockiert ist */
bool blocked(const Labyrinth* l, Position p) {
    // TODO Implementieren Sie diese Funktion
    return false;
}

/* Sucht einen Weg von l->start nach l->target, der möglichst wenige
 * Züge enthält. Gibt die Anzahl Züge auf diesem Weg zurück.
 * Die Funktion erzeugt keine Ausgabe */
int count_steps(const Labyrinth* l) {
    const int n_directions = 4;
    Position moves[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    // TODO Implementieren Sie diese Methode. Sie dürfen Datenstrukturen
    //      aus dem Repo benutzen.
    //
    //      Hinweise:
    //      - Passen Sie das Makefile an die gewählte Datnstruktur an :)
    //      - Es werden nur Datenstrukturen aus dem Repo benötigt.
    //      - Die Algorithmen zum Durchsuchen von Graphen aus der Aldat
    //        funktionieren nicht nur auf Graphen!

    return 0;
}

int main(void) {
    /* Hier bitte nichts ändern :) */
    Labyrinth* l = read_labyrinth(stdin);
    if(!l) {
        fprintf(stderr, "Fehler: Konnte Eingabe nicht lesen.\n");
        return 1;
    }
    labyrinth_print(l, stdout);

    printf(RESULT_MSG, l->start.x, l->start.y, l->target.x, l->target.y, count_steps(l));

    labyrinth_destroy(l);
    free(l);

    return 0;
}
