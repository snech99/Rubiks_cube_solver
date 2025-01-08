/*
*	Rubiks´s Cube solver by Gerrit Hinrichs
*   Solved "like a human" without Depth First Search
* 
+   11.2024
* 	main_file
*/
#include "cube.h"
#include "game.h"
#include "do_magic.h"
#include "example_cubes.h"

int main ()
{	
	int move_array_final [200] = {};
	int *ptr_array_final = move_array_final;

	//some example cubes
	set_bsp_01(); //white already solved
	set_bsp_02();
	set_bsp_03();
    set_bsp_04();

	//solving function
	int erg = do_magic(bsp_cube_02, ptr_array_final);

	//print the final move array
    if(erg >= 0)
    {
        for(int i=0; i<200; i++)
        {
            if(move_array_final[i] != 0)
            {
                printf("%d ",move_array_final[i]);
            }
        }
        printf("\nSolved with %d moves\n",erg);
    }
    else
    {
        printf("Error: Can't solve the cube!");
    }

    return 0;
}

