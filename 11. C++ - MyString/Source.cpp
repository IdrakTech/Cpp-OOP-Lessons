#include <iostream>
using namespace std;

class MyString
{
private:
	char* str;
	int size;

public:
	MyString();		// default constructor
	MyString(const char* text);	// overloaded constructor
	MyString(const MyString& myString);		// copy constructor
	~MyString();	// destructor

	//void concat(const char* text);
	//void replace(const char* text);

	void concat(MyString str);	// strcat	// "Hello".concat("World") => "HelloWorld"
	void replace(MyString str); // strcpy	// "Hello".concat("World") => "World"
	void isEqual(MyString str);		// strcmp	// 
	void input();	// input string 

	int getSize() const
	{
		return size;
	}

	const char* getStr() const
	{
		return str;
	}
};




void main()
{
	MyString text1("Hello");
	MyString text2("World");
	text1.concat(text2);
	text1.concat("!!!");
	cout << text1.getStr() << endl;		// HelloWorld!!!

	if(text1.isEqual(text2))
	{
		cout << "Not equal!";
	}

	text2.replace("My name is Dlbayob");
	cout << text2.getStr() << endl;		// My name is Dlbayob
}