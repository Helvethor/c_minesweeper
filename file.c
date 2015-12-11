#include "head.h"


void add_winner(PLAYER * winner){
	
	int i = 0, j = 0;
	char leader_file[32] = "leader_board_", s_size[3];
	
	sprintf(s_size, "%d", winner->size);
	strcat(leader_file, s_size);

	PLAYER ** leaders = load(leader_file);
	PLAYER ** lasts = load("recent_players");
	
	for (i = 9; i > 0; i--){
		lasts[i] = lasts[i - 1];
	}
	lasts[0] = winner;

	while (i < 10 && player_gt(leaders[i], winner))
		i++;

	if (i < 10){
		for (j = 9; j > i; j--)
			leaders[j] = leaders[j - 1];
		leaders[j] = winner;
	}

	save(leader_file, leaders);
	save("recent_players", lasts);

	free(leaders);
	free(lasts);
}


void save(char file_name[32], PLAYER ** players){
	
	FILE * file = fopen(file_name, "wb");

	if (file){
		fwrite(players, sizeof(PLAYER *), 10, file);
		fclose(file);
	}
}


PLAYER ** load(char file_name[32]){
	
	FILE * file = fopen(file_name, "ab+");
	PLAYER ** players;
	players = malloc(10 * sizeof(PLAYER *));

	if (file){
		fread(players, sizeof(PLAYER *), 10, file);
		fclose(file);
	}

	return players;

}
