//Louis Jensen
//CS 4301
//Lab 10
 
#include <turing.h>
 
using namespace std;
 
Turing::Turing()
{
  name = "Louis Jensen";
  labNumber = 10;
  description = "{(x=, x=y) | x is in {a,b}* and\n"
"             y contains the elements from x in ascending order}";
}
 
void Turing::initializeMachine()
{
  /*
   *-------------------------------------------------------next state
   *----------------------------------------------------------move  |
   *-------------------------------------------write character   |  | 
   *---------------------------------------read character    |   |  |
   *------------------------current state               |    |   |  |   */
  //State 1
  machine.insert(pair<uint, TableEntry>(1, TableEntry(' ', ' ',  1, 1)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('a', ' ',  1, 2)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('b', ' ',  1, 3)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('=', '=',  1, 6)));
  //State 2
  machine.insert(pair<uint, TableEntry>(2, TableEntry(' ', 'a', -1, 4)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'a',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 'b',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('=', '=',  1, 2)));
  //State 3
  machine.insert(pair<uint, TableEntry>(3, TableEntry(' ', 'b', -1, 5)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 'a',  1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 'b',  1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('=', '=',  1, 3)));
  //State 4
  machine.insert(pair<uint, TableEntry>(4, TableEntry(' ', 'a',  1, 1)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('a', 'a', -1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'b', -1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('=', '=', -1, 4)));
  //State 5
  machine.insert(pair<uint, TableEntry>(5, TableEntry(' ', 'b',  1, 1)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('a', 'a', -1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 'b', -1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('=', '=', -1, 5)));
  //State 6
  machine.insert(pair<uint, TableEntry>(6, TableEntry(' ', ' ',  0, 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('a', 'a',  1, 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('b', ' ',  1, 7)));
  //State 7
  machine.insert(pair<uint, TableEntry>(7, TableEntry(' ', ' ', -1, 9)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('a', 'b', -1, 8)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('b', 'b',  1, 7)));
  //State 8
  machine.insert(pair<uint, TableEntry>(8, TableEntry(' ', 'a',  1, 6)));
  machine.insert(pair<uint, TableEntry>(8, TableEntry('a', 'a', -1, 8)));
  machine.insert(pair<uint, TableEntry>(8, TableEntry('b', 'b', -1, 8)));
  //State 9
  machine.insert(pair<uint, TableEntry>(9, TableEntry(' ', 'b',  0, 0)));
  machine.insert(pair<uint, TableEntry>(9, TableEntry('b', 'b', -1, 9)));
  
}