#include <iostream>
using namespace std;

class Car
{
private:
	char* model;// = new char[] {"Unknown"};
	short year = 1900;
	double maxSpeed = 0;
	int power = 0;


public:
					/* ----- *Constructers* ----- */
					// Default constructers
	
/*
	Car(const char* model, short year, double maxSpeed, int power)
		: year(year), maxSpeed(maxSpeed), power(power) // Initializer list
	{
		strcpy_s(this->model, model); // tolko year pishem tak kak 
									  // char metodom Initializer ne vozmojen
	}
*/
	


					// Overloaded constructor
	Car(const char* model = "Unknown", short year = 1900, double maxSpeed = 0, int power = 0)  // constructor budet default 
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
		cout << "Car created " << endl;

		/*strcpy_s(this->model, model);
		this->year = year;
		this->maxSpeed = maxSpeed;
		this->power = power;*/
	}

					/* ---- * Destructor * ---- */

	// Destructor nujen tolko dla toqo chtobi udalat 
	// zapolnenniy pamat dinamicheskim massivom

	~Car()
	{
		delete[] model;  // eto dla toqo chtobi  udalit 
						 // pamat kotoruyu zanimaet /* new char[size + 1] */
						 
		cout << "Car delited " << endl;
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

	void setModel(const char* model) // Zdes nazvaniya modeli "Lanborgini" = 11 Byte
	{
		int size = strlen(model);
		if (size > 0)
		{
			delete[] this->model;					// mi tut ochishaem staruyu pamat 
			this->model = new char[size + 1];		// i pishem uje novuyu 

			strcpy_s(this->model, size + 1, model);
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

	void setPower(int power)
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

void main()
{
	//cout << "Begin" << endl;
	//if (true)
	//{							/*     Destructor eto function cotoriy   
	//	Car car;					   udolaet pola Constructor pri zavershenii kakoqo
	//	cout << "Test" << endl;		   libo zadanii v etom sluchae mi  
	//}							 */    nachenaem s {-ok i zavershaem s }-mi
	//cout << "End" << endl;

	/* write with setter */
	//Car car1;
	//car1.setModel("Lada sedan");
	//car1.setMaxSpeed(170);
	//car1.setPower(110);
	//car1.setYear(2016);
	//car1.showInfo();

	Car car1("Lanborgini", 1234, 380, 1100);
	while (true)
	{
		car1.setModel("Lanborgini");
	}

	////Car car2;
	////car2.setModel("lanborgini");
	////car2.setMaxSpeed(380);
	////car2.setYear(1977);
	////car2.setPower(1100);
	//Car car2("Lada Priora");
	//car2.showInfo();

}