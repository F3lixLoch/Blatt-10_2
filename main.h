#ifndef MAIN_N_H
#define MAIN_N_H
#include "labyrinth.h"
#include "labyrinth.h"
#include "dlinkedlist.h"

typedef struct NodeListElement NodeListElement;
typedef struct Node Node;

struct Node{
  Position p; 
};

struct NodeListElement{
    int n_neighbours;
    Position* neighbours;
};

#endif
