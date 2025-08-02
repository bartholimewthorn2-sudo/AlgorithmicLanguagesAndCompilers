//Louis Jensen
//CS 4301
//Lab 06

#include <pda.h>
 
using namespace std;
 
PDA::PDA()
{
  name = "Louis Jensen";
  labNumber = 6;
  description = "{a^(2i)b^(3i) | i >= 0}";
}

void PDA::initializeMachine()
{
  // Example from notes
  /*
   *---------------------------------------------------------next state
   *--------------------------------------------------------push pop  |
   *----------------------------------------------input symbol     |  |
   *-----------------------------------------stack symbol    |     |  |
   *------------------------current state               |    |     |  |  */
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '%', " *", 0)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'a', " *", 2)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'a', "+b", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 'b', " *", 5)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 'a', " *", 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 'a', "+b", 3)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 'b', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('b', 'b', "-b", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '%', " *", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('b', 'b', " *", 5)));
}