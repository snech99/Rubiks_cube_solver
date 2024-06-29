# Rubik´s Cube Solver
This work was created as part of a project in my mechatronics course at Hochschule Wismar, University of Applied Sciences: Technology, Business and Design. This code was compiled as a DLL and integrated into a LabView file. The executing robot is a self-built robot based on LEGO and the EV3 Brick.
The project was a group project that I completed together with a fellow student from my degree program.


At the beginning we have a Depth First Search (DFS) to solve any side of the cube. Subsequently, the cube is solved with normal algorithms, as they can be found everywhere on the internet.


Some example cubes are available. These can be used to determine the required input for solving the cube. 
It is important to read the cube according to a certain pattern.
The order of the sides does not matter, but the order of the bricks on each side is important.
The cube is held with the red side facing forward and the yellow side facing up. Below is a picture showing the order in which the bricks are to be read for each side.

![alt text](https://github.com/snech99/Rubiks_cube_solver/blob/main/cube.png?raw=true)



The own cube must be inserted according to the given pattern and saved as a cube in the examaple_cubes.h file in order to be called in the main.cpp.
The output is a sequence of turns that must be performed to solve the cube (make sure you are holding the cube correctly)

| color | right | left | 
|-------|-------|------|
| white | 1     |  7   |
| yellow| 2     |   8  |
| red | 3     |  9   |
| green| 4     |   10  |
| orange | 5     | 11   |
| blue| 6   |   12  |
