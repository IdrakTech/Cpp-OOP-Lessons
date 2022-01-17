#include <iostream>
using namespace std;

//class Array;
//class MyString;

/*
*	-- DONE --

	constructor
	copy constructor
	destructor ~

	void pushBack(int data)
	int getSize()
	int get(int position)
	int set(int position, int data)
	void removeAt(int position)
	int indexvoidOf(int data)
	void insert(int data, int position)  // func for past data on write position 
	void remove(int data)				 // func for remove data on char array
	int lastIndexvoidOf(int data)		 // func for search index on last position
	void clear()						 // clear all arrey
	void sort()							 // sort all arrey
	
	-- TODO -
	
*/

class IntArray
{
private:
	int* arr = nullptr;
	int size = 0;

public:


	~IntArray()
	{
		delete[] arr;
	}


	// foo add to arr write int Data 
	void pushBack(int data)
	{
		int* temp = new int[size + 1];
		memcpy(temp, arr, sizeof(int) * size);
		delete[] arr;
		arr = temp;
		arr[size] = data;
		size++;
	}

	// foo to remove data on the point position
	void removeAt(int position)
	{
		if (position >= 0 && position < size)
		{
			int* temp = new int[size - 1];
			memcpy(temp, arr, sizeof(int) * position);
			memcpy(temp + position, arr + position + 1, sizeof(int) * (size - position));
			delete[] arr;
			arr = temp;
			size--;
		}
	}

	// foo for remove data witch will be point
	void remove(int data)
	{
		for (int position = 0; position < size; position++)
		{
			if (arr[position] == data)
			{
				int* temp = new int[size - 1];
				memcpy(temp, arr, sizeof(int) * position);
				memcpy(temp + position, arr + position + 1, sizeof(int) * (size - position));
				delete[] arr;
				arr = temp;
				size--;
			}
							
		}		
	}

	// foo return size
	int getSize() const
	{
		return size;
	}

	// if indexOf true return index else -1
	int indexOf(int data)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == data)
			{
				return i;
				//cout << i << '\t';
			}
		}
		return -1;
	}


	//       V
	//11 22 33 44 55 66
	//__ __ __ __ __ __ __
	void insert(int data, int position)
	{
		int* temp = new int[size + 1];
		memcpy(temp, arr, sizeof(int) * position);
		memcpy(temp + position + 1, arr + position, sizeof(int) * (size - position));
		delete[] arr;
		arr = temp;
		arr[position] = data;
		size++;
	}


	//                 V
	// 11 24 67 47 55 67 78 
	// __ __ __ __ __ __ __
	// func for search index on last position or return -1
	int lastIndexVoidOf(int data) 
	{
		for (int i = 0; i < size; i++)		// for() in here will fiend position of data 
		{
			for (int j = size; j > 0; --j)	// for() in here count from end position
			{								// to begin position
				if (arr[j] == data)
				{
					return j;
				}
			}
		}
		return -1;
	}


	void lastIndexPosition()
	{
		int data;
		for (int i = 0; i < size; i++)		// for() in here will fiend position of data 
		{
			data = arr[i];
			
		}

		//cout << data << '\t';

		for (int i = 0; i < size; i++)		// for() in here will fiend position of data 
		{
			if (arr[i] == data)
			{
				cout << i;
			}
		}

	}


	// foo for clear all arr
	void clear()
	{
		int arrSize = 0;
		while ( arrSize < size)
		{
			++arrSize;
		}

		if (size == arrSize)
		{
			arrSize = arrSize * 2;
			for (int i = 0; i < (size * arrSize); ++i)
			{
				int* temp = new int[size];
				delete[] arr;
				arr = temp;
				size--;
			}
		}
		
	}


	//							  V
	//						V
	//				  V
	//11 22 33 44 55 33 66 11 77 03
	//03 11 11 22 33 33 44 55 66 77
	void sort()
	{	
		int temp;
		for (int sortPos = 0; sortPos < size; ++sortPos) 
		{
			for (int unsortPos = sortPos + 1;  unsortPos < size;  ++unsortPos)
			{
				if (arr[sortPos] > arr[unsortPos])
				{
					temp = arr[sortPos];
					arr[sortPos] = arr[unsortPos];
					arr[unsortPos] = temp;
				}
			}
		}
	}


	/*
	*  foo-s getter & setter
	* -->> begin
	*/
	int get(int position) const
	{
		return arr[position];
	}

	void set(int position, int data)
	{
		arr[position] = data;
	}

	/*
	* -->> end
	*/
};


// foo for cout arr on window
void print(const IntArray &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr.get(i) << '\t';
	}
}


class Student
{
	char name[100];
	IntArray grades;

	void setGrade(int grade)
	{
		grades.pushBack(grade);
	}
};



int main()
{
	IntArray myArr;

	myArr.pushBack(11);
	myArr.pushBack(22);
	myArr.pushBack(33);
	myArr.pushBack(11);
	myArr.pushBack(44);
	myArr.pushBack(55);
	myArr.pushBack(11);
	/*myArr.pushBack(33);
	myArr.pushBack(66);
	myArr.pushBack(11);
	myArr.pushBack(77);
	myArr.pushBack(03);*/
	
	//cout << myArr.get(1) << endl;
	//myArr.set(2, 99);

	print(myArr);

	cout << endl;

	//myArr.removeAt(1);
	myArr.remove(11);
	//cout << myArr.clear() << endl;
	//myArr.clear();
	//myArr.insert(37, 5);
	//myArr.sort();
	//myArr.lastIndexPosition();
	print(myArr);

	//cout << endl;

	//cout << myArr.indexOf(66) << endl;


	//for (int i = 0; i < myArr.getSize(); i++)
	//{
	//	cout << myArr.get(i) << endl;
	//}
}