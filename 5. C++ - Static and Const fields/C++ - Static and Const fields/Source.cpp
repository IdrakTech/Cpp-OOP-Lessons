#include <iostream>
using namespace std;

class Person
{
	char name[100];
	int age;
	static int count;


public:
	const int id;

	Person() : id(++Person::count)
	{
	
	}

	//~Person()
	//{
	//	count--;
	//}

	char* getName()
	{
		return name;
	}

	int getAge()
	{
		return age;
	}

	static int getCount()
	{
		return Person::count;
	}

	void setName(const char* name)
	{
		strcpy_s(this->name, name);
	}

	void setAge(int age)
	{
		this->age = age;
	}

	static void setCount(int count )
	{
		if (count > 0)
		{
			Person::count = count;
		}
	}

	void ShowInfo()
	{
		cout << "Count: " << count << endl;
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};



//void test()
//{
//	static int i = 0;
//	i++;
//	cout << i << endl;
//}
//
//void test1()
//{
//	static int i = 0;
//	i++;
//	cout << i << endl;
//}

int Person::count = 0;

void main()
{
	Person p1;
	cout << " *Haidren ID is\t" << p1.id << endl;

	Person p2;
	cout << " *Silver ID is\t" << p2.id << endl;




	//Person p1;
	//if (true)
	//{
	//	Person p2;
	//	Person p3;
	//	//p3.ShowInfo();
	//}
	////cout << p1.getCount() << endl;
	//Person::setCount(Person::getCount() + 1);
	//cout << Person::getCount() << endl;



	//p1.count = 1;
	//cout << p3.count << endl;
	//p2.count = 5;
	//cout << p1.count << endl;

	//cout << "\n";

	//Person::count = 4;
	//cout << Person::count << endl;
	//Person::count = 14;
	//cout << Person::count << endl;

	/* test function */

	//test();
	//test1();
	//test();
	//test1();
	//test();
	//test1();

}