//============================================================================
// Name        : assignment_2.cpp
// Author      : Yash Sonar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class matrix {
	int add_a[10][10],add_b[10][10],add_c[10][10],sum=0,col,row,row1,col1,row2,col2,flag,g[10],r[10],c[10],low,t1,t2;
public:
	int degree;
	matrix(){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				add_a[i][j]=0;
				add_b[i][j]=0;
				add_c[i][j]=0;
				g[j]=0;
				r[j]=0;
				c[j]=0;
			}
		}
	}
	void input(){
		cout<<"Enter the degree of matrix and two matrices";
		cin>>degree;
		for(int i=0;i<degree;i++){
			for(int j=0;j<degree;j++){
				cin>>add_a[i][j];
			}
		}
		for(int i=0;i<degree;i++){
			for(int j=0;j<degree;j++){
				cin>>add_b[i][j];
			}
		}

	}
	void input_s(){
			cout<<"Enter the degree of matrix and the matrices";
			cin>>degree;
			for(int i=0;i<degree;i++){
				for(int j=0;j<degree;j++){
					cin>>add_a[i][j];
				}
			}
	}
	void diag(){
		for(int i=0;i<degree;i++){
			for (int j=0;j<degree;j++){
				if(i==j) {
					sum = sum+add_a[i][j];
				}
			}
		}
		cout<<sum<<endl;
	}
	void add(){
		for(int i=0;i<degree;i++){
			for(int j=0;j<degree;j++){
				add_c[i][j] = add_a[i][j]+add_b[i][j];
			}
		}
		for(int i=0;i<degree;i++){
			for(int j=0;j<degree;j++){
				cout<<add_c[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	void sub(){
		for(int i=0;i<degree;i++){
					for(int j=0;j<degree;j++){
						add_c[i][j] = add_a[i][j]-add_b[i][j];
					}
				}
				for(int i=0;i<degree;i++){
					for(int j=0;j<degree;j++){
						cout<<add_c[i][j]<<"\t";
					}
					cout<<endl;
				}
	}
	void input_m(){
		cout<<"Enter order of matrix 1";
		cin>>row1>>col1;
		cout<<"Enter order of matrix 2";
		cin>>row2>>col2;
		for(int i=0;i<row1;i++){
			for(int j=0;j<col1;j++){
				cin>>add_a[i][j];
			}
		}
		for(int i=0;i<row2;i++){
			for(int j=0;j<col2;j++){
				cin>>add_b[i][j];
			}
		}
	}
	void mul(){
		if(col1!=row2){
			cout<<"The order of the matrix is not suitable for multiplication";
		}else{
			int prod_r = row1;
			int prod_c = col2;
			for(int i=0;i<prod_r;i++){
				for(int j=0;j<prod_c;j++){
					add_c[i][j]=0;
					for(int k=0;k<row2;k++){
						add_c[i][j] += add_a[i][k]*add_b[k][j];
					}
				}
			}
			for(int i=0;i<row1;i++){
				for(int j=0;j<col2;j++){
					cout<<add_c[i][j]<<"\t";
				}
				cout<<endl;
			}
		}

	}
	void input_t(){
		cout<<"Enter the number of rows";
		cin>>row;
		cout<<"Enter the number of columns";
		cin>>col;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>add_a[i][j];
				add_b[j][i] = add_a[i][j];
			}
		}
	}
	void print_t(){
		for(int i=0;i<col;i++){
			for(int j=0;j<row;j++){
			    cout<<add_b[i][j]<<"\t";
			}
				cout<<endl;
		}
	}
	void upper_t(){
		flag=0;
		cout<<"Enter the degree of the matrix";
		cin>>degree;
		cout<<"Enter the matrix";
		for(int i=0;i<degree;i++){
			for(int j=0;j<degree;j++){
				cin>>add_a[i][j];
				if(i>j&&add_a[i][j]==0){
					flag++;
				}
			}
		}
		if(flag==(degree*degree-degree)/2){
			cout<<"Upper Triangular matrix verified";
		}else{
			cout<<"Test failed";
		}
	}
	void saddle(){
		flag=0;
		cout<<"Enter order of matrix";
		cin>>row;
		cin>>col;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				cin>>add_a[i][j];
			}
		}
		for(int j=0;j<col;j++){
			for(int i=0;i<row;i++){
				if(g[j]<add_a[i][j]){
					g[j]=add_a[i][j];
					r[j]=i;
					c[j]=j;
				}
			}
		}

		for(int j=0;j<col;j++){
			flag = 0;
			int i = r[j];
			low=g[j];
			for(int k=0;k<col;k++){
				if(low>add_a[i][k]){
					flag =1;
				}
			}
			if(flag == 1){
				cout<<"greatest element of column "<<j<<" is not a saddle point"<<endl;
			}else if(flag == 0){
				cout<<"The greatest element of column "<<j<<" is a saddle point with a value "<<g[j]<<endl;
			}
		}
	}
};
int main() {
	int i;
	cout<<"1 for adding matrix"<<endl;
	cout<<"2 for subtracting matrix"<<endl;
	cout<<"3 for multiplying matrix"<<endl;
	cout<<"4 for checking upper triangular matrix"<<endl;
	cout<<"5 for adding diagonal elements"<<endl;
	cout<<"6 for computing transpose of matrix"<<endl;
	cout<<"7 for checking saddle point of matrix"<<endl;
	cin>>i;
	matrix m;
	switch(i){
		case 1:
			m.input();
			m.add();
			main();
			break;
		case 2:
			m.input();
			m.sub();
			main();
			break;
		case 3:
			m.input_m();
			m.mul();
			main();
			break;
		case 4:
			m.upper_t();
			main();
			break;
		case 5:
			m.input_s();
			m.diag();
			main();
			break;
		case 6:
			m.input_t();
			m.print_t();
			main();
			break;
		case 7:
			m.saddle();
			main();
			break;
		default:
			cout<<"Invalid Input";

	}
}
