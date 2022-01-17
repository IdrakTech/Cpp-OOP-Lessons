#include <iostream>
using namespace std;

class Car
{
private:
	char model[100];
	short year;
	double maxSpeed;
	int power;


public:
	/* ----- *Constructers* ----- */
	// Default constructers
	Car()
	{
		strcpy_s(model, "Unknown");
		year = 0;
		maxSpeed = 0;
		power = 0;
	}

	// Overloaded constructor
	Car(const char* model, short year, double maxSpeed, int power) : Car()
	{
		/*

		 Vtoroy metod dla vvedeniye 
		 ** Default constructor Vnutr Overloaded constructor **

		 this->Car::Car();
		 -----------------

		*/

		/* chtobi vtoroy raz ne provodit proverku v konstruk-
		-tore mi ispolzuem setteri v samom kostruktore */
		setModel(model);
		setYear(year);
		setMaxSpeed(maxSpeed);
		setPower(power);

		/*strcpy_s(this->model, model);
		this->year = year;
		this->maxSpeed = maxSpeed;
		this->power = power;*/
	}

	/* ----- *qetters* ----- */

	char* getModel()
	{
		return model;
	}

	short getYear()
	{
		return year;
	}

	double getMaxSpeed()
	{
		return maxSpeed;
	}

	int getPower()
	{
		return power;
	}


	/* ----- *setter* ----- */

	void setModel(const char* model)
	{
		if (strlen(model) > 0)
		{
			strcpy_s(this->model, model);
		}
	}

	void setYear(short year)
	{
		if (year >= 1900 && year <= 2019)
		{
			this->year = year;
		}
		//else if(year <= 1900 && year >= 2019)
		//{
		//	this->year = year;
		//	cout << setYear << " ->Year is Wrong!!! " << endl;
		//}
	}

	void setMaxSpeed(double maxSpeed)
	{
		if (maxSpeed >= 0 && maxSpeed <= 1000)
		{
			this->maxSpeed = maxSpeed;
		}
	}

	void setPower( int power)
	{
		if (power >= 0 && power <= 2000)
		{
			this->power = power;
		}
	}

	void showInfo()
	{
		cout << "Model: " << model << endl;
		cout << "Year: " << year << endl;
		cout << "MaxSpeed: " << maxSpeed << endl;
		cout << "Power: " << power << endl << endl;
	}

};

int  main()
{
	/* write with setter */
	Car car1;
	car1.setModel("Lada sedan");
	car1.setMaxSpeed(170);
	car1.setPower(110);
	car1.setYear(2016);
	car1.showInfo();

	Car car2("Lanborgini", 1234, 380, 1100);
	car2.showInfo();
	//Car car2;
	//car2.setModel("lanborgini");
	//car2.setMaxSpeed(380);
	//car2.setYear(1977);
	//car2.setPower(1100);

	return 0;
}