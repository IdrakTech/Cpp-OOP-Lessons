#include <iostream>
using namespace std;

class Person
{
public:
	char *name;
	int age;

	Person()
	{

	}

	Person(const char* name, int age) : age(age)
	{
		
		/*  Function for static char --> (char name[100])
			strcpy_s(this->name, name);
		*/

		//Function for dynamic char
		int length = strlen(name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}

	~Person()
	{
		delete[] name;
	}

	//Copy constructor
	Person(const Person& p)
	{
		this->age = p.age;

		int length = strlen(p.name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, p.name);

		//memcpy(this, &p, sizeof(Person));
	}

	void print()
	{
		cout << name << " - " << age << endl;
	}
};

void main()
{
	Person p1("Gleb", 25);
	Person p2(p1);		//Person p2 = p1;
	Person p3("Silver", 27);
	Person p4(p3);

	//Person p2;
	//memcpy(&p2, &p1, sizeof(Person));

	p1.print();
	p2.print();  
	p3.print();
	p4.print();

	cout << endl;

	p1.name[3] = 'p';
	p3.name[0] = 'H';
		
	p1.print();
	p2.print();
	p3.print();
	p4.print();

	cout << endl;
}