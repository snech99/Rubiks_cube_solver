/*
*	Rubiks´s Cube solver by Gerrit Hinrichs
*  	First side searched with DFS, followed by "normal" algorithm
*
* 	main_file
*/
#include "cube.h"
#include "game.h"
#include "example_cubes.h"

//function which solves the given cube
//input -> cube_array[54]
//output -> move_array
void do_magic (int *input, int *output)
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
	int s = G.short_things_up_3(ptr_array, ptr_array_short);
	int sa = G.short_things_up_up_down(ptr_array_short, output);

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
		printf("Success with %d moves (saved with shorten_up: %d)!\n",count, s + sa);
	}
	else
	{
		printf("Failed!\n");
	}
	printf("\n");
}

//main function 
int main ()
{	
	int move_array_final [200] = {};
	int *ptr_array_final = move_array_final;

	//some example cubes
	set_bsp_01();
	set_bsp_02();
	set_bsp_03();
	set_bsp_04();

	//solving function
	do_magic(bsp_cube_02, ptr_array_final);

	//print the final move array
	for(int i=0; i<200; i++)
	{
		if(move_array_final[i] != 0)
		{
			printf("%d ",move_array_final[i]);
		}
	}
	printf("\n");;
}

