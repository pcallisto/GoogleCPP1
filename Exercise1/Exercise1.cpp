// Exercise1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

/*-----------------------------------------------------------------------------
The integer 36 has a peculiar property: it is a perfect square, and is also
the sum of the integers from 1 through 8. The next such number is 1225 which is 35(2),
and the sum of the integers from 1 through 49. Find the next number that is a
perfect square and also the sum of a series 1...n. This next number may be
greater than 32767. You may use library functions that you know of, (or mathematical
formulas) to make your program run faster. It is also possible to write this program
using for-loops to determine if a number is a perfect square or a sum of a series.
(Note: depending on your machine and your program, it can take quite a while to find this number.)
*/
bool doesItAddUp(double& square, double x, double i) {
	double sumOAF = 0;
	for (double j = 0; j <= square; ++j) {
		sumOAF += j;
		if (sumOAF == i) {
			cout << "Eureka! We've found one: " << sumOAF << " j: " << j << " x: " << x << endl;
			return true;
		}
	}
	return false;
}
void findSquaresThatAddUp(double limit) {
	const int startingPoint = 1;
	int x = startingPoint;
	for (float i = 0.0; i < limit; ++i) {
		float x = sqrtf(i);
		if ((int)(x * 1000) % 1000 == 0.0) {
			double square = (double)i;
			doesItAddUp(square, x, i);
		}
	}       // we found them at 36(6,1..8) 1225(35,1..49) 41616(204,1..288) 374545(612,1..865) 1.41372E06(1189,1..2258)
}


int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Missing arguments!" << endl;
        return 1;
    }
    int option = stoi(argv[1]);
	switch (option) {
	case 1:
	{
		double limit = stod(argv[2]);
		findSquaresThatAddUp(limit);
		break;
	}
	case 2:
		timeForwardAndBack();
		break;
	case 3:
		joshinWithPointers();
		break;
	case 4:
		ptrPlay();
		break;
	default:
		cout << "Goodbye!" << endl;
		break;
	}

    return 0;
}

