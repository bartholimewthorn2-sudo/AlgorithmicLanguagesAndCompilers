//Louis Jensen
//CS 4301
//Lab 09
 
#include <turing.h>
 
using namespace std;
 
Turing::Turing()
{
  name = "Louis Jensen";
  labNumber = 9;
  description = "{(x=, x=ans) | x is in {a,b}*,\n"
"               ans = 1 if x contains an even number of substrings ba\n"
"               ans = 0 otherwise}";
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
  machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 'a',  1, 3)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 'b',  1, 2)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('=', '=',  1, 6)));
  //State 2                                                  
  machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'a',  1, 4)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 'b',  1, 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('=', '=',  1, 6)));
  //State 3                                                  
  machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 'a',  1, 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 'b',  1, 2)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('=', '=',  1, 6)));
  //State 4                                                  
  machine.insert(pair<uint, TableEntry>(4, TableEntry('a', 'a',  1, 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'b',  1, 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('=', '=',  1, 7)));
  //State 5                                                  
  machine.insert(pair<uint, TableEntry>(5, TableEntry('a', 'a',  1, 3)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 'b',  1, 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('=', '=',  1, 7)));
  //State 6
  machine.insert(pair<uint, TableEntry>(6, TableEntry(' ', '1',  1, 0)));
  //State 7                                             
  machine.insert(pair<uint, TableEntry>(7, TableEntry(' ', '0',  0, 0)));
}