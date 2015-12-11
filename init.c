#include "head.h"

void init_grid(GRID * grid){

	int s = (grid->size = get_size()), difficulty = get_difficulty(), i = 0, bomb_goal = 0, x = 0, y = 0; 
	CASE * this_case;

	bomb_goal = pow(s, 2) * difficulty / 10;

	grid->cases = malloc(s * sizeof(CASE *));
	if (grid->cases == NULL) exit(0);

	grid->nb_bombs = 0;
	grid->nb_safe = pow(s, 2) - bomb_goal;
	grid->nb_dug = 0;
	grid->nb_marked = 0;
	
	for (i = 0; i < s; i++){
		grid->cases[i] = malloc(s * sizeof(CASE));
		if (grid->cases[i] == NULL) exit(0);
	}


	while (grid->nb_bombs < bomb_goal){
		x = (rand() % s + s) % s;
		y = (rand() % s + s) % s;
		this_case = &(grid->cases[y][x]);
		
		if (!this_case->bomb){
			this_case->bomb = true;
			inc_values(grid, y, x);
			grid->nb_bombs++;
		}
	}
}


void inc_values(GRID * grid, int y, int x){

	int i = 0, j = 0;

	for (i = y - 1; i <= y + 1; i++){
		if (i >= 0 && i < grid->size){

			for (j = x - 1; j <= x + 1; j++){
				if (j >= 0 && j < grid->size){
					grid->cases[i][j].neighbors++;
				}
			}
		}
	}
}


void init_files(char file_name[32]){
	
	int i = 0;
	
	PLAYER blank = {.name = "", .time = {0,0,0,0,0,0,0,0,0}, .size = 0};
	PLAYER ** noobs = malloc(10 * sizeof(PLAYER *));


	for (i = 0; i < 10; i++)
		noobs[i] = &blank;

	save(file_name, noobs);
}
