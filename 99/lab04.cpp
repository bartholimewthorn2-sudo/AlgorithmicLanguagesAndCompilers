//Louis Jensen
//CS 4301
//Lab 03

#include <iostream>
#include <cstdlib>
#include <string>
#include <fsa.h>

using namespace std;
FSA::FSA();

void FSA::initializeMachine()
{
	machine.insert(pair<uint, TableEntry>(0, TableEntry('a', 0)));
	machine.insert(pair<uint, TableEntry>(0, TableEntry('b', 2)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 0)));
	machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 3)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 2)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 3)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 4)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('a', 0)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 4)));
}