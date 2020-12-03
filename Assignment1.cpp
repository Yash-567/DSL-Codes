//============================================================================
// Name        : STUD_MARK.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include<string>
using namespace std;
class student{
	int n,max=0,min,abs=0,k,b,flag,t=0,m,a=0;
	float stud[30],temp=0,freq[30][2];
	string names[30],absentees[30];

public:
	student(){
		freq[0][0]=stud[0];
		freq[0][1]=1;
		k=1;
	}

	void input_n(){
		cout<<"Enter the number of students";
		cin>>n;

	}

	void input_m(){
		cout<<"Enter the name and marks of "<<n<<" students and enter -1 for absent";
		for(int i=0;i<n;i++){
			cin>>names[i];
			cin>>stud[i];
		}
	}
	void average(){
		for(int i=0;i<n;i++){
			if(stud[i]>0){
				temp+=stud[i];
			}else{
				continue;
			}
		}
		float average = temp/n;
		cout<<"The average marks are"<<average<<endl;
	}
	void max_f(){
		for(int i=0;i<n;i++){
			if(stud[i]>0){
				if(max<stud[i]){
					max=stud[i];
				}
			}
			else{
				continue;
			}
		}
		cout<<"The max marks in the class are "<<max<<endl;
	}
	void min_f(){
		min = stud[0];
			for(int i=0;i<n;i++){
				if(stud[i]>0){
					if(min>stud[i]){
						min=stud[i];
					}
				}
				else{
					continue;
				}
			}
			cout<<"The min marks in the class are "<<min<<endl;
		}
	void absent(){
		for(int i=0;i<n;i++){
			if(stud[i]==-1){
				abs+=1;
			}else{
				continue;
			}
		}
		cout<<"The number of absent students is "<<abs<<endl;

	}
	void absent_r(){
		for(int i=0;i<n;i++){
			if(stud[i]==-1){
				absentees[a] = names[i];
				a++;
			}
		}
	}
	void display_a(){
		cout<<"The names of absent students are \t ";
		for(int i=0;i<a;i++){
			cout<<absentees[i]<<"\t";
		}
		cout<<endl;
	}
	void mode(){
		freq[0][0] = stud[0];
		freq[0][1] = 1;
		k=1;
		for(int i=1;i<n;i++){
			b=stud[i];
			flag=0;
			for(int j=0;j<k;j++){
				if(freq[j][0]==b){
					freq[j][1]=freq[j][1]+1;
					flag=1;
				}

			}
				if(flag==0){
					freq[k][0]=b;
					freq[k][1]=1;
					k++;
				}
		}
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(freq[i][1]<freq[i+1][1]){
					t=freq[i][1];
					freq[i][1] = freq[i+1][1];
					freq[i+1][1]=t;
					t=freq[i][0];
					freq[i][0] = freq[i+1][0];
					freq[i+1][0]=t;
				}
			}
		}

		cout<<"Maximum number of students have got marks "<<freq[0][0]<<endl;
	}


};
int main() {
	student s;
	s.input_n();
	s.input_m();
	s.average();
	s.max_f();
	s.min_f();
	s.absent();
	s.absent_r();
	s.display_a();
	s.mode();
	return 0;
}
