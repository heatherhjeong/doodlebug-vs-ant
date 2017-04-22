this is a simple predator-prey simulation game implemented in C++

in this game, the prey are ants and the predators are doodlebugs. they live in 20x20 grid of cells where only one critter may occupy a cell at a time and a critter is not allowed to move off the edges of the world. time is simulated in time steps and each critter performs action each time step.

ants' actions at each time step is described as follows:
  1) move - at each time step, a random move is generated to: up, down, right or left. if the neighboring cell in the selected direction is occupied or it would move off the grid, the any stays in the current cell.
  2) breed - if an ant survives three time steps, then after it moves, the ant breeds. this is simulated by creating a new ant in an adjacent cell (up, down, right or left) that is empty. if there is no empty cell available, then the ant breeds when an empty cell becomes available at a subsequent time step.

doodlebugs' action at each time step is described as follows:
  1) move - at each time step, if there is an adjacent (up, down, right or left) ant, then a doodlebug randomly chooses which ant to eat by moving to the cell containing that ant. if there is no ant available to eat in an adjacent cell, then the doodlebug moves in the same manner as an ant.
  2) breed - if a doodlebug survives for eight time steps, then after it moves, it breeds in the same manner as an ant
  3) starve - if a doodlebug has not eaten an ant within last three time steps, then at the end of the time step (after it moved and bred) it starves and dies. this is simulated by the doodlebug being removed from the grid of cells

at each time step, doodlebugs move first and then ants move. doodlebugs and ants breed at the same time. and at the end of each time step, some doodlebugs may starve. priority of each action is given to earlier cell in the grid; if a cell in a grid can be represented as grid[row][col], then a cell c1 (grid[row1][col1]) is earlier than a cell c2 (grid[row2][col2]) if row1 < row2 or row1 = row2 and col1 < col2

at each time step, the state of the grid is printed as follows:
  1) an ant is represented by 'o'
  2) a doodlebug is represented by 'X'
  3) an empty cell is represented by '-'

the world is initialized with 5 doodlebugs and 100 ants. the user must press enter to initiate a time step 
