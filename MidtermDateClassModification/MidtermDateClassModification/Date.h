//Mickie Blair
//Midterm Project
//Date Class Specification File

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

//date class declaration
class Date
{
private:
	int month;			//integer variable for month
	int day;			//integer variable for day
	int year;			//integer variable for year

public:
	//Exception Class
	class InvalidInput{};

	//constructors
	Date();
	Date(int, int, int);
	Date(Date*);

	//determine month name static method
	static string determineMonthName(int);

	//setters
	void setMonth(int);
	void setDay(int);
	void setYear(int);

	//getters
	int getMonth();
	int getDay();
	int getYear();
	
	//operator overloads
	bool operator < (const Date&);
	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	int operator-(const Date&);

	//friends
	friend ostream& operator<<(ostream&, const Date&);
	friend istream& operator>>(istream&, Date&);
};

#endif

