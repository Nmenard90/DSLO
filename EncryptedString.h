//decalration file for data members
#ifndef EncryptedString_H
#define EncryptedString_H

#include <string>

using namespace std;


class EncryptedString
{
	
	public:
		
		EncryptedString();
		EncryptedString(string aString);
		void set(string s);
		string get() const;
		string getEncrypted() const;
		
	private:
		
		string myString;
};
#endif

