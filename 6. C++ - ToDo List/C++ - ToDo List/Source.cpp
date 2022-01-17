#include <iostream>
using namespace std;


class Task
{
private:
	char name[100];
	bool done;


public:

	Task()
	{
		/* 
			We created this empty Constructor 
			for using on TaskList class
			function 
			** ------------------------------- ** 
			Task* temp = new Task[taskCount + 1]
		*/
	}

	Task(const char* name)
	{

		//strcpy_s(this->name, name);
		setName(name);
		this->done = false;
	}

	char* getName()
	{
		return name;
	}

	bool getDone()
	{
		return done;
	}

	void setName(const char* name)
	{
		if (strlen(name) > 0)
		{
			strcpy_s(this->name, name);
		}
	}

	void setDone(bool done)
	{
		this->done = done;
	}

};


class TaskList
{
private:

	/* 
	Task* is linked with Task class
	if Task class was not created
	then "Task* tasks" can not been created
	*/
	Task* tasks;
	int taskCount;

public:
	TaskList()
	{
		tasks = nullptr;
		taskCount = 0;
	}

	~TaskList()
	{
		delete[] tasks;
	}
	/*
		if we wont to created 
	*/
	void addTask(Task task)
	{
		Task* temp = new Task[taskCount + 1];
		for (int i = 0; i < taskCount; i++)
		{
			temp[i] = tasks[i];
		}
		delete[] tasks;
		tasks = temp;
		tasks[taskCount] = task;
		taskCount++;
	}

	void printTasks()
	{
		for (int i = 0; i < taskCount; i++)
		{
			cout << tasks[i].getName() << endl;
		}
	}

};

void main()
{
	TaskList list;

	cout << "Enter task count: ";
	int count;
	cin >> count;
	cin.ignore();

	for (int i = 0; i < count; i++)
	{
		char taskName[100];
		cout << "Task #" << i + 1 << ": ";
		cin.getline(taskName, 100);
		list.addTask(Task(taskName));
	}

	cout << endl;
	list.printTasks();


	/*
	Task task1("Do my homework - 1");
	Task task2("Feed my cat - 1");

	list.addTask(task1);
	list.addTask(task2);
	
	list.addTask(Task("Hello ")); 
	list.addTask(Task("Hi"));

	list.printTasks();
	*/
}