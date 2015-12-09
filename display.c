#include "head.h"


void show_grid(GRID * grid){
	
	int i = 0, j = 0;
	char c;

	for (i = 0; i < grid->size; i++){
		for (j = 0; j < grid->size; j++){
			c = case2char(&(grid->cases[i][j]));
			printf("%c ", c);
		}
	}
}

void show_scores(void){

}


void show_case(CASE * this_case){
	
	printf(
		"CASE :\tneigh : %d\n"
		"\tbomb : %d\n"
		"\tdug : %d\n"
		"\tmarked : %d\n",
		this_case->neighbors, this_case->bomb, this_case->dug, this_case->marked);

}


void help(void){
	printf(
		"\tplay\tStart a new game\n"
		"\tscores\tShow leaderboard\n"
		"\thelp\tFATAL ERROR : Max Recursion Depth Exceeded\n"
		);
}
