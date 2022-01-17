#include <iostream>
#include <ctime>
using namespace std;

class Money
{
private:
	unsigned int dollars = 0;
	unsigned int cents = 0;

public:
	Money(unsigned int dollars = 0, unsigned int cents = 0)
	{
		this->dollars = dollars;
		this->cents = cents;
	}

	Money(double money)
	{
		this->dollars = (int)money;
		//this->cents = (money - (int)money) * 100;
		this->cents = ((int)(money * 100) % 100);
	}
	

	unsigned int getDollars()	const
	{
		return dollars;
	};

	unsigned int getCents()	const
	{
		return cents;
	};

	void setDollars(unsigned int dollars)
	{
		this->dollars = dollars;
	};

	void setCents(unsigned int cents)
	{
		dollars += cents / 100;
		this->cents = cents % 100;
	};

	void print() const
	{
		cout << dollars << "." << cents << "$\n";
	}

	//friend Money operator+(const Money& m1, const Money& m2);

	// operator overloading using method
	Money operator+(const Money& m2)
	{
		Money result;
		result.dollars = this->dollars + m2.dollars;
		result.setCents(this->cents + m2.cents);
		return result;
	}

	Money operator+(const double& m2)
	{
		Money result;
		result.dollars = this->dollars + (int)m2;
		result.setCents(this->cents + ((int)(m2 * 100) % 100));
		return result;
	}
	

	bool operator==(const Money& money)	const
	{
		return this->dollars == money.dollars && this->cents == money.cents;
			/*return true;
		else 
			return false;*/
	}


	bool equals(const Money& money)	const
	{
		return this->dollars == money.dollars && this->cents == money.cents;
	}
	//friend Money operator+(const double& m1, const Money& m2);

	//++x
	Money& operator++()
	{
		this->cents++;
		return *this;
	}

	//x++
	Money operator++(int)
	{
		Money temp(*this);
		this->cents++;
		return temp;
	}


	operator int() const 
	{
		return getDollars();  
	}


	operator double() const
	{
		return getDollars() + getCents() / 100.0;
	}


	operator float() const
	{
		return getDollars() + getCents() / 100.0;
	}
};

//// operator overloading using function
ostream& operator<<(ostream& out, const Money& money)
{
	out << money.getDollars() << "." << money.getCents() << "$";
	return out;
}

// const we have to remove, becouse Money& money we write a value
istream& operator>>(istream& in, Money& money)
{
	int dolars = 0;
	int cents = 0;
	cout << "Dollars: ";
	in >> dolars;
	cout << "Cents: ";
	in >> cents;
	money.setDollars(dolars);
	money.setCents(cents);
	return in;
}


Money operator+(const double& m1, const Money& m2)
{
	Money result;
	result.setDollars(m2.getDollars() + (int)m1);
	result.setCents(m2.getCents() + ((int)(m1 * 100) % 100));
	return result; 
}


//// operator overloading using function
//Money operator+(const Money& m1, const Money& m2)
//{
//	Money result;
//	result.setDollars(m1.getDollars() + m2.getDollars());
//	result.setCents(m1.getCents() + m2.getCents());
//	return result;
//}

//// operator overloading using friend function
//Money operator+(const Money& m1, const Money& m2)
//{
//	Money result;
//
//	result.dollars = m1.dollars + m2.dollars;
//	result.cents = m1.cents + m2.cents;
//
//	result.dollars += result.cents / 100;
//	result.cents = result.cents % 100;
//
//	return result;
//}


void main()
{
	const Money money1(120, 55);
	const Money money2(125, 55);
	
	int num = money1;
	cout << num << endl;

	double num2 = money1;
	cout << num2 << endl;

	float num3 = money1;
	cout << num3 << endl;


	if (money1.equals(money2))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	//--------------------------------------------------------

	/*
	//Example 1
	Money money1;
	cout << "Enter your money: \n";
	cin >> money1;
	cout << money1 << endl;
	*/
	
	//--------------------------------------------------------
	
	/*
	//Example 2
	cout << money1 << endl;
	
	cout << money1++ << endl;
	cout << ++money1 << endl;

	cout << money1 << endl;
	*/

	//--------------------------------------------------------

	/*
	//Example 3
	Money money1(115, 45);
	Money money2(56, 80);

	//money1.print();
	//money2.print();
	cout << money1 << endl;
	cout << money2 << endl;

	//Money money3 = money1 + money2;		// Money money3 = operator+(money1, money2);
	Money money3 = money1 + money2;		    // Money money3 = money1.operator+(money2);
	//money3.print();
	cout << money3 << endl;

	Money money4 = money3 + 50.40;
	//money4.print();
	cout << money4 << endl;

	Money money5 =Money(10.10) + money4;
	//money5.print();
	cout << money5 << endl;

	Money money6 = 10.10 + money5;			// operator+(10.10,money5)
	//money6.print();
	cout << money6 << endl;

	if (money1 == money1)
	{
		cout << "YES!";
	}
	else
	{
		cout << "NO!";
	}
	*/
}



/*
class Time
{
private:
	short hours;
	short minutes;
	short seconds;

public:
	Time();
	Time(short hours, short minutes, short seconds);

	// == > < != >= <= (operators)
	//++	add a seconds
	//--	minus seconds
	//+ - += -=
	//cout 
};
*/


