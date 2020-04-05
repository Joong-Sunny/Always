//============================================================================
// Name        : Lab5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class record{
public:
	record (double aa);
	void input(string x);
	void check_score();
	void setquiz();
	void setmid();
	void setfinal();
	void setave();

	double getquiz();
	double getmid();
	double getfinal();
	double getave();

private:
	double score;
	double quiz_score;
	double midterm_score;
	double final_score;
	double average_score;

};

record::record(double aa){		//making a constructor to initialize the aa, which will be using as 0
	score = aa;
	quiz_score = aa;
	midterm_score = aa;
	final_score = aa;
	average_score =aa;
}

void record::input(string x)
{
	cout << "Enter the score of "<<x;
	cin	>>	score;
}

void record::setquiz(){					////set
	quiz_score = score;					////set
}										////set
void record::setmid(){					////set
	midterm_score = score;				////set
}										////set
void record::setfinal(){				////set
	final_score = score;				////set
}										////set
void record::setave(){					////set
	average_score = quiz_score*1.25 + midterm_score*0.25 + final_score*0.5;
}

double record::getquiz(){				////get
	return quiz_score;
}
double record::getmid(){				////get
	return midterm_score;
}
double record::getfinal(){				////get
	return final_score;
}
double record::getave(){				////get
	return average_score;
}


void task1(){
	record student1(0);
	string z;
	z= "total Quiz (X/20)";
		student1.input(z);
		student1.setquiz();

	z= "Midterm exam (X/100)";
		student1.input(z);
		student1.setmid();

	z= "Final exam (X/100)";
		student1.input(z);
		student1.setfinal();
		student1.setave();

	double y = student1.getave();
	cout << "The total weighted score of student1 is: "<<y<<endl;
	cout<< "Task 1 is done!!!"<<endl;
}

//task1 is done/////////////////////////////////////////////////////////////////////
class CounterType {

private:

    int count;
    int counter = 0;

public:

    CounterType() { count = 0; }
    CounterType(int c) { count = c; }

    void increseCounter();
    int decreaseCount();
    int getCount();
    int getCounter();
    void print_c(ostream &cout);

};
int CounterType::getCount(){return count;}
int CounterType::getCounter(){return counter;}
void CounterType::print_c(ostream&cout){
    cout << "Count : " << getCount() << "\n";
    cout << "Counter : " << getCounter() << "\n\n";
}
int CounterType::decreaseCount(){
    if (count == 0)
        {return 0;}
    count--;
    return 1;}
void CounterType::increseCounter(){
	counter++;
}

void task2() {

    int value;
    cout << "Enter Number: ";
    cin >> value;

    CounterType c(value);

    while (1) {
        c.print_c(cout);
        c.increseCounter();
        int t = c.decreaseCount();
        if (!t) {
            break;
        }
    }
}

int main() {
	task1();
	task2();
	return 0;
}

/*
Result
*********************************************************************Task1
Enter the score of total Quiz (X/20)18.73
Enter the score of Midterm exam (X/100)95
Enter the score of Final exam (X/100)77
The total weighted score of student1 is: 85.6625
Task 1 is done!!!

*********************************************************************Task2
Enter Number: 4
Count : 4
Counter : 0

Count : 3
Counter : 1

Count : 2
Counter : 2

Count : 1
Counter : 3

Count : 0
Counter : 4
 */

















