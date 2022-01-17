#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <windows.h>
//#include <time.h>

using namespace std;

class Person
{
	char name[100];
	int age;
};

class DateTime
{
public:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;

	DateTime()
	{
		auto timeInSeconds = time(0);
		tm* time = localtime(&timeInSeconds);
		year = time->tm_year + 1900;
		month = time->tm_mon + 1;
		day = time->tm_mday;
		hour = time->tm_hour;
		minute = time->tm_min;
		second = time->tm_sec;
	}

	DateTime(int year, int month, int day, int hour = 0, int minute = 0, int second = 0)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}

	void printDate()
	{
		cout << "Date: " << day << "-" << month << "-" << year << endl;
	}

	void printTime()
	{
		cout << "Time: " << hour << ":" << minute << ":" << second << endl;
	}

	void print()
	{
		printDate();
		printTime();	
	}

	static int compare(DateTime first, DateTime second)
	{
		if (first.year > second.year)
			return 1;
		else if (first.year < second.year)
			return -1;
		else if (first.month > second.month)
			return 1;
		else if (first.month < second.month)
			return -1;
		else if (first.day > second.day)
			return 1;
		else if (first.day < second.day)
			return -1;
		else if (first.hour > second.hour)
			return 1;
		else if (first.hour < second.hour)
			return -1;
		else if (first.month > second.month)
			return 1;
		else if (first.month < second.month)
			return -1;
		else if (first.minute > second.minute)
			return 1;
		else if (first.minute < second.minute)
			return -1;
		else if (first.second > second.second)
			return 1;
		else if (first.second < second.second)
			return -1;
		return 0;
	}
};

void main()
{
	DateTime dt;
	dt.print();

	Sleep(1000);

	DateTime dob;
	dob.printDate();

	cout << DateTime::compare(dt, dob) << endl;

	//srand(time(0));

	//cout << time(0) << endl;

	//auto timeInSeconds = time(0);
	//cout << ctime(&timeInSeconds) << endl;

	//while (true)
	//{
	//	system("cls");
	//	auto timeInSeconds = time(0);
	//	cout << ctime(&timeInSeconds) << endl;
	//	Sleep(1000);
	//}


	/*
	auto timeInSeconds = time(0);
	tm* time = localtime(&timeInSeconds);
	cout << "Year: " << time->tm_year + 1900 << endl;
	cout << "Month: " << time->tm_mon + 1 << endl;
	cout << "Day: " << time->tm_mday << endl;
	cout << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
	*/

}