#ifndef MCTSH
#define MCTSH

#include "uctnode.h"

#define USEROUNDS 

#define DEFAUT_TIME_PER_STEP (time_t(0.5*CLOCKS_PER_SEC))
#define DEFAUT_SIMS 50000
#define BLOCKSIZE 50

#define RESIGN 0.2

typedef int Action;//for clarity

using namespace std;

class MCTS
{
public:
  Action best_action(board &init_b, bool color, int simu_per_step = DEFAUT_SIMS);
  double calc_winrate();
  void init_with_board(board &b); //init MCTS with board
  void reset(board &b); //reset board and path before each cycle
  void clear(); //clear MCTS by delete root

  Node* select();
  bool roll_out();
  void backpropogation(bool res);

  int total;
  Node* root; //the current position to play, root of select
  board root_board; //root board should be saved
  board simu_board; //board for select + simulation
  vector<Node*> path; //record path of each select
#ifdef USERAVEQ
  vector<Action> rave_path[2]; //for amaf rave value update
#endif
  //http://www.cs.utexas.edu/~pstone/Courses/394Rspring13/resources/mcrave.pdf simu_tree+simu_defaut is a good way to think
};


#endif //MCTSH
