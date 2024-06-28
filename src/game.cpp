/*
*	Rubiks´s Cube solver by Gerrit Hinrichs 
*   06.2024
*
* 	class game member functions
*/
#include "game.h"
#include "cube.h"

using namespace std;

//set a cube to the game
void Game::setcube(cube *cu)
{
	del_cube_ptr = new cube (*cu);
	c = *del_cube_ptr;
}

//get the cube of a game
cube Game::get_cube()
{
	return this->c;
}
	
//checks if one side is fixed
int Game::hasWon() 
{
	return c.one_side_fixed();
}

//print the cube of the game
void Game::print_cube()
{
	this->c.print_side(def);
}

//moves one side of the cube in the game
void Game::moveCube(int move)
{
    switch (move)
    {
		case 1:	
				c.rotate_right(white);
			break;

		case 2: 
				c.rotate_right(yellow);
			break;

		case 3:
				c.rotate_right(red);
			break;

		case 4: 
				c.rotate_right(green);
			break;

		case 5:
				c.rotate_right(orange);
			break;

		case 6: 
				c.rotate_right(blue);
			break;

		case 7:	
				c.rotate_left(white);
			break;

		case 8: 
				c.rotate_left(yellow);
			break;

		case 9: 
				c.rotate_left(red);
			break;

		case 10:
				c.rotate_left(green);
			break;

		case 11: 
				c.rotate_left(orange);
			break;

		case 12: 
				c.rotate_left(blue);
			break; 
    }
}

//moves one side back based on the given move
void Game::move_back(int old_move)
{
	if (old_move < 7)
	{
		this->moveCube(old_move+6);
	}
	else
	{
		this->moveCube(old_move-6);
	}
}

//writes a move to a specific array
//moves which are found in the DSF
void Game::set_move_array (int deep, int val)
{
	move_array[deep] = val;
}

//print the hole move array
void Game::print_move_array_all()
{
	for(int i=0; i<POS; i++)
	{
		printf("%d ", this->move_array_all[i]);
	}
	printf("   %d\n", POS);
}

//increments the move in the move_array (DSF)
void Game::inc_move_array (int deep)
{
	move_array[deep] += 1;
}

//read the move out of the move_array (DSF)
int Game::get_move_array (int deep)
{
	return (move_array[deep]);
}

//saves the moves into the big move_array_all
void Game::save_move(int move)
{
	move_array_all[POS] = move;
	POS++;

	if(POS >= 500)
	{
		printf("move_array_all is full!\n");
	}
}

//moves the cube of the game and saves them (only outside the DSF)
void Game::move_Gamecube(int move)
{
    switch (move)
    {
		case 1:	
				c.rotate_right(white);
				save_move(1);
			break;

		case 2: 
				c.rotate_right(yellow);
				save_move(2);
			break;

		case 3:
				c.rotate_right(red);
				save_move(3);
			break;

		case 4: 
				c.rotate_right(green);
				save_move(4);
			break;

		case 5:
				c.rotate_right(orange);
				save_move(5);
			break;

		case 6: 
				c.rotate_right(blue);
				save_move(6);
			break;

		case 7:	
				c.rotate_left(white);
				save_move(7);
			break;

		case 8: 
				c.rotate_left(yellow);
				save_move(8);
			break;

		case 9: 
				c.rotate_left(red);
				save_move(9);
			break;

		case 10:
				c.rotate_left(green);
				save_move(10);
			break;

		case 11: 
				c.rotate_left(orange);
				save_move(11);
			break;

		case 12: 
				c.rotate_left(blue);
				save_move(12);
			break; 
    }
}

//converts the move array back and writes the move_array of the DSF 
//and the one of the other algorithms together
void Game::complete_move_array (int* array)
{
	convert_back_move_array_all();

	int pos = 0;

	for (int i=0; i<11; i++)
	{
		if (this->move_array[i] != 0)
		{
			array[pos] = move_array[i];
			pos++;
		}
	}

	if(convert_num == 1)
	{
		for (int i=0; i<POS; i++)
		{
			array[pos] = move_array_all[i];
			pos++;			
		}
	}
	else
	{
		for (int i=0; i<POS; i++)
		{
			array[pos] = move_array_all_fixed[i];
			pos++;
		}	
	}
}

//looking for 3 moves in a row and deletes them -> replace with counter move
int Game::short_things_up_3(int *array_old, int *array_short)
{

	int count = 0;
	int new_move = 0;
	int old_move = 0;
	int move = 0;
	int pos = 0;
	int count_pos = 0;

	int pos_old = 0;
	int pos_new = 0;

	int saved = 0;

	while(array_old[count_pos] != 0)
	{
		new_move = array_old[count_pos];

		if (old_move == new_move)
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count == 2)
		{	
			saved = saved + 2;
			if (array_old[count_pos] < 7)
			{
				move = array_old[count_pos]+6;
			}
			else
			{
				move = array_old[count_pos]-6;
			}
			pos = pos-2;
			array_short[pos] = move;
			old_move = move;
			pos++;
			count = 0;
		}
		else
		{
			array_short[pos] = array_old[count_pos];
			old_move = new_move;
			pos++;
		}	
		count_pos++;
	}
	return saved;
}

//searches for a move and a counter move successively -> deletes both
int Game::short_things_up_up_down(int *array_old, int *array_short)
{
	int new_move = 0;
	int old_move = 0;
	int move = 0;
	int pos = 0;
	int count_pos = 0;

	int saved = 0;

	while(array_old[count_pos] != 0)
	{
		array_short[pos] = array_old[count_pos];

		new_move = array_old[count_pos];

		if (new_move > 7)
		{
			move = new_move-6;
		}
		else
		{
			move = new_move+6;
		}

		if (move == old_move)
		{
			saved = saved + 2;
			pos = pos-2;
			old_move = array_short[pos];
		}
		else
		{
			old_move = new_move;
		}	
		pos++;
		count_pos++;
	}
	return saved;
}



			