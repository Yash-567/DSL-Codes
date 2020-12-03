//============================================================================
// Name        : assignment_3_sparse.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class sparse{
	int pos[10];
	struct sp
	{
	int r;
	int c;
	int v;
	}
	s[10];
	public:
	sparse()
	{
	s[0].r=0;
	s[0].c=0;
	s[0].v=0;
	}
	void create()
	{
	cout<<"No of rows & columns& elements"<<endl;
	cin>>s[0].r;
	cin>>s[0].c;
	cin>>s[0].v;
	for(int i=1;i<=s[0].v;i++)
	{
	cout<<"row & column & element"<<endl;
	cin>>s[i].r;
	cin>>s[i].c;
	cin>>s[i].v;
	}
	}
	sparse transpose(sparse s2){

		int value=s[0].v,k;
		int arr[value];
		s2.s[0].v=s[0].v;
		s2.s[0].c=s[0].r;
		s2.s[0].r=s[0].c;
		for(int i=0;i<=s[0].v;i++){
			arr[i]=0;
		}

		for(int i=1;i<=s[0].v;i++){
			k=s[i].c;
			arr[k]++;
		}
		cout<<arr[1]<<endl;
		cout<<arr[2]<<endl;
		arr[0]=0;
		cout<<"s1.c is "<<s[1].c<<endl;
		for(int i=0;i<=value;i++){
			pos[i]=0;
		}
		pos[1]=1;
		for(int i=2;i<=value;i++){
			pos[i]=pos[i-1]+arr[i-1];
		}
		for(int i=1;i<=s[0].v;i++){
			k=s[i].c;
			s2.s[pos[k]].r=s[i].c;
			s2.s[pos[k]].c=s[i].r;
			s2.s[pos[k]].v=s[i].v;
			pos[k]++;
		}
		cout<<s2.s[1].r<<endl;
		return s2;
	}
	void display()
	{
	cout<<"No of rows and columns and elements"<<endl;
	for(int i=0;i<=s[0].v;i++)
	{
	cout<<s[i].r<<"\t";
	cout<<s[i].c<<"\t";
	cout<<s[i].v<<endl;
	}
	}
	sparse operator +(sparse s2)
	{	sparse s3;
		if((s[0].r!=s2.s[0].r)||(s[0].c!=s2.s[0].c)){
			cout<<"Rows and columns of the 2 matrices should be same"<<endl;
		}else{
		cout<<"The addition of the 2 matrices is:"<<endl;
		int k=1;
		s3.s[0].r=s[0].r;
		s3.s[0].c=s[0].c;
		int i=1,j=1;
		while(i<=s[0].v || j<=s2.s[0].v)
		{
		if((s[i].r==s2.s[j].r)&&(s[i].c==s2.s[j].c))
		{
		s3.s[k].r=s[i].r;
		s3.s[k].c=s[i].c;
		s3.s[k].v=s[i].v+s2.s[j].v;
		i++; j++; k++;
		//cout<<"Now k is:"<<k;
		}
		else if((s[i].r!=s2.s[j].r)||(s[i].c!=s2.s[j].c)){
			if((s[i].r<s2.s[j].r)||((s[i].r==s2.s[j].r)&&(s[i].c<s2.s[j].c))){
				s3.s[k].r=s[i].r;
				s3.s[k].c=s[i].c;
				s3.s[k].v=s[i].v;
				i++;k++;
			}if((s[i].r>s2.s[j].r)||((s[i].r==s2.s[j].r)&&(s[i].c>s2.s[j].c))){
				s3.s[k].r=s2.s[j].r;
				s3.s[k].c=s2.s[j].c;
				s3.s[k].v=s2.s[j].v;
				j++;k++;
			}
		}
		}
		cout<<k-1;
		s3.s[0].v=k-1;
		return s3;
		}

	}
};
int main()
{	char i;
	int n;
	sparse s1,s2,s3;
	do{
		cout<<"Press 1 for addition of 2 sparse "<<endl;
		cout<<"Enter 2 for transpose of a matrix"<<endl;
		cin>>n;
		switch(n){
		case 1:
			s1.create();
			s2.create();
			s3=s1+s2;
			s3.display();
			break;
		case 2:
			cout<<"Enter the matrix you want to see the transpose of."<<endl;
			s1.create();
			s3=s1.transpose(s2);
			s3.display();
		}
		cout<<"Do you want to continue?"<<endl;
		cin>>i;
	}while(i='y'||'Y');

	//s1.display();
	//s2.display();

	return 0;
}
