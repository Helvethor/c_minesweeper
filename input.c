#include "head.h"


void get_entry(char entry[32]){
	
	int i = 0;

	while ((entry[i] = getchar()) != '\n') i++;
	entry[i] = '\0';
}

int get_difficulty(){
	
	/*
	 * Easy : 10% of bombs
	 * Medium : 20% of bombs
	 * Hard : 30% of bombs
	 */

	char entry[32];

	do{
		printf(" # Choose difficulty : easy, medium, hard\n > ");
		get_entry(entry);
	} while (strcmp(entry, "easy") && strcmp(entry, "medium") && strcmp(entry, "hard"));
	
	if (entry[0] == 'e') // Lazy-ass method
		return 1;
	else if (entry[0] == 'm')
		return 2;
	else if (entry[0] == 'h')
		return 3;

	return 1;
}


int get_int(void){

	int value = 0;
	char c;
	while (isdigit((c = getchar()))){
		value *= 10;
		value += c - '0';
	}

	return value;
}


int get_size(void){
	
	/*
	 * Small : 8x8
	 * Medium : 12x12
	 * Large : 16x16
	 * Custom
	 */


	char entry[32];

	do{
		printf(" # Choose size : small, medium, large, custom\n > ");
		get_entry(entry);
	} while (strcmp(entry, "small") && strcmp(entry, "medium") && strcmp(entry, "large") && strcmp(entry, "custom"));

	if (entry[0] == 's')
		return 8;
	else if (entry[0] == 'm')
		return 12;
	else if (entry[0] == 'l')
		return 16;
	else
		return get_int();

	return 8;
}


void get_yn(char entry[32]){

	do {
		printf(" # Choices : yes, no\n > ");
		get_entry(entry);
	} while (strcmp(entry, "yes") && strcmp(entry, "no"));
}


void get_board(char entry[32]){

	do {
		printf(" # Choose the board : leaders, recent\n > ");
		get_entry(entry);
	} while (strcmp(entry, "recent") && strcmp(entry, "leader"));
}
