#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <conio.h>
using namespace std;

enum class Color
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	LightGray,
	DarkGray,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	LightMagenta,
	LightYellow,
	White
};

enum class Key
{
	UpArrow = 72,
	DownArrow = 80,
	Enter = 13,
	Esc = 27
};

class Console
{
private:
	static HANDLE h;

public:
	static void setPosition(short x, short y)
	{
		SetConsoleCursorPosition(h, { x, y });
	}

	static void setColor(Color foreground, Color background)
	{
		SetConsoleTextAttribute(h, (int)background * 16 + (int)foreground);
	}

	static void drawText(string text, Color foreground = Color::LightGray, Color background = Color::Black)
	{
		setColor(foreground, background);
		cout << text;
		setColor(Color::LightGray, Color::Black);
	}

	static void drawRectagle(short x, short y, short width, short height, Color color)
	{
		setColor(Color::LightGray, color);

		for (int i = 0;  i < height;  i++)
		{
			setPosition(x, y + i);
			for (int j = 0; j < width; j++)
			{
				cout << ' ';
			}
			cout << endl;
		}
		setColor(Color::LightGray, Color::Black);
	}

	//template <typename T>
	//static void menu(int count, T ...)
	//{
	//	va_list items;
	//	va_start(items, count);

	//	for (int i = 0; i < count; i++)
	//	{
	//		T item = va_arg(items, T);
	//		cout << item;
	//	}
	//}

	static void hideCursor(bool tf)
	{
			CONSOLE_CURSOR_INFO Cursor;
			GetConsoleCursorInfo(h, &Cursor);
			Cursor.bVisible = tf;
			GetConsoleCursorInfo(h, &Cursor);
	}

	static int menu(short x, short y, int count, const char* ...)
	{
		int selection = 0;
		va_list items;
		
		while (true)
		{
			va_start(items, count);
			for (int i = 0; i < count; i++)
			{
				setPosition(x, y + i);
				string item = va_arg(items, const char*);
			

				if (i == selection)
				{
					setColor(Color::Black, Color::LightGray);
				}
				item.resize(8, ' ');
				cout << item << endl;
				setColor(Color::LightGray, Color::Black);
			}

			Key key = (Key)_getch();
			switch (key)
			{
			case Key::UpArrow:
				selection--;
				break;
			case Key::DownArrow:
				selection++;
				break;
			case Key::Enter:
				return selection;
				break;
			//case Key::Esc:
			//	break;
			default:
				break;
			}
		}

	}
};

HANDLE Console::h = GetStdHandle(STD_OUTPUT_HANDLE);

void main()
{
	Console::hideCursor(false);
	Console::drawRectagle(4, 4, 10, 6, Color::LightBlue);
	int selection = Console::menu(5, 5, 4, "New", "Open", "Edit", "Exit");
	cout << selection;



	//srand(time(0));

	//while (true)
	//{
	//	short x = rand() % 10;
	//	short y = rand() % 10;
	//	short w = rand() % 10;
	//	short h = rand() % 10;
	//	Color color = Color(rand() % 16);
	//	Console::drawRectagle(x, y, w, h, color);
	//	//system("cls");
	//}
	

	//cout << "Hello!";
	//Console::drawText(" World", Color::DarkCyan);
	//cout << " man";


	//Console::setPosition(12, 5);
	//Console::setColor(Color::Black, Color::White);
	//cout << "Fuad";
}

