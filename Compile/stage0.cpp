//Louis Jensen
//CS 4301
//Stage 0 Compiler

//Includes
#include<ctime>
#include<iomanip>
#include<stage0.h> 
#include<array>

//Debugging On/Off
//#define DEBUGGING //Debugging of most functions
//#define DEEPDEBUG //Debugging of the functions called many times that flood the output
//#define DEBUGGINGEMIT //Debugging of emit and other printing functions
//#define DEEPDEBUGRETURNS //Debugging of return values of functions that spam
//#define DEBUGTOK
//#define DEBUGCHA

//Functions I defined
int iCount = 0;
int bCount = 0;
bool ended = false;

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
	
	listingFile << "STAGE0:" << setw(2) << " "  << "LOUIS JENSEN " << setw(6) << " " << ctime(&now) << endl;
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
	
	else if (err == "IBR") // non-keyword identifier, "begin", or "var" expected
				listingFile << "non-keyword identifier, \"begin\", or \"var\" expected"<< endl;
	else if (err == "NKI") // non-keyword identifier expected
				listingFile << "non-keyword identifier expected"<< endl;			
	else if (err == "NKB") // non-keyword identifier or "begin" expected
				listingFile << "non-keyword identifier or \"begin\" expected"<< endl;
	else if (err == "COE") // ":" expected
				listingFile << "\":\" expected"<< endl;
	
	//Semantic Errors
	else if (err == "MND") // Multiple Name Definitions
				listingFile << "Symbol is defined multiple times"<< endl;
	else if (err == "IUK") // Illegal use of Keyword
				listingFile << "Illegal Use of Keyword"<< endl;
	else if (err == "RUC") // Reference to undefined constant
				listingFile << "Reference to undefined constant"<< endl;
	else if (err == "TRI") // Token to the right of '=' is illegal
				listingFile << "token to right of \"=\" illegal"<< endl;
	else if (err == "IES") // integer expected after sign
				listingFile << "integer expected after sign"<< endl;
	else if (err == "BEN") // integer expected after sign
				listingFile << "boolean expected after \"not\""<< endl;				
	else if (err == "DTR") // data type of token on the right-hand side must be INTEGER or BOOLEAN
				listingFile << "data type of token on the right-hand side must be INTEGER or BOOLEAN"<< endl;
	else if (err == "IFC") // illegal type follows ":"
				listingFile << "illegal type follows \":\""<< endl;

	//Compiler Errors
	else if (err == "CEC") // Compiler Error Called
				listingFile << "Compiler error since function should not be called with illegal arguemetns"<< endl;

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
	
	if (nextToken() != "end")
		processError("KEE");
	
	if (nextToken() != ".")
		processError("PDE");
	
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
	
	string temp,tempString;
	
	if (!isNonKeyId(token))
		processError("NKI");
	
	tempString = token;
	temp = token;
	
	if (nextToken() == ",")
	{
		if (!isNonKeyId(nextToken()))
			processError("NKI");
		tempString = temp + "," + ids(); //Be careful of "tempString" overwriting itself. 
	}
	return (tempString);
}

void Compiler::insert(string externalName,storeTypes inType, modes inMode, string inValue,
allocation inAlloc, int inUnits)
//create symbol table entry for each identifier in list of external names
//Multiply inserted names are illegal
{
	#ifdef DEBUGGING
		cout << "Debugging: We're in insert() with externalName: " << externalName << endl;
	#endif 
	
	string name = "";
	uint oldLength = 0;
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
		else if (i == (len - 1))
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
					cout << "Name: " << name << endl;
					SymbolTableEntry currEntry = SymbolTableEntry(name, inType, inMode, inValue, inAlloc, inUnits);
					symbolTable.insert(std::make_pair(name, currEntry));
					//symbolTable[name] = currEntry;
				}
				else
				{	
					//cout << inType << endl;
					cout << "Name: " << name << endl;
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
	
	objectFile << left << "; LOUIS JENSEN " << setw(6) << " " << ctime(&now) << left;
	objectFile << "%INCLUDE \"Along32.inc\"" << endl;
	objectFile << "%INCLUDE \"Macros_Along.inc\"" << endl << endl;
	emit("SECTION", ".text");
	
	if(progName.length() > 15)
		tempProgName = progName.erase(15);
	else
		tempProgName = progName;
	
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
			operand = "1";
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
	
	array<string, 10>IDS = {"program", "begin", "end", "var", "const", "integer", "boolean", "true", "false", "not"};
	bool status = false;
	
	for (int i = 0; i < 10; i++)
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
	
	array<char, 7>SpecSym = {'=', ':', ',', ';', '.', '+', '-'};
	bool status = false;
	
	for(int i = 0; i < 7; i++)
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
	
	if (isBoolean(s) || isalnum(s[index]) || s == "+" || s == "-" || s =="not")
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