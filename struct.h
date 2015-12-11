
typedef enum {
	false,
	true,
} BOOL;

typedef struct {
	BOOL dug;
	BOOL marked;
	BOOL bomb;
	int neighbors;
} CASE;

typedef struct{
	int size;
	CASE ** cases;
	int nb_safe;
	int nb_bombs;
	int nb_dug;
	int nb_marked;
} GRID;

typedef struct{
	char name[32];
	struct tm time;
	int size;
} PLAYER;

