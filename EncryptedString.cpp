//definitions file for data methods/behaviors
#include "EncryptedString.h"

#include <cctype>

using namespace std;

EncryptedString::EncryptedString():myString(string())//default (no argument) constructor/stores an empty string in the data field
{
}

EncryptedString::EncryptedString(string aString)//constructor takes a string as a parameter and stores the parameter in encrypted format
{
	set(aString);//calls mutator to store the string 
}

//Method set - encrypt the string and store the object 
void EncryptedString::set(string aString)//stores parameter in encrypted format
{
	myString = "";
	//encrypt each character and add myString
	for (size_t i=0;i<aString.length();i++)//compare unsigned types for sizes to avoid compiler warnings
	{
		char ch = aString[i];
		
		if(ch == 'Z')
		{
			ch = 'A';
			myString += ch;
		}
		else if (ch == 'z')
		{
			ch = 'a';
			myString += ch;
	
		}
		else if (isalpha(ch))
		{
			ch++;
			myString += ch;
		}
		else if (ch == ' ')
		{
			myString += ch;
		}
//		else remove the character
//		{
//			*Unsure of syntax for implementation 
//			iterator erase (const_iterator p);
//			-Erases the character pointed by p.
//
//			iterator p = ch;
//			myString.erase(iterator position/const_iterator p);	
//		}
		
	}
	
}

//Method get - decrypt the string before returning
string EncryptedString::get() const
{
	string resultString = "";
	//encrypt each character and add myString
	for(size_t i=0; i<myString.length(); i++)//compare unsigned types for sizes  to avoid compiler warnings
	{
		char ch = myString[i];
		
		if(ch== 'A')
		{
			ch = 'Z';
			resultString += ch;
		}
		else if (ch == 'a')
		{
			ch = 'z';
			resultString += ch;
		}
		else if(isalpha(ch))
		{
			ch--;
			resultString += ch;
		}
		else if(ch == ' ')
		{
			resultString += ch;
		}
	}
	return resultString;
}

//Method getEncrypted - return a copy of the encrypted string
string EncryptedString::getEncrypted() const
{
	return myString;
}
