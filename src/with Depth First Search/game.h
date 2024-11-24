/*
*	Rubiks´s Cube solver by Gerrit Hinrichs 
*   06.2024
*
* 	header for game class
*/
#include "cube.h"

using namespace std;

#ifndef	GAME_NEW_H
#define GAME_NEW_H

class Game 
{
	cube c;

	cube *del_cube_ptr;

	int move_array[11] = {};			//saves the moves of the DSF
	int move_array_all[200] = {};		//saves the moves of the other algorithms
	int move_array_all_fixed[200] = {}; //both together

	int POS = 0;
	
	public:

	int convert_num = 0;

	//constructor
	Game(cube *cu)
	{
		del_cube_ptr = new cube (*cu);
		c = *del_cube_ptr;
	}

	//destructor
	~Game()
	{
		delete(del_cube_ptr);
	}

	void setcube(cube *cu);
	cube get_cube();
	int hasWon();
	void print_cube();

	void moveCube(int);
	void move_back (int);
	void save_move(int);
	
	void set_move_array(int, int);
	void inc_move_array(int);
	int get_move_array(int);

	void print_move_array_all();
	void move_Gamecube(int);

	//main functions
	int solve_side();
	void solve_white_complete ();
	void correct_cube (int);
	void solve_first_layer();

	void solve_second_layer();

	void solve_third_layer();	

	//help functionss for convert
	void convert_pos (int*, int*, int);
	void convert_num_red (int array[54]);
	void convert_num_yellow (int array[54]);
	void convert_num_green (int array[54]);
	void convert_num_blue (int array[54]);
	void convert_num_orange (int array[54]);

	//help functions for first layer
	color next_side_circle (color);
	void get_up_8 (color);
	void get_up_9_and_down_side (color);
	void get_down_9_front(color);
	color get_color(color, int);
	bool check_stone (color, int);
	bool check_yellow_cross(color);

	//help functions for second_layer
	void automove_left (color);
	void automove_right (color);
	color color_stone_top(color);

	//help functions for third_layer
	int read_yellow_cross();
	int read_yellow_x();
	void KREUZZUG();
	void fisch_left();
	void fisch_right();
	void align_yellow_cross();
	void rotate_Kantensteine(color );
	void align_rainbow_middle();
	void L_move(color);
	void finish_cube();

	//Convert move_array back to normal cube
	void convert_back_move_array_all();
	int convert_from_red(int);
	int convert_from_green(int);
	int convert_from_orange(int);
	int convert_from_blue(int);
	int convert_from_yellow(int);

	int Test_cube_success(Game);
	void complete_move_array (int *);
	int short_things_up_3 (int *, int *);
	int short_things_up_up_down (int *, int *);
};

#endif
