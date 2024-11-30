
void obj_test(OBJ_ATTR * obj);
void handle_PLAYER_anim(void);
void handle_input(void);

typedef enum {
    DOWN = 0, UP = 4, LEFT = 8, RIGHT = 12 
} WALK_N;

typedef struct overworld {
    OBJ_ATTR * obj;
    int animf;
    int firstanimframe;
    int currentframe;
    WALK_N walkcycleN;
} overworld;

extern OBJ_ATTR *red;
extern OBJ_ATTR obj_buffer[];
