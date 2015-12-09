
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
	CASE ** bombs;
	int nb_bombs;
	CASE ** normals;
	int nb_normals;
} GRID;

typedef struct{
	char name[32];
	int time;
	int size;
} PLAYER;
