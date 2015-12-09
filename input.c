#include "head.h"


void get_entry(char entry[32]){
	
	int i = 0;

	while ((entry[i] = getchar()) != '\n') i++;
	entry[i] = '\0';
}

int get_difficulty(){
	
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

int get_size(){
	
	char entry[32];

	do{
		printf(" # Choose size : small, medium, large\n > ");
		get_entry(entry);
	} while (strcmp(entry, "small") && strcmp(entry, "medium") && strcmp(entry, "large"));

	if (entry[0] == 's')
		return 8;
	else if (entry[0] == 'm')
		return 12;
	else if (entry[0] == 'l')
		return 16;

	return 8;
}
