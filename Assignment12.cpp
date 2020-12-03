//============================================================================
// Name        : assignment12.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class student{
	int rollNo[40],num;

public:
	void getData(){
		cout<<"How many students you want to enter?"<<endl;
		cin>>num;
		for(int i=0;i<num;i++){
			cout<<"Roll No:"<<endl;
			cin>>rollNo[i];
		}
		cout<<"Student data stored!\n";
	}
	void swap(int *xp, int *yp)  {
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	void selectionSort(int arr[], int n){
		int i, j, min_idx;


		for (i = 0; i < n-1; i++)
		{

			min_idx = i;
			for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

			swap(&arr[min_idx], &arr[i]);
		}
	}
	void passSelection(){
		selectionSort(rollNo, num);
	}
	void bubbleSort(){
		int temp;
		for(int i=0;i<num;i++){
			for(int j=0;j<num-1;j++){
				if(rollNo[j]>rollNo[j+1]){
					temp = rollNo[j];
					rollNo[j]=rollNo[j+1];
					rollNo[j+1]=temp;
				}
			}
		}
	}
	void display(){
		cout<<"The top 5 scores are\n";
		for(int i=0;i<5;i++){
			cout<<i+1<<" "<<rollNo[num-1-i]<<endl;
		}
	}
};

int main() {
	student s;
	int choice;
	cout<<"Sort Algorithm\n\n";
	cout<<"Press 1 for selection sort\n";
	cout<<"Press 2 for bubble sort\n";
	cin>>choice;
	switch(choice){
	case 1:
		s.getData();
		s.passSelection();
		s.display();
		break;
	case 2:
		s.getData();
		s.bubbleSort();
		s.display();
		break;
	}


	return 0;
}
