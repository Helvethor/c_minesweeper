#include "head.h"


void play(void){
	
	char entry[32];
	int pos[2];
	BOOL end = false;
	GRID grid;
	
	init_grid(&grid);
	init_cases(&grid);

	do{

		printf(" > ");
		get_entry(entry);
		split(entry, pos);

		if (valid_pos(grid.size, pos)){

			if (!strcmp(entry, "dig"))
				dig(&grid, pos);
			else if (!strcmp(entry, "mark"))
				mark(&grid, pos);
			else if (!strcmp(entry, "unmark"))
				unmark(&grid, pos);

		}

	} while (!end);
}


void dig(GRID * grid, int pos[2]){
	
	int i = 0, j = 0, neighbor_pos[2];

	grid->cases[pos[1]][pos[0]].dug = true;

	if (grid->cases[pos[1]][pos[0]].neighbors == 0){
		for (i = pos[1] - 1; i <= pos[1] + 1; i++){
			if (i >= 0 && i < grid->size){
				
				for (j = pos[0] - 1; j <= pos[0] + 1; j++){
					if (j >= 0 && j < grid->size){
						neighbor_pos[0] = i; neighbor_pos[1] = j;
						dig(grid, neighbor_pos);
					}
				}
			}
		}
	}
}


void mark(GRID * grid, int pos[2]){
	grid->cases[pos[1]][pos[0]].marked = true;
}

void unmark(GRID * grid, int pos[2]){
	grid->cases[pos[1]][pos[0]].marked = false;
}
