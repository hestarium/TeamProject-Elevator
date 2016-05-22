#include "Function.h"
// SIMULATION FUNCTION
int simulation_menu()
{
	int menu_num;
	
	return menu_num;
}

void simulation_print(ELEVATOR* elv[ELEVATOR_NUM], FLOOR* flr[FLOOR_NUM])
{
	int i, tmp_flr;
	char print_direction[2];

	for(i = FLOOR_NUM; i >= 0; i--)
	{
		if(i == 0)
			tmp_flr = -1;
		else
			tmp_flr = i;
		printf("%2dF", tmp_flr);
		
		for(j = 0; j < ELEVATOR_NUM; j++)
		{
			if(elv[j]->direction_flag[0] == FALLING_STATUS && print_direction[0] != P_FALLING_STATUS)
				print_direction[0] = P_FALLING_STATUS;
			if(elv[j]->direction_flag[1] == RISING_STATUS && print_direction[1] != P_RISING_STATUS)
				print_direction[1] = p_RISING_STATUS;
		}
	
		printf("  %c %c  ", print_direction[0], print_direction[1]);

		for(j = 0; j < ELEVATOR_NUM; j++)
		{
			if(flr[j][i]->checkELEVATOR == LOCATED)
				printf("--a--");
			else
				printf("-- --");
		} 
		printf("\n");
	}
}

void print_FLOOR(FLOOR* flr[FLOOR_NUM])
{
	
}
// ELEVATOR FUNCTION START

ELEVATOR* createELEVATOR()
{
	ELEVATOR* elv_ret = (ELEVATOR *)malloc(sizeof(ELEVATOR));
	if(elv_ret == NULL)
	{
		printf("[ERROR][createELEVATOR] - CAN'T MALLOC ELEVATOR!\n");
		return NULL;
	}

	else
	{
		elevator_destination = -1;
		elevator_next_floor = -1;
		direction_flag = PAUSED_STATUS;
	}

	return elv_ret;
}

void deleteELEVATOR(ELEVATOR* free_elv)
{
	free(free_elv);
	if(free_elv != NULL)
		printf("[ERROR][deleteELEVATOR] - CAN'T FREE ELEVATOR!\n");
}

// FLOOR FUNCTION START
FLOOR* createFLOOR()
{
	FLOOR* flv_ret = (FLOOR *)malloc(sizeof(FLOOR));
	if(flv_ret == NULL)
	{
		printf("[ERROR][createFLOOR] - CAN'T MALLOC FLOOR!\n");
		return NULL;
	}

	else
	{
		// UP BUTTON
		button_flag[0] = NOT_PRESS_BUTTON;
		// DOWN BUTTON
		button_flag[1] = NOT_PRESS_BUTTON; 
		check_ELEVATOR = LOCATED;
	}
	return flv_ret;
}

void deleteFLLOR(FLOOR* free_flr)
{
	free(free_flr);
	if(free_flr != NULL)
		printf("[ERROR][deleteFLOOR] - CAN'T FREE FLOOR!\n");
}
