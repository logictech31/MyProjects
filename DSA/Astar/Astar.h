#ifndef _ASTAR_H_
#define _ASTAR_H_
#define MAX 64

static int goal = -1;

int heuristic(int value);

int closed_list[MAX];
int open_list[MAX];


#endif