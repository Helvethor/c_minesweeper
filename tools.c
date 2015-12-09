#include "head.h"


void split(char entry[32], int pos[2]){
	
	char c;
	
	sscanf(entry, "%s %c %d", entry, &c,  pos + 1);
	pos[0] -= (int)(c - 'A');
}

int valid_pos(int size, int pos[2]){
	return (pos[0] >= 0 && pos[0] < size && pos[1] >= 0 && pos[1] < size);
}

char case2char(CASE * this_case){
	
	/*	How to show dirrent cases
	 *
	 *	not dug : ' '
	 *	dug :	bomb :	'X'
	 *			normal : value of neighbors
	 */

	if (this_case->dug){
		if (this_case->bomb)
			return 'X';
		else
			return (char)(this_case->neighbors) + '0';
	}
	else
		return ' ';

	return ' ';
}
