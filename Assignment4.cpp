//============================================================================
// Name        : Ass4_linkedlist.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;
class node
{
public:
	char name[20];
	int prn;
	node *next;
	node(char a[],int x)
	{
		strcpy(name,a);
		prn=x;
		next=NULL;
	}
};
class pinnacle

{	node *head;
	node *president;
	node *member;
	node *secretary;
public:
	void getdata();
	void display();
	void insert();
	void del();
	void total();
	void reverse(node *temp);
	void reverse_dis();
	void concatinate(pinnacle *obj2);
	void sort();
	//void merge();
	pinnacle()
	{	head=NULL;
		president = NULL;
		member = NULL;
		secretary = NULL;
	}
};
void pinnacle::getdata()

{
	char a[20];
	int x,c;
	node *p;
		cout<<"enter the name,prn of president";
		cin>>a;
		cin>>x;
		president =new node(a,x);
		p = president;
		while(1)

		{
			cout<<"Enter the name and prn of member"<<endl;
			cin>>a;
			c=strcmp(a,"stop");
			if(!c)
				break;
			cin>>x;
			p->next= new node(a,x);
			secretary=p->next;
			p=p->next;
		}
		cout<<"Enter the name and prn of secretary: "<<endl;
		cin>>a>>x;
		p->next=new node(a,x);
		secretary = p->next;
}
void pinnacle::display()

{
	node *temp;
	temp= president;
	while(temp!=NULL)

	{
		cout<<temp->name<<endl;
		cout<<temp->prn<<endl;
		temp=temp->next;
	}
}
void pinnacle::del()

{
	int n;
	cout<<"Enter 1 to delete president \n2 to delete secretary \n3 to delete member ";
	cin>>n;
	switch (n)
	{
	case 1:node *p;
	p=president->next;
	president = p;
	break;
	case 2: node *q;
	q= president;
	while(q->next != secretary)
		q=q->next;
	secretary = q;
	delete q->next;
	q->next=NULL;
	break;
	case 3:
		int flag=0;
	cout<<"enter prn number of member to be deleted: ";
	int x;
	cin>>x;
	p=president;
	q=president;
	while(p->next != NULL)
	{
		if(p->prn==x)
		{
			flag=1;
			q->next=p->next;
			delete p;
		}
		p=p->next;
	}
	if(flag==0)
		cout<<"no prn found"<<endl;
	}
}
void pinnacle::insert()
{
	cout<<"Enter 1 to insert president\n2 to insert member\n3 to insert secretary"<<endl;
	int n;
	cin>>n;
	switch (n)
	{
	case 1:
		node *p;
		int x;
		char a[20];
		cout<<"Enter the name and prn of new president";
		cin>>a>>x;
		p = new node(a,x);
		p->next=president;
		president=p;
		break;
	case 2:
		node *q;
		p=president;
		int count;
		count = 1;
		cout<<"enter the location after which member is to be added: ";
		int z;
		cin>>z;
		while(count < z)
		{
			p=p->next;
			count++;
		}
		cout<<"Enter the name and prn of member"<<endl;
		cin>>a>>x;
		q=new node(a,x);
		q->next = p->next;
		p->next=q;
		break;
		case 3:
		p= president;
		cout<<"enter the name and prn of secretary: ";
		while(p->next != NULL)
			p=p->next;
		cin>>a>>x;
		p->next = new node(a,x);
		secretary = p->next;
		break;
	}
}
void pinnacle::total()
{
	node *temp;
	temp= president;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"total number of member in pinnacle club are: "<<count;
}

void pinnacle::reverse(node *temp)
{
	if(!temp){
		;
	}else{
		reverse(temp->next);
		cout<<temp->name<<endl;
		cout<<temp->prn<<endl;
	}
}
void pinnacle::reverse_dis(){
	head=president;
	reverse(head);
}
void pinnacle::concatinate(pinnacle *obj2){
	head = president;
	node *temp=NULL;
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=obj2->president;
	while(head!=NULL)

		{
			cout<<head->name<<endl;
			cout<<head->prn<<endl;
			head=head->next;
		}
}
void pinnacle:: sort(){
	node *temp3=NULL;
	temp3=president->next;
	int num;
	char names[20];
	node *temp2=NULL;
	temp2= president;
	int count=0;
	while(temp2!=NULL)
	{
		count++;
		temp2=temp2->next;
	}
	for(int i=0;i<count-2;i++){
		while(temp3->next->next!=secretary){
			if(temp3->prn>temp3->next->prn){
				num=temp3->next->prn;
				strcpy(names,temp3->next->name);
				temp3->next->prn=temp3->prn;
				strcpy(temp3->next->name,temp3->name);
				temp3->prn=num;
				strcpy(temp3->name,names);
			}
			temp3=temp3->next;
		}
	}
}
//void pinnacle::merge(pinnacle *obj2){
//	node *temp=NULL;
//	temp=president;
//}
int main()
{
	pinnacle pin,pin2;
	int i;
	cout<<"Press 1 for inserting data"<<endl;
	cout<<"Press 2 for counting members"<<endl;
	cout<<"Press 3 for deleting data"<<endl;
	cout<<"Press 4 for viewing list in reverse"<<endl;
	cout<<"Press 5 for concatenate"<<endl;
	cout<<"Press 6 for sorted merge"<<endl;
	cout<<"Press 7 for sorting linked list"<<endl;
	cin>>i;
	switch(i){
	case 1:
		pin.getdata();
		pin.display();
		pin.insert();
		pin.display();
		break;
	case 2:
		pin.getdata();
		pin.display();
		pin.total();
		break;
	case 3:
		pin.getdata();
		pin.display();
		pin.del();
		pin.display();
		pin.total();
		break;
	case 4:
		pin.getdata();
		pin.display();
		pin.reverse_dis();
		break;
	case 5:
		pin.getdata();
		pin2.getdata();
		pin.concatinate(&pin2);
		break;
//	case 6:
//		pin.getdata();
//		pin2.getdata();
//		pin.sort();
//		pin2.sort();
//		pin.merge(&pin2);
//		break;
	case 7:
		pin.getdata();
		pin.sort();
		cout<<"Sorted linked list:\n";
		pin.display();
		break;
	default:
		cout<<"Invalid input"<<endl;
		break;
	}
}
