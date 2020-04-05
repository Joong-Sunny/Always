//============================================================================
// Name        : Lab4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <list>
using namespace std;

bool Iswhitespace(char ch)
{
	return (ch==' ' or ch =='\t' or ch=='\r' or ch=='\n');
}


void task1() {
	cout<<"...task1 begin.........................."<<endl;
	int length;
	char nstr[200];
	int j=0;
	bool IsInitial = true;
	bool IsFirstblank = false;



	char str[400] = "  noW  iS   thE    TiMe  fOr  aLl\n"
			"         gOOD MEN TO  ComE TO   tHe\n"
			"  		aId\n"
			"oF\n"
			"\n"
			"\n"
			"   ThE  CounTRY.\n";
	length = strlen(str);

	for(int i=0; i<length; i++)										//condition
	{
		if(Iswhitespace(str[i])){

			if(IsInitial){
				continue;
			}
			if(IsFirstblank==false){
				nstr[j]=' ';
				j++;
				IsFirstblank = true;

			}
		}
		else{
			if(IsInitial){

				IsInitial=false;
			}
			IsFirstblank=false;
			nstr[j]= tolower(str[i]);
			j++;
			}
	}

	nstr[j] = '\0';
	nstr[0] = toupper(nstr[0]);

	cout<<"String was..."<<endl
			<<"******************************"<<endl		//output
			<<str <<endl
			<<"******************************"<< endl;
	cout<<"Make it better!"<<endl
			<<"******************************"<<endl
			<<nstr <<endl
			<<"******************************"<< endl;		//output end
	cout <<"task1 is done...";
}


bool IsAlphabet(char ch){
	if (('a'<=ch and 'z'>=ch)or ('A'<=ch and 'Z'>=ch))
	{
		return true;
	}
	else {
		return false;
	}
}


void task2() {
	cout<<"task 2 begin"<<endl;
	cout << "Enter you sentence" <<endl;
	string str1;
	getline(cin,str1);
	int length;
	cout << str1<<endl<<endl;
	char str [300];
	int arr[300];
	strcpy(str,str1.c_str());
	length = strlen(str);



	for (int i=0; i<length ; i++){
		if (IsAlphabet(str[i])){			//detecting alphabet
			arr[i]=1;
		}
		else{
			arr[i]=0;
		}
		}
	for (int i=0; i<length ; i++){
		if (str[i]=='h' or str[i]=='H'){			//detecting H or h=2
			arr[i]=2;
		}
		else if (str[i]=='e'){						//detecting e=3
			arr[i]=3;
		}
		else if (str[i]=='i'){						//detecting i=4
			arr[i]=4;
		}
		else if (str[i]=='m'){						//detecting	m =5
			arr[i]=5;
		}
		else if (str[i]=='s'){						//detecting=6
			arr[i]=6;
		}
		else if (str[i]=='r'){						//detecting=7
			arr[i]=7;
		}
	}
arr[length]=0;
	for (int i=0; i<length; i++){
		if (arr[i]==0){
		if (arr[i+1]==2){
			if (arr[i+2]==3){
				if (arr[i+3]==0){//case: he
					str[i+1]=0;
					str[i+2]=0;
					arr[i+2]=11;
				}
				else if (arr[i+3]==7){
					if(arr[i+4]==0){
						//case: her
						str[i+1]=0;
						str[i+2]=0;
						str[i+3]=0;
						arr[i+3]=12;
					}
				}
			}
			else if (arr[i+2]==4){
				if (arr[i+3]==5){
					if(arr[i+4]==0){//case him
						str[i+1]=0;
						str[i+2]=0;
						str[i+3]=0;
						arr[i+3]=13;
					}
				}
				else if (arr[i+3]==6){//case his
					if(arr[i+4]==0){
						str[i+1]=0;
						str[i+2]=0;
						str[i+3]=0;
						arr[i+3]=14;
						}

				}
			}
		}
		else if (arr[i+1]==6 and arr[i+2]==2 and arr[i+3]==3 and arr[i+4]==0){
			str[i+1]=0;
			str[i+2]=0;
			str[i+3]=0;
			arr[i+3]=15; //case her
		}
	}
	}

if (arr[0]==2){
	if (arr[1]==3 and arr[2]==0){ //he
		str[0]=0;
		str[1]=0;
		arr[1]=11;
	}
	else if (arr[1]==3 and arr[2]==7 and arr[3]==0){
		str[0]=0; //her
		str[1]=0;
		str[2]=0;
		arr[1]=12;
	}
	else if (arr[1]==4 and arr[2]==5 and arr[3]==0){
		str[0]=0;
		str[1]=0;
		str[2]=0;
		arr[1]=13;						//him
	}
	else if (arr[1]==4 and arr[2]==6 and arr[3]==0){
		str[0]=0;
		str[1]=0;
		str[2]=0;
		arr[1]=14;						//his
	}
}
else if (arr[0]==6 and arr[1]==2 and arr[2]==3){		//she
	str[0]=0;
	str[1]=0;
	str[2]=0;
	arr[1]=15;
}


for(int i=0; i< length; i++){
if (str[i]!=0){
	cout<<str[i];}

if(arr[i]==11){
	cout<<"she or he";
}
else if(arr[i]==12){
	cout<<"her or him";
}
else if(arr[i]==13){
	cout<<"her or him";
}
else if(arr[i]==14){
	cout<<"her(s) or his";
}
else if(arr[i]==15){
	cout<<"she or he";
}
}

	cout<<endl<<"task 2 is done"<<endl;
}








int main() {
	task1();
	task2();
	return 0;
}
