#include "Function.h"

int main(void)
{
	ELEVATOR* elv[ELEVATOR_NUM];
	FLOOR* flr[ELEVATOR_NUM][FLOOR_NUM];

	
	int i, simulation_flag;

	
	// CREATE
	for(i = 0; i < ELEVATOR_NUM; i++)
		elv[i] = createELEVATOR();
	
	for(i = 0; i < ELEVATOR_NUM; i++)
		for(j = 0; j < FLOOR_NUM; j++)
			flr[i][j] = createFLOOR();

	simulation_flag = SIMULATION_PAUSED;	
	
	while(simulation_flag != SIMULATION_END)
	{
		simulation_print(elv, flr);
		simulation_menu();		
	}

	// DELETE 
	for(i = 0; i < FLOOR_NUM; i++)
		deleteFLOOR(flr[i]);

	for(i = 0; i < ELEVATOR_NUM; i++)
		deleteELEVATOR(elv[i]);		

	return 0;
}

