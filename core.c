#include "head.h"


void play(void){
	
	time_t s_time;
	struct tm * tm_duration;
	char entry[32];
	int pos[2], game_over = 0;
	GRID grid;
	
	init_grid(&grid);
	time(&s_time);

	show_grid(&grid, 0);

	do{

		printf(" > ");
		get_entry(entry);
		split(entry, pos);
		
		if (!strcmp(entry, "dig") || !strcmp(entry, "mark") || !strcmp(entry, "unmark")){
			if (valid_pos(grid.size, pos)){
				if (entry[0] == 'd')
					dig(&grid, pos);
				else if (entry[0] == 'm')
					mark(&grid, pos);
				else if (entry[0] == 'u')
					unmark(&grid, pos);
				show_grid(&grid, 0);
			}
			else
				printf(" # Invalid position, type help\n");
		}
		else if (!strcmp(entry, "end"))
			end(&(grid.nb_dug));
		else
			help_play();
		game_over = check(&grid);

	} while (!game_over);
	
	show_grid(&grid, 1);

	tm_duration = duration(s_time);
	printf(" # Your game lasted %dh %dm %ds\n", tm_duration->tm_hour, tm_duration->tm_min, tm_duration->tm_sec);

	if (game_over == 1)
		win(tm_duration, grid.size);
	else
		lose();

}


void dig(GRID * grid, int pos[2]){
	
	int i = 0, j = 0, neighbor_pos[2];
	CASE * this_case = &(grid->cases[pos[0]][pos[1]]);

	if (!this_case->dug){
		this_case->marked = false;
		this_case->dug = true;

		if (this_case->bomb)
			grid->nb_dug = -1;

		else{
			grid->nb_dug++;
			
			if (this_case->neighbors == 0){
				
				for (i = pos[0] - 1; i <= pos[0] + 1; i++){
				
					if (i >= 0 && i < grid->size){
						for (j = pos[1] - 1; j <= pos[1] + 1; j++){
						
							if (j >= 0 && j < grid->size){
								neighbor_pos[0] = i; neighbor_pos[1] = j;
								
								if (!this_case->neighbors && !grid->cases[i][j].dug){
									printf("NEXT DIG %d %d :\n", i, j);
									show_case(&(grid->cases[i][j]));
									dig(grid, neighbor_pos);
								} // !
							} // e
						} // e
					} // e
				} // e
			} // e
		} // e
	} // h
} // W


void mark(GRID * grid, int pos[2]){
	CASE * this_case = &(grid->cases[pos[0]][pos[1]]);

	/* The condition for winning by marking all bombs is
	 * that only bombs are marked, thus if we add 1 for
	 * every well marked case, the sum will equal the number 
	 * of bombs. To be sure the player has only marked bombs
	 * we add a malus (-1) for every falsely marked case.
	 */
	
	if (!this_case->marked){
		if (this_case->bomb)
			grid->nb_marked++;
		else
			grid->nb_marked--;
	}

	this_case->marked = true;
}

void unmark(GRID * grid, int pos[2]){
	CASE * this_case = &(grid->cases[pos[0]][pos[1]]);

	if (this_case->marked){
		if (this_case->bomb)
			grid->nb_marked--;
		else
			grid->nb_marked++;
	}

	grid->cases[pos[0]][pos[1]].marked = false;
}


int check(GRID * grid){
	
	if (grid->nb_marked == grid->nb_bombs || grid->nb_dug == grid->nb_safe)
		return 1;
	else if (grid->nb_dug == -1)
		return -1;
	
	return 0;

}


void win(struct tm * duration, int size){

	char entry[32];
	PLAYER winner;

	printf(
		" # Congratulations, you won!\n"
		" # Would you like to enter your name on the leaderboard?\n"
		);
	get_yn(entry);

	if (entry[0] == 'y'){
		printf(" # Enter your name\n > ");

		get_entry(winner.name);
		winner.time = *duration;
		winner.size = size;

		add_winner(&winner);
	}

}


void lose(void){

}


void end(int * dug){

	char entry[32];

	printf(" # Are you sure you want to abandon ?\n");
	get_yn(entry);
	if (entry[0] == 'y')
		*dug = -1;
}


void reset(void){
	
	char file_name[32];
	
	printf(" # Enter the name of the file to reset\n > ");
	get_entry(file_name);
	init_file(file_name);
}
