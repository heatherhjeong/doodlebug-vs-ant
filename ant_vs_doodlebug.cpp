#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Game;
class Organism;
class Doodlebug;
class Ant;

//valid moves for each organism
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;

const int WORLD_DIMENSION = 20;

//the number of each critter we initialize the world with
const int INIT_DOODLEBUG_COUNT = 5;
const int INIT_ANT_COUNT = 100;

//the time steps it takes for each critter to breed
const int DOODLEBUG_BREED_TIME = 8;
const int ANT_BREED_TIME = 3;

//the time steps it takes for a doodlebug to starve
const int DOODLEBUG_STARVE_TIME = 3;

//number to indicate the type of each critter
const int DOODLEBUG = 1;
const int ANT = 2;

typedef Organism* OrganismPtr;
typedef Game* GamePtr;

class Game {

  friend class Organism;
  friend class Ant;
  friend class Doodlebug;

private:
  OrganismPtr world[WORLD_DIMENSION][WORLD_DIMENSION];
  int timeStepCount;
  int generateRandomNumber(int startRange, int endRange) const;

public:
  Game();
  void startGame();
  void takeTimeStep();
  void printWorld() const;
  void setInWorld(int x, int y, OrganismPtr critter);
  OrganismPtr getFromWorld(int x, int y) const;

};

class Organism {

protected:
  GamePtr currGame;
  int x;
  int y;
  int timeTillBreed;
  //given a coordinate of the cell (x,y), 
  //returns a list of valid moves to adjacent empty cells
  vector<int> getMovesToEmptyCells(int x, int y) const;
  bool isValidCoordinate(int x, int y) const;
  //given a valid move from grid[x][y],
  //updates x and y according to the move
  void getCoordinate(int& x, int& y, int move) const;

public:
  Organism();
  Organism(GamePtr currGame, int x, int y);
  virtual void breed();
  virtual void move();
  virtual int getType() = 0;
  virtual bool starves() { return false; }

};

class Doodlebug: public Organism {

private:
  int timeTillStarve;
  //given a coordinate of the cell (x,y),
  //returns a list of valid moves to adjacent ants
  vector<int> getMovesToAnts(int x, int y) const;

public:
  Doodlebug();
  Doodlebug(GamePtr currGame, int x, int y);
  void breed();
  void move();
  int getType(){ return DOODLEBUG; }
  bool starves(){ return timeTillStarve == 0; }

};

class Ant: public Organism {

public:
  Ant();
  Ant(GamePtr currGame, int x, int y);
  void breed();
  void move();
  int getType(){ return ANT; }

};

