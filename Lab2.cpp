//============================================================================
// Name        : Lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

int add(int A, int B){

	return A+B;
}

double add(double A, double B){

	return A+B;
}

void add(char A, char B){

	cout << A << B << endl;
}




/////////////////////////////////////////////////////



double Best_score (double array[2][8],int a){
	double best=0;
	int i;
	for(i=0; i<5;i++){
		if (array[a][i]> best){
			best=array[a][i];
		}
	}
	return best;
}

double Worst_score(double array[2][8],int a){
	double worst=1000;
	int i;
	for(i=0; i<5;i++){
		if (array[a][i]< worst){
			worst=array[a][i];
		}
	}
	return worst;
}

double Sum(double array[2][8],int a){
	double sum=0;
	int i;
	for (i=0; i<5; i++){
		sum=sum+array[a][i];
	}
	return sum;

}

int main() {
	//EX1//////////////////////////////////////////////////
	int y;
		cout <<"What is your input?" << endl;
		cout << "Int => type 1, Floating number => type 2, Charicter => type 3" << endl;
		cin >> y;
		if (y == 1) {
			int a;
			int b;
			cout <<"input the values" << endl;
			cin >> a ;
			cin >> b;
			int c=add(a,b);
			cout << c ;
		}
		else if (y ==2) {
			double a;
			double b;
			cout << "Input the values" << endl;
			cin >> a;
			cin >> b;
			double c=add(a,b);
			cout << c;
		}
		else {
			cout << "Input your Charicters" << endl;
			char a;
			char b;
			cin >> a;
			cin >> b;
			add(a,b);
		}
//////////////////////////////////////////////////////////////////////


	//Ex2
		int ARRAY_SIZE= 100;
			char ch;
			char array[ARRAY_SIZE];
			int size=0;
			cout <<"Input your character: OOOOOO. " << endl;
			cin >> ch;
			while (ch != '.'){
				if(size <= ARRAY_SIZE)
					{
					array[size]=ch;
					size ++;
					cin>>ch;
					}
				else {
					cout <<" Hey!!!!!!!!!!Too long"<< endl;
					break;
				}
			}
			for (int i= size-1; i>=0; i--)
			{
				cout << array[i];
			}

//////////////////////////////////////////////////////////////////////////



	//ex3

	double val[2][8];
	cout << "Put your HW score: " << endl;
	for (int i=0; i<5; i++) {
		cin >> val[0][i];
	}
	cout << "Put your lab score: " << endl;
	for (int i=0; i<5; i++) {
			cin >> val[1][i];
	}

	val[0][5]= Best_score(val,0);
	val[0][6]= Worst_score(val,0);
	val[0][7]= Sum(val,0)/5;
	val[1][5]= Best_score(val,1);
	val[1][6]= Worst_score(val,1);
	val[1][7]= Sum(val,1)/5;

		cout<<"	1	2	3	4	5	Best	Worst	Avg"<<endl;
	cout<<"*************************************************************************"<<endl;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout<<"HW	";
	for (int j=0; j<8; j++) {
		cout << val[0][j]<< "	";
		}


	cout<< endl << "LAB	";
	for (int j=0; j<8; j++){
		cout<< val[1][j]<< "	";
		}

	cout<< endl <<"AVG	" << (val[0][0]+val[1][0])/2 <<"	"<<(val[0][1]+val[1][1])/2 << "	"<<(val[0][2]+val[1][2])/2 << "	"<< (val[0][3]+val[1][3])/2<< "	"<<(val[0][4]+val[1][4])/2 << "	"<<(val[0][5]+val[1][5])/2;
	cout<< " overall " << (val[0][7]+val[1][7])/2;
	if (val[0][7] >= 50 && val[1][7]>=50){
		cout<<endl<<"Congratulations! You passed the class!";
	}
	else {
		cout<<endl<<"I`m sorry....you failed...your performance in <";
				if (val[0][7]<50){
					cout <<" HW ";
				}
				if (val[1][7]<50){
					cout << " LAB ";
				}

		cout<<"> was <50%....";
	}
}



/*
 * Lab #1 Ex1
What is your input?
Int => type 1, Floating number => type 2, Charicter => type 3
2
Input the values
3.25
2.77
6.02
 * Lab #2 Ex2
Input your character: OOOOOO.
AAAABCDEFEFESZ.
ZSEFEFEDCBAAAA

* Lab #3 Ex3
Put your HW score:
100
0
51
0
100
Put your lab score:
34
98
47
36
24
	1	2	3	4	5	Best	Worst	Avg
*************************************************************************
HW	100.00	0.00	51.00	0.00	100.00	100.00	0.00	50.20
LAB	34.00	98.00	47.00	36.00	24.00	98.00	24.00	47.80
I`m sorry....you failed...your performance in < LAB > was <50%....



*/











