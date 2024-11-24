/*
*	Rubiks´s Cube solver by Gerrit Hinrichs 
*   11.2024
*
* 	solver function
*/

#include "cube.h"
#include "game.h"
#include "do_magic.h"

//function which solves the given cube
//input -> cube_array[54]
//output -> move_array
int do_magic (int *input, int *output)
{
	int count = 0;
	int move_array [200] = {};
	int *ptr_array = move_array;
	int move_array_short [200] = {};
	int *ptr_array_short = move_array_short;

	//create cube based on the input
	cube C1(input);

	//create two games:
	//one for solving and one for tests
	Game G (&C1), G_Test (&C1);

	//solving the cube layer by layer
	G.solve_first_layer();
	G.solve_second_layer();
	G.solve_third_layer();

	//optimize the finale move_array
	G.complete_move_array(ptr_array);

	G.short_things_up_3(ptr_array, ptr_array_short);
	G.short_things_up_up_down(ptr_array_short, output);
	G.short_things_up_3(output, ptr_array_short);
	G.short_things_up_up_down(ptr_array_short, output);

	//test the moves
	for(int i=0; i<200; i++)
	{
		if(output[i] != 0)
		{
			G_Test.move_Gamecube(output[i]);
			count++;
		}
	}
	
	//check for win
	if (G_Test.get_cube().allSidesFixed())
	{
		return count;
	}
	else
	{
		return -1;
	}
}