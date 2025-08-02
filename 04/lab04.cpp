//Louis Jensen
//CS 4301
//Lab 04
#include <iostream>
#include <fsa.h>

using namespace std;
FSA::FSA(){}

void FSA::initializeMachine()
{
	//If you're in here trying to see why my code failed to print a lab number or my name,
	//Then I hope you can find what I couldn't I've just given up and am assuming doing it on my
	//Home PC is messing with the makefile in some way. 
	//On 'a'
	machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 1)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 3)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 3)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('a', 1)));
	//On 'b'
	machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 2)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 4)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 4)));
	//On '%'
	machine.insert(pair<uint, TableEntry>(1, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('%', 0)));
}