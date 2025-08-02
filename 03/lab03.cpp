//Louis Jensen
//CS 4301
//Lab 03

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isValid(string s)
{
	typedef enum {S, A, B, C} States;	
	States state = S;
	string::iterator itr, end = s.end();	
	for (itr = s.begin(); itr < end; ++itr)
	{
		if (*itr != 'a' && *itr != 'b' && *itr != ' ' && itr != end)
			return false; //Was having trouble with the error state, this fixed it 
		switch (state)
		{
			case S: if (*itr == 'a') //Only worried about "ba" if we keep getting a's it's fine
						state = S;
					else if (*itr == 'b') //We got a 'b' need to account for that
						state = A;
					break;
			case A: if (*itr == 'a') // We now have "ba" enter a fail state unless another one appears
						state = B;
					else if (*itr == 'b')//We can keep going with b's forever and be fine
						state = A;
					break;
			case B: if (*itr == 'a') //We need another 'b' to get "ba" back to even, stay until a 'b'
						state = B;
					else if (*itr == 'b')//alright to next fail state to wait for an 'a'
						state = C;		
					break;
			case C: if (*itr == 'a')//We got the 'a' for "ba" back to an accept state
						state = S;
					else if (*itr == 'b')//Still need that 'a' after a 'b' 
						state = C;
					break;
		}
	}	

	if (state == S || state == A)//Accept States are A or B
		return true;
	else 
		return false;
}