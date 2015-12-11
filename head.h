#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "struct.h"


// CORE

void play(void);
void dig(GRID * grid, int arg[2]);
void mark(GRID * grid, int arg[2]);
void unmark(GRID * grid, int arg[2]);
int check(GRID * grid);
void end(int * nb_dug);
void win(struct tm * duration, int size);
void lose(void);
void reset(void);

// DISPLAY

void show_grid(GRID * grid, int reveal);
void show_border_h(int size, int tabs);
void show_border_v(int i, int max, int tabs);
void print_tabs(int tabs);
void show_scores(void);
void show_board(char file_name[32]);
void show_case(CASE * this_case);
void show_all_cases(GRID * grid);
void help_main(void);
void help_play(void);

// INIT

void init_grid(GRID * grid);
void inc_values(GRID * grid, int x, int y);
void init_file(char file_name[32]);


// INPUT

void get_entry(char entry[32]);
int get_difficulty(void);
int get_int(void);
int get_size(void);
void get_yn(char entry[32]);
void get_board(char entry[32]);


// FILE

void add_winner(PLAYER * winner);
PLAYER ** load(char file_name[32]);
void save(char file_name[32], PLAYER ** players);



// TOOLS

void split(char entry[32], int pos[2]);
int valid_pos(int size, int pos[2]);
char case2char(CASE * this_case, int reveal);
struct tm * duration(time_t s_time);
int player_gt(PLAYER * p1, PLAYER * p2);
