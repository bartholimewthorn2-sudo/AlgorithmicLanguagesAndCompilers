//Louis Jensen
//CS 4301
//Lab 08

#include <pdt.h>
 
using namespace std;
 
PDT::PDT()
{
  name = "Louis Jensen";
  labNumber = 8;
  description = "{a^ib^j,c^k | i, j > 0; k = min(i, j)}";
}
void PDT::initializeMachine()
{
	machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'a', "+a", 2, '*')));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'a', "+a", 2, '*')));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 'b', "-a", 3, 'c')));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 'b', "-a", 3, 'c')));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('@', 'b', " *", 4, '*')));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('@', '%', " *", 0, '*')));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '%', " *", 0, '*')));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'b', " *", 4, '*')));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', '%', "-a", 3, '*')));
}