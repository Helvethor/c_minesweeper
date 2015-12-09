#include "head.h"

void init_grid(GRID * grid){

	int i = 0;
	
	grid->size = get_size();
	grid->cases = malloc(grid->size * sizeof(CASE *));

	if (grid->cases == NULL) exit(0);

	for (i = 0; i < grid->size; i++){
		grid->cases[i] = malloc(grid->size * sizeof(CASE));
		if (grid->cases[i] == NULL) exit(0);
	}
}

void init_cases(GRID * grid){
	
	CASE * this_case = NULL;
	int difficulty = 0, nb_bombs = 0, i = 0, j = 0, x = 0, y = 0;
	difficulty = get_difficulty();

	/* 
	 * Difficulty gives the bomb ratio
	 * 1 : 10%
	 * 2 : 20%
	 * 3 : 30%
	 */
	nb_bombs = floor(pow(grid->size, 2) * difficulty / 10);
	grid->bombs = malloc(nb_bombs * sizeof(CASE *));
	grid->normals = malloc((pow(grid->size, 2) - nb_bombs) * sizeof(CASE *));
	grid->nb_bombs = 0;
	grid->nb_normals = 0;

	if (grid->bombs == NULL || grid->normals == NULL) exit(0);

	for (i = 0; i < grid->size; i++){
		for (j = 0; j < grid->size; j++){
			//printf("[%d, %d / %d] INIT CASE DEFAULT ", i, j, grid->size);
			show_case(&(grid->cases[i][j]));
			init_case(&(grid->cases[i][j]));
			//printf("DONE\n");
		 }
	}
	printf("CASE DEFAULT INIT SUCCESS\n");

	while (grid->nb_bombs < nb_bombs){
		x = (rand() % grid->size + grid->size) % grid->size;
		y = (rand() % grid->size + grid->size) % grid->size;
		
		show_case(this_case);
		printf("TA PUTAIN DE ");
		printf("[%d, %d] RAND BOMB\n", x, y);
		printf("PUTAIN DE ");
		this_case = &(grid->cases[y][x]);
		printf("TAMERE");
		if (this_case->bomb == false){
			printf("[%d / %d] CASE BOMB INIT ", grid->nb_bombs, nb_bombs);
			grid->bombs[grid->nb_bombs] = this_case;
			grid->nb_bombs++;
			printf("# INIT CASE ");
			this_case->bomb = true;
			printf("# INC NEIGH ");
			inc_values(grid, x, y);
			printf("# DONE\n");
		}
	}

	printf("CASE BOMB INIT SUCCESS");

	for (i = 0; i < grid->size; i++){
		for (j = 0; j < grid->size; j++){
			this_case = &(grid->cases[y][x]);
			
			if (!this_case->bomb){
				init_case(this_case);
				grid->normals[grid->nb_normals] = this_case;
				grid->nb_normals++;
			}
		 }
	}

}

void init_case(CASE * this_case){
	this_case->dug = false;
	this_case->marked = false;
	this_case->bomb = false;
	this_case->neighbors = 0;
}

void inc_values(GRID * grid, int x, int y){

	int i = 0, j = 0;

	for (i = y - 1; i <= y + 1; i++){
		if (i >= 0 && i < grid->size){

			for (j = x - 1; i <= x + 1; j++){
				if (j >= 0 && j < grid->size){
					grid->cases[i][j].neighbors++;
					printf("+1");
				}
			}
		}
	}
}
