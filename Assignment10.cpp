    //============================================================================
// Name        : Assignment10.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class dequeue
{
	int job[20];
	int front;
	int rear;
public:
	dequeue()
	{
		front = -1;
		rear = -1;
	}
	bool pushBack(int);
	bool pushFront(int);
	int popFront();
	int popBack();
	void display();
};

bool dequeue::pushBack(int i)
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

bool dequeue::pushFront(int i)
{
	if(front == 0) return false;
	else if(front == -1)
	{
		front++;
		rear++;
		job[front] = i;
		return true;
	}
	else
	{
		front--;
		job[front] = i;
		return true;
	}
}

int dequeue::popFront()
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

int dequeue::popBack()
{
	int x;
	if(front == -1) return 0;
	else if(front == rear)
	{
		x = rear;
		front = rear = -1;
		return job[x];
	}
	else
	{
		rear--;
		return job[rear+1];
	}
}

void dequeue::display()
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
	dequeue dq;
	int choice, id;
	while(true)
	{
		cout<<"\n\nWhat would you like to do :"
			<<"\n1. Add Job to be done next"
			<<"\n2. Add job to be done last"
			<<"\n3. Remove next job"
			<<"\n4. Remove last job"
			<<"\n5. Exit"
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
				if(!dq.pushFront(id))
				{
					cout<<"\nOverflow!!! Let all jobs complete or remove all manually!!";
				}
				break;
		case 2 :cout<<"\nEnter job ID (Non-Zero) : ";
				cin>>id;
				if(!id)
				{
					cout<<"\nDo not enter zero! It means no job!!";
					break;
				}
				if(!dq.pushBack(id))
				{
					cout<<"\nOverflow!!! Let all jobs complete or remove all manually!!";
				}
				break;
		case 3 :id = dq.popFront();
				if(!id)
				{
					cout<<"\nNo jobs to remove!!!";
					break;
				}
				cout<<"\nJob removed!!";
				break;
		case 4 :id = dq.popBack();
				if(!id)
				{
					cout<<"\nNo jobs to remove!!!";
					break;
				}
				cout<<"\nJob removed!!";
				break;
		case 5 :return 0;
		default:cout<<"\nEnter correct choice!!!";
		}
		cout<<endl;
		dq.display();
	}
	return 0;
}


