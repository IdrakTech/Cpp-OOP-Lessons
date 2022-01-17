#include <iostream>

/*
------------------Example For Struct------------------------------------
struct Person // * mi mojem eto provernut uje so struct *
{
public:
	char name[100];
};

void SayHello(Person p)
{
	std::cout << "hello from " << p.name << std::endl;
}
------------------------------------------------------------------------
*/


class Person /*mi mojem eto provernut tolko v sluchae class */
{
public:
	char name[100];

	void SayHello()
	{
		std::cout << "Hello from " << name << std::endl;
	}
};


void main() 
{
	Person fuad; /*fuad eto sozdonniy obyekt*/
	strcpy_s(fuad.name, "Fuad!");
	fuad.SayHello(); // esli ispolzovat class

	//SayHello(fuad); // esli ispolzovat strukt

/*---------------------------------------------------------------*/

	Person ferid; /*ferid eto sozdonniy obyekt*/
	strcpy_s(ferid.name, "Ferid!");
	ferid.SayHello(); // esli ispolzovat class

	//SayHello(ferid); // esli ispolzovat strukt
}

