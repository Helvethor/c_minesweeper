#include "head.h"


int main(void){
	
	char entry[32];

	srand(time(NULL));

	do {
		
		printf(" # Type help\n > ");
		get_entry(entry);

		if (!strcmp(entry, "play"))
			play();
		else if (!strcmp(entry, "scores"))
			show_scores();
		else if (!strcmp(entry, "reset"))
			reset();
		else
			help_main();

	} while (strcmp(entry, "quit"));

	return 0;
}
