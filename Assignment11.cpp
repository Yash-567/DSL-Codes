//============================================================================
// Name        : Assignment11.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
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
	bool linearSearch(int search){
		for(int i=0;i<num;i++){
			if(rollNo[i]==search){
				return true;
			}
		}
		return false;
	}
	void sentinelSearch(int search){
		int last = rollNo[num-1];
		rollNo[num-1] = search;    // Here item is the search element.
		int i = 0;
		while(rollNo[i]!=search)
		{
		    i++;
		}
		rollNo[num-1] = last;
		if( (i < num-1) || (search == rollNo[num-1]) )
		{
		    cout << "Item Found at position "<<i<<endl;
		}
		else
		{
		    cout << "Item Not Found\n";
		}
	}
	int binarySearch(int arr[], int l, int r, int x)
	{
	    if (r >= l) {
	        int mid = l + (r - l) / 2;

	        // If the element is present at the middle
	        // itself
	        if (arr[mid] == x)
	            return mid;

	        // If element is smaller than mid, then
	        // it can only be present in left subarray
	        if (arr[mid] > x)
	            return binarySearch(arr, l, mid - 1, x);

	        // Else the element can only be present
	        // in right subarray
	        return binarySearch(arr, mid + 1, r, x);
	    }

	    // We reach here when element is not
	    // present in array
	    return -1;
	}
	int fibonacciSearch(int arr[], int x, int n)
	{
	    int fibMMm2 = 0;
	    int fibMMm1 = 1;
	    int fibM = fibMMm2 + fibMMm1;

	    while (fibM < n)
	    {
	        fibMMm2 = fibMMm1;
	        fibMMm1 = fibM;
	        fibM  = fibMMm2 + fibMMm1;
	    }


	    int offset = -1;

	    while (fibM > 1)
	    {
	        int i = min(offset+fibMMm2, n-1);

	        if (arr[i] < x)
	        {
	            fibM  = fibMMm1;
	            fibMMm1 = fibMMm2;
	            fibMMm2 = fibM - fibMMm1;
	            offset = i;
	        }

	        else if (arr[i] > x)
	        {
	            fibM  = fibMMm2;
	            fibMMm1 = fibMMm1 - fibMMm2;
	            fibMMm2 = fibM - fibMMm1;
	        }

	        else return i;
	    }

	    /* comparing the last element with x */
	    if(fibMMm1 && arr[offset+1]==x)return offset+1;

	    /*element not found. return -1 */
	    return -1;
	}
	void display(){
		for(int i=0;i<num;i++){
			cout<<"Roll No:";
			cout<<rollNo[i]<<endl;
		}
	}
	void startBinSearch(int search){
		int result = binarySearch(rollNo, 0, num - 1, search);
		(result==-1)?cout<<"Entry not found\n":cout<<"Entry found!\n";
	}
	void startFibonacciSearch(int search){
		int result = fibonacciSearch(rollNo,search,num - 1);
		(result==-1)?cout<<"Entry not found\n":cout<<"Entry found!\n";
	}
};

int main() {
	student s;
	int roll;
	char ans;
	do{
		cout<<"Search Algorithm\n";
		int choice;
		cout<<"Press 1 for linear search\n";
		cout<<"Press 2 for sentinel search\n";
		cout<<"Press 3 for binary search\n";
		cout<<"Press 4 for fibonacci search\n";
		cin>>choice;
		switch(choice){
		case 1:
			s.getData();
			cout<<"Which number do you want to search for?\n";
			cin>>roll;
			if(s.linearSearch(roll)){
				cout<<"Entry found!\n";
			}else{
				cout<<"No entry found\n";
			}
			break;
		case 2:
			s.getData();
			cout<<"Which number do you want to search for?\n";
			cin>>roll;
			s.sentinelSearch(roll);
			break;
		case 3:
			s.getData();
			cout<<"Which number do you want to search for?\n";
			cin>>roll;
			s.startBinSearch(roll);
			break;
		case 4:
			s.getData();
			cout<<"Which number do you want to search for?\n";
			cin>>roll;
			s.startFibonacciSearch(roll);
			break;
		default:
			cout<<"Invalid choice\n";
		}
		cout<<"Do you want to make another search?(y or n)\n";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
	return 0;
}
