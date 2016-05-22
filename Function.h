#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __ELEVATOR
{
	int elevator_destination;
	int elevator_next_floor;
	// 0: UP DIRECTION 1: DOWN DIRECTION
	int direction_flag[2];
}ELEVATOR;

typedef struct __FLOOR
{
	// 0: UP BUTTON 1: DOWN BUTTON
	int button_flag[2];
	int floor_index;
	int check_ELEVATOR;
}FLOOR;

#define ELEVATOR_NUM 3
// FROM B1 TO 10
#define FLOOR_NUM 11

// SIMULATION FLAG
#define SIMULATION_START  0
#define SIMULATION_PAUSED 1
#define SIMULATION_END   -1

// ELEVATOR WHETHER OR NOT
#define LOCATED   1
#define UNLOCATED 0
// ELEVATOR DIRECTION FLAG
#define RISING_STATUS   1
#define PAUSED_STATUS   0
#define FALLING_STATUS -1

// PRINT DIRECTION FLAG
#define P_RISING_STATUS      "▲"
#define P_NOT_RISING_STATUS  "△"
#define P_FALLING_STATUS     "▼"
#define P_NOT_FALLING_STATUS "▽"

// BUTTON FLAG
#define PRESS_UP         1
#define NOT_PRESS_BUTTON 0
#define PRESS_DOWN      -1


// SIMULATION FUNCTION
int simulation_menu();
void simulation_print(ELEAVATOR* elv[ELEVATOR_NUM], FLOOR* flr[FLOOR_NUM]);
void print_FLOOR(FLOOR* flr[FLOOR_NUM]);

// ELEVATOR FUNCTION
ELEVATOR* createELEVATOR();
void deleteELEVATOR(ELEVATOR* free_elv);

// FLOOR FUNCTION
FLOOR* createFLOOR();
void deleteFLOOR(FLOOR* free_flr);
