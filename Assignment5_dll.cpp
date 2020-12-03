#include<iostream>
using namespace std;
class binary;
class node
{
	node *prev;
	bool n;
	node*next;
public:
	node()
	{
		prev=next=NULL;
	}
	node(bool b)
	{
		n=b;
		prev=next=NULL;
	}
	friend class binary;
};

class binary
{
	node *head;

	public:
		binary()
		{
			head=NULL;
		}
		void generateBinary(int no){
            bool rem;
            node *p;
            rem=no%2;
            head=new node(rem);
            no=no/2;
            while(no!=0)
            {
                rem=no%2;
                no=no/2;
                p=new node(rem);
                p->next=head;
                head->prev=p;
                head=p;
    	    }
        }
		void displayBinary(){
            node *t;
            t=head;
            while(t!=NULL)
            {
                cout<<t->n;
                t=t->next;
            }
            cout<<endl;
        }
		void onesComplement(){
            node *t;
            t=head;
            while(t!=NULL)
            {
                if(t->n==0)
                    t->n=1;
                else
                    t->n=0;
                t=t->next;
            }
        }
		void twoscomplement(){
            onesComplement();
            bool carry=1;
            node *t;
            t=head;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            while(t!=NULL)
            {
            if(t->n==1&& carry==1)
            {
                t->n=0;
                carry=1;
            }
            else
            if(t->n==0&& carry==1)
            {
                t->n=1;
                carry=0;
            }
            else
            if(carry==0)
            break;
            t=t->prev;
            }
            displayBinary();
        }
		binary operator +(binary n1){
            binary sum;
            node *a=head;
            node *b=n1.head;
            bool carry=false;
            while(a->next!=NULL)
                a=a->next;
            while(b->next!=NULL)
                b=b->next;

            while(a!=NULL && b!=NULL)
            {
                sum.addBitAtBegin((a->n)^(b->n)^carry);
                carry=((a->n&& b->n) || (a->n&& carry) || (b->n && carry));
                a=a->prev;
                b=b->prev;
            }
            while(a!=NULL)
            {
                sum.addBitAtBegin(a->n^carry);
                a=a->prev;
            }
            while(b!=NULL)
            {
                sum.addBitAtBegin(b->n^carry);
                b=b->prev;
            }
            sum.addBitAtBegin(carry);
            return sum;
        }
        bool addBitAtBegin(bool val)
        {
            node *nodee=new node(val);
            if(head==NULL)
            {
                head=nodee;
            }
            else
            {
                nodee->next=head;
                head->prev=nodee;
                head=nodee;
            }
            return true;
        }
};

int main(){
	int num,num1;
	binary n1,n3,n2;
	int i;
    char ans;
	do
	{
		cout<<"\nPress 1 to Generate binary"<<endl;
        cout<<"Press 2 to get One's Complement"<<endl;
        cout<<"Press 3 to get Two's Complement"<<endl;
        cout<<"Press 4 for addition of 2 numbers"<<endl;
		cin>>i;
		switch(i)
		{
			case 1: cout<<"Enter Number in decimal form:"<<endl;
					cin>>num;
					n1.generateBinary(num);
					cout<<"Binary Representation: "<<endl;
					n1.displayBinary();
					break;
			case 2:cout<<"Enter Number in decimal form: "<<endl;
					cin>>num;
					n1.generateBinary(num);
					cout<<"Binary Representation: "<<endl;
					n1.displayBinary();
					cout<<"Ones Complement: "<<endl;
					n1.onesComplement();
					n1.displayBinary();
					break;
			case 3:cout<<"Enter Number in decimal form: "<<endl;
					cin>>num;
					n1.generateBinary(num);
					cout<<"Binary Representation: "<<endl;
					n1.displayBinary();
					cout<<"Twos complement: "<<endl;
					n1.twoscomplement();
					break;
			case 4: cout<<"Enter Two Numbers: "<<endl;
					cin>>num>>num1;
					n1.generateBinary(num);
					n2.generateBinary(num1);
					n1.displayBinary();
					cout<<" + ";
					n2.displayBinary();
					cout<<"= ";
					n3=n1+n2;
					n3.displayBinary();
		}
        cout<<"Do you want to continue?(y or n)"<<endl;
        cin>>ans;
	}while(ans=='Y'||ans=='y');
	return 0;
}

