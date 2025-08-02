//Louis Jensen
//CS 4301-020
//Lab 02
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isValid(std::string s)
{
	char lastChar = 'u'; //Track what the previous character was
	int numofba = 0; //number of 'ba' we have seen
	for (int i = 0; i < s.length(); i++)
	{
		if (i != 0) //If it isn't our first iteration
		{
			if (lastChar == 'b' && s[i] == 'a') //if the last two chars make "ba"
			{
				numofba++;
			}
		}
		if (s[i] == 'a') //If the current char is a
		{
			lastChar = 'a';
		}
		else if (s[i] == 'b') //If the current char is b
		{
			lastChar = 'b';
		}
		else //Non 'a' or 'b' recieved, auto-fail
			return false;
	}
	if (numofba == 1) //probably unecessary, product of debugging 
		return false;
	if ((numofba % 2) != 0) //Modulus to check if amount of "ba" is even
		return false;
	else //we passed everything else, so it's true
		return true;
}