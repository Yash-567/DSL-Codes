    //============================================================================
// Name        : Assignment6.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

bool error = false;

class set;

class student
{
	int rno;
	student* next;
public:
	student()
	{
		rno = 0;
		next = NULL;
	}
	~student()
	{
		delete next;
		next = NULL;
	}
	friend class set;
};

class set
{
	student* head;
public:
	set()
	{
		head = NULL;
	}
	~set()
	{
		delete head;
		head = NULL;
	}
	void add(int);
	void display();
	void uni(set*, set*);
	void inter(set*, set*);
	void sub(set*, set*);
};

void set::add(int i)
{
	error = false;

	if(!head)
	{
		head = new student;
		head->rno = i;
		return;
	}

	student* t = head;

	while(t->next)	t = t->next;

	if(t->rno == i)
	{
		cout<<"\nStudent already present!!\n";
		error = true;
		t = NULL;
		return;
	}
	if(t->rno > i)
	{
		cout<<"\nEnter roll no. in ascending order!!!\n";
		error = true;
		t = NULL;
		return;
	}
	t->next = new student;
	t->next->rno = i;
	t = NULL;
}

void set::display()
{
	student* t;
	t = NULL;

	if(!head)
	{
		cout<<"\nThe set is empty!!!\n";
		return;
	}
	t = head;

	cout<<"\n{ ";
	while(t)
	{
		if(!t->next) cout<<t->rno<<' ';
		else cout<<t->rno<<", ";
		t = t->next;
	}
	cout<<"}\n";

}

void set::uni(set* B, set* res)
{
	student* a = head;
	student* b = B->head;

	while(a && b)
	{
		if(a->rno < b->rno)
		{
			res->add(a->rno);
			a = a->next;
		}
		else if(a->rno > b->rno)
		{
			res->add(b->rno);
			b = b->next;
		}
		else
		{
			res->add(a->rno);
			a = a->next;
			b = b->next;
		}
	}
	for( ; a ; a = a->next) res->add(a->rno);
	for( ; b ; b = b->next) res->add(b->rno);
}

void set::inter(set* B, set* res)
{
	student* a = head;
	student* b = B->head;

	while(a && b)
	{
		if(a->rno < b->rno) a = a->next;
		else if(a->rno > b->rno) b = b->next;
		else {
			res->add(a->rno);
			a = a->next;
			b = b->next;
		}
	}
	a = NULL;
	b = NULL;
}

void set::sub(set* B, set* res)
{
	student* a = head;
	student* b = B->head;

	while(a && b)
	{
		if(a->rno < b->rno)
		{
			res->add(a->rno);
			a = a->next;
		}
		else if(a->rno > b->rno) b = b->next;
		else{
			a = a->next;
			b = b->next;
		}
	}
	for( ; a ; a = a->next) res->add(a->rno);
	b = NULL;
}

int main()
{
	set x, U, V, B, u, n, VB, BV, uc;
	int str, stu, pref = 0;
	char ch;

	cout<<"\nHow many students are there : ";
	cin>>str;

	for(int i = 0; i < str; i++)
	{
		pref = 0;

		cout<<"\nEnter roll no. ";
		cin>>stu;

		cout<<"Do they like vanilla : ";
		cin>>ch;
		if(ch == 'Y' || ch == 'y') pref++;

		cout<<"Do they like butterscotch : ";
		cin>>ch;
		if(ch == 'Y' || ch == 'y') pref += 2;

		U.add(stu);
		if(error)
		{
			i--;
			error = false;
		}
		else
		{
			switch(pref)
			{
			case 1 :V.add(stu);
					break;
			case 2 :B.add(stu);
					break;
			case 3 :V.add(stu);
					B.add(stu);
					break;
			}
		}
	}

	V.uni(&B, &u);
	V.inter(&B, &n);
	V.sub(&B, &VB);
	B.sub(&V, &BV);
	U.sub(&u,&uc);

	cout<<"\nSet of students who like either vanilla or butterscotch are :"; u.display();
	cout<<"\nSet of students who like both vanilla and butterscotch are :"; n.display();
	cout<<"\nSet of students who like vanilla but not butterscotch are :"; VB.display();
	cout<<"\nSet of students who like butterscotch but not vanilla are :"; BV.display();
	cout<<"\nSet of students who like neither vanilla nor butterscotch are :"; uc.display();

	return 0;
}


