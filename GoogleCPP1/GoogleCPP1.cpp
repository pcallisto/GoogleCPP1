// GoogleCPP1.cpp : Defines the entry point for the console application.
//  https://developers.google.com/edu/c++/next-steps

/*
The integer 36 has a peculiar property: it is a perfect square, and is also 
the sum of the integers from 1 through 8. The next such number is 1225 which is 35(2), 
and the sum of the integers from 1 through 49. Find the next number that is a 
perfect square and also the sum of a series 1...n. This next number may be 
greater than 32767. You may use library functions that you know of, (or mathematical 
formulas) to make your program run faster. It is also possible to write this program 
using for-loops to determine if a number is a perfect square or a sum of a series. 
(Note: depending on your machine and your program, it can take quite a while to find this number.)
*/

#include "stdafx.h"
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>


using namespace std;


void ptrPlay() {
	int *ptr;  // create a pointer to nowhere
			   // it's a promise make it point to something in the future;
	int *ptr2, *ptr3, *ptr4;
	ptr = new int;   // now it points to a new int variable on the heap
	int x = 0;          // x is on the stack
	*ptr = 5;

	cout << "intptr's heap address: " << ptr << " and this is the valued stored there: " << *ptr << endl;
	cout << "x's stack address: " << &x << " and this is the valued stored there: " << x << endl;
	cout << "ptr gets ++'d to: " << ++*ptr << endl;
	cout << "x gets ++'d to: " << ++x << endl;

	ptr2 = ptr;
	ptr3 = ptr;
	ptr4 = ptr;
	cout << "ptr2 gets ++'d, and this is ptr's value: " << ++*ptr2 << " : " << *ptr << endl;
	cout << "ptr3 gets ++'d, and this is ptr's value: " << ++*ptr3 << " : " << *ptr << endl;
	cout << "ptr4 gets ++'d, and this is ptr's value: " << ++*ptr4 << " : " << *ptr << endl;
	cout << "ptr  gets ++'d, and this is ptr's value: " << ++*ptr << " : " << *ptr << endl;
	cout << "this is their 5 addesses on the heap: " << ptr << ", " << ptr2 << ", " << ptr3 << ", " << ptr4 << endl;
}

void Duplicate(int& a, int& b, int& c) {
	a *= 2;
	b *= 2;
	c *= 2;
}

void DoIt(int &foo, int goo);
void DoIt(int &foo, int goo) {
	foo = goo + 3;
	goo = foo + 4;
	foo = goo + 3;
	goo = foo;
}

void accelerate(int& speed, int amount) {
	speed += amount;
	amount = 0;
}

void joshinWithPointers() {
	int x = 1, y = 3, z = 7;
	Duplicate(x, y, z);
	// The following outputs: x=2, y=6, z=14.
	cout << "x=" << x << ", y=" << y << ", z=" << z << endl;

	int *foo, *goo;
	foo = new int;
	*foo = 1;
	goo = new int;
	*goo = 3;
	*foo = *goo + 3;
	foo = goo;
	*goo = 5;
	*foo = *goo + *foo;
	DoIt(*foo, *goo);
	cout << (*foo) << endl;

	int speed = 100;
	int amount = 10;
	accelerate(speed, amount);
	cout << "Sped up by " << amount << " to reach a speed of " << speed << endl;
}

class Time {
private:
	int hours_;
	int minutes_;
	int seconds_;
public:
	void set(int h, int m, int s) { hours_ = h; minutes_ = m; seconds_ = s; return; }
	void increment();
	void decrement();
	void display();
};
void Time::increment() {
	seconds_++;
	minutes_ += seconds_ / 60;
	hours_ += minutes_ / 60;
	seconds_ %= 60;
	minutes_ %= 60;
	hours_ %= 24;
	return;
}
void Time::decrement() {
	seconds_--;
	if (seconds_ == -1) {
		seconds_ = 59;
		minutes_--;
	}
	if (minutes_ == -1) {
		minutes_ = 59;
		hours_--;
	}
	if (hours_ == -1) {
		hours_ = 24;
	}
	return;
}
void Time::display() {
	cout << (hours_ % 12 ? hours_ % 12 : 12) << ':'
		<< (minutes_ < 10 ? "0" : "") << minutes_ << ':'
		<< (seconds_ < 10 ? "0" : "") << seconds_
		<< (hours_ < 12 ? " AM" : " PM") << endl;
}
void timeForwardAndBack() {
	Time timer;
	timer.set(23, 59, 58);
	cout << "Elevator going up..." << endl;
	timer.display();
	cout << endl;
	for (int i = 0; i < 5; i++) {
		timer.increment();
		timer.display();
		cout << endl;
	}

	cout << "Elevator going down..." << endl;
	timer.set(12, 00, 01);
	timer.display();
	cout << endl;
	for (int i = 0; i < 5; i++) {
		timer.decrement();
		timer.display();
		cout << endl;
	}
}

bool doesItAddUp(double& square, float fx, float fi) {
	double sumOAF = 0;
	for (double j = 0; j <= square; ++j) {
		sumOAF += j;
		if (sumOAF == fi) {
			cout << "Eureka! We've found one: " << sumOAF << " j: " << j << " fx: " << fx << endl;
			return true;
		}
	}
	return false;
}
void findSquaresThatAddUp() {
	const int startingPoint = 1;
	int x = startingPoint;
	for (float fi = 0.0; fi < 3000000.0; ++fi) {
		float fx = sqrtf(fi);
		if ((int)(fx * 1000) % 1000 == 0.0) {
			double square = (double)fi;
			doesItAddUp(square, fx, fi);
		}
	}       // we found them at 36(6,1..8) 1225(35,1..49) 41616(204,1..288) 374545(612,1..865) 1.41372E06(1189,1..2258)
}
template <typename T> T digitCount(T arg ){
	int count = { 0 };
	for (int d = 1; d <= arg; d *= 10)
		count++;
	return count;
}
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
void getUserInput(int& factor) {
	string answer;
	cout << "Do Times Tables for " << factor << "? " << endl;
	int tmp = { 0 };
	do {
		cout << "Enter Y to accept, or N to enter desired number: " << endl;
		cin >>  answer;
		if (answer == "Y" || answer == "y")
			return;
		cout << "Enter desired number:";
		cin >> tmp;
		if (tmp <= 3) {
			cout << "Seriously bro? " << tmp << " ?";
			break;
		}
		else if (tmp > 1000) {
				char response;
				cout << "Are you sure you want " << tmp << ", that will be a huge table?(type Y to continue)" << endl;
				cin >> response;
				if (toupper(response) == 'Y')
					break;
		}
		else {
			break;
		}
	} while (1);
	factor = tmp;
}
void timesTablesToFile(int maxFactor) {
	ofstream outFile;
	stringstream stm1,stm2;

	getUserInput(maxFactor);
	char fileName[132];
	sprintf_s(fileName, "TimesTables%d.txt", maxFactor,sizeof(fileName));
	
	const int KdigitCount = digitCount(maxFactor);
	const int KcolumnWidth = KdigitCount * 2 + 1;
	outFile.open(fileName, ios::out);
	if (!outFile.is_open())	{
		cout << "FILEOPEN-E-CANTOPEN - Error encountered on opening file." << endl;
		return;
	}

	//stm1 is header1
	stm1 << std::setfill(' ') << std::setw(KdigitCount) << ' ';
	for (int a = 1; a <= maxFactor; a++) {
		stm1 << std::right << std::setfill(' ') << std::setw(KcolumnWidth+2) << a;
	}
	stm1 << endl;
	//stm2 is header2
	stm2 << std::setfill(' ') << std::setw(KdigitCount + 2) << '-';
	for (int d = 1; d <= maxFactor; d++)
		stm2 << std::right << std::setfill('-') << std::setw(KcolumnWidth+2) << '-';
	stm2 << endl;

	outFile << stm1.str();
	outFile << stm2.str();

	for (int c = 1; c <= maxFactor; c++) {
		outFile << std::right << std::setfill(' ') << std::setw(KdigitCount) << c << "| ";
		int data = {0};
		for (int i = 1; i <= maxFactor; i++) {
			data = i*c;
			outFile << std::right << std::setfill(' ') << std::setw(KcolumnWidth) << data << '|' << numeralValue(data);
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

	timesTablesToFile(12);
//  findSquaresThatAddUp();
//	timeForwardAndBack();
//	joshinWithPointers();
//  ptrPlay();

	int x555;
	cin >> x555;
    return 0;
}

