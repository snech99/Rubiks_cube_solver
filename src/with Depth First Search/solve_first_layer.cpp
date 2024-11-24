/*
*	Rubiks´s Cube solver by Gerrit Hinrichs 
*   06.2024
*
* 	solving the first layer
*	DSF 
*/
#include "game.h"
#include "cube.h"
#include  <time.h>

//short function for the complete layer
void Game::solve_first_layer ()
{
	convert_num = solve_side();
	correct_cube(convert_num);
	solve_white_complete();
}

//DSF for one fixed side without adjacent stones
//array instead of stack, but same function
int Game::solve_side ()
{
	clock_t start = clock();
	printf("solving .. \n");

	int max_deep = 10;
	bool found = false;
	int count_deep = 0;
	int move = 1;

	int win_side = 0;

	set_move_array(0,1);
	moveCube(get_move_array(0));

	while(!found)
	{	

		if (count_deep < max_deep)
		{
			count_deep++;
			set_move_array(count_deep, 1);
			move = 1;

			moveCube(move);

			if ((win_side = hasWon()) > 0)
			{
				found = 1;
			}
		}
		else 
		{
			if ( get_move_array(count_deep) < 12)
			{

				move = get_move_array(count_deep); 
				move_back(move);


				inc_move_array(count_deep);
				move = get_move_array(count_deep);
				moveCube(move);
				
				if ((win_side = hasWon()) > 0)
				{
					found = 1;
				}
			}
			else
			{
				while ( get_move_array(count_deep) == 12)
				{
					set_move_array(count_deep, 0);
					moveCube(6);
					count_deep--;
				}

				move = get_move_array(count_deep);
				move_back(move);

				
				inc_move_array(count_deep);
				move = get_move_array(count_deep);
				moveCube(move);
				
				if ((win_side = hasWon()) > 0)
				{
					found = 1;
				}
			}
		}
	}

	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;

	printf("found side in DSF: %d in %.2f seconds\n", win_side, seconds);

	return win_side;
}

//solving the adjacent stones for the found side in the DSF
void Game::solve_white_complete ()
{	
	color stone = red;
	color mid = red; 

	//edge stone
	for (int i=3; i<7; i++)
	{
		mid = (color)i;
		if( !check_stone(mid, 8) )
		{
			get_up_8(mid);
			while(check_yellow_cross(white))
			{		
				stone = get_color(mid, 2);
				while( !check_stone(mid, 2))
				{					
					mid = next_side_circle(mid);
					move_Gamecube(8);
				}
				get_up_8(mid);
			}	
		}
	}

	//corner stones
	for (int i=3; i<7; i++)
	{
		mid = (color) i;

		if (!check_stone(mid, 9))
		{	
			get_up_9_and_down_side(mid);
			while( get_color(mid, 3) == white)
			{
				while ( !check_stone(next_side_circle(mid), 1) )
				{
					mid = next_side_circle(mid);
					move_Gamecube(8);
				}
				get_down_9_front(mid);

				if(!(get_color(next_side_circle(mid), 1) == white))
				{
					break;
				}

				while(!check_stone(mid, 3))
				{
					mid = next_side_circle(mid);
					move_Gamecube(8);
				}
				get_up_9_and_down_side(mid);
			}
		}
	}
}	

//help function for next side in the circle
color Game::next_side_circle (color col)
{
	int temp = (int) col;
	temp++;
	if(temp > 6)
	{
		temp = 3;
	}
	return ((color) temp);
}

//function to switch stones in the first layer
void Game::get_up_9_and_down_side (color col)
{
	switch (col)
	{
		case red:	move_Gamecube(4);  
					move_Gamecube(2);	
					move_Gamecube(10);	
					move_Gamecube(8);	
			break;

		case blue:	move_Gamecube(3);
					move_Gamecube(2);
					move_Gamecube(9);
					move_Gamecube(8);
			break;

		case green:	move_Gamecube(5);
					move_Gamecube(2);
					move_Gamecube(11);
					move_Gamecube(8);
			break;

		case orange:move_Gamecube(6);
					move_Gamecube(2);
					move_Gamecube(12);
					move_Gamecube(8);
			break;

		default: break;			
	}
}

//function to switch stones in the first layer
void Game::get_down_9_front (color col)
{
	switch (col)
	{
		case red:	move_Gamecube(2);  	
					move_Gamecube(4);	
					move_Gamecube(8);	
					move_Gamecube(10);	
			break;

		case blue:	move_Gamecube(2);
					move_Gamecube(3);
					move_Gamecube(8);
					move_Gamecube(9);
			break;

		case green:	move_Gamecube(2);
					move_Gamecube(5);
					move_Gamecube(8);
					move_Gamecube(11);
			break;

		case orange:move_Gamecube(2);
					move_Gamecube(6);
					move_Gamecube(8);
					move_Gamecube(12);
			break;

		default: break;			
	}
}

//get the color of a stone based on the side and position
color Game::get_color(color rainbow, int pos)
{
	int col = 0;
	int row = 0;

	convert_pos(&row, &col, pos);

	switch(rainbow)
	{
		case red:	return ((color)c.front.val[row][col]);
			break;

		case yellow:return ((color)c.up.val[row][col]);
			break;

		case blue: 	return ((color)c.left.val[row][col]);
			break;

		case green: return ((color)c.right.val[row][col]);
			break;

		case orange:return ((color)c.back.val[row][col]);
			break;

		default:		return def;
			break;
	}
}

//checks if a stone is matching with the mid-stone
bool Game::check_stone (color rainbow, int pos)
{
	int row;
	int col;

	convert_pos(&row, &col, pos);

	switch (rainbow)
	{
		case red: 	if (c.front.val[row][col] == red)
					{
						return true;
					}
					return false;
					break;

		case blue: 	if (c.left.val[row][col] == blue)
					{
						return true;
					}
					return false;
					break;

		case green: if (c.right.val[row][col] == green)
					{
						return true;
					}
					return false;
					break;

		case orange:if (c.back.val[row][col] == orange)
					{
						return true;
					}
					return false;
					break;
		case yellow:if (c.up.val[row][col] == yellow)
					{
						return true;
					}
					return false;
					break;
		default: return false;
				break;
	}
}

//gets the row and col based on a position
void Game::convert_pos (int *row, int *col, int pos)
{
	switch	(pos)
	{
		case 1:		*row = 0;
					*col = 0;
			break;
		case 2:		*row = 0;
					*col = 1;
			break;
		case 3:		*row = 0;
					*col = 2;
			break;
		case 4:		*row = 1;
					*col = 0;
			break;
		case 6:		*row = 1;
					*col = 2;
			break;
		case 7:		*row = 2;
					*col = 0;
			break;
		case 8:		*row = 2;
					*col = 1;
			break;
		case 9:		*row = 2;
					*col = 2;
			break;
		default:
			break;
	}
}

//function to switch stones in the first layer
void Game::get_up_8 (color col)
{
	switch (col)
	{
		case red:	move_Gamecube(10);
					move_Gamecube(6);

					move_Gamecube(3);
					move_Gamecube(3);

					move_Gamecube(4);
					move_Gamecube(12);
			break;

		case blue:	move_Gamecube(9);
					move_Gamecube(5);

					move_Gamecube(12);
					move_Gamecube(12);

					move_Gamecube(3);
					move_Gamecube(11);
			break;

		case green:	move_Gamecube(3);
					move_Gamecube(11);

					move_Gamecube(10);
					move_Gamecube(10);

					move_Gamecube(9);
					move_Gamecube(5);
			break;

		case orange:move_Gamecube(4);
					move_Gamecube(12);

					move_Gamecube(5);
					move_Gamecube(5);

					move_Gamecube(10);
					move_Gamecube(6);
			break;

		default: break;			
	}
}

//checks for a yellow or white cross
bool Game::check_yellow_cross(color col)
{
	switch (col)
	{
		case yellow: 	if( (c.up.val[0][1] == yellow) && (c.up.val[1][0] == yellow) 
							&& (c.up.val[1][2] == yellow) && (c.up.val[2][1] == yellow))
						{
							return true;
						}
						return false;
						break;

		case white:		if( (c.up.val[0][1] == white) || (c.up.val[1][0] == white) 
							|| (c.up.val[1][2] == white) || (c.up.val[2][1] == white))
						{
							return true;
						}
						return false;
						break;
		default:		return false;
						break;
	}
}