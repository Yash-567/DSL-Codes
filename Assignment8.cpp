    //============================================================================
// Name        : Assignment8.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

class stack
{
	char ch[50];
	int top;
public:
	stack()
{
		top = -1;
}
	int getTop();
	bool push(char);
	char pop();
};

bool stack::push(char c)
{
	if(top == 49)
	{
		cout<<"\nStack Overflow!!!";
		return true;
	}
	top++;
	ch[top] = c;
	return false;
}

char stack::pop()
{
	if(top == -1)	return '\t';
	top--;
	return ch[top+1];
}

int stack::getTop()
{
	return top;
}

class stackInt
{
	float n[50];
	int top;
public:
	stackInt()
{
		top = -1;
}
	int getTop();
	bool push(float);
	float pop();
};

bool stackInt::push(float c)
{
	if(top == 49)
	{
		cout<<"\nStack Overflow!!!";
		return true;
	}
	top++;
	n[top] = c;
	return false;
}

float stackInt::pop()
{
	if(top == -1)	return 0;
	top--;
	return n[top+1];
}

int stackInt::getTop()
{
	return top;
}

int pres(char,char);
int cmp(char,char);
void toPost(char[], char[], int);
float eval(char[], int);
inline int next(char);

int main()
{
	char infix[30], postfix[30];
	float ev;

	cout<<"\nEnter expression without spaces : ";
	cin.getline(infix,29);

	toPost(infix,postfix,29);

	cout<<"\nThe postfix expression is : ";
	cout<<endl<<postfix<<endl;

	ev = eval(postfix,29);

	cout<<endl<<"The result is : "<<ev;

	return 0;
}

int pres(char curr, char top = 'x')
{
	if(curr == '(' || curr == '[' || curr == '{') return 1; //push
	if(curr == ')' || curr == ']' || curr == '}') return -1; //pop till
	if(top == '(' || top == '[' || top == '{')
	{
		if(curr == '-' || curr == '+' || curr == '*' || curr == '/') return 1;
		else return 2;
	}
	if(curr == '+' || curr == '-') return 0; //pop
	if(curr == '*' || curr == '/')
	{
		if(top == '+' || top == '-') return 1; //push
		else return 0;
	}
	return 2;
}

int cmp(char a, char b)
{
	if(a == '(' && b == ')') return 1;
	else if(a == '[' && b == ']') return 1;
	else if(a == '{' && b == '}') return 1;
	else return 0;
}

int next(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/') return 0;
	else return 1;
}

void toPost(char infix[], char res[], int n)
{
	stack s;
	char ch = '\0';
	int i = 0;
	int j = 0;
	int pre;

	while(infix[i])
	{
		if(s.getTop() == -1 && pres(infix[i]) == 2) pre = 2;
		else if(s.getTop() == -1) pre = 1;
		else{
			ch = s.pop();
			pre = pres(infix[i],ch);
		}

		switch(pre)
		{
		case 1 :if(ch != '\0')
				{
					s.push(ch);
					ch = '\0';
				}
				s.push(infix[i]);
				break;
		case 0 :res[j] = ch;
				ch = '\0';
				s.push(infix[i]);
				j++;
				break;
		case -1:while(!cmp(ch,infix[i]))
				{
					res[j] = ch;
					j++;
					ch = '\0';
					ch = s.pop();
				}
				ch = '\0';
				break;
		case 2 :res[j] = infix[i];
				if(ch != '\0')
				{
					s.push(ch);
					ch = '\0';
				}
				j++;
				break;
		}
		i++;
	}
	while(s.getTop() != -1)
	{
		ch = s.pop();
		res[j] = ch;
		j++;
	}
	res[j] = '\0';
}

float eval(char postfix[], int n)
{
	stackInt val;
	float var[20];
	int cnt = 0;
	int i = 0;
	float val1, val2, res;
	int used = 0;

	while(postfix[i])
	{
		if(postfix[i] != '+' && postfix[i] != '-'  && postfix[i] != '*'  && postfix[i] != '/') cnt++;
		i++;
	}

	cout<<"\nEnter value of all variables : ";
	for(i = 0; i < cnt; i++)
	{
		cin>>var[i];
	}

	i = 0;

	while(postfix[i])
	{
		if(next(postfix[i]))
		{
			val.push(var[used]);
			used++;
		}
		else
		{
			val2 = val.pop();
			val1 = val.pop();
			switch(postfix[i])
			{
			case'+':res = val1 + val2;
				break;
			case'-':res = val1 - val2;
				break;
			case'*':res = val1 * val2;
				break;
			case'/':res = val1 / val2;
				break;
			}
			val.push(res);
		}
		i++;
	}
	return(val.pop());
}


