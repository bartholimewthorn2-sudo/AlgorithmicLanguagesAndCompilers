//Louis Jensen
//CS 4301
//Stage 1 Compiler

//Includes
#include<ctime>
#include<iomanip>
#include<stage1.h> 
#include<array>

//Debugging On/Off
//#define DEBUGGING //Debugging of most functions
//#define DEEPDEBUG //Debugging of the functions called many times that flood the output
//#define DEBUGGINGEMIT //Debugging of emit and other printing functions
//#define DEEPDEBUGRETURNS //Debugging of return values of functions that spam
//#define DEBUGTOK //Next Token Debug
//#define DEBUGCHA //Next Char Debug
//#define DEBUGGINGREAD //Read Statements Debug
//#define DEBUGGINGWRITE //Write Statements Debug
//#define STAGEONE //Stage 1 functions debug
//#define DEBUGSTACK //Debugging of Pop and Push

//#define PROGNAMEDEBUG
//Functions I defined
bool isMultOp (string);
bool isAddOp (string);
bool isRelOp (string);
int iCount = 0;
int bCount = 0;
bool ended = false;
int labelNum = -1;

using namespace std;

Compiler::Compiler(char **argv) // constructor ✓
{
	sourceFile.open(argv[1], ifstream::in); //Source File Opened for Input
	listingFile.open(argv[2], ofstream::out); //Listing File Opened for Output
	objectFile.open(argv[3], ofstream::out); //Object File Opened for Output
}

Compiler::~Compiler() // destructor ✓
{
	objectFile.close(); //Close the Object File
	listingFile.close(); //Close the Listing File
	sourceFile.close();  //Close the Source File
}

void Compiler::createListingHeader() //Listing File Header ✓
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in createListingHeader() with token: " << endl;
	#endif
	lineNo++;
	time_t now;
	now = time(NULL);
	listingFile << "STAGE1:" << setw(2) << " "  << "LOUIS JENSEN " << setw(6) << " " << ctime(&now) << endl;
	listingFile << "LINE NO." << setw(14) << " " << "SOURCE STATEMENT" << endl << endl;
	listingFile << right << setw(5) << lineNo << "|";
	//line numbers and source statements should be aligned under the headings
}

void Compiler::parser()
{
	nextChar();
	//ch must be initialized to the first character of the source file
	if (nextToken() != "program")
		processError("KPC");
		//a call to nextToken() has two effects
		// (1) the variable, token, is assigned the value of the next token
		// (2) the next token is read from the source file in order to make
		// the assignment. The value returned by nextToken() is also
		// the next token.
	prog();
	//parser implements the grammar rules, calling first rule
}

void Compiler::createListingTrailer() //✓
{
	listingFile << endl;
	listingFile << "COMPILATION TERMINATED" << setw(7) << errorCount;
	if (errorCount == 1)
		listingFile << " ERROR ENCOUNTERED" << endl;
	else
		listingFile << " ERRORS ENCOUNTERED" << endl;
}

void Compiler::processError(string err) 
{	
	errorCount++;
	listingFile << endl << "Error: " << "Line " << lineNo <<  ": ";
	//Lexical Errors
	if 		(err == "ILC") //Illegal Character
				listingFile << "Illegal Character"<< endl;
	else if (err == "RCB") //Right Curly brace began a token
				listingFile << "\"}\" cannot begin token"<< endl;
	else if (err == "UET") // Underscore at end of token
				listingFile << "\"_\"at end of token"<< endl;

	//Syntactic Errors
	else if (err == "NTE") //No Text may follow end
				listingFile << "No text may follow \"end\""<< endl;
	else if (err == "PNE") //Program Name Expected
				listingFile << "Program name expected"<< endl;	
	else if (err == "KPC") //Keyword Program expected
				listingFile << "Keyword \"program\" expected"<< endl;
	else if (err == "KBE") //Keyword begin expected
				listingFile << "Keyword \"begin\" expected"<< endl;
	else if (err == "KCE") //Keyword const expected
				listingFile << "Keyword \"const\" expected"<< endl;
	else if (err == "NKC") //Non-Keyword expected
				listingFile << "Non-keyword identifier must follow \"const\""<< endl;
	else if (err == "NKV") //Keyword Program expected
				listingFile << "Non-keyword identifier must follow \"var\""<< endl;
	else if (err == "KVE") //Keyword var expected
				listingFile << "Keyword \"var\" expected"<< endl;
	else if (err == "KEE") //Keyword end expected
				listingFile << "Keyword \"end\" expected"<< endl;
	else if (err == "SCE") //Semicolon Expected
				listingFile << "Semicolon expected"<< endl;	
	else if (err == "PDE") //Period Expected
				listingFile << "period expected"<< endl;
	else if (err == "EQE") //= expected
				listingFile << "\"=\" expected"<< endl;
	else if (err == "UEF") // Unexpected end of file
				listingFile << "Unexpected End of File"<< endl;
	
	else if (err == "RAO") 
				listingFile << "Relational or Addition operator or \")\" or \";\" expected"<< endl;
	else if (err == "BIN") 
				listingFile << "\"not\", \"true\", \"false\", \"(\", \"+\", \"-\", \"INTEGER\", or non-keyword identifier expected after \":=\""<< endl;			
	else if (err == "RSC") 
				listingFile << "Relational Operator Expected"<< endl;
	else if (err == "KWE") 
				listingFile << "Keywork \"write\" expected"<< endl;
	else if (err == "RPE") 
				listingFile << "\")\" expected"<< endl;
	else if (err == "LPE") 
				listingFile << "Attempting to read a read only location"<< endl;			
	else if (err == "KRE") 
				listingFile << "Keyword \"read\" expected"<< endl;
	else if (err == "KWR") 
				listingFile << "Keyword \"read\", \"write\", or non-keyword identifier expected"<< endl;	
	else if (err == "CRV") 
				listingFile << "Can't read variable of this type"<< endl;
	else if (err == "RRL") 
				listingFile << "Attempting to read a read only location"<< endl;			
	else if (err == "IOA") 
				listingFile << "Operands must be the same data type"<< endl;
	else if (err == "OLV") 
				listingFile << "Operand on left hand side of assignment must be a variable"<< endl;
				
	else if (err == "IBR") 
				listingFile << "non-keyword identifier, \"begin\", or \"var\" expected"<< endl;
	else if (err == "NKI") 
				listingFile << "non-keyword identifier expected"<< endl;			
	else if (err == "NKB") 
				listingFile << "non-keyword identifier or \"begin\" expected"<< endl;
	else if (err == "COE") 
				listingFile << "\":\" expected"<< endl;
	
	//Semantic Errors
	else if (err == "MND") 
				listingFile << "Symbol is defined multiple times"<< endl;
	else if (err == "IUK") 
				listingFile << "Illegal Use of Keyword"<< endl;
	else if (err == "RUC") 
				listingFile << "Reference to undefined constant"<< endl;
	else if (err == "TRI") 
				listingFile << "token to right of \"=\" illegal"<< endl;
	else if (err == "IES") 
				listingFile << "integer expected after sign"<< endl;
	else if (err == "BEN") 
				listingFile << "Boolean data type expected after \"not\""<< endl;				
	else if (err == "DTR") 
				listingFile << "data type of token on the right-hand side must be \"INTEGER\" or \"BOOLEAN\""<< endl;
	else if (err == "IFC") 
				listingFile << "illegal type follows \":\""<< endl;
				
	else if (err == "IEA") 
				listingFile << "Integer data type expected for addition"<< endl;
	else if (err == "IEB") 
				listingFile << "Integer data type expected for subtraction"<< endl;
	else if (err == "IEM")
				listingFile << "Integer data type expected for multiplication"<< endl;				
	else if (err == "IE%") 
				listingFile << "Integer data type expected for modulus"<< endl;
	else if (err == "IEN") 
				listingFile << "Integer data type expected for negation"<< endl;
			
	else if (err == "EUN") 
				listingFile << "Expected Unique non-keyword identifier"<< endl;
	else if (err == "ROD")
				listingFile << "Relational operators require matching data types"<< endl;				
	else if (err == "BEO") 
				listingFile << "Boolean data type expected after \"or\""<< endl;
	else if (err == "BEA") 
				listingFile << "Boolean data type expected after \"and\""<< endl;
	else if (err == "BIT")
				listingFile << "\"not\", \"true\", \"false\", \"+\", \"-\", \"BOOLEAN\", \"INTEGER\", or non-keyword identifier expected after"<< endl;
	//Compiler Errors
	else if (err == "CEC") 
				listingFile << "Compiler error since function should not be called with illegal arguemetns"<< endl;
	else if (err == "CET") 
				listingFile << "Compiler Error: stack underflow"<< endl;				
	else if (err == "CEO") 
				listingFile << "Compiler Error: stack overflow"<< endl;
	else if (err == "CEU") 
				listingFile << "Compiler Error: currentTemoNo should be ≥ 0"<< endl;
	//Failsafe Error
	else 
		listingFile << "Uknown error occurred" ;
	
	createListingTrailer();
	exit(EXIT_FAILURE);
}

void Compiler::prog() //token should be "program"
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in prog() with token: " << token << endl;
	#endif
	
	if (token != "program")
		processError("KPE");
	
	progStmt();
	
	if (token == "const")
		consts();
	
	if (token == "var")
		vars();
	
	if (token != "begin")
		processError("KBE");
	
	beginEndStmt();
	
	if (token.at(0) != END_OF_FILE)
		processError("NTE");
}

void Compiler::progStmt() //token should be "program"
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in progStmt() with token: " << token << endl;
	#endif 
	
	string x;
	
	if (token != "program")
		processError("KPE");
	
	x = nextToken();
	#ifdef PROGNAMEDEBUG
		listingFile << " Programe Name: " << x;
	#endif
	if (!isNonKeyId(token))
		processError("PNE");

		
	if (nextToken() != ";")
		processError("SCE");
	
	nextToken();
	code("program", x);
	insert(x,PROG_NAME,CONSTANT,x,NO,0);
}

void Compiler::consts() //token should be "const"
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in consts() with token: " << token << endl;
	#endif 
	
	if (token != "const")
		processError("KCE");
	
	if (!isNonKeyId(nextToken()))
		processError("NKC");
	
	constStmts();
}

void Compiler::vars() //token should be "var"
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in vars() with token: " << token << endl;
	#endif 
	
	if (token != "var")
		processError("KVE");
	
	if (isKeyword(nextToken()))
		processError("NKV");
	
	varStmts();
}

void Compiler::beginEndStmt() //token should be "begin"
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in beinEndStmt() with token: " << token << endl;
	#endif 
	
	if (token != "begin")
		processError("KBE");
	nextToken();
	if (token != "end" && (token == "read" || token == "write" || isNonKeyId(token)))
		execStmts();
	if (token == "end")
	{
		if (nextToken() != ".")
			processError("PDE");
	}
	else
		processError("KEE");
	
	ended = true;
	nextToken();
	code("end", ".");
}

void Compiler::constStmts() //token should be NON_KEY_ID
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in constStmts() with token: " << token << endl;
	#endif 
	
	string x,y;
	storeTypes stor;
	
	if (!isNonKeyId(token))
		processError("NKI");
		
	x = token;
	
	if (nextToken() != "=")
		processError("EQE");
	
	y = nextToken();
	
	if (!isLiteral(y) && isNonKeyId(y))
		processError("TRI");
	
	if (y == "+" || y == "-")
	{
		nextToken();
		if (!isdigit(token[0]))
			processError("IES");
		y = y + token;
	}

	if (y == "not")
	{
		if (!isBoolean(nextToken()))
			processError("BEN");
		
		if (token == "true")
			y = "false";
		else
			y = "true";
	}
	if (nextToken() != ";")
		processError("SCE");
	
	if (isBoolean(y) == 0 && isalnum(y[0]) == 1)
		processError("DTR");
	
	if (isBoolean(y))
		stor = BOOLEAN;
	else 
		stor = INTEGER;
	modes inMode = CONSTANT;
	allocation inAlloc = YES;
	
	insert(x,stor,inMode,y,inAlloc,1);
	
	x = nextToken();
	
	if (x != "begin" && x != "var" && !isNonKeyId(x))
		processError("IBR");
	
	if (isNonKeyId(x))
		constStmts();
}

void Compiler::varStmts() //token should be NON_KEY_ID
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in varStmts() with token: " << token << endl;
	#endif 
	
	string x,y;
	storeTypes stor;
	
	if (!isNonKeyId(token))
		processError("NKI");
	
	x = ids();
	
	if (token != ":")
		processError("COE");
	nextToken();
	if (token != "integer" && token != "boolean")
		processError("IFC");
	
	y = token;
	if (nextToken() != ";")
		processError("SCE");
	
	if (y == "boolean")
		stor = BOOLEAN;
	else 
		stor = INTEGER;
	
	modes inMode = VARIABLE;
	allocation inAlloc = YES;
	insert(x, stor, inMode, y, inAlloc, 1);
	
	if (!isNonKeyId(nextToken()) && token != "begin")
		processError("NKB");
	
	if (isNonKeyId(token))
		varStmts();
}

string Compiler::ids() //token should be NON_KEY_ID
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in ids() with token: " << token << endl;
	#endif 
		
	if (!isNonKeyId(token))
		processError("NKI");
	
	string temp = token; 
    nextToken();

    while (token == ",") 
	{
		nextToken();
        if (isNonKeyId(token))
		{
			temp += "," + token; // Append the comma and the next identifier
			nextToken();	
		}
		else
			processError("NKI");  
    }
    return (temp);
}

void Compiler::insert(string externalName,storeTypes inType, modes inMode, string inValue, allocation inAlloc, int inUnits)
//create symbol table entry for each identifier in list of external names
//Multiply inserted names are illegal
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in insert() with externalName: " << externalName << endl;
	#endif 
	
	string name = "";
	int i = 0;
	int k = 0;
	int j = 0;
	int l = 0;
	int len = externalName.length();
	bool multiple = false;
	
	while (i < len)
	{
		if (externalName[i] == ',')
		{
			for (j = 0; j < i; j++)
			{
				name.append(1, externalName[j]);
				multiple = true;
				l = k;
				k = i + 1;
			}
		}
		else if (i == (len - 1) && k == 0)
			name = externalName;
		else if (i != (len - 1) && k != 0)
		{
			name.append(1, externalName[l]);
		}
		else if (i == (len -  1))
		{
			for (j = k; j <= i; j++)
				name.append(1, externalName[j]);
		}
		if (i == (len - 1) || multiple)
		{
			if (symbolTable.count(name) != 0)
				processError("MND");
			else if (isKeyword(name))
				processError("IUK");
			else //create table entry
			{
				if (isupper(name[0]))
				{
					//cout << "Name: " << name << endl;
					SymbolTableEntry currEntry = SymbolTableEntry(name, inType, inMode, inValue, inAlloc, inUnits);
					symbolTable.insert(std::make_pair(name, currEntry));
					//symbolTable[name] = currEntry;
				}
				else
				{	
					//cout << inType << endl;
					//cout << "Name: " << name << endl;
					string internalName = genInternalName(inType);
					SymbolTableEntry currEntry = SymbolTableEntry(internalName, inType, inMode, inValue, inAlloc, inUnits);
					symbolTable.insert(std::make_pair(name, currEntry));
					//symbolTable[name] = currEntry;
				}
			}
		}
			multiple = false;
			name.clear();
		i++;
	}
}


storeTypes Compiler::whichType(string name) //tells which data type a name has
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in whichType() with name: " << name << endl;
	#endif 
	
	storeTypes dataType;
	if (isLiteral(name))
	{
		if (isBoolean(name))
			dataType = BOOLEAN;
		else
			dataType = INTEGER;
	}
	else //name is an identifier and hopefully a constant
	{
		if (symbolTable.count(name) > 0)
		{
			dataType = whichType(name);
		}
		else
		{
			processError("RUC");
		}
	}
	return (dataType);
}

string Compiler::whichValue(string name) //tells which value a name has
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in whichValues() with name: " << name << endl;
	#endif 
	
	string value;
	
	if (isLiteral(name))
		value = name;
	else //name is an identifier and hopefully a constant
	{
		SymbolTableEntry symNameVa = symbolTable.at(name);
		if (symbolTable.count(name) > 0 && symNameVa.getValue() != "")
			value = symNameVa.getValue();
		else
			processError("RUC");
	}
	return (value);
}
/*
***************************************************************************
void Compiler::code(string op, string operand1, string operand2)
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in code() with op: " << op << endl;
	#endif 
	
	if (op == "program")
		emitPrologue(operand1);
	else if (op == "end")
		emitEpilogue();
	else
		processError("CEC");
}
***************************************************************************
*/
void Compiler::emit(string label, string instruction, string operands, string comment)
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emit() with label: " << label << endl;
	#endif 
	
	objectFile << left;
	objectFile << setw(8) << label;
	objectFile << setw(8) << instruction;
	objectFile << setw(24) << operands;
	if (comment != "")
		objectFile << "; " << comment; 
	objectFile << endl;
}

void Compiler::emitPrologue(string progName, string operand2)
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitPrologue() with progName: " << progName << endl;
	#endif 
	time_t now;
	now = time(NULL);
	string tempProgName;
	
	if(progName.length() > 15)
		tempProgName = progName.erase(15);
	else
		tempProgName = progName;
	objectFile << left << "; LOUIS JENSEN " << setw(6) << " " << ctime(&now) << left;
	objectFile << "%INCLUDE \"Along32.inc\"" << endl;
	objectFile << "%INCLUDE \"Macros_Along.inc\"" << endl << endl;
	emit("SECTION", ".text");
	
	emit("global", "_start", "", "program " + tempProgName);
	objectFile << endl;
	emit("_start:");
}

void Compiler::emitEpilogue(string operand1, string operand2)
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitEpilogue with operand1: () " << operand1 <<endl;
	#endif 
	
	emit("","Exit", "{0}");
	objectFile << endl;
	emitStorage();
}

void Compiler::emitStorage()
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitStorage()" << endl;
	#endif 
	
	string label;
	string truncKey;
	map<string, SymbolTableEntry>::iterator symItBeg = symbolTable.begin(); 
	map<string, SymbolTableEntry>::iterator symItEnd = symbolTable.end(); 
	map<string, SymbolTableEntry>::iterator symItBeg2 = symbolTable.begin(); 
	string operand = "0";

	emit("SECTION", ".data");

	for (symItBeg = symbolTable.begin(); symItBeg != symItEnd; symItBeg++) 
	{
		string key = symItBeg->first;  // Get the key
		SymbolTableEntry entry = symItBeg->second; // Get the entry
		if (entry.getMode() == CONSTANT && entry.getAlloc() == YES)
		{
			label = entry.getInternalName();
			operand = entry.getValue();
			if (operand == "true")
				operand = "-1";
			else if (operand == "false")
				operand = "0";
			else
			{
				for (symItBeg2 = symbolTable.begin(); symItBeg2 != symItEnd; symItBeg2++)
				{
					string comKey = symItBeg2->first;
					string curVal = entry.getValue();
					if (curVal == comKey)
					{
						SymbolTableEntry value = symItBeg2->second;
						operand = value.getValue();
						break;
					}
				}
			}
			if (key.length() > 15)
				truncKey = key.erase(15);
			else 
				truncKey = key;
			emit(label, "dd", operand, truncKey);
		}
	} 
	objectFile << endl;
	emit("SECTION", ".bss");
	for (symItBeg = symbolTable.begin(); symItBeg != symItEnd; ++symItBeg) 
	{
		string key = symItBeg->first;  // Get the key
		SymbolTableEntry entry = symItBeg->second; // Get the entry
		if (entry.getMode() == VARIABLE && entry.getAlloc() == YES)
		{
			label = entry.getInternalName();
			operand = entry.getValue();
			if (key.length() > 15)
				truncKey = key.erase(15);
			else 
				truncKey = key;
			emit(label, "resd", operand, truncKey);
		}
	}
}

string Compiler::nextToken() //returns the next token or end of file marker
{
	#ifdef DEBUGTOK
		cout << "Debugging: We're in nextToken() with token: " << token << endl;
	#endif 
	
	token = "";
	char tchar;
	while (token == "")
	{
	
	if (ch == '{')  //process comment
	{
		tchar = nextChar();
		while (tchar != END_OF_FILE && tchar != '}')
		{ //empty body }
			if (tchar == END_OF_FILE)
				processError("UEF");
			else
				tchar = nextChar();
		}
		nextChar();
	}
	else if (ch == '}') 
		processError("RCB");
	else if (isspace(ch)) 
		nextChar();
	else if (isSpecialSymbol(ch)) 
	{
		token = ch;
		nextChar();
	}
	else if (islower(ch)) 
	{
		token = ch;
		tchar = nextChar();
		while ((isalpha(tchar) || isdigit(tchar) ||  tchar == '_') && (tchar != END_OF_FILE) && tchar != ' ')
		{
			token += ch;
			tchar = nextChar();
		}
		if (tchar == END_OF_FILE)
			processError("UEF");
	}
	else if (isdigit(ch)) 
	{
		token = ch;
		tchar = nextChar();
		while (isdigit(tchar) && tchar != END_OF_FILE)
		{
			token+=ch;
			tchar = nextChar();
		}
		if (tchar == END_OF_FILE)
			processError("UEF");
	}
	else if (ch == END_OF_FILE) 
		token = ch;
	else 
		processError("ILC");
	}
	return (token);
}
char Compiler::nextChar() //returns the next character or end of file marker
{
	#ifdef DEBUGCHA
		cout << "Debugging: We're in nextChar() with token: " << token << endl;
	#endif 
	
	ch = sourceFile.get();
	if (sourceFile.eof())
		ch = END_OF_FILE; //use a special character to designate end of file
		// END_OF_FILE is defined in stage0.h
	else
	{
		if ((ch == '\n' || ch == '\r') && token != "." && token != "}" && !ended)
		{
			lineNo++;
			listingFile << endl << right << setw(5) << lineNo << "|";
			return (ch);
			nextChar();
		}
		else 
		{
			listingFile << ch;
		}
	}
	return (ch);
}

bool Compiler::isKeyword(string ID) const 
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isKeyword() with token: " << token  << " and string: " << ID << endl;
	#endif 
	
	array<string, 16>IDS = {"program", "begin", "end", "var", "const", "integer", "boolean", "true", "false", "not", "mod", "div", "and", "or", "read", "write"};
	bool status = false;
	
	for (int i = 0; i < 16; i++)
	{
		if (ID == IDS[i])
		{
			status = true;
		}
	}
	#ifdef DEEPDEBUGRETURNS
		cout << "Returning from isKeyword with status: " << status << endl; 
	#endif
	return (status);
}
bool Compiler::isSpecialSymbol(char c) const // determines if c is a special symbol
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isSpecialSymbol() with token: " << token << " and char: " << c << endl;
	#endif 
	
	array<char, 12>SpecSym = {'=', ':', ',', ';', '.', '+', '-', '*', '(', ')', '<', '>', };
	bool status = false;
	
	for(int i = 0; i < 12; i++)
	{
		if (c == SpecSym[i])
		{
			status = true;
			break;
		}
	}
	#ifdef DEEPDEBUGRETURNS
		cout << "Returning from isSpecialSymbol with status: " << status << endl; 
	#endif
	return (status);
}
bool Compiler::isNonKeyId(string s) const  // determines if s is a non_key_id
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isNonKeyId() with token: " << token << " and string: " << s << endl;
	#endif 
	
	bool status = false;
	
	if(isKeyword(s) == 0 && (isalpha(s[0]) == 0 || isdigit(s[0]) == 0))
		status = true;
	
	#ifdef DEEPDEBUGRETURNS
		cout << "Returning from isNonKeyId with status: " << status << endl; 
	#endif
	
	return (status);
}
bool Compiler::isInteger(string s) const // determines if s is an integer
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isInteger() with token: " << token  << " and string: " << s << endl;
	#endif 
	
	bool status = false;
	if (isdigit(s[0]))
		status = true;
	
	#ifdef DEEPDEBUGRETURNS
		cout << "Returning from isInteger with status: " << status << endl; 
	#endif
	
	return (status);
}
bool Compiler::isBoolean(string s) const  // determines if s is a boolean
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isBoolean() with token: " << token << " and string: " << s << endl;
	#endif 
	
	bool status = false;
	if (s == "true" || s == "false")
		status = true;
	
	#ifdef DEEPDEBUGRETURNS
		cout << "Returning from isBoolean with status: " << status << endl; 
	#endif
	
	return (status);
}
bool Compiler::isLiteral(string s) const // determines if s is a literal
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isLiteral() with token: " << token << " and string: " << s << endl;
	#endif 
	int index = 0;
	bool status = false;
	if (s[0] == '-' || s[0] == '+')
		index = 1;
	//Edited Literals to Include read write
	if (isBoolean(s) || isalnum(s[index]) || s == "+" || s == "-" || s =="not" || s == "write" || s == "read")
		status = true;
	
	#ifdef DEEPDEBUGRETURNS
		cout << "Returning from isLiteral with status: " << status << endl; 
	#endif
	
	return (status);
}

string Compiler::genInternalName(storeTypes stype) const
{
	string label;
	if (stype == INTEGER)
	{
		string currentI = to_string(iCount);
		label = "I" + currentI;
		iCount++;
	}
	else if (stype == BOOLEAN)
	{
		string currentB = to_string(bCount);
		label = "B" + currentB;
		bCount++;
	}
	return (label);
}

void Compiler::execStmts()
{
	#ifdef STAGEONE
		cout << "Debugging: We're in execStmts() with token: " << token << endl;
	#endif  
	
	while (token != "end" && (token == "read" || token == "write" || isNonKeyId(token)))
	{
		execStmt();
	}
	if (token == "end")
		return;
	else
		processError("KEE");
}
void Compiler::execStmt()  
{
	#ifdef STAGEONE
		cout << "Debugging: We're in execStmt() with token: " << token << endl;
	#endif 
	
	if (token != "read" && token != "write" && isKeyword(token))
		processError("KRW");
	//NO NEXT TOKEN HERE
	if (isNonKeyId(token))
		assignStmt();
	if (token == "read")
		readStmt();
	if (token == "write")
	{
		writeStmt();
	}
	return;
}    
void Compiler::assignStmt()    
{
	#ifdef STAGEONE
		cout << "Debugging: We're in assignStmt() with token: " << token << endl;
	#endif 
	if (isKeyword(token))
		processError("NKB");
	pushOperand(token);
	nextToken();
	if (token != ":")
		processError("COE");
	nextToken();
	if (token != "=")
		processError("= expected");
	nextToken();
	pushOperator(":=");
	nextToken(); //001.dat
	if (token != ";")
		express();

	if (token != ";")
	{
		processError("SCE");
	}
	string s1 = popOperand();
	string s2 = popOperand();
	code(popOperator(), s1, s2);
	nextToken(); //MARKED Unknown usefulness
	return;
	
}
void Compiler::readStmt() 
{
	#ifdef STAGEONE
		cout << "Debugging: We're in readStmt() with token: " << token << endl;
	#endif
	string temp;
	if (token != "read")
		processError("KRE");
	nextToken();
	temp = token;
	if (token != "(")
		processError("LPE");
	else 
	{
		nextToken();
		temp = ids();
	}
	if (token == ")") //nextToken() //May be needed unsure for now
	{
		if (nextToken() != ";")
			processError("SCE");
		pushOperand(temp);
		code("read", popOperand());
	}
	else 
	{
		processError("RPE");
	}
	nextToken();
	return;
}    
void Compiler::writeStmt() 
{
	#ifdef STAGEONE
		cout << "Debugging: We're in writeStmt() with token: " << token << endl;
	#endif 
	
	if (token != "write")
		processError("KWE");
	nextToken();
	if (token != "(")
		processError("LPE");
	else 
	{
		nextToken();
		string tempID = ids();
		pushOperand(tempID);
	}
	if (token != ")") //nextToken() //May be needed unsure for now
		processError("RPE");
	code("write", popOperand());
	if (nextToken() != ";")
	{
		//cout << endl << endl << "FOUND" << endl << endl;
		processError("SCE");
	}
	nextToken(); //Dataset 101
	return;
		
}    
void Compiler::express() 
{
	#ifdef STAGEONE
		cout << "Debugging: We're in express() with token: " << token << endl;
	#endif 
	if (token == ";")
		return;
	nextToken();
	if (isLiteral(token) || token == "(")
	{
		term();
		expresses();
	}
	else
		processError("TRI");
	//nextToken(); //MARKED Unknown usefulness
	return;
}       
void Compiler::expresses()
{
	#ifdef STAGEONE
		cout << "Debugging: We're in expresses() with token: " << token << endl;
	#endif 
	
	if (isRelOp(token))
	{
		pushOperator(token);
		term();
		if (token != ";")
		{
			string s1 = popOperand();//May need to move out of if statement
			string s2 = popOperand();
			code(popOperator(), s1, s2);
            if (isTemporary(s1)) 
                freeTemp();
            if (isTemporary(s2) && s1 != s2) 
                freeTemp();
			nextToken(); //MARKED Unknown usefulness
			expresses();
		}
	}
	if (token == "write" || token == "read")
		return;
	if (token == ";" || token == ")")
		return;
	else 
		processError("RSC");
	//nextToken(); //MARKED Unknown usefulness
}     	
void Compiler::term()
{
	#ifdef STAGEONE
		cout << "Debugging: We're in term() with token: " << token << endl;
	#endif
	
	if (isLiteral(token) || token == "(")
	{
		factor();
		terms();
	}		
	else 
		processError("TRI");
	return;
	
}          
void Compiler::terms()
{
	#ifdef STAGEONE
		cout << "Debugging: We're in TERMS() with token: " << token << endl;
	#endif 
	
	if (isAddOp(token))
	{
		pushOperator(token);
		nextToken();
		factor();
		string s1 = popOperand();
		string s2 = popOperand();
		code(popOperator(), s1, s2);
		//nextToken(); //MARKED Unknown usefulness
		terms();
	}
	if (isRelOp(token) || token == ")" || token ==";")
	{
		if (token == ")")
			nextToken(); //Added to assist Dataset 2 
		if ((isRelOp(token) || isAddOp(token) || isMultOp(token)) && token != ";")
		{
			nextToken();
			term();
		}
		//if (token == ";") //May be needed, didn't fix dataset 2
			//nextToken();
		return;
	}
	else
		processError("RSC");
	//nextToken(); //MARKED Unknown usefulness
}        
void Compiler::factor() 
{
	#ifdef STAGEONE
		cout << "Debugging: We're in factor() with token: " << token << endl;
	#endif 
	
	if (token != "not" && token != "true" && token != "false" && token != "(" && token != "+" && token != "-" && isKeyword(token) && !isInteger(token))
		processError("BIN");
	else 
	{
		part();
		factors();
	}
	return;
	//nextToken(); //MARKED Unknown usefulness
}      
void Compiler::factors() 
{
	#ifdef STAGEONE
		cout << "Debugging: We're in factors() with token: " << token << endl;
	#endif 
	
	if (isMultOp(token))
	{
		pushOperator(token);
		nextToken(); //MARKED2 Unkown Use
		part();
		string s1 = popOperand();
		string s2 = popOperand();
		code(popOperator(), s1, s2);
		if (isMultOp(token) || isRelOp(token) || token == ")" || token == ";" || isAddOp(token))
			factors();
		else 
			return;
	}
	if (isRelOp(token) || token == ")" || token == ";" || isAddOp(token))
	{
		//nextToken(); //MARKED2 Unknown Use
		return;
	}
	else 
	{
		processError("RAO");
	}
	//nextToken(); //MARKED Unknown usefulness
}      
void Compiler::part()
{
	#ifdef STAGEONE
		cout << "Debugging: We're in part() with token: " << token << endl;
	#endif 
	
	if (token == "not")
	{
		pushOperator(token);
		nextToken();
		if (token == "(")
		{
			nextToken();
			while (token != ")" && token[0] != END_OF_FILE && token != ";") //added ";" dataset 2 attmept
				express();
			if (token[0] == END_OF_FILE)
				processError("UEF");
			if (token == ")")
			{
				code("not", popOperand());
				nextToken();
				return;
			}
		}
		if (isBoolean(token))
		{
			pushOperand(token);
			nextToken(); //Uncertain call, Think where returning to 
			return;
		}
		if (isNonKeyId(token))
		{
			code("not", token);
			nextToken(); //Uncertain call, Think where returning to 
			return;
		}
	}
	else if (token == "(")
	{
		nextToken();
		while (token != ")" && token[0] != END_OF_FILE && token != ";")
			express();
		if (token[0] == END_OF_FILE)
			processError("UEF");
		if (token == ")")
		{
			nextToken();
			return;
		}	
	}
	else if (token == "+")
	{
		nextToken();
		if (token == "(")
		{
			nextToken();
			while (token != ")" && token[0] != END_OF_FILE && token != ";")
				express();
			if (token[0] == END_OF_FILE)
				processError("UEF");
			if (token == ")")
			{
				nextToken();
				return;
			}
		}
		if (isInteger(token) || isNonKeyId(token))
		{
			pushOperand(token);
			nextToken();
			return;
		}
	}
	else if (token == "-")
	{
		nextToken();
		if (token == "(")
		{
			nextToken();
			while (token != ")" && token[0] != END_OF_FILE && token != ";")
				express();
			if (token[0] == END_OF_FILE)
				processError("UEF");
			if (token == ")")
			{
				code("neg", popOperand());
				nextToken();
				return;
			}
		}
		if (isInteger(token))
		{
			pushOperand(token);
			nextToken();
			return;
		}
		if (isNonKeyId(token))
		{
			code("neg", popOperand()); //Changed from token to popOperand for dataset 2
			nextToken();
			return;
		}
	}
	else if (isInteger(token) || isBoolean(token) || isNonKeyId(token))
	{
			pushOperand(token);
			nextToken(); //Uncertain Call
			return;
	}
	if (token == ";")
		return;
	processError("BIT");
}          
void Compiler::emitReadCode(string operand, string operand2)
{
	#ifdef DEBUGGINGREAD
		cout << "Debugging: We're in emitReadCode() with operands: " << operand << "and" << operand2 << endl;
	#endif 
	
	string name;
	size_t pos = 0; 
	while ((pos = operand.find(",")) != string::npos)
	{
		name = operand.substr(0, pos);
		operand.erase(0, pos + 1);
		SymbolTableEntry symbolEntry = symbolTable.at(name);
		if (symbolTable.count(name) <= 0)
			processError("RUC");
		if (symbolEntry.getDataType() != INTEGER)
		{
			processError("CRV");
		}
		if (symbolEntry.getMode() != VARIABLE)
			processError("RRL");
		emit("", "Call", "ReadInt", "read int; value placed in eax");
		emit("", "mov", name + ",eax", "store eax at " + operand);
		contentsOfAReg = name;
	}
	name = operand;
	SymbolTableEntry symbolEntry = symbolTable.at(name);
	if (symbolTable.count(name) <= 0)
		processError("RUC");
	if (symbolEntry.getDataType() != INTEGER)
		processError("CRV");
	if (symbolEntry.getMode() != VARIABLE)
		processError("RRL");
	emit("", "Call", "ReadInt", "read int; value placed in eax");
	emit("", "mov", name + ",eax", "store eax at " + operand);
	contentsOfAReg = name;
	return;
}
void Compiler::emitWriteCode(string operand, string operand2)
{
	#ifdef DEBUGGINGWRITE
		cout << "Debugging: We're in emitWriteCode() with operands: " << operand << "and" << operand2 << endl;
	#endif 
	
	string name;
	size_t pos = 0; 
	//static bool definedStorage = false;
	
	while ((pos = operand.find(",")) != string::npos)
	{
		name = operand.substr(0, pos);
		operand.erase(0, pos + 1);
		SymbolTableEntry symbolEntry = symbolTable.at(name);
		if (symbolTable.count(name) <= 0)
			processError("RUC");
		if (contentsOfAReg != name)
		{
			emit("", "mov ", name + ", eax", "");
			contentsOfAReg = name;
		}
		if (symbolEntry.getDataType() == INTEGER || symbolEntry.getDataType() == BOOLEAN)
			emit("", "Call", "WriteInt", "");
		emit("", "Call", "Clrf", "");
	}
	name = operand.substr(0, pos);
	operand.erase(0, pos + 1);
	SymbolTableEntry symbolEntry = symbolTable.at(name);
	if (symbolTable.count(name) <= 0)
		processError("RUC");
	if (contentsOfAReg != name)
	{
		emit("", "mov ", name + ", eax", "");
		contentsOfAReg = name;
	}
	if (symbolEntry.getDataType() == INTEGER && symbolEntry.getDataType() == BOOLEAN)
		emit("", "Call", "WriteInt", "");
	emit("", "Call", "Clrf", "");
	return;
}
void Compiler::emitAssignCode(string operand1, string operand2)         
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitAssignCode() with operands: " << operand1 << " and " << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("IOA");
	if (symbolEntry2.getMode() != VARIABLE) //Unsure why Operand 2
		processError("OLV");
	if (symbolEntry1.getValue() == symbolEntry2.getValue())
		return;
	if (symbolEntry1.getValue() != contentsOfAReg)
	{
		emit("", "mov ","eax, " + operand1, "");
		contentsOfAReg = operand1;
	}
	emit("", "mov ", operand2 + ", eax", "");
	contentsOfAReg = operand2;
	//if (symbolEntry1.getInternalName()[0] == 'T')
	if (isTemporary(operand1))
		freeTemp();
	return;
}
void Compiler::emitAdditionCode(string operand1, string operand2)       
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitAdditionCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != INTEGER || symbolEntry2.getDataType() != INTEGER)
		processError("IEA");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov ", contentsOfAReg + ", eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	//isTemporary(symbolTable.at(contentsOfAReg).getInternalName())
	if (isTemporary(contentsOfAReg) && contentsOfAReg != operand1 && contentsOfAReg != operand2)
		contentsOfAReg = "";
	if (contentsOfAReg != operand2)
	{
		emit("", "mov ","eax, " + operand2, "");
		contentsOfAReg = operand2;
	}
	emit("", "add", "eax, " + operand2, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp();
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitSubtractionCode(string operand1, string operand2)    
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitSubtractionCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != INTEGER || symbolEntry2.getDataType() != INTEGER)
		processError("IEB");
	if (isTemporary(contentsOfAReg) && contentsOfAReg != operand2)
	{
		emit("", "mov ", contentsOfAReg + ", eax", "");
		symbolTable.at(contentsOfAReg).setAlloc(YES);
		contentsOfAReg = "";
	}
	if (contentsOfAReg != operand2 && isTemporary(contentsOfAReg))
		contentsOfAReg = "";
	if (contentsOfAReg != operand2)
		emit("", "mov", "eax, " + operand2, "");
	emit("", "sub", "eax, " + operand2, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitMultiplicationCode(string operand1, string operand2) 
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitMultiplicationCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != INTEGER || symbolEntry2.getDataType() != INTEGER)
		processError("IEM");
	if (isTemporary(contentsOfAReg))
	{
		if (operand1 == contentsOfAReg || operand2 == contentsOfAReg)
		{
			emit("", "mov ", contentsOfAReg + ", eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	//isTemporary(symbolTable.at(contentsOfAReg).getInternalName())
	if (isTemporary(contentsOfAReg) && contentsOfAReg != operand1 && contentsOfAReg != operand2)
		contentsOfAReg = "";
	if (contentsOfAReg != operand2)
	{
		emit("", "mov ","eax, " + operand2, "");
		contentsOfAReg = operand2;
	}
	emit("", "imul", "eax, " + operand2, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp();
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitDivisionCode(string operand1, string operand2)       
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitDivisionCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != INTEGER || symbolEntry2.getDataType() != INTEGER)
		processError("IED");
	if (isTemporary(contentsOfAReg) && contentsOfAReg != operand2)
	{
		emit("", "mov ", contentsOfAReg + ", eax", "");
		symbolTable.at(contentsOfAReg).setAlloc(YES);
		contentsOfAReg = "";
	}
	if (contentsOfAReg != operand2 && isTemporary(contentsOfAReg))
		contentsOfAReg = "";
	if (contentsOfAReg != operand2)
		emit("", "mov", "eax, " + operand2, "");
	emit("", "cdq", "", "");
	emit("", "idiv", "dword " + operand2, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitModuloCode(string operand1, string operand2)         
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitModuloCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != INTEGER || symbolEntry2.getDataType() != INTEGER)
		processError("IE%");
	if (isTemporary(contentsOfAReg) && contentsOfAReg != operand2)
	{
		emit("", "mov ", contentsOfAReg + ", eax", "");
		symbolTable.at(contentsOfAReg).setAlloc(YES);
		contentsOfAReg = "";
	}
	if (contentsOfAReg != operand2 && isTemporary(contentsOfAReg))
		contentsOfAReg = "";
	if (contentsOfAReg != operand2)
		emit("", "mov", "eax, " + operand2, "");
	emit("", "cdq", "", "");
	emit("", "idiv", "dword " + operand2, "");
	emit("", "xchg", "eax, edx", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitNegationCode(string operand1, string operand2)           
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitNegationCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry = symbolTable.at(operand1);
    if (symbolEntry.getDataType() != INTEGER) 
        processError("IEN");
    if (contentsOfAReg != operand1)
	{
        emit("", "mov", "eax, " + operand1, "");
        contentsOfAReg = operand1;
    }
    emit("", "neg", "eax", ""); 
    contentsOfAReg = getTemp();
    symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitNotCode(string operand1, string operand2)                
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitNotCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != BOOLEAN || symbolEntry2.getDataType() != BOOLEAN)
		processError("BEN");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov ", contentsOfAReg + ", eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		emit("", "mov", "eax, " + operand2, "");
	emit("", "not", "eax, " + operand1, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp();
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(BOOLEAN);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitAndCode(string operand1, string operand2)            
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitAndCode() with with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != BOOLEAN || symbolEntry2.getDataType() != BOOLEAN)
		processError("BEA");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov ", contentsOfAReg + ", eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		emit("", "mov", "eax, " + operand2, "");
	emit("", "and", "eax, " + operand1, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp();
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(BOOLEAN);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitOrCode(string operand1, string operand2)             
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitOrCode() with with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != BOOLEAN || symbolEntry2.getDataType() != BOOLEAN)
		processError("BEO");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov ", contentsOfAReg + ", eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		emit("", "mov", "eax, " + operand2, "");
	emit("", "or", "eax, " + operand1, "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp();
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(BOOLEAN);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitEqualityCode(string operand1, string operand2)      
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitGreaterThanOrEqualToCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("ROD");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov", contentsOfAReg + ",eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (contentsOfAReg != operand1 && contentsOfAReg != operand2)
		emit("", "mov", "eax," + operand2, "");
	emit("", "cmp", "eax," + operand1, "");
	string label = getLabel();
	emit("", "je", label, "");
	emit("", "mov", "eax,[FALSE]", "");
	string label2 = getLabel();
	emit("", "jmp", label2, "");
	emit(label, "", "", "");
	emit("", "mov", "eax,[TRUE]");
	string yes = "true";
	insert(yes, BOOLEAN, VARIABLE, to_string(-1), YES, 1);
	emit(label2, "", "", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitInequalityCode(string operand1, string operand2)     
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitGreaterThanOrEqualToCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("ROD");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov", contentsOfAReg + ",eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (contentsOfAReg != operand1 && contentsOfAReg != operand2)
		emit("", "mov", "eax," + operand2, "");
	emit("", "cmp", "eax," + operand1, "");
	string label = getLabel();
	emit("", "jne", label, "");
	emit("", "mov", "eax,[FALSE]", "");
	string label2 = getLabel();
	emit("", "jmp", label2, "");
	emit(label, "", "", "");
	emit("", "mov", "eax,[TRUE]");
	string yes = "true";
	insert(yes, BOOLEAN, VARIABLE, to_string(-1), YES, 1);
	emit(label2, "", "", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitLessThanCode(string operand1, string operand2)       
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitGreaterThanOrEqualToCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("ROD");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov", contentsOfAReg + ",eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (contentsOfAReg != operand1 && contentsOfAReg != operand2)
		emit("", "mov", "eax," + operand2, "");
	emit("", "cmp", "eax," + operand1, "");
	string label = getLabel();
	emit("", "jl", label, "");
	emit("", "mov", "eax,[FALSE]", "");
	string label2 = getLabel();
	emit("", "jmp", label2, "");
	emit(label, "", "", "");
	emit("", "mov", "eax,[TRUE]");
	string yes = "true";
	insert(yes, BOOLEAN, VARIABLE, to_string(-1), YES, 1);
	emit(label2, "", "", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitLessThanOrEqualToCode(string operand1, string operand2)
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitGreaterThanOrEqualToCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("ROD");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov", contentsOfAReg + ",eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (contentsOfAReg != operand1 && contentsOfAReg != operand2)
		emit("", "mov", "eax," + operand2, "");
	emit("", "cmp", "eax," + operand1, "");
	string label = getLabel();
	emit("", "jle", label, "");
	emit("", "mov", "eax,[FALSE]", "");
	string label2 = getLabel();
	emit("", "jmp", label2, "");
	emit(label, "", "", "");
	emit("", "mov", "eax,[TRUE]");
	string yes = "true";
	insert(yes, BOOLEAN, VARIABLE, to_string(-1), YES, 1);
	emit(label2, "", "", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitGreaterThanCode(string operand1, string operand2)    
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitGreaterThanOrEqualToCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("ROD");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov", contentsOfAReg + ",eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (contentsOfAReg != operand1 && contentsOfAReg != operand2)
		emit("", "mov", "eax," + operand2, "");
	emit("", "cmp", "eax," + operand1, "");
	string label = getLabel();
	emit("", "jg", label, "");
	emit("", "mov", "eax,[FALSE]", "");
	string label2 = getLabel();
	emit("", "jmp", label2, "");
	emit(label, "", "", "");
	emit("", "mov", "eax,[TRUE]");
	string yes = "true";
	insert(yes, BOOLEAN, VARIABLE, to_string(-1), YES, 1);
	emit(label2, "", "", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}
void Compiler::emitGreaterThanOrEqualToCode(string operand1, string operand2)
{
	#ifdef DEBUGGINGEMIT
		cout << "Debugging: We're in emitGreaterThanOrEqualToCode() with operands: " << operand1 << "and" << operand2 << endl;
	#endif 
	
	SymbolTableEntry symbolEntry1 = symbolTable.at(operand1);
	SymbolTableEntry symbolEntry2 = symbolTable.at(operand2);
	if (symbolEntry1.getDataType() != symbolEntry2.getDataType())
		processError("ROD");
	if (isTemporary(contentsOfAReg))
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
		{
			emit("", "mov", contentsOfAReg + ",eax", ""); 
			symbolTable.at(contentsOfAReg).setAlloc(YES);
			contentsOfAReg = "";
		}
	}
	else 
	{
		if (symbolEntry1.getValue() != contentsOfAReg || symbolEntry2.getValue() != contentsOfAReg)
			contentsOfAReg = "";
	}
	if (contentsOfAReg != operand1 && contentsOfAReg != operand2)
		emit("", "mov", "eax," + operand2, "");
	emit("", "cmp", "eax," + operand1, "");
	string label = getLabel();
	emit("", "jge", label, "");
	emit("", "mov", "eax,[FALSE]", "");
	string label2 = getLabel();
	emit("", "jmp", label2, "");
	emit(label, "", "", "");
	emit("", "mov", "eax,[TRUE]");
	string yes = "true";
	insert(yes, BOOLEAN, VARIABLE, to_string(-1), YES, 1);
	emit(label2, "", "", "");
	if (isTemporary(operand1))
		freeTemp();
	if (isTemporary(operand2) && operand1 != operand2)
		freeTemp(); 
	contentsOfAReg = getTemp();
	symbolTable.at(contentsOfAReg).setDataType(INTEGER);
	pushOperand(contentsOfAReg);
	return;
}

void Compiler::pushOperator(string name) //push name onto operatorStk
{
	#ifdef DEBUGSTACK
		cout << "Debugging: We're in pushOperator() with token: " << token << " and string:" << name << endl;
	#endif 
	
	if (isRelOp(name) || isAddOp(name) || isMultOp(name) || name == ":=")
		operatorStk.push(name);
	else
		processError("CEC");
	return;
}

void Compiler::pushOperand(string name) //push name onto operandStk
//if name is a literal, also create a symbol table entry for it
{
	#ifdef DEBUGSTACK
		cout << "Debugging: We're in pushOperand() with token: " << token << " and string: " << name << endl;
	#endif 

	if (isLiteral(name))
	{
		//storeTypes stor = whichType(name);
		//modes mode = VARIABLE;
		//allocation alloc = YES;
		string intName = genInternalName(whichType(name));
		insert(intName, whichType(name), VARIABLE, name, YES, 1);
		operandStk.push(intName);		
	}
	else
		processError("EUN");
	return;
}

string Compiler::popOperator() //pop name from operatorStk
{
	#ifdef DEBUGSTACK
		cout << "Debugging: We're in popOperator() with token: " << token << endl;
	#endif 
	cout << operatorStk.size();
	if (!operatorStk.empty())
	{
		string operatorR = operatorStk.top();
		operatorStk.pop();
		return(operatorR);
	}
	else
		processError("CEO");
	return("How did this even happen");
}

string Compiler::popOperand() //pop name from operandStk
{
	#ifdef DEBUGSTACK
		cout << "Debugging: We're in popOperand() with token: " << token << endl;
	#endif 
	cout << operandStk.size();
	if (!operandStk.empty())
	{ 	
		string operand = operandStk.top();
		operandStk.pop();
		return(operand);
	}
	else
		processError("CEO");
	return("How did this even happen");
}

void Compiler::code(string op, string operand1, string operand2)
{
	#ifdef DEBUGSTACK
		cout << "Debugging: We're in code() with token: " << token << " op: " << op << " operand1: " << operand1 << " and operand2: " << operand2 << endl;
	#endif 
	
	if (op == "program")
		emitPrologue(operand1);
	else if (op == "end")
		emitEpilogue();
	else if (op == "read")
		emitReadCode(operand1);
	else if (op == "write")
		emitWriteCode(operand1);
	else if (op == "+") // this must be binary '+'
		emitAdditionCode(operand1, operand2);
	else if (op == "-") // this must be binary '-'
		emitSubtractionCode(operand1, operand2);
	else if (op == "neg") // this must be unary '-'
		emitNegationCode(operand1);
	else if (op == "not")
		emitNotCode(operand1);
	else if (op == "*")
		emitMultiplicationCode(operand1, operand2);
	else if (op == "div")
		emitDivisionCode(operand1, operand2);
	else if (op == "mod")
		emitModuloCode(operand1, operand2);
	else if (op == "and")
		emitAndCode(operand1, operand2);
	else if (op == "or")
		emitOrCode(operand1, operand2);
	else if (op == "=")
		emitEqualityCode(operand1, operand2);
	else if (op == ":=")
		emitAssignCode(operand1, operand2);
	else if (op == "<>")
		emitInequalityCode(operand1, operand2);
	else if (op == "<=")
		emitLessThanOrEqualToCode(operand1, operand2);
	else if (op == ">=")
		emitGreaterThanOrEqualToCode(operand1, operand2);
	else if (op == ">")
		emitGreaterThanCode(operand1, operand2);
	else if (op == "<")
		emitLessThanCode(operand1, operand2);
	else
		processError("CEC");
}

void Compiler::freeTemp() 
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in freeTemp() with token: " << token  << " and currentTempNo: " << currentTempNo << endl;
	#endif 
	
    if (currentTempNo >= 0) 
	{ 
        string tempName = "T" + to_string(currentTempNo); 
        symbolTable.erase(tempName); // Use erase() to remove from the map
        currentTempNo--; 
    } 
	else
        processError("CEC"); 
	return;
}
string Compiler::getTemp()
{
	string temp;
    currentTempNo++; 
	
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in getTemp() with token: " << token  << " and currentTempNo: " << currentTempNo << endl;
	#endif 
	
    temp = "T" + to_string(currentTempNo); 

    if (currentTempNo > maxTempNo) 
	{
        insert(temp, UNKNOWN, VARIABLE, "", NO, 1); 
        maxTempNo = currentTempNo; 
    }
    return (temp);
}
bool isMultOp (string s)
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isMultOp() with string: " << s << endl;
	#endif 
	
	bool status = false;
	if (s == "*" || s == "div" || s == "mod" || s == "and")
		status = true;
	return(status);
}
bool isAddOp (string s)
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isMultOp() with string: " << s << endl;
	#endif 
	
	bool status = false;
	if (s == "+" || s == "-" || s == "or")
		status = true;
	return (status);
}
bool isRelOp (string s)
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isMultOp() with string: " << s << endl;
	#endif 
	
	bool status = false;
	if (s == "<" || s == ">" || s == "=" || s == "<=" || s == ">=" || s == "<>")
		status = true;
	return(status);
}
bool Compiler::isTemporary(string s) const
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in isTemporary() with Temporary: " << s << endl;
	#endif 
	
	if (s[0] == 'T')
		return(true);
	else
		return(false);
}
string Compiler::getLabel()
{
	#ifdef DEEPDEBUG
		cout << "Debugging: We're in getLabel() with labelNum: " << labelNum << endl;
	#endif 
	
	labelNum++;
	return("L" + to_string(labelNum));
}