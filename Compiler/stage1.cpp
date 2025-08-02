//Louis Jensen and Jacob Tucker 
//CS 4301
//Compiler Stage 0

#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<ios>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cctype>
#include<ctime>
#include<queue>
#include<stack>
#include<typeinfo>
#include<iterator>

using namespace std; 
const int MAX_SYMBOL_TABLE_SIZE = 256;
enum storeType {INTEGER, BOOLEAN, PROG_NAME, UNKNOWN};
enum allocation {YES,NO};
enum modes {VARIABLE, CONSTANT};

void CreateListingHeader();
void Parser();
void CreateListingTrailer();
void PrintSymbolTable();
void Prog();
void ProgStmt();
void Consts();
void Vars();
void BeginEndStmt();
void ConstStmts();
void VarStmts();
string Ids();
void Insert(string externalName,storeType inType, modes inMode, string inValue,
	allocation inAlloc, int inUnits);
string NextToken();
char NextChar();
bool nonKeyId(string tken);
void errorHandle (string, int);
void PushOperator(string);
void PushOperand(string);
string PopOperator();
string PopOperand();
void Code(string, string, string);
void EmitAdditionCode(string, string);
void EmitDivisionCode(string, string);
void EmitMultiplicationCode(string, string);
void EmitSubtractionCode(string, string);
void EmitAndCode(string, string);
void EmitOrCode(string, string);
void EmitEqualsCode(string, string);
void EmitAssignCode(string, string);
void FreeTemp();
string GetTemp();
bool relOp(string);
bool addOp(string);
bool multOp(string);
void part();
void factor();
void factors();
void terms();
void expresses();
void term();
void ids();
void express();
storeType WhichType(string);
struct entry //define symbol table entry format
{
	string internalName;
	string externalName;
	storeType dataType;
	modes mode;//lsearch
	string value;
	allocation alloc;
	int units;
}
;
ifstream sourceFile;
vector<entry> symbolTable;
ofstream listingFile,objectFile;
string token = "allotmespacemycompiler";
char charac = ' ';
const char END_OF_FILE = '$'; // arbitrary choice
array<string, 4> errors = {"lexical", "semantic", "syntactic", "Stage 1"}; //For errors processing
int errCnt = 0; //Gloabal counts of errors 
int intCount = 0, boolCount = 0;
vector<string> keyIds = {"program", "begin", "end", "var", "const", "integer", 
		"boolean","true", "false", "not", "mod", "div", "and", "or", "read", "write"}; //List of all intital keywords
bool recur = false;
int lineNum = 1;
bool endTokenFound = false;
string conToken = "";
queue<string> varToken = {};
string interName = "";
stack<string> operatorStk;
stack<string> operandStk;
string REGA;
string REGQ;
int currentTempNo = -1;
int maxTempNo = 1;

//Hopefully done
int main(int argc, char **argv)
{
	//this program is the stage0 compiler for Pascallite. It will accept
	//input from argv[1], generating a listing to argv[2], and object code to
	//argv[3]
	/*if (argc < 3)
	{
		cerr << "usage: " << argv[0] << " SOURCE LISTING OBJECT\n";
		return 1;
	}*/

	sourceFile.open(argv[1], ifstream::in);
	
	listingFile.open(argv[2],ofstream::out);

	objectFile.open(argv[3], ofstream::out);
	
	CreateListingHeader();
	Parser();
	CreateListingTrailer();
	
	PrintSymbolTable();
	
	listingFile.close();
	objectFile.close();
	sourceFile.close();
	
 return 0;
}
//Should be Done
void CreateListingHeader()
{
	string names = "Louis Jensen and Jacob Tucker";
	time_t timeOfDay = time (NULL);
	//Prints stage, name(s), and the time/date to listing file
	listingFile << left << setw(7) << "STAGE0:" << setw(2) << "  " << right << setw(21) << names
				<< "  " << left << setw(1) << ctime(&timeOfDay) << endl;
	//Prints Line No. and SOURCE STATEMENT header line to listing file
	listingFile << left << setw(8) << "LINE NO." << right << setw(30)
				<< "SOURCE STATEMENT" << endl << endl << right << setw(5) << lineNum << '|';
	//line numbers and source statements should be aligned under the headings
	lineNum++; // lineNum serves to keep track of how many lines of code have been read.
}

//Should be Done
void Parser()
{
	NextChar();
	//charac must be initialized to the first character of the source fill
	
	if(NextToken() != "program")
	{
		errorHandle(errors[2], 16); //process error: keyword "program" expected;
	}
	//a call to NextToken() has two effects
	// (1) the variable, token, is assigned the value of the next token
	// (2) the next token is read from the source file in order to make
	// the assignment. The value returned by NextToken() is also
	// the next token.
	Prog();
	//parser implements the grammar rules, calling first rule
}

void CreateListingTrailer()
{
	listingFile << endl;
	listingFile << left << setw(22) << "COMPILATION TERMINATED" << "      " << left << setw(1) << errCnt
				<< " ERRORS ENCOUNTERED" << endl;
}

//Should be done 
void PrintSymbolTable()
{
	string names = "Louis Jensen and Jacob Tucker";
	string datType = "";
	time_t timeOfDay = time (NULL);
	
	objectFile << left << setw(7) << "STAGE0:" << setw(2) << "  " << right << setw(21) << names
				<< "  " << right << setw(1) << ctime(&timeOfDay) << endl;
	
	//Symbol Table output header text
	objectFile << "Symbol Table" << endl << endl;
	
	for (unsigned int i = 0; i < symbolTable.size(); i++)
	{
		entry x = symbolTable[i];
		objectFile << left << setw(15) << x.externalName << "  " << left << setw(4) << x.internalName << "  "; 
		switch (x.dataType)
		{
			case 0: datType = "INTEGER";
			break;
			case 1: datType = "BOOLEAN";
			break;
			case 2: datType = "PROG_NAME";
		}
		objectFile << right << setw(9) << datType << "  ";
		datType = "";
		switch (x.mode)
		{
			case 0: datType = "VARIABLE";
			break;
			case 1: datType = "CONSTANT";
		}
		objectFile << setw(8) << datType << "  " << setw(15) << x.value << "  ";
		datType = "";
		switch (x.alloc)
		{
			case 0: datType = "YES";
			break;
			case 1: datType = "NO";
		}
		objectFile << setw(3) << datType << setw(2) << "  " << x.units << endl;
		datType = "";
	}
}

//Should be done
void Prog() //token should be "program"
{
	if (token != "program")
	{
		errorHandle(errors[2], 16); //process error: keyword "program" expected
	}
	
	ProgStmt();
	if (token == "const") 
		Consts();
	
	if (token == "var") 
		Vars();
	
	if (token != "begin")
		errorHandle(errors[2], 11); //process error: keyword "begin" expected
	
	BeginEndStmt();
	if (NextChar() != END_OF_FILE)
		errorHandle(errors[2], 18); //process error: no text may follow "end"
	
}

//Should be Done
void ProgStmt() //token should be "program"
{
	string x = "";
	NextToken();
	x =token;
	
	if (nonKeyId(x))
		errorHandle(errors[2], 17); //process error: program name expected

	if (NextToken() != ";")
		errorHandle(errors[2], 3); //process error: semicolon expected
	 
	NextToken();
	Insert(x,PROG_NAME,CONSTANT,x,NO,0);
}

//Should be Done 
void Consts() //token should be "const"
{
	if (token != "const")
		errorHandle(errors[2], 15); //process error: keyword "const" expected
	NextToken();
	//if (nonKeyId(NextToken()))
		//errorHandle(errors[1], 5); //process error: non-keyword identifier must follow "const"
	
	ConstStmts();
}

//Should be done 
void Vars() //token should be "var"
{
	if (token != "var")
		errorHandle(errors[2], 14); //process error: keyword "var" expected
	NextToken();
	if (nonKeyId(token))
		errorHandle(errors[1], 4); //process error: non-keyword identifier must follow "var"

	VarStmts();
}

//Should be Done 
void BeginEndStmt() //token should be "begin"
{
	if (token != "begin")
		errorHandle(errors[2], 11); //process error: keyword "begin" expected
	NextToken();
	while (token != "end")
	{
		//AssignStmts 
		if (nonKeyId(token))
		{
			PushOperand(token);
			NextToken();
			if (token == ":=")
			{
				PushOperator(":=");
				express();
				if (token != ";")
				{
					errorHandle(errors[2], 9);
				}
				else 
				{
					NextToken();
					Code(PopOperator, PopOperand, PopOperand);
				}
			}
		}
		//ReadStmts
		if (token == "read")
		{
			if (token == "(")
			{
				ids();
				Code("read", token, "");
			}
			if (token != ")")
				errorHandle(errors[2], 19);
		}
		//WriteStmts
		if (token == "write")
		{
			if (token == "(")
			{
				ids();
				Code("write", token, "");
			}
			else 
				if (!nonKeyId(token))
					errorHandle(errors[1], 1);
			if (token != ")")
				errorHandle(errors[2], 19);
		}
	}
	if (NextToken() != ".")
			errorHandle(errors[2], 13); //process error: period expected	
}

//Should be done 
void ConstStmts() //token should be NON_KEY_ID
{
	string x = "",y = "";
	conToken = token; // Sets up a global token for const nonKeyId
	string symbolVal = "";
	bool isSigned = false;
	if (!recur)
	{
		if (nonKeyId(token)) //Make sure its not a key ID 
		{
			errorHandle(errors[1], 1); //process error: non-keyword identifier expected
		}
	}
	NextToken();
	if (token != "=") // after declaration must be an =
	{
		errorHandle(errors[2], 5); //process error: "=" expected
	}
	NextToken();
	//The first equal can only be followed by these values or its an errors
	if (token != "+" && token != "-" && token != "not" && nonKeyId(token) && token != "true" && token != "false" && token != "INTEGER" && !isdigit(token.front()) && token != " ")
	{
		errorHandle(errors[2], 6); //process errors: token to right of "=" illegal
	}
	
	if (token == "+" || token == "-") // +- indicate the next value should be an integer
	{
		string tknVal = token;
		isSigned = true;
		if(!isdigit(NextToken().front()))
		{
			errorHandle(errors[2], 7); //process error: integer expected after sign
		}
		else
		{
			tknVal = tknVal.append(token);
			Insert(conToken, INTEGER, CONSTANT, tknVal, YES, 1);
		}
	}
	if (token == "not") //not indicates the next value should be a boolean 
	{
		NextToken();
		if(token != "true" && token != "false")
		{
			errorHandle(errors[2], 8); //process errors: boolean expected after not
		}
		if(token == "true")
		{
			Insert(conToken, BOOLEAN, CONSTANT, "0", YES, 1);
		}
		else
		{
			Insert(conToken, BOOLEAN, CONSTANT, "1", YES, 1);
		}
	}
	else
	{
		if (token == "true") //booleans without "not" token
		{
			Insert(conToken, BOOLEAN, CONSTANT, "1", YES, 1);
		}
		else if (token == "false")
		{
			Insert(conToken, BOOLEAN, CONSTANT, "0", YES, 1);
		}
		else if (isSigned == false && isdigit(token.front()))
		{
			Insert(conToken, INTEGER, CONSTANT, token, YES, 1);
		}
		else if (isSigned == false)
		{
			symbolVal = token;
			for (unsigned int i = 0; i < symbolTable.size(); i++)
			{
				entry symbolCheck = symbolTable[i];
				if (token == symbolCheck.externalName)
				{
					symbolVal = symbolCheck.value;
				}
			}
			Insert(conToken, INTEGER, CONSTANT, symbolVal, YES, 1);
		}
	}
	NextToken();
	if (token != ";")
	{
		errorHandle(errors[2], 9); //process error: semicolon expected
	}
	NextToken();
	if (token != "begin" && token != "var" && (nonKeyId(token)))
	{
		errorHandle(errors[2], 10); //process error: non-keyword identifier,"begin", or "var" expected
	}
	if (token == "var" || token == "begin")
	{
		goto VarEnd;
	}
	if (!nonKeyId(token))
	{
		recur = true;
		ConstStmts();
	}
	VarEnd:;
}

//Should be done 
void VarStmts() //token should be NON_KEY_ID
{
	unsigned int x = 0;
	varToken.emplace(token);
	if (nonKeyId(token)) //Check if its a key Id
		errorHandle(errors[1], 1); //process error: non-keyword identifier expected
	NextToken();
	if (token != ":")
	{
		if (token != ",")
			errorHandle(errors[2], 1); //process error: ":" expected
		else if (token == ",")
		{
			NextToken();
			VarStmts();
		}
	}
	else if (token == ":")
	{
		NextToken(); // int or bool
		if ((token == "integer") || (token == "boolean"))
		{
			if (token == "integer")
			{
				while (x < varToken.size())
				{
					Insert(varToken.front(), INTEGER, VARIABLE, "", YES, 1);
					varToken.pop();
				}
			}
			else if (token == "boolean")
			{
				while (x < varToken.size())
				{
					Insert(varToken.front(), BOOLEAN, VARIABLE, "", YES, 1);
					varToken.pop();
				}
			}
			NextToken();
			if (token == ";")
			{
				NextToken();
				if (token == "begin")
					goto weDone;
				else
					VarStmts();
			}
			else 
				errorHandle(errors[2], 3); //process error: semicolon expected
		}
		else
		{
			errorHandle(errors[2], 2); //process error: illegal type follows ":"
		}
	}
	if (token != "begin" && nonKeyId(token))
		errorHandle(errors[2], 4); //process error: non-keyword identifier or "begin" expected
weDone:;
}

//Should be Done 
string Ids() //token should be NON_KEY_ID
{
	string temp = "",tempString = "";
	if (!nonKeyId(token)) //If it is a key ID 
		errorHandle(errors[1], 1); //process error: non-keyword identifier expected

	tempString = token;
	temp = token;
	if(NextToken() == ",")
	{
		if (!nonKeyId(token)) //If it is a key ID 
		{
			errorHandle(errors[1], 1); //process error: non-keyword identifier expected
			tempString = temp + "," + Ids();
		}
	}
	return tempString;
}

void Insert(string externalName,storeType inType, modes inMode, string inValue,
 allocation inAlloc, int inUnits)
 //create symbol table entry for each identifier in list of external names
 //Multiply inserted names are illegal
{
	storeType inte = INTEGER;
	storeType boole = BOOLEAN;
	storeType prog = PROG_NAME;
	string name = externalName;
	string passName = "";
	//probably need a while loop to split a actually defined name so that it is only single words 
	while (name != "") //pull from other code name broken from list of external names and put into name
	{
		vector<entry> x = symbolTable;
		while (x.size() != 0)
		{
			entry y = x.back();
			if (y.externalName == name) //may need to either attach boolean to symbolTable or rewrite if fuction
				errorHandle(errors[1], 2); //process errors: multiple name definition
			x.pop_back();
		}
		if (nonKeyId(name)) //keyword needs to be defined
		{
			errorHandle(errors[1], 3); //process error: illegal use of keyword
			name = "";
		}
		else //create table entry
		{
			if (isupper(name[0])) 
			{
				entry alpha;
				alpha.externalName = name;
				alpha.internalName = name;
				alpha.dataType = inType;
				alpha.mode = inMode;
				alpha.value = inValue;
				alpha.alloc = inAlloc;
				alpha.units = inUnits;
				symbolTable.emplace_back(alpha);
				objectFile << "made it";
				interName = "";
				name = "";
			}
			else
			{
				if (inType == inte)
				{
					interName = "I";
					passName = to_string(static_cast<char>(intCount));
					interName = interName + passName;
					entry alpha;
					alpha.externalName = externalName;
					alpha.internalName = interName;
					alpha.dataType = inType;
					alpha.mode = inMode;
					alpha.value = inValue;
					alpha.alloc = inAlloc;
					cerr << externalName << " " << inAlloc << endl;
					alpha.units = inUnits;
					symbolTable.emplace_back(alpha);
					intCount++;
					interName = "";
					passName = "";
					name = "";
				}
				else if (inType == boole)
				{
					interName = "B";
					passName = to_string(static_cast<char>(boolCount));
					interName = interName + passName;
					entry alpha;
					alpha.externalName = externalName;
					alpha.internalName = interName;
					alpha.dataType = inType;
					alpha.mode = inMode;
					alpha.value = inValue;
					alpha.alloc = inAlloc;
					cerr << externalName << " " << inAlloc << endl;
					alpha.units = inUnits;
					symbolTable.emplace_back(alpha);
					boolCount++;
					interName = "";
					passName = "";
					name = "";
				}
				else if (inType == prog)
				{
					interName = "P0";
					entry alpha;
					alpha.externalName = externalName;
					alpha.internalName = interName;
					alpha.dataType = inType;
					alpha.mode = inMode;
					alpha.value = inValue;
					alpha.alloc = inAlloc;
					cerr << externalName << " " << inAlloc << endl;
					alpha.units = inUnits;
					symbolTable.emplace_back(alpha);
					interName = "";
					name = "";
				}
			}
		}
	}
	name = "";
}

//Should be Done 
string NextToken() //returns the next token or end of file marker
{
	token = "";
	while (token == "")
	{
		if (charac == '{')
		{
			while (charac != '}') // As long as the file hasnt ended
			{
				//listingFile << " " << charac << " ";
				if (charac=='$') //If the end of the file is reached 
					errorHandle(errors[0], 1); //process error: unexpected end of file
				else //Continue on 
					NextChar();
			}
			NextChar();
		}
		else if (charac == '}')
			errorHandle(errors[0], 2); //process error: '}' cannot begin token
			
		else if (isspace(charac))
			while(isspace(charac))
				NextChar(); 
		else if (ispunct(charac))
		{
			if (charac ==  '=')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
			}
			else if (charac ==  '+')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
			}
			
			else if (charac == '-')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
			}
			else if (charac == ':')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
				if (charac == '=')
				{
					token =+ charac;
					NextChar();
				}
			}
			else if (charac == ';')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
			}
			else if (charac == ',')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
			}
			else if (charac == '.')
			{
				token =+ charac; // may need to be =+
				NextChar(); //continue on
			}
			else if (endTokenFound == true && charac == '$')
			{
				return token;
			}
			else if (charac == '*')
			{
				token =+ charac;
				NextChar();
			}
			else if (charac == '(')
			{
				token =+ charac;
				NextChar();
			}
			else if (charac == ')')
			{
				token =+ charac;
				NextChar();
			}
			else if (charac == '<')
			{
				token =+ charac;
				NextChar();
				if (charac == '=')
				{
					token =+ charac;
					NextChar();
				}
				else if (charac == '>')
				{
					token =+ charac;
					NextChar();
				}
			}
			else if (charac == '>')
			{
				token =+ charac;
				NextChar();
				if (charac == '=')
				{
					token=+ charac;
					NextChar();
				}
			}
			else
				errorHandle(errors[0], 4); //process error: illegal symbol
		}
		else if (isalpha(charac))
		{
			while (isalnum(charac) || charac == '_')
			{
				token += charac;
				NextChar();
			}
			if (token.back() == '_')
				errorHandle(errors[0], 3);

		}
		else if (isdigit(charac))
		{
			while (isdigit(charac)) 
			{
				token=+charac;
				NextChar();
			}
		}
		else 
		{
			cerr << charac;
			errorHandle(errors[0], 4); //process error: illegal symbol
		}
	}
	return token;
}

char NextChar() //returns the next character or end of file marker
{
	char charCheck = sourceFile.peek();
	charac = ' ';
	if (sourceFile.eof())
	{
		charac = '$'; //use a special character to designate end of file
	}
	else if (isalnum(charCheck) || isspace(charCheck) || ispunct(charCheck)  || charCheck == '$')
	{
		charac = sourceFile.get();
		if (endTokenFound == true && charac == '\n')
		{
			listingFile << charac;
		}
		else if (charac == '\n')
		{
			listingFile << charac << right << setw(5) << lineNum << '|';
			lineNum++;
		}
		else
		{
			listingFile << charac;
		}
	}
	return (charac);
}

//Should be Done 
bool nonKeyId(string tken) //Checks if a token is a Keyword 
{
	for (unsigned int i = 0; i < keyIds.size(); i++) //Loops through every Keyword checking if token is equal
	{
		if (tken == keyIds[i])
		{
			return false; //If token ever matches return false 
		}
		if (i == (keyIds.size() - 1)) //If everything has been checked add token to keyIds
		{
			keyIds.emplace_back(tken);    //Since variables can't have the same name once
		}
	}
	
	return true; //If it never failed return true, its not a Keyword
}

//Should be Done
void errorHandle (string errTyp, int errNum) //Need to print out the line number the of the error and determine the errors type
{
	listingFile << errTyp << " " << errNum << endl;
	/*Lexical: Errors should only originate from the NextToken() function
	Semantic: Should only come from Insert() function, Illegal keywords, Undefined symbols, and multiple definitions
	Syntactic: Almost any other error is syntax based
	*/
	if (errTyp == "lexical")
	{
		listingFile << "Lexical error: ";
		if (errNum == 1)
		{
			listingFile << "Unexpected end of file\n";
			errCnt++;
		}
		else if (errNum == 2)
		{
			listingFile << "'}' cannot begin a token\n";
			errCnt++;
		}
		else if (errNum == 3)
		{
			listingFile << "'_' cannot end a token\n";
			errCnt++;
		}
		else if (errNum == 4)
		{
			listingFile << "illegal symbol\n";
			errCnt++;
		}
		else 
		{
			listingFile << "Unknown error\n";
			errCnt++;
		}
	}
	else if (errTyp == "semantic")
	{
		listingFile << "Semantic error: ";
		if (errNum == 1)
		{
			listingFile << "non-keyword identifier expected\n";
			errCnt++;
		}
		else if (errNum == 2)
		{
			listingFile << "multiple names defined\n";
			errCnt++;
		}
		else if (errNum == 3)
		{
			listingFile << "illegal use of a keyword\n";
			errCnt++;
		}
		if (errNum == 4)
		{
			listingFile << "non-keyword identifier must follow 'var'\n";
			errCnt++;
		}
		if (errNum == 5)
		{
			listingFile << "non-keyword identifier must follow 'const'\n";
			errCnt++;
		}
		else 
		{
			listingFile << "Unknown error\n";
			errCnt++;
		}
	}
	else if (errTyp == "syntactic")
	{
		listingFile << "Syntactic error: ";
		if (errNum == 1)
		{
			listingFile << "':'expected\n";
			errCnt++;
		}
		else if (errNum == 2)
		{
			listingFile << "illegal type follows ':'\n";
			errCnt++;
		}
		else if (errNum == 3)
		{
			listingFile << "; expected\n";
			errCnt++;
		}
		else if (errNum == 4)
		{
			listingFile << "non-keyword identifier or 'begin' expected\n";
			errCnt++;
		}
		else if (errNum == 5)
		{
			listingFile << "'=' expected\n";
			errCnt++;
		}
		else if (errNum == 6)
		{
			listingFile << "illegal token to right of '='\n";
			errCnt++;
		}
		else if (errNum == 7)
		{
			listingFile << "integer expected after sign\n";
			errCnt++;
		}
		else if (errNum == 8)
		{
			listingFile << "boolean expected after not\n";
			errCnt++;
		}
		else if (errNum == 9)
		{
			listingFile << "';' expected";
			errCnt++;
		}
		else if (errNum == 10)
		{
			listingFile << "non-keyword identifier 'begin' or 'var' expected\n";
			errCnt++;
		}
		else if (errNum == 11)
		{
			listingFile << "keyword 'begin' expected\n";
			errCnt++;
		}
		else if (errNum == 12)
		{
			listingFile << "keyword 'end' expected\n";
			errCnt++;
		}
		else if (errNum == 13)
		{
			listingFile << "'.' expected\n";
			errCnt++;
		}
		else if (errNum == 14)
		{
			listingFile << "keyword 'var' expected\n";
			errCnt++;
		}
		else if (errNum ==15)
		{
			listingFile << "keyword 'const' expected\n";
			errCnt++;
		}
		else if (errNum ==16)
		{
			listingFile << "keyword 'program' expected\n";
			errCnt++;
		}
		else if (errNum ==17)
		{
			listingFile << "program name expected\n";
			errCnt++;
		}
		else if (errNum ==18)
		{
			listingFile << "no text may follow 'end'\n";
			errCnt++;
		}
		else if (errNum ==19)
		{
			listingFile << "')' expected\n";
			errCnt++;
		}
		else 
		{
			listingFile << "Unknown error\n";
			errCnt++;
		}
	}
	else if (errTyp == "Stage 1")
	{
		listingFile << "Stage 1, Replace this: ";
		if (errNum == 1)
		{
			listingFile << "Operator Stack Underflow";
			errCnt++;
		}
		else if (errNum == 2)
		{
			listingFile << "Undefined Operation";
			errCnt++;
		}
		else if (errNum == 3)
		{
			listingFile << "Illegal Type";
			errCnt++;
		}
		else if (errNum = 4)
		{
			listingFile << "Incompatable Type";
			errCnt++;
		}
		else if (errNum = 5)
		{
			listingFile << "symbol on left-hand side of assignment must have a storage mode of VARIABLE";
			errCnt++;
		}
		else if (errNum = 6)
		{
			listingFile << "Current tempNum must be greater than -1\n";
			errCnt++;
		}
		else 
		{
			listingFile << "Unknown error\n";
			errCnt++;
		}
	}
	else
	{
		listingFile << "Unknown error \n";
		errCnt++;
	}
	CreateListingTrailer();
	if (errCnt > 0)
	{
		PrintSymbolTable();
		exit(EXIT_FAILURE);
	}
}

void PushOperator(string name) //push name onto operatorStk
{
	operatorStk.push(name);
}
void PushOperand(string name) //push name onto operandStk
//if name is a literal, also create a symbol table entry for it
{
	//Literal means its a fixed value in source code, stackOverFlow has good answer
	if (is_const<const char*>(name) && nonKeyId(name)) //This may not work Not sure if its a good literal test or not
	{
		storeType type = whichType(name);
		Insert(name, type, CONSTANT, name, YES, 1);
	}
	operandStk.push(name);
	/*insert symbol table entry, call whichType to determine the data type of the literal
	push name onto stack;*/
}
string PopOperator() //pop name from operatorStk
{
	if (operatorStk.size() > 0)
	{
		auto rtrnVal = operatorStk.top();
		operatorStk.pop();
		return rtrnVal;
	}
	else 
		errorHandle(errors[3], 1);//process error: operand stack underflow;
}
string PopOperand() //pop name from operandStk
{
	if (operandStk.size() > 0)
	{
		auto rtrnVal = operandStk.top();
		operandStk.pop();
		return rtrnVal;
	}
	else
		errorHandle(errors[3], 1);//process error: operand stack underflow;
}
void Code(string operators, string operand1 = ””, string operand2 = ””)
{
	switch(operators)
	{
		case "program": objectFile << "STRT " << "NOP          " << "stage1no" << datFileNumber << " - " << names << "\n";
		case "end" :; objectFile << "     HLT" << "\n";
			objectFile <<; //REGQ stack needs to be popped releasing all data 
			objectFile << "     END" << " STRT" << "\n";
			//emit HLT, BSS and DEC pseudo ops, and END
		case "read" :; // read command is RDI emit read code;
		case "write" :; // write command is PRI emit write code
		case "+"   : EmitAdditionCode(operand1, operand2); //this must be binary "+"
		case "-"   : EmitSubtractionCode(operand1, operand2); //this must be binary "-"
		case "neg" : EmitNegativeCode(operand1, operand2); //this must be unary "-"
		case "not" : EmitNotCode (operand1, operand2);
		case "*"   : EmitMultiplicationCode(operand1, operand2);
		case "div" : EmitDivisionCode(operand1, operand2);
		case "mod" : EmitModuloCode(operand1, operand2);
		case "and" : EmitAndCode(operand1, operand2);
		case "or"  :	EmitOrCode (operand1, operand2);
		case "="   : EmitEqualsCode(operand1, operand2);
		case ":="  : EmitAssignCode(operand1, operand2);
		default : errorHandle(errors[3], 2);//process error: undefined operation
	}
}
void EmitModuloCode(string operand1, string operand2)
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "int" || tstTyp2 != "int")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
							symbolTable[j].alloc = YES;
							break;
					}
				}
			}
		}
	}
	if (REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	objectFile << "n spaces" << "IDV" << "25" + XX; //Emit Addition Code
	//QREG holds current remainder, store it in whatever value it needs to be in
	GetTemp();
	symbolTable.back().dataType = INTEGER;
	REGA = symbolTable.back().internalName;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitNotCode(string operand1, string operand2);
{
	if (operand1 == "true")
		objectFile << //Load false into AREG I think 
	else if (operand1 == "false")
		objectFile << //Load true into AREG 
	else
		errorHandle(errors[3], 3);
	
}
void EmitAdditionCode(string operand1,string operand2) //add operand1 to operand2
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "int" || tstTyp2 != "int")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
							symbolTable[j].alloc = YES;
							break;
					}
				}
			}
		}
	}
	if (REGA != operand1 && REGA != operand2)
	{
		REGA = "";
		REGA = operand2; //Move Operand2 into REGA
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	objectFile << "n spaces" << "IAD" << "14" + XX; //Emit Addition Code
	
	
	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	GetTemp();
	REGA = symbolTable.back().internalName;
	symbolTable.back().dataType = INTEGER;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push the name of the result onto operandStk
}
void EmitDivisionCode(string operand1,string operand2) //divide operand2 by operand1
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "int" || tstTyp2 != "int")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
							symbolTable[j].alloc = YES;
							break;
					}
				}
			}
		}
	}
	if (REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	objectFile << "n spaces" << "IDV" << "25" + XX; //Emit Addition Code

	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	GetTemp();
	symbolTable.back().dataType = INTEGER;
	REGA = symbolTable.back().internalName;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitMultiplicationCode(string operand1,string operand2) //multiply operand2 by operand1
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "int" || tstTyp2 != "int")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
							symbolTable[j].alloc = YES;
							break;
					}
				}
			}
		}
	}
	if (REGA != operand1 && REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	objectFile << "n spaces" << "IMU" << "24" + XX; //Emit Addition Code
	
	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	GetTemp();
	symbolTable.back().dataType = INTEGER;
	REGA = symbolTable.back().internalName;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitSubtractionCode(string operand1, string operand2)
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "int" || tstTyp2 != "int")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
							symbolTable[j].alloc = YES;
							break;
					}
				}
			}
		}
	}
	if (REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	objectFile << "n spaces" << "IDV" << "25" + XX; //Emit Addition Code
	
	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	GetTemp();
	symbolTable.back().dataType = INTEGER;
	REGA = symbolTable.back().internalName;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitAndCode(string operand1,string operand2) //"and" operand1 to operand2
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "bool" || tstTyp2 != "bool")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
							symbolTable[j].alloc = YES;
							break;
					}
				}
			}
		}
	}
	if (REGA != operand1 && REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	objectFile << "n spaces" << "IDV" << "25" + XX; //Emit Addition Code
	
	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	GetTemp();
	symbolTable.back().dataType = BOOLEAN;
	REGA = symbolTable.back().internalName;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitOrCode(string operand1,string operand2) //"or" operand1 to operand2
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "bool" || tstTyp2 != "bool")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
						symbolTable[j].alloc = YES;
						break;
					}
				}
			}
		}
	}
	if (REGA != operand1 && REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	//emit code to perform a register-memory addition with A Register holding the result
	EmitAdditionCode(operand1, operand2);
	//emit code to perform an AZJ to the next available Ln +1
	objectFile << "n spaces" << "AZJ" << "36" + XX;
	//emit code to label the next instruction with that label and do a register-memory load TRUE
	objectFile << label;
	//insert TRUE in symbol table with value 1 and external name true
	Insert("TRUE", BOOLEAN, VARIABLE, "", YES, 1);
	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	GetTemp();
	symbolTable.back().dataType = BOOLEAN;
	REGA = symbolTable.back().internalName;
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitEqualsCode(string operand1,string operand2) //test whether operand2 equals operand1
{
	string tstTyp1 = typeid(operand1).name();
	string tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != "bool" || tstTyp2 != "bool")
		errorHandle(errors[3], 3);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (REGA == symbolTable[i].value)
		{
			if (REGA != operand1 && REGA != operand2)
			{
				GetTemp(); //Get temporary for storing
				symbolTable.back().value = REGA; //Deassign REGA by adding to temp
				REGA = ""; //Clear REGA 
				objectFile << "n spaces" << "STA" << "20" + XX; //Store temp into memory as T#
				for (int j = 0; j < symbolTable.size(); j++)
				{
					if (symbolTable[j].value = symbolTable.back().value)
					{
						symbolTable[j].alloc = YES;
						break;
					}
				}
			}
		}
	}
	if (REGA != operand1 && REGA != operand2)
	{
		REGA = "";
		REGA = operand2;
		objectFile << "n spaces" << "LDA" << "12" + XX; //Load operand2 into REGA
	}
	EmitSubtractionCode(operand1, operand2);
	//emit code to perform an AZJ to the next available Ln
	objectFile << "n spaces" << "AZJ" << "36" + XX;
	//emit code to do a register-memory load FALS
	objectFile << "n spaces" << "LDA" << "12" + XX;
	//insert FALS in symbol table with value 0 and external name false
	Insert("FALS", BOOLEAN, VARIABLE, "", YES, 0);
	//emit code to perform a UNJ to the acquired label Ln +1
	objectFile << "n spaces" << "UNJ" << "75" + XX;
	//emit code to label the next instruction with the acquired label Ln
			//and do a register-memory load TRUE
	Insert("true", INTEGER, VARIABLE, "1", NO, 1);
	//insert TRUE in symbol table with value 1 and external name true
	//deassign all temporaries involved and free those names for reuse;
	/* for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].internalName.front() == "T")
		{
			symbolTable.erase(i);
			FreeTemp();
		}
	} */
	string temp = GetTemp();
	symbolTable.back().dataType = BOOLEAN;
	REGA = symbolTable.back().internalName;
	Code("=", temp, " ");//Set REGA to next temp
	//A Register = next available temporary name and change type of its symbol table entry to integer
	PushOperator(REGA);
	//push name of result onto operandStk;
}
void EmitAssignCode(string operand1,string operand2) //assign the value of operand1 to operand2
{
	auto tstTyp1 = typeid(operand1).name();
	auto tstTyp2 = typeid(operand2).name();
	
	if (tstTyp1 != tstTyp2)
		errorHandle(errors[3], 4);
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].value == operand1 && symbolTable[i].mode == CONSTANT)
			errorHandle(errors[3], 5);//process error: symbol on left-hand side of assignment must have a storage mode of VARIABLE
	}
	if (operand1 == operand2) 
		return;
	if (operand1 != REGA)
		Code(":=", operand1, " ");//A Register = operand 1
	//emit code to store the contents of that register into the memory location pointed to by
	//operand2
	//deassign operand1;
	const char t = 'T';
	const char& T = t;
	int j = 0;
	/* for (j; j < symbolTable.size(); j++);
	{
		for (auto i = symbolTable.begin(); i != symbolTable.end(); i++)
		{
			if (test.internalName == symbolTable[j].internalName)
			{
				if (symbolTable[j].internalName == operand1)
				{
					symbolTable.erase(i);
					FreeTemp();
				}
			}
		}
	} */
}
void FreeTemp()
{
	currentTempNo--;
	if (currentTempNo < -1)
		errorHandle(errors[3], 6);
}
string GetTemp()
{
	string temp;
	currentTempNo++;
	temp = "T" + currentTempNo;
	if (currentTempNo > maxTempNo)
	{
		Insert(temp, UNKNOWN, VARIABLE, "", NO, 1);
		maxTempNo++;
	}
	return temp;
}
bool relOp(string tkn)
{
	array<string, 6> relOps = {"=", "<", ">", "<=", ">=", "<>"} ;
	for (int i = 0; i < 6; i++)
	{
		if (relOps[i] == tkn)
			return true;
	}
	return false;
}
bool addOp(string tkn)
{
	array<string, 3> addOps = {"+", "-", "or"};
	for (int i = 0; i < 3; i++)
	{
		if (addOps[i] == tkn)
			return true;
	}
	return false;
}
bool multOp(string tkn)
{
	array<string, 4> multOps = {"*", "mod", "div", "and"};
	for (int i = 0; i < 4; i++)
	{
		if (multOps[i] == tkn)
			return true;
	}
	return false;
}
void part()
{
	//Express->Term->Factor->Part
	if (token == "BOOLEAN")
	{
		NextToken();
		return;
	}
	else if (token == "not")
	{
		NextToken();
		if (token == "BOOLEAN")
		{
			if (token == "true" || token == "false")
			{
				PushOperand("not");
				PushOperand(token);
				NextToken();
				return;
			}
			else 
				errorHandle(errors[3], 3);
		}
		if (token == "(")
		{
			NextToken();
			while (token != ")")
			{
				if (token == "$")
					errorHandle(errors[0], 1);
				express();
				NextToken();
			}
			Code("not", PopOperand(), " ");
			return;
		}
		if (nonKeyId(token))
		{
			Code("not", token, " ");
			NextToken();
			return;
		}
	}
	else if (token == "+")
	{
		if (token == "(")
		{
			NextToken();
			while (token != ")")
			{
				if (token == "$")
					errorHandle(errors[0], 1);
				express();
				NextToken();
			}
			return;
		}
		else if (token == "INTEGER" || nonKeyId(token))
		{
			PushOperand(token);
			NextToken();
			return;
		}
	}
	else if (token == "-")
	{
		if (token == "(")
		{
			NextToken();
			while (token != ")")
			{
				if (token == "$")
					errorHandle(errors[0], 1);
				express();
				NextToken();
			}
			Code("neg", PopOperand(), " ");
			return;
		}
		else if (token == "INTEGER")
		{
			PushOperand("-");
			PushOperand("+");
			PushOperand(token);
			NextToken();
		}
		else if (nonKeyId(token))
			Code("neg", token, " ");
	}
	else if (token == "INTEGER" || nonKeyId(token) || token == "BOOLEAN")
	{
		PushOperand(token);
		NextToken();
		return;
	}
	if (token == "(")
	{
		NextToken();
		while (token != ")")
		{
			if (token == "$")
				errorHandle(errors[0], 1);
			express();
			NextToken();
		}
		Code("neg", PopOperand(), " ");
		return;
	}
	
}
void factor()
{
	part();
	factors();
}
void factors()
{
	if (multOp(token))
	{
		PushOperator(token);
		NextToken();
		part();
		Code(PopOperator(), PopOperand(), PopOperand());
		factors();
	}
}
void terms()
{
	if (addOp(token))
	{
		PushOperator(token);
		NextToken();
		factor();
		Code(PopOperator(), PopOperand(), PopOperand());
		terms();
	}
}
void expresses()
{
	if (relOp(token))
	{
		NextToken();
		PushOperator(token);
		term();
		Code(PopOperator(), PopOperand(), PopOperand());
		expresses();
	}
}
void term()
{
	factor();
	terms();
}
void ids()
{
	if (nonKeyId(token))
	{
		NextToken();
		if (token == ",")
		{
			NextToken();
			ids();
		}
	}
	else 
		errorHandle(errors[1], 3);
}
void express()
{
	term();
	expresses();
}
storeType WhichType(string name)
{
	if (std::is_const<name>::value)
	{
		if (name == "true" || name == "false")
			return BOOLEAN;
		else 
			return INTEGER;
	}
	else 
	{
		for (int i = 0; i < symbolTable.size(); i++)
		{
			if (symbolTable[i].internalName == name || symbolTable[i].externalName == name)
				return symbolTable[i].dataType;
		}
	}
}	