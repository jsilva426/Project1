﻿// BloodSugarProject 1.cpp 
// Jacob Silva
// Project 1
//COSC 2030


#include "stdafx.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <String>
using std::string;
using std::getline;
#include "LinkedList.h"
#include "BloodSugarFunctions.h"



int main()
{
	cout << "BloodSugar Values" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Directions: " << endl << "1) Type D or Day for daily summary" << endl;
	cout << "2) Type W or Week for weekly summary" << endl;
	cout << "3) Type N or Next to move on to the next day" << endl;
	cout << "4) Type DONE to end the program" << endl;
	cout << "----------------------------------------------------------------------------------------------" << endl;
	
	int day= 0; //keeps track of day the user is on
	List days[14];
	
	string input;
	double inBuf;
	bool finished = false;
	
	
	cout << "Monday" << endl << "------------------------------------------------------------------------------------" << endl;
	while (!finished)
	{
	
		cout << "Please enter a blood sugar : " << endl;
		getline(cin, input);
		inBuf = strtof((input).c_str(), 0);
		if (!cin.good())
		{

			cin.clear();
			cin.ignore();
		}
		 if (input == "DONE")
		{
			finished = true;

		}
		if (inBuf > 0)
		{
			days[day].insertAsFirst(inBuf);

		}
		if ((input == "D")||(input=="Day"))
		{
			daySummary(days[day]);
		}
		if ((input == "N") || (input == "Next"))
		{
			day = day + 1;
			cout << Day(day) << endl << "------------------------------------------------------------------------------------"<<endl;
		}
		if ((input == "W") || (input == "Week"))
		{
			weekSummary(days, day);
		}

	
	}
	return 0;
}
