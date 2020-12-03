    //============================================================================
// Name        : Assignment9.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class queue
{
	int job[20];
	int front;
	int rear;
public:
	queue()
	{
		front = -1;
		rear = -1;
	}
	bool push(int);
	int pop();
	void display();
};

bool queue::push(int i)
{
	if(rear == 19) return false;
	if(front == -1)
	{
		front++;
		rear++;
		job[rear] = i;
		return true;
	}
	else
	{
		rear++;
		job[rear] = i;
		return true;
	}
}

int queue::pop()
{
	int x;
	if(front == -1)	return 0;
	else if(front == rear)
	{
		x = front;
		front = rear = -1;
		return job[x];
	}
	else
	{
		front++;
		return job[front-1];
	}
}

void queue::display()
{
	if(front == -1)
	{
		cout<<"\nJob Queue Empty!!!\n";
		return;
	}
	cout<<"\nJob Queue : ";
	for(int i = front; i <= rear; i++)
	{
		cout<<job[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	queue q;
	int choice, id;
	while(true)
	{
		cout<<"\n\nWhat would you like to do :"
			<<"\n1. Add Job"
			<<"\n2. Remove Job"
			<<"\n3. Exit"
			<<"\nEnter choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1 :cout<<"\nEnter job ID (Non-Zero) : ";
				cin>>id;
				if(!id)
				{
					cout<<"\nDo not enter zero! It means no job!!";
					break;
				}
				if(!q.push(id))
				{
					cout<<"\nOverflow!!! Let all jobs complete or remove all manually!!";
				}
				break;
		case 2 :id = q.pop();
				if(!id)
				{
					cout<<"\nNo jobs to remove!!!";
					break;
				}
				cout<<"\nJob removed!!";
				break;
		case 3 :return 0;
		default:cout<<"\nEnter correct choice!!!";
		}
		cout<<endl;
		q.display();
	}
	return 0;
}


