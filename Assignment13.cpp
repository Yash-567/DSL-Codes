//============================================================================
// Name        : assignment13.cpp
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
		cout<<"How many students do you want to enter?\n";
		cin>>num;
		for(int i=0;i<num;i++){
			cout<<"Roll No:\n";
			cin>>rollNo[i];
		}
		cout<<"Student data stored!!"<<endl;
	}
	void swap(int* a, int* b)
	{
	    int t = *a;
	    *a = *b;
	    *b = t;
	}

	int partition (int arr[], int low, int high)
	{
	    int pivot = arr[high];
	    int i = (low - 1);

	    for (int j = low; j <= high - 1; j++)
	    {
	        if (arr[j] < pivot)
	        {
	            i++;
	            swap(&arr[i], &arr[j]);
	        }
	    }
	    swap(&arr[i + 1], &arr[high]);
	    return (i + 1);
	}

	void quickSort(int arr[], int low, int high)
	{
	    if (low < high)
	    {

	        int pi = partition(arr, low, high);
	        quickSort(arr, low, pi - 1);
	        quickSort(arr, pi + 1, high);
	    }
	}
	void passQuick(){
		quickSort(rollNo,0,num-1);
	}
	void display(){
		cout<<"------------------------------------------------------------------------------------\n";
		cout<<"The top 5 scores are\n";
		for(int i=0;i<5;i++){
			cout<<i+1<<" "<<rollNo[num-1-i]<<endl;
		}
	}
};

int main() {
	cout<<"Welcome to Student Data Center!"<<endl;
	cout<<"--------------------------------------------------------------------------------------\n";
	student s;
	s.getData();
	s.passQuick();
	s.display();
	return 0;
}
