#include "head.h"


void split(char entry[32], int pos[2]){
	
	char c = 'A';
	char temp[32];

	strcpy(temp, entry);
	
	sscanf(temp, "%s %c%d", entry, &c,  pos);
	pos[1] = (int)(c - 'A');
	pos[0] -= 1;
}

int valid_pos(int size, int pos[2]){
	return (pos[0] >= 0 && pos[0] < size && pos[1] >= 0 && pos[1] < size);
}

char case2char(CASE * this_case, int reveal){
	
	/*	
	 *	How to show different cases
	 *
	 *	dug :	bomb :	'X'
	 *			else :	number of neighbors ('0'..'8')
	 *	not d :	marked : '+'
	 *			else :	' '
	 */
	
	if (!reveal){ // Still in game
		if (this_case->marked)
			return '+'; // Marked cases
		else if (!this_case->dug)
			return ' '; // Not dug nor marked yet
	}

	else if (this_case->bomb){ // Game over, show the bombs
		if (this_case->dug)
			return 'X'; // The bomb that exploded
		else
			return '@'; // Bombs that didn't explode
	}

	return this_case->neighbors + '0'; // Dug safe case, show the neighbors
}


struct tm * duration(time_t s_time){
	time_t e_time;
	time(&e_time);
	int time_t_duration = (int)difftime(e_time, s_time);

	int h = time_t_duration / 3600;
	int m = (time_t_duration -= h * 3600) / 60;
	int s = (time_t_duration -= m * 60);

	h = h > 23 ? 23 : h; // In case some cave geek falls asleep 
	
	static struct tm tm_duration;
	tm_duration.tm_sec = s;
	tm_duration.tm_min = m;
	tm_duration.tm_hour = h;

	return &tm_duration;

}


int player_gt(PLAYER * p1, PLAYER * p2){

	int diff = difftime(mktime(&(p1->time)), mktime(&(p2->time)));
	if (diff < 0)
		return 1;
	return 0;
}
