#include <iostream>
#include <string>
using namespace std;

void main()
{
								/*			Class String 2			*/

	string str = "Lorem ipsum dolor sit amet dolor";
	//str.assign(100, 'a');
	//str.append("123456", 2);
	//str.erase(2, 2);
	//cout << str.find("dolor", 13) << endl;
	//cout << str.rfind("dolor") << endl;
	//cout << str.find_first_of(",.!?");
	//str.insert(str.find("dolor") + 6, "Hello");
	//str.replace(str.find("dolor"), 5, "TEST");
	//str.resize(100, 'a');
	//cout << str.capacity();
	//string result = str.substr(str.find("dolor"));
	
	
	cout << str << " Length:" << str.length() << " capacity:" << str.capacity() << endl;
	str.reserve(1000);
	cout << str << " Length:" << str.length() << " capacity:" << str.capacity() << endl;
	str.shrink_to_fit();
	cout << str << " Length:" << str.length() << " capacity:" << str.capacity() << endl;



								/*			Class String 1			*/

	//string text = "Hello ";

	//char str[] = "Happy birthday to you";
	//text.copy(str, 6, 0);
	//cout << text << endl;
	//cout << str << endl;

	//string text2 = "World";
	//cout << (text.compare(text2) == 0 ? "Yes" : "No") << endl;

	//text.clear();
	//cout << text << endl;
	
	//text.resize(100, '-');
	//for (int i = 0;  i < 100;  i++)
	//{
	//	text += '!';
	//	cout << text << endl;
	//	cout << "Lenght: " << text.length() << endl;
	//	cout << "Capacity: " << text.capacity() << endl;
	//}


	//cout << text[0] << endl;
	//cout << text.at(0) << endl;

	//cout << text.front() << endl;
	//cout << text[0] << endl;

	//cout << text.back() << endl;
	//cout << text[text.length() - 1] << endl;
	

	//string text2 = " for you";
	//text += " for you";
	//text.append(" for you");
	//text.append(text2);
	//text.append(" for you", 4, 3);
	//cout << text << endl;

	//text = "Goodbye world";
	//text.assign("Goodbye world");		// assigne and = are the same thing 
	//text.assign(10, 'F');
	//cout << text << endl;

	//char* text2 = new char[100];
	//strcpy_s(text2, text.length() + 1, text.c_str());
	//cout << text2;

	//string text1 = "Hello";
	//string text2 = "world";

	//string text;
	//cin >> text;
	//cin.getline()				// you write text to char array
	//getline(cin, text);			// you write text to string
	//cout << text << endl;


	//string text3 = text1 + " " + text2;
	//cout << text3 << endl;

	//cout << text1 + " " + text2 << endl;

	//cout << (text1 == text2 ? "yes" : "no") << endl;
//					^
//					|		the same things
//					v
	//if (time1 == time2)
	//{
	//	cout << "YES\n";
	//}
	//else
	//{
	//	cout << "NO\n";
	//}

	//string text1(10, 'a');
	//cout << text1 << endl;


	//string text1("Hello");
	//string text2 = "Hello";
	//string text3{"Hello"};
	//string text4 = {"Hello"};

	//string text = "Hello";

	//cout << text << endl;

	//cout << text[0] << endl;
	//text[0] = 'h';
	//cout << text << endl;

	//cout << text.length() << endl;

	//text += " World";
	//cout << text << endl;

	//text = "Good bye World";
	//cout << text << endl;

	//string text2;
	//text2 = text;
	//cout << text2 << endl;
}