#include "../src/MString.h"
#include "../src/MStringArray.h"
#include <fstream.h>

void main() 
{

	//This file tests *all* MString functions (wip!)

	char myChar[] = "Hello, this is 1234, a string...?";
	char myLet = 'j';

	MString fromChar(myChar);
	MString fromLet(myLet);
	MString fromLetRep(myLet,20);
	MString fromM(fromChar);

	cout << fromChar << endl
		<< fromLet << endl
		<< fromLetRep << endl
		<< fromM << endl;

	//Large file read and memory test.
/*


	MString readLarge;

	for (int f1 = 0; f1 < 1000; f1++) {
		ifstream in;
		in.open("h:\\server\\MString\\largefile.txt");
		while (in) {
		
			in >> readLarge;
		}
		cout << readLarge;
		readLarge.Empty();
		
		cout << "!!!!    " << f1 << endl;
	}

*/
	
	//Loop test for deallocation
	//also Empty()
	MString test;
	for (int i = 0; i < 3000; i++) {
		test = "this is a test";
		test.Empty();
	}

	//GetLength
	cout << "Length of fromChar = " << fromChar.GetLength()
		<< endl;

	//IsEmpty
	cout << "IsEmpty()\n";
	if (fromChar.IsEmpty())
		cout << "!!!! fromChar is EMPTY\n";
	else cout << "fromChar is not EMPTY\n";

	//GetAt
	cout << "GetAt\n";
	for (int k = 0; k < fromChar.GetLength(); k++) {
		cout << fromChar.GetAt(k);
	}
	cout << endl;
	
	//Rvalue operator []

	cout << "Rvalue operator []\n";

	for (int f = 0; f < fromLetRep.GetLength(); f++) {
		fromLetRep[f] = 'w';
	}
	cout << fromLetRep << endl;


	//SetAt

	cout << "SetAt\n";

	for (int g = 0; g < fromLetRep.GetLength(); g++) {
		fromLetRep.SetAt(g, 'j');
	}
	cout << fromLetRep << endl;

	// = 

	cout << " = \n";

	test = fromLetRep;
	cout << test << endl;
	test = 'y';
	cout << test << endl;
	test = "hello and how are you?";
	cout << test << endl;
	test = 675444;
	cout << test << endl;
	test = 323.2341;
	cout << test << endl;

	// + 

	cout << " + \n";

	test = fromLetRep + fromChar;
	cout << test << endl;
	test = fromChar + '>';
	cout << test << endl;
	test = '<' + fromChar;
	cout << test << endl;
	test = fromChar + "CHAR STRING";
	cout << test << endl;
	test = "CHAR STRING" + fromChar;
	cout << test << endl;

	// +=

	cout << " += \n";

	test += fromLetRep;
	cout << test << endl;
	test.Empty();
	test += 'j';
	cout << test << endl;
	test.Empty();
	test += "CHAR STRING????";
	cout << test << endl;
	test += 999999;
	cout << test << endl;
	test.Empty();
	test += 34.2342;
	cout << test << endl;	

	test.Empty();
	test = 34.00000234;
	cout << test << endl;
	test.Empty();
	test = 340.012;
	cout << test << endl;

	MString dub(456.322);
	cout << dub << endl;	
	dub.Replace('2','6');
	cout << dub << endl;
}
