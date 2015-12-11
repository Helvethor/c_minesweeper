#include "head.h"


void show_grid(GRID * grid, int reveal){
	
	int i = 0, j = 0;
	char c;
	
	printf("\n");
	show_border_h(grid->size, 2);

	for (i = 0; i < grid->size; i++){
		
		show_border_v(i, grid->size, 2);

		for (j = 0; j < grid->size; j++){
			c = case2char(&(grid->cases[i][j]), reveal);
			printf(" %c", c);
		}
		
		printf(" ");
		show_border_v(i, grid->size, 0);
		printf("\n");
	}

	show_border_h(grid->size, 2);
	printf("\n");
}

void show_border_h(int size, int tabs){
	
	int i = 0;
	char lines[4];
	char blanks[4];

	if (size < 10){
		strcpy(lines, "---");
		strcpy(blanks, "   ");
	}
	else {
		strcpy(lines, "----");
		strcpy(blanks, "    ");
	}
	
	print_tabs(tabs);
	printf("+%s+", lines);
	for(i = 0; i < size; i++)
		printf("--");
	printf("-+%s+\n", lines);
	
	print_tabs(tabs);
	printf("|%s|", blanks);
	for(i = 0; i < size; i++)
		printf(" %c", (char)(i + 'A'));
	printf(" |%s|\n", blanks);
	
	print_tabs(tabs);
	printf("+%s+", lines);
	for(i = 0; i < size; i++)
		printf("--");
	printf("-+%s+\n", lines);

}


void show_border_v(int i, int max, int tabs){
	
	print_tabs(tabs);
	if (max < 10 || i >= 9)
		printf("| %d |", i + 1);
	else if (i < 10)
		printf("|  %d |", i + 1);
}


void print_tabs(int tabs){
	int j = 0;
	for (j = 0; j < tabs; j++)
		printf("\t");
}


void show_scores(void){
	
	char entry[32], leader_file[32];
	int size = 0;

	get_board(entry);

	if (entry[0] == 'l'){
		printf(" # Choose the category to show (IE width of the board)\n > ");
		size = get_int();
		sprintf(leader_file, "leader_board_%d", size);
		show_board(leader_file);
	}
	else
		show_board("recent_players");
}


void show_board(char file_name[32]){

	int i = 0;
	PLAYER ** players = load(file_name);

	for (i = 0; i < 0; i++){
		if (players[i]->name[0] != '\0'){
			printf("%s\t%d\t%d:%d:%d\n", players[i]->name, players[i]->size, players[i]->time.hour, players[i]->time.min, players[i]->time.sec);
		}
	}

}


void show_case(CASE * this_case){
	// Debug function

	printf(
		"CASE :\tneigh : %d\n"
		"\tbomb : %d\n"
		"\tdug : %d\n"
		"\tmarked : %d\n",
		this_case->neighbors, this_case->bomb, this_case->dug, this_case->marked);

}


void show_all_cases(GRID * grid){
	
	int i = 0, j = 0;

	for (i = 0; i < grid->size; i++){
		for(j = 0; j < grid->size; j++)
			show_case(&(grid->cases[i][j]));
	}
}


void help_main(void){
	printf(
		" # Main commands\n"
		"   play\n      Start a new game\n"
		"   scores\n      Show leaderboard\n"
		"   help\n      FATAL ERROR : Max Recursion Depth Exceeded\n"
		);
}


void help_play(void){
	printf(
		" # Play commands\n"
		"   dig <pos>\n      Dig a case\n"
		"   mark <pos>\n      Mark a case\n"
		"   unmark <pos>\n      Unmark a case\n"
		"   <pos>\n      A1..P16, represents a case on the grid\n"
		);
}
