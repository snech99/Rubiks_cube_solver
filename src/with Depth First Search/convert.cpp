/*
*	Rubiks´s Cube solver by Gerrit Hinrichs 
*   06.2024
*
* 	converts the cube based on the first found side to the white side
*/
#include "game.h"
#include "cube.h"

//function which calls the color functions base on the found side
void Game::correct_cube (int erg_side)
{
	int array_cube[54] = {};
	int pos = 0;

	//copy the complete give cube
	for(int i=0; i<3; i++)
	{
		for(int k=0; k<3; k++)
		{
			array_cube[pos] = c.front.val[i][k];
			pos++;
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int k=0; k<3; k++)
		{
			array_cube[pos] = c.back.val[i][k];
			pos++;
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int k=0; k<3; k++)
		{
			array_cube[pos] = c.left.val[i][k];
			pos++;
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int k=0; k<3; k++)
		{
			array_cube[pos] = c.right.val[i][k];
			pos++;
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int k=0; k<3; k++)
		{
			array_cube[pos] = c.up.val[i][k];
			pos++;
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int k=0; k<3; k++)
		{
			array_cube[pos] = c.down.val[i][k];
			pos++;
		}
	}

	//converts the cube based on found side in DSF
	switch(erg_side)
	{
		case 2: convert_num_yellow(array_cube);
			break;
		case 3: convert_num_red(array_cube);
			break;
		case 4: convert_num_green(array_cube);
			break;
		case 5: convert_num_orange(array_cube);
			break;
		case 6: convert_num_blue(array_cube);
			break;
		default: return;
	}
}

void Game::convert_num_red (int array[54])
{
	int num = 0;
	int new_array[54] = {};
	for (int i=0; i<54; i++)
	{
		num = array[i];
		switch (num)
		{
			case 1:		new_array[i] = num+4;
				break;
			case 2:		new_array[i] = num+1;
				break;
			case 3:		new_array[i] = num-2;
				break;
			case 4:		new_array[i] = num;
				break;
			case 5:		new_array[i] = num-3;
				break;
			case 6:		new_array[i] = num;
				break;	
			default: new_array[i] = 99;
				break;
		}
	}

	cube C(new_array);
	setcube(&C);
	c.cpy_mainside(&c.left);
	c.rotate_mainside_right(&c.left);
	c.cpy_mainside(&c.right);
	c.rotate_mainside_left(&c.right);

	c.cpy_mainside(&c.back);
	c.rotate_mainside_right(&c.back);
	c.cpy_mainside(&c.back);
	c.rotate_mainside_right(&c.back);

	c.cpy_mainside(&c.up);
	c.rotate_mainside_right(&c.up);
	c.cpy_mainside(&c.up);
	c.rotate_mainside_right(&c.up);
}

void Game::convert_num_yellow (int array[54])
{
	int num = 0;
	int new_array[54] = {};
	for (int i=0; i<54; i++)
	{
		num = array[i];
		switch (num)
		{
			case 1:		new_array[i] = num+1;
				break;
			case 2:		new_array[i] = num-1;
				break;
			case 3:		new_array[i] = num+2;
				break;
			case 4:		new_array[i] = num;
				break;
			case 5:		new_array[i] = num-2;
				break;
			case 6:		new_array[i] = num;
				break;	
			default: new_array[i] = 99;
				break;
		}
	}

	cube C(new_array);
	setcube(&C);

	c.cpy_mainside(&c.left);
	c.rotate_mainside_right(&c.left);
	c.cpy_mainside(&c.left);
	c.rotate_mainside_right(&c.left);

	c.cpy_mainside(&c.right);
	c.rotate_mainside_left(&c.right);
	c.cpy_mainside(&c.right);
	c.rotate_mainside_left(&c.right);

	c.cpy_mainside(&c.front);
	c.rotate_mainside_left(&c.front);
	c.cpy_mainside(&c.front);
	c.rotate_mainside_left(&c.front);

	c.cpy_mainside(&c.back);
	c.rotate_mainside_left(&c.back);
	c.cpy_mainside(&c.back);
	c.rotate_mainside_left(&c.back);
}

void Game::convert_num_orange (int array[54])
{
	int num = 0;
	int new_array[54] = {};
	for (int i=0; i<54; i++)
	{
		num = array[i];
		switch (num)
		{
			case 1:		new_array[i] = num+2;
				break;
			case 2:		new_array[i] = num+3;
				break;
			case 3:		new_array[i] = num-1;
				break;
			case 4:		new_array[i] = num;
				break;
			case 5:		new_array[i] = num-4;
				break;
			case 6:		new_array[i] = num;
				break;	
			default: new_array[i] = 99;
				break;
		}
	}

	cube C(new_array);
	setcube(&C);
	
	c.cpy_mainside(&c.left);
	c.rotate_mainside_left(&c.left);

	c.cpy_mainside(&c.right);
	c.rotate_mainside_right(&c.right);

	c.cpy_mainside(&c.back);
	c.rotate_mainside_left(&c.back);
	c.cpy_mainside(&c.back);
	c.rotate_mainside_left(&c.back);

	c.cpy_mainside(&c.down);
	c.rotate_mainside_left(&c.down);
	c.cpy_mainside(&c.down);
	c.rotate_mainside_left(&c.down);
}

void Game::convert_num_green (int array[54])
{
	int num = 0;
	int new_array[54] = {};
	for (int i=0; i<54; i++)
	{
		num = array[i];
		switch (num)
		{
			case 1:		new_array[i] = num+5;
				break;
			case 2:		new_array[i] = num+2;
				break;
			case 3:		new_array[i] = num;
				break;
			case 4:		new_array[i] = num-3;
				break;
			case 5:		new_array[i] = num;
				break;
			case 6:		new_array[i] = num-4;
				break;	
			default: new_array[i] = 99;
				break;
		}
	}

	cube C(new_array);
	setcube(&C);
	
	c.cpy_mainside(&c.front);
	c.rotate_mainside_right(&c.front);

	c.cpy_mainside(&c.back);
	c.rotate_mainside_left(&c.back);

	c.cpy_mainside(&c.up);
	c.rotate_mainside_right(&c.up);

	c.cpy_mainside(&c.left);
	c.rotate_mainside_right(&c.left);

	c.cpy_mainside(&c.right);
	c.rotate_mainside_right(&c.right);
}

void Game::convert_num_blue (int array[54])
{
	int num = 0;
	int new_array[54] = {};
	for (int i=0; i<54; i++)
	{
		num = array[i];
		switch (num)
		{
			case 1:		new_array[i] = num+3;
				break;
			case 2:		new_array[i] = num+4;
				break;
			case 3:		new_array[i] = num;
				break;
			case 4:		new_array[i] = num-2;
				break;
			case 5:		new_array[i] = num;
				break;
			case 6:		new_array[i] = num-5;
				break;	
			default: new_array[i] = 99;
				break;
		}
	}

	cube C(new_array);
	setcube(&C);
	
	c.cpy_mainside(&c.front);
	c.rotate_mainside_left(&c.front);

	c.cpy_mainside(&c.back);
	c.rotate_mainside_right(&c.back);

	c.cpy_mainside(&c.right);
	c.rotate_mainside_left(&c.right);

	c.cpy_mainside(&c.left);
	c.rotate_mainside_left(&c.left);

	c.cpy_mainside(&c.up);
	c.rotate_mainside_left(&c.up);
}