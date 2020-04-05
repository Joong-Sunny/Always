//============================================================================
// Name        : Lab3t2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
using namespace std;

int task1() {
	ifstream READREAD;
	ofstream WRITEWRITE;

	READREAD.open("LabInput3-1.txt");				//opening the file as name READREAD
	WRITEWRITE.open("LabOutput3-1.txt");			//opening the file as name WRITEWRITE (to write the file)
	char storage[100];
	string s= "";
 if(READREAD.fail())								//check if file opened correctly
 {
	cout << "File has not opened correctly!!";
	exit(1);
 }
 else{

	 int i=0;
	 while(!READREAD.eof())
	 {
		READREAD.get(storage[i]);
		storage[i] = toupper(storage[i]);
		s=s+storage[i];
		i++;
	 }
	 }
 s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end()); // this library function eliminates white space(copy from google)
 cout << s<<endl;
 WRITEWRITE << s;  //String goes in to outsourced text file

 READREAD.close();
 WRITEWRITE.close();
 cout<< endl <<"/////Task 1 is done!!/////" << endl;
 return 0;
}
//////////////task1 is done////////////////

//task2, if user selects the 1) option
bool readFromKeyboard(int inputArray[], int&size) {
	cout << "enter your number, enter '7777' to finish your statement"<<endl;
			int num = 0;
	size = 0;
	while(true){
		cin>>num;
		if(num == 7777){
			break;
		}
		inputArray[size] = num;
	}
	return true;
}
//task2, if user selects the 2) option
bool readFromFile(int inputArray[], int&size){
	char fname[50];

	cout << "Please enter a file name: ";
	cin >> fname;

	ifstream ifs;

	ifs.open(fname);
	if(ifs.fail()){
		cout<< "File has not opened correctly!!";
		return false;
	}
	size = 0;
	while (!ifs.eof()){
		ifs >> inputArray[size];
		size++;

	}
	return true;
}
void countArray(int inputArray[], int size) {
	int uniqueArray[50];
	int countArray[50];
	bool found = false;

	for (int i = 0; i < 50; i++) {
		uniqueArray[i] = 0;
		countArray[i] = 0;
	}

	// Sort the inputArray, from largest to the smallest
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (inputArray[i] < inputArray[j]) {
				// Swap the two
				int temp = inputArray[j];
				inputArray[j] = inputArray[i];
				inputArray[i] = temp;
			}
		}
	}

	int index = 0;
	for (int i = 0; i < size; i++) {
		found = false;
		for (index = 0; uniqueArray[index] != 0; index++) {
			if (inputArray[i] == uniqueArray[index]) {
				countArray[index]++;
				found = true;
				break;
			}
		}

		if (!found) {
			index = 0;
			while (countArray[index++] != 0) {
			};


			uniqueArray[index - 1] = inputArray[i];
			countArray[index - 1]++;
		}
	}

	// Print the output
	cout << setw(6) << "N" << setw(6) << "Count" << endl;
	for (int i = 0; i < size && countArray[i] != 0; i++) {
		cout << setw(6) << uniqueArray[i];
		cout << setw(6) << countArray[i];
		cout << endl;
	}
}
void SelectionSort(int inputArray[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (inputArray[i] > inputArray[j]) {
				// Swap the two
				int temp = inputArray[j];
				inputArray[j] = inputArray[i];
				inputArray[i] = temp;
			}
		}
	}

}

int task2(){

	int select;
	int inputArray[50];
	int size;
	cout<< "Select your choice"<<endl;
	cout<<"1)keyboard"<<endl << "2) file" << endl <<"3) Nope?"<<endl;  //select which one to use?
	cin >> select;
	cout << "your selection is" << select << endl; 				//checking selection

	if (select==1){
		readFromKeyboard(inputArray,size);		//receiving array
		countArray(inputArray, size);			//sorting and counting
	}
	else if(select==2){
		if(readFromFile(inputArray,size)==true){	//receiving array(from file)
			countArray(inputArray, size);			//sorting and counting
		}
	}
	else if(select==3){								//case that user does not want to do anything
		cout<< "Bye~" << endl;

	}
	else{
		cout << "What the...." << endl;
	}
	cout<< "//////Task 2 is done/////"<<endl;
	return 0;
}


int task3() {
	using namespace std;
	ifstream AA;				//1st inputstream
	ifstream BB;				//second stream
	int READING[50];

		AA.open("LabInput3-3.txt");
		if(AA.fail()){
			cout<< "File has not opened correctly!"<<endl;}
		BB.open("LabInput3-4.txt");
		if(BB.fail()){
			cout<< "File has not opened correctly!"<<endl;}
		int size = 0;
		while (AA >>READING[size++]){

		}
		size -=1;
		while (BB >> READING[size++]){

		}
		size -=1;

		SelectionSort(READING, size);

		for(int i = 0; i<size; i++)
		{
			cout << READING[i]<< " ";
		}
		cout << endl<<endl <<"/////task3 is done!!/////";
		return 0;
}


int main(){					//Yes, here is main
	task1();
	task2();
	task3();
}
