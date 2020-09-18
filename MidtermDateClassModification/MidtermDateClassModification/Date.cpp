//Mickie Blair
//Midterm Project
//Date Class Implementation File

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;


//default no args constructor
Date::Date()
{
	month = 1;
	day = 1;
	year = 1900;
}

//constructor
Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

//copy constructor
Date::Date(Date* obj) 
{
	month = obj->month;
	day = obj->day;
	year = obj->year;
}

//static function to determine Month Name
string Date::determineMonthName(int num)
{
	string name;	//variable to hold month name

	//switch for month name using int month
	switch (num)
	{
		case 1:
		{
			name = "January";
			break;
		}
		case 2:
		{
			name = "February";
			break;
		}
		case 3:
		{
			name = "March";
			break;
		}
		case 4:
		{
			name = "April";
			break;
		}
		case 5:
		{
			name = "May";
			break;
		}
		case 6:
		{
			name = "June";
			break;
		}
		case 7:
		{
			name = "July";
			break;
		}
		case 8:
		{
			name = "August";
			break;
		}
		case 9:
		{
			name = "September";
			break;
		}
		case 10:
		{
			name = "October";
			break;
		}
		case 11:
		{
			name = "November";
			break;
		}
		case 12:
		{
			name = "December";
			break;
		}
	}

	return name;
}

//setters which throw invalid input if value out of range
void Date::setMonth(int m)
{
	if (m < 1 || m > 12)
		{
			cout << "\nMonth is invalid.\n" << endl;
			throw InvalidInput();
		}
	else
		{
			month = m;
		}
		
}

void Date::setDay(int d)
{
	switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (d < 1 || d > 31)
			{
				cout << "\nDay must be between 1 and 31 for " << determineMonthName(month)
					<< ".\n" << endl;
				throw InvalidInput();
			}

			else
			{
				day = d;
			}
		break;
		}
		
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (d < 1 || d > 30)
			{
				cout << "\nDay must be between 1 and 30 for " << determineMonthName(month)
					<< ".\n" << endl;
				throw InvalidInput();
			}

			else
			{
				day = d;
			}
		break;
		}
		
		
		case 2:
		{
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			{
				if (d < 1 || d > 29)
				{
					cout << "\nFor a Leap Year, February's days must be between 1 and 29.\n" << endl;
					throw InvalidInput();
				}

				else
				{
					day = d;
				}
			}

			else
			{
				if (d < 1 || d > 28)
				{
					cout << "\nFor a Non-Leap Year, February's days must be between 1 and 28.\n" << endl;
					throw InvalidInput();
				}

				else
				{
					day = d;
				}
			}
		break;
		}
	}
}

void Date::setYear(int y)
{
	if (y < 0)
		{
			cout << "\nYear must only contain numbers.\n\n";
			throw InvalidInput();
		}
	else
		{
			year = y;
		}

}

//getters
int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

//less than operator overload for date
bool Date::operator<(const Date& right)
{
	bool isLessThan = false;

	if (year < right.year)
		{
			isLessThan = true;
		}
	else if (year == right.year)
		{
			if (month< right.month)
				{
					isLessThan = true;
				}

			else if (month == right.month)
			{
				if (day< right.day)
				{
					isLessThan = true;
				}
			}
		}

	return isLessThan;
}

//Overloaded prefix ++ operator
Date Date::operator++()
{
	++day;
	
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			{
				if (day == 32)
				{
					day = 1;
					month++;
				}
			break;
			}
			
		case 4:
		case 6:
		case 9:
		case 11:
			{
				if (day == 31)
				{
					day = 1;
					month++;
				}
			break;
			}
			
		case 12:
			{
				if (day == 32)
				{
					day = 1;
					month= 1;
					year++;
				}
			break;
			}
			
		case 2:
			{
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				{
					if (day == 30)
						{
							day = 1;
							month++;
						}
				}
					
			else
				{
					if (day == 29)
						{
							day = 1;
							month++;
						}
				}
			break;		
			}
	}

	return *this;
}

//Overloaded postfix ++ operator
Date Date::operator++(int)
{
	Date temp(month, day, year);

	day++;

	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		{
			if (day == 32)
			{
				day = 1;
				month++;
			}
		break;
		}
		
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (day == 31)
			{
				day = 1;
				month++;
			}
		break;
		}
		
		case 12:
		{
			if (day == 32)
			{
				day = 1;
				month = 1;
				year++;
			}
		break;
		}
		
		case 2:
		{
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			{
				if (day == 30)
				{
					day = 1;
					month++;
				}
			}

			else
			{
				if (day == 29)
				{
					day = 1;
					month++;
				}
			}
		break;
		}

	}

	return temp;
}

//Overloaded prefix -- operator
Date Date::operator--()
{
	--day;

	switch (month)
	{
		case 1:
			{
				if (day == 0)
				{
					day = 31;
					month = 12;
					year--;
				}
			break;
			}
			
		case 3:
			{
				if (day == 0)
				{
					month--;

					if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
					{
					
							day = 29;
					}

					else
					{
						day = 28;
					}
				}
			break;
			}
			
		case 5:
		case 7:
		case 10:
		case 12:
			{
				if (day == 0)
				{
					day = 30;
					month--;
				}
			break;
			}
			
		case 2:
		case 8:
		case 4:
		case 6:
		case 9:
		case 11:
			{
				if (day == 0)
				{
					day = 31;
					month--;
				}
			break;
			}
	}

	return *this;
}

//Overloaded postfix -- operator
Date Date::operator--(int)
{
	Date temp(month, day, year);

	--day;

	switch (month)
	{
		case 1:
		{
			if (day == 0)
			{
				day = 31;
				month = 12;
				year--;
			}
		break;
		}
	
		case 3:
		{
			if (day == 0)
			{
				month--;

				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				{

					day = 29;
				}

				else
				{
					day = 28;
				}
			}
		break;
		}
	
		case 5:
		case 7:
		case 10:
		case 12:
		{
			if (day == 0)
			{
				day = 30;
				month--;
			}
		break;
		}
	
		case 2:
		case 8:
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (day == 0)
			{
				day = 31;
				month--;
			}
		break;
		}
	
	}

	return temp;
}

//overloaded - operator
int Date::operator-(const Date& secondDate)
{	
	//declared start and end date
	Date start;
	Date end;

	//declare days difference accumulator
	int daysDiff = 0;

	//set the start and end date
	if (*this < secondDate)
		{
			start = *this;
			end = secondDate;
		}
	else
		{
			start = secondDate;
			end = *this;
		}

	//increment the day and the days difference while the start day
	// is less than the end day
	while (start < end) {
		start++;
		daysDiff++;
	}

	//return days difference
	return daysDiff;
}

//overload the cout's <<
ostream& operator<<(ostream& strm, const Date& obj)
{
	//create strm of month (using static determineMonthName), day and year
	strm << Date::determineMonthName(obj.month) << " "
		 <<  obj.day << ", " << obj.year;

	return strm;
}

//overload the cin's >>
istream& operator >> (istream& strm, Date& obj)
{
	string input;			//variable for string input from user
	bool isValid = false;	//boolean for valid input from user
	string mm;				//string of month only
	string dd;				//string of day only
	string yyyy;			//string of year only
	int m;					//month after converting to integer
	int d;					//day after converting to integer
	int y;					//year after converting to integer
	
	//input validation
	while (!isValid)
	{
		cout << "Enter date (ex. 01/01/2018): ";

		getline(cin, input);

		try
			{
				//check format of input
				if (input.length() != 10 || input[2] != '/' && (input[5] != '/'))
					 
					{
						//if not valid display message and throw invalid input
						cout << "\nDate Format is Invalid. (Valid Format: mm/dd/yyyy)\n" << endl;
						throw Date::InvalidInput();
					}

				else
					{
						//assign substrings of input to individual string variables
						mm.assign(input, 0, 2);
						dd.assign(input, 3, 2);
						yyyy.assign(input, 6, 4);

						//check for integers only
						for (int index = 0; index < int(mm.length()); index++)
						{
							if (!isdigit(mm[index]))
							{
								cout << "\nMonth must be numbers only.\n" << endl;
								throw Date::InvalidInput();
							}
						}

						for (int index = 0; index < int(dd.length()); index++)
						{
							if (!isdigit(dd[index]))
							{
								cout << "\nDay must be numbers only.\n" << endl;
								throw Date::InvalidInput();
							}
						}

						for (int index = 0; index < int(yyyy.length()); index++)
						{
							if (!isdigit(yyyy[index]))
							{
								cout << "\nYear must be numbers only.\n" << endl;
								throw Date::InvalidInput();
							}
						}

						//convert to int can throw an illegal_argument exception
						y = (stoi(yyyy));
						obj.setYear(y);

						m = (stoi(mm));
						obj.setMonth(m);

						d = (stoi(dd));
						obj.setDay(d);

						isValid = true;
					}
			}

		catch (invalid_argument)
			{
				//if caught change isValid to false and display message
				isValid = false;
				cout << "\nInvalid Date Format. Date must be numbers separated by /.\n" << endl;
			}

		catch (Date::InvalidInput)
			{
				//if caught change isValid to false(specific message supplied by setters)
				isValid = false;
			}

	}

	return strm;
}
