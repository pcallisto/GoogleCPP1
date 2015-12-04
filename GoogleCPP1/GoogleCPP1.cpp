// GoogleCPP1.cpp : Defines the entry point for the console application.
//  https://developers.google.com/edu/c++/next-steps


#include "stdafx.h"
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>


using namespace std;


template <typename T> T digitCount(T arg ){
	int count = { 0 };
	for (int d = 1; d <= arg; d *= 10)
		count++;
	return count;
}
//-- for fans of Numerology
template <typename T> T numeralValue(T &arg) {
	int value = { 0 };
	stringstream str;
	str << arg; 
	if (str.str().length() == 1)
		return stoi(str.str());

	for (int d = 1; d <= digitCount(arg); d++) {
		value += stoi(str.str().substr(d - 1, 1)); // add 2
	}
	if (value > 9)
		value = numeralValue(value);

	return value;
}
template <typename T> T numeralValueFast(T &arg) {
	int value = arg % 9;
	return (value == 0) ? 9 : value;
}

void getUserInput(int& first, int& second) {
	string answer;
	cout << "Do Times Tables for " << first << "? " << endl;
	int start, to = {0};
	
	do {
		cout << "Enter Y to accept, or N to enter desired number: " << endl;
		cin >>  answer;
		if (answer == "Y" || answer == "y")
			return;
		cout << "Enter desired number or range in the form of 'from,to' : ";
		cin >> answer;
		int commaPos  = -1;
		commaPos = answer.find(','); // 34,123   =2
		if (commaPos != -1) {
			start = stoi(answer.substr(0, commaPos));
			to = stoi(answer.substr(commaPos+1, (answer.length()+1)-commaPos) )      ;
		}
		else {
			start = 1;
			to = stoi(answer);
		}
		if (start <= 4 && to == 0) {
			cout << "Seriously bro? " << start << " ? That's it, why bother." << endl;
			break;
		}
		else if (abs( start - to ) > 1000 ) {
				char response;
				cout << "Are you sure you want " << abs(start-to) << ", that will be a huge table?(type Y to continue)" << endl;
				cin >> response;
				if (toupper(response) == 'Y')
					break;
		}
		else {
			break;
		}
	} while (1);
	first = start;
	second = to;
}
void timesTablesToFile(int firstFactor) {
	ofstream outFile;
	stringstream stm1,stm2;
	int secondFactor = -1;
	int start, to = 0;
	getUserInput(firstFactor,secondFactor);
	char range[132];
	if (secondFactor != -1) { 
		// We are dealing with a range
		sprintf_s(range, "%d-%d", firstFactor, secondFactor);
		start = firstFactor;
		to = secondFactor;
	}
	else {
		sprintf_s(range, "%d", firstFactor);
		start = 1;
		to = firstFactor;
	}
	char fileName[132];
	sprintf_s(fileName, "TimesTables%s.txt", range);
	
	const int KdigitCount = digitCount( abs(start - to) );
	const int KcolumnWidth = KdigitCount * 2 + 1;
	outFile.open(fileName, ios::out);
	if (!outFile.is_open())	{
		cout << "FILEOPEN-E-CANTOPEN - Error encountered on opening file." << endl;
		return;
	}

	//stm1 is header1
	stm1 << std::setfill(' ') << std::setw(KdigitCount) << ' ';
	for (int a = start; a <= to; a++) {
		stm1 << std::right << std::setfill(' ') << std::setw(KcolumnWidth+2) << a;
	}
	stm1 << endl;
	//stm2 is header2
	stm2 << std::setfill(' ') << std::setw(KdigitCount + 2) << '-';
	for (int d = start; d <= to; d++)
		stm2 << std::right << std::setfill('-') << std::setw(KcolumnWidth+2) << '-';
	stm2 << endl;

	outFile << stm1.str();
	outFile << stm2.str();

	for (int c = start; c <= to; c++) {
		outFile << std::right << std::setfill(' ') << std::setw(KdigitCount) << c << "| ";
		int data = {0};
		for (int i = start; i <= to; i++) {
			data = i*c;
			outFile << std::right << std::setfill(' ') << std::setw(KcolumnWidth) << data << '|' << numeralValueFast(data);
		}
		outFile << endl;
	}
	outFile << stm2.str();
	outFile << stm1.str();
	cout << "Done. See file " << fileName << " for results." << endl;

	outFile.close();
}

int main()
{

	timesTablesToFile(15);

	
	return 0;
}

