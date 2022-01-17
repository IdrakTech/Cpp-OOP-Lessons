#include <iostream>
using namespace std;

class MyClass
{
private:

public:
	int x;
	double y;

	void Test()
	{
		cout << x << endl;
		cout << y << endl;
		cout << this << endl;
	}

};

void Test(MyClass* _this)
{
	cout << _this->x << endl;
	cout << _this->y << endl;
}


void main()
{
	MyClass a;

	a.x = 10;
	a.y = 1.5;

	MyClass b;

	b.x = 20;
	b.y = 2.5;

	//cout << sizeof(a);
	cout << &a << endl;

	a.Test();
	b.Test();
}
