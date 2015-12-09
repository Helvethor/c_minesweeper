#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "struct.h"


// CORE

void play(void);
void dig(GRID * grid, int arg[2]);
void mark(GRID * grid, int arg[2]);
void unmark(GRID * grid, int arg[2]);

// DISPLAY

void show_grid(GRID * grid);
void show_scores(void);
void show_case(CASE * this_case);
void help(void);

// INIT

void init_grid(GRID * grid);
void init_cases(GRID * grid);
void inc_values(GRID * grid, int x, int y);
void init_case(CASE * this_case);


// INPUT

void get_entry(char entry[32]);
int get_difficulty(void);
int get_size(void);


// TOOLS

void split(char entry[32], int pos[2]);
int valid_pos(int size, int pos[2]);
char case2char(CASE * this_case);
