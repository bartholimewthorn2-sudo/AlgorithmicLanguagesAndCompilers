//Louis Jensen
//CS 4301
//Lab 07

#include <pda.h>
 
using namespace std;
 
PDA::PDA()
{
  name = "Louis Jensen";
  labNumber = 7;
  description = "{w | w is a legal NASM integer constant}";
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
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '0', " *", 2)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '1', " *", 4)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '2', " *", 5)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '3', " *", 5)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '4', " *", 5)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '5', " *", 5)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '6', " *", 5)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '7', " *", 5)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '8', " *", 6)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', '9', " *", 6)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'A', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'B', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'C', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'D', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'E', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'F', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'a', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'b', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'c', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'd', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'e', " *", 7)));
  machine.insert(pair<uint, TableEntry>(1, TableEntry('@', 'f', " *", 7)));
  
//State 2 Possible Prefix
  //Lonely 0 
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '%', " *", 0)));
  
  //Prefix Complete for Binary
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'B', "+B", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'b', "+B", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'Y', "+B", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'y', "+B", 3)));
  
  //Prefix Complete for Octal
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'O', "+Q", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'o', "+Q", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'Q', "+Q", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'q', "+Q", 3)));
  
  //Prefix Complete for Decimal
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'D', "+D", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'd', "+D", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'T', "+D", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 't', "+D", 3)));
  
  //Prefix Complete for Hex
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'H', "+H", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'h', "+H", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'X', "+H", 3)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'x', "+H", 3)));
  
  //Prefix Not Here
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '_', " *", 4)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '0', " *", 4)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '1', " *", 4)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '2', " *", 5)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '3', " *", 5)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '4', " *", 5)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '5', " *", 5)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '6', " *", 5)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '7', " *", 5)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '8', " *", 6)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', '9', " *", 6)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'A', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'C', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'E', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'F', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'a', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'c', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'e', " *", 7)));
  machine.insert(pair<uint, TableEntry>(2, TableEntry('@', 'f', " *", 7)));
  
//State 3 Prefixs
  //Binary Prefix
  machine.insert(pair<uint, TableEntry>(3, TableEntry('B', '0', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('B', '1', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('B', '_', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('B', '%', "-B", 0)));
  
  //Octal Prefix
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '_', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '0', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '1', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '2', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '3', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '4', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '5', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '6', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '7', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('Q', '%', "-Q", 0)));
  
  //Decimal Prefix
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '_', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '0', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '1', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '2', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '3', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '4', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '5', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '6', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '7', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '8', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '9', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('D', '%', "-D", 0)));
  
  //Hex Prefix
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '_', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '0', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '1', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '2', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '3', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '4', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '5', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '6', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '7', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '8', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '9', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'A', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'B', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'C', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'D', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'E', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'F', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'a', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'b', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'c', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'd', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'e', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', 'f', " *", 3)));
  machine.insert(pair<uint, TableEntry>(3, TableEntry('H', '%', "-H", 0)));
 
//No Prefix detected 
  //State 4 Could be anything
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '_', " *", 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '0', " *", 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '1', " *", 4)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '2', " *", 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '3', " *", 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '4', " *", 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '5', " *", 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '6', " *", 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '7', " *", 5)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '8', " *", 6)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '9', " *", 6)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'A', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'B', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'C', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'D', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'E', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'F', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'a', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'b', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'c', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'd', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'e', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'f', "+P", 7)));

  //End of Binary String with Suffix 
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'B', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'b', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'Y', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'y', " *", 0)));
  
  //End of Octal String only with 0 and 1 with Suffix
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'Q', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'q', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'O', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'o', " *", 0)));
  
  //End of Decimal String with only 0 and 1
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'D', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'd', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'T', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 't', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', '%', " *", 0)));
  
  //End of Hex String with only 0 and 1 with Suffix
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'H', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'h', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'X', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('@', 'x', " *", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('P', 'H', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('P', 'h', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('P', 'X', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('P', 'x', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('Z', 'H', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('Z', 'h', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('Z', 'X', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(4, TableEntry('Z', 'x', "-Z", 0)));
  
  //State 5 Can't be Binary
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '_', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '0', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '1', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '2', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '3', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '4', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '5', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '6', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '7', " *", 5)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '8', " *", 6)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '9', " *", 6)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'A', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'B', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'C', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'D', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'E', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'F', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'a', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'b', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'c', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'd', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'e', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'f', "+P", 7)));
  
  
  //End of Octal String with Suffix     
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'Q', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'q', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'O', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'o', " *", 0)));
  
  //End of Decimal String with only 0-7 
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'D', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'd', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'T', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 't', " *", 0))); 
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', '%', " *", 0)));
  
  //End of Hex String with only 0-7 with Suffix
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'H', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'h', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'X', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('@', 'x', " *", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('P', 'H', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('P', 'h', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('P', 'X', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('P', 'x', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('Z', 'H', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('Z', 'h', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('Z', 'X', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(5, TableEntry('Z', 'x', "-Z", 0)));
  
  //State 6 Can't be Binary or Octal
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '_', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '0', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '1', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '2', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '3', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '4', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '5', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '6', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '7', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '8', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '9', " *", 6)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'A', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'B', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'C', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'D', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'E', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'F', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'a', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'b', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'c', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'd', "+G", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'e', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'f', "+P", 7)));
  
  //Default Decimal
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', '%', " *", 0)));
  
  //End of Decimal String with Suffix
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'D', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'd', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'T', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 't', " *", 0)));
  
  //End of Hex String with only 0-9 with Suffix
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'H', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'h', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'X', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('@', 'x', " *", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('P', 'H', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('P', 'h', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('P', 'X', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('P', 'x', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('Z', 'H', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('Z', 'h', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('Z', 'X', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(6, TableEntry('Z', 'x', "-Z", 0)));
  
  //State 7 Hex or Nothing
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '_', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '0', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '1', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '2', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '3', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '4', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '5', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '6', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '7', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '8', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '9', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'A', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'B', "+Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'C', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'D', "+Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'E', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'F', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'a', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'b', "+Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'c', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'd', "+Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'e', "+P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'f', "+P", 7)));
  
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '_', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '0', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '1', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '2', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '3', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '4', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '5', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '6', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '7', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '8', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', '9', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'A', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'B', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'C', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'D', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'E', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'F', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'a', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'b', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'c', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'd', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'e', "-Z", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'f', "-Z", 7)));
  
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '_', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '0', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '1', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '2', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '3', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '4', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '5', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '6', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '7', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '8', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', '9', "-P", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'A', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'B', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'C', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'D', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'E', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'F', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'a', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'b', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'c', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'd', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'e', " *", 7)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'f', " *", 7)));
  
  //Default Decimal
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', '%', " *", 0)));
  
  //Binary and Decimal Catch
  machine.insert(pair<uint, TableEntry>(7, TableEntry('G', '%', "-G", 0)));
  
  //End of Hex String with Suffix
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'H', " *", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'h', " *", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'X', " *", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('@', 'x', " *", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'H', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'h', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'X', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('P', 'x', "-P", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'H', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'h', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'X', "-Z", 0)));
  machine.insert(pair<uint, TableEntry>(7, TableEntry('Z', 'x', "-Z", 0)));
  
  
}