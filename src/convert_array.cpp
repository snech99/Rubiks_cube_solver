/*
*	Rubiks´s Cube solver by Gerrit Hinrichs 
*   06.2024
*
* 	converts the move_array back based on the first found side
*/
#include "game.h"
#include "cube.h"

//case which decides the following convert functions
void Game::convert_back_move_array_all()
{
    for (int i=0; i<POS; i++)
    {
        switch (convert_num)
        {
            case 2: move_array_all_fixed[i] = convert_from_yellow(move_array_all[i]);
                    break;
            case 3: move_array_all_fixed[i] = convert_from_red(move_array_all[i]);
                    break;
            case 4: move_array_all_fixed[i] = convert_from_green(move_array_all[i]);
                    break;
            case 5: move_array_all_fixed[i] = convert_from_orange(move_array_all[i]);
                    break;
            case 6: move_array_all_fixed[i] = convert_from_blue(move_array_all[i]);
                    break;
        }
    }
}

int Game::convert_from_red(int in)
{
    switch(in)
    {
        case 1:     return (3);
        case 2:     return (5);
        case 3:     return (2);
        case 4:     return (4);
        case 5:     return (1);
        case 6:     return (6);
        case 7:     return (6+3);
        case 8:     return (6+5);
        case 9:     return (6+2);
        case 10:    return (6+4);
        case 11:    return (6+1);
        case 12:    return (6+6);
        default:    return (0);
    }
}
int Game::convert_from_green(int in)
{
    switch(in)
    {
        case 1:     return (4);
        case 2:     return (6);
        case 3:     return (3);
        case 4:     return (2);
        case 5:     return (5);
        case 6:     return (1);
        case 7:     return (6+4);
        case 8:     return (6+6);
        case 9:     return (6+3);
        case 10:    return (6+2);
        case 11:    return (6+5);
        case 12:    return (6+1);
        default:    return (0);
    }
}
int Game::convert_from_orange(int in)
{
    switch(in)
    {
        case 1:     return (5);
        case 2:     return (3);
        case 3:     return (1);
        case 4:     return (4);
        case 5:     return (2);
        case 6:     return (6);
        case 7:     return (6+5);
        case 8:     return (6+3);
        case 9:     return (6+1);
        case 10:    return (6+4);
        case 11:    return (6+2);
        case 12:    return (6+6);
        default:    return (0);
    }
}
int Game::convert_from_blue(int in)
{
    switch(in)
    {
        case 1:     return (6);
        case 2:     return (4);
        case 3:     return (3);
        case 4:     return (1);
        case 5:     return (5);
        case 6:     return (2);
        case 7:     return (6+6);
        case 8:     return (6+4);
        case 9:     return (6+3);
        case 10:    return (6+1);
        case 11:    return (6+5);
        case 12:    return (6+2);
        default:    return (0);
    }
}
int Game::convert_from_yellow(int in)
{
    switch(in)
    {
        case 1:     return (2);
        case 2:     return (1);
        case 3:     return (5);
        case 4:     return (4);
        case 5:     return (3);
        case 6:     return (6);
        case 7:     return (6+2);
        case 8:     return (6+1);
        case 9:     return (6+5);
        case 10:    return (6+4);
        case 11:    return (6+3);
        case 12:    return (6+6);
        default:    return (0);
    }
}