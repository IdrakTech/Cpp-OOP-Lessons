#include <iostream>
using namespace std;

class MyString
{
private:
	char* str;
	int size;

	void copy(const MyString& myString)
	{
		memcpy(this, &myString, sizeof(myString));	// one variant

		//this->size = myString.size;		// the another variant 

		int lenght = myString.size + 1;
		this->str = new char[lenght];
		strcpy_s(this->str, lenght, myString.str);
	}

public:
	MyString() { }		// default constructor
	
	MyString(const char* text)	// overloaded constructor
	{
		int lenght = strlen(text) + 1;
		str = new char[lenght];
		strcpy_s(str, lenght, text);
		size = lenght - 1;
	}

	MyString(const MyString& myString)		// copy constructor
	{
		copy(myString);
	}

	void operator=(const MyString& myString)
	{
		memcpy(this, &myString, sizeof(myString));
		int lenght = myString.size + 1;
		this->str = new char[lenght];
		strcpy_s(this->str, lenght, myString.str);
	}


	~MyString()			// destructor
	{
		if (str != nullptr)
		{
			delete[] str;
		}
	}


	int getSize() const
	{
		return size;
	}

	const char* getStr() const
	{
		return str;
	}


	// use '&' for change a letter on word 
	char& operator[](int index)
	{
		return this->str[index];
	}

	// we can overload also () operator too 
	/* It's an example for explanations
	char& operator()()
	{
		return this->str[0];
	}
	*/
};

ostream& operator<<(ostream& out, const MyString& str)
{
	out << str.getStr();
	return out;
}

void test(MyString str)
{
	cout << str << endl;
}

void main()
{
	// The third example



	// The second example
	//MyString text = "Hello World!";
	//cout << text[0] << endl;
	//text[0] = 'X';
	//cout << text << endl;


	// The first example
	//MyString text = "Hello World!";
	////MyString text2(text);	// MyString text2 = text
	//MyString text2;
	//text2.operator=(text); 	//text2 = text;
	//cout << text2 << endl;
	//test(text);
	//cout << text << endl;
}