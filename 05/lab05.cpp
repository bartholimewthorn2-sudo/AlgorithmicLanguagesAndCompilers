//Louis Jensen
//CS 4301
//Lab 04

#include <fsa.h>

using namespace std;
FSA::FSA()
{
	name = "Louis Jensen";
	labNumber = 5;
	description = "{x | x in {a, b}* and every substring of length four has at least one b}";
}
void FSA::initializeMachine()
{
	//On 'a'
	machine.insert(pair<uint, TableEntry>(1, TableEntry('a', 2)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('a', 3)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('a', 4)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('a', 5)));
	machine.insert(pair<uint, TableEntry>(5, TableEntry('a', 5)));
	machine.insert(pair<uint, TableEntry>(6, TableEntry('a', 7)));
	machine.insert(pair<uint, TableEntry>(7, TableEntry('a', 8)));
	machine.insert(pair<uint, TableEntry>(8, TableEntry('a', 9)));
	machine.insert(pair<uint, TableEntry>(9, TableEntry('a', 10)));
	machine.insert(pair<uint, TableEntry>(10, TableEntry('a', 10)));
	//On 'b'
	machine.insert(pair<uint, TableEntry>(1, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(5, TableEntry('b', 5)));
	machine.insert(pair<uint, TableEntry>(6, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(7, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(8, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(9, TableEntry('b', 6)));
	machine.insert(pair<uint, TableEntry>(10, TableEntry('b', 10)));
	//On '%'
	machine.insert(pair<uint, TableEntry>(1, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(2, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(3, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(4, TableEntry('%', 0)));
	//state 5 fails
	machine.insert(pair<uint, TableEntry>(6, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(7, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(8, TableEntry('%', 0)));
	machine.insert(pair<uint, TableEntry>(9, TableEntry('%', 0)));
	//state 10 fails
}