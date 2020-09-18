//Mickie Blair
//Midterm Project
//Date Class Demo Program

#include "Prototypes.h"
#include "Date.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <new>

using namespace std;

//main function
int main() {
	try 
	{
		//repeat the program
		repeatProgram();

		//display complete message
		cout << "Program run complete.\n";

	}
	catch (bad_alloc)
	{
		cout << "Insufficient Memory.\n";
	}
	

	return 0;

}

//show Intro
void showIntro() {
	string key;
	//display introduction
	cout << "Date Class with Modifications\n" << endl;
	cout << "The user will be asked to enter a date using the\n"
		<< "overloaded cin stream extraction operator (>>).\n\n"
		<< "The program will demonstrate the following:\n\n"
		<< " - overloaded subtraction (-) operator for calculating the\n"
		<< "   the number of days between two dates.\n"
		<< " - overloaded increment operator (++) prefix and postfix\n"
		<< " - overloaded decrement operator (--) prefix and postfix.\n\n"
		<< "The results will be displayed using an overloaded\n"
		<< "cout stream insertion operator (<<).\n\n" 
		<< "The program will implement exceptions and input validation.\n" << endl;
			
}

//repeat Program
void repeatProgram() {

	string again;					//variable for again loop 

	//do while loop
	do
	{
		//display introduction
		showIntro();

		//repeat menu
		repeatMenu();
		
		//ask user if they would like to go again
		cout << "Would you like to run the program again? (Enter Y or N) ";
		getline(cin, again);

		//validate entry
		while (again != "Y" && again != "N" && again != "y" && again != "n")
		{
			cout << "\nInvalid entry:" << endl;
			cout << "Would you like to run the program again? (Enter Y or N) ";
			getline(cin, again);
		}

		cout << endl;

		//clear
		system("CLS");
	}

	while (again == "Y" || again == "y");
}

//repeat Menu
void repeatMenu() {

	string again;					//variable for again loop 

	//do while loop
	do
	{
		//demonstrate the month class with overloads
		dateClass();

		//ask user if they would like to choose from the menu again
		cout << "\nWould you like to choose from the menu again? (Enter Y or N) ";
		getline(cin, again);

		//validate entry
		while (again != "Y" && again != "N" && again != "y" && again != "n")
		{
			cout << "\nInvalid entry:" << endl;
			cout << "Would you like to choose from the menu again? (Enter Y or N) ";
			getline(cin, again);
		}

		//clear the screen
		system("CLS");
	}

	while (again == "Y" || again == "y");

	

}

void dateClass() {
	
	int option;		//char for option
		
		//get menu option
		option = getMenuOption();

		//switch menu
		switch (option)
		{
			case 1:
				{
					//calculate days
					calculateDays();

					break;
				}
				
			case 2:
				{
					//increment operator
					demoIncrementOperator();
					break;
				}
				
			case 3:
				{
					//demonstrate decrement
					demoDecrementOperator();

					break;
				}	
		}
}

//get menu options with input validation
int getMenuOption()
{
	string input;		// string for input

	cout << "Menu Options\n\n"
		<< "1. Calculate Days Between Dates (- operator)\n"
		<< "2. Demonstrate Prefix and PostFix Increment Operator (++)\n"
		<< "3. Demonstrate Prefix and PostFix Decrement Operator (--)\n"
		<< endl;

	cout << "Please Enter a Menu Option: ";
	getline(cin, input);

	while (input != "1" && input != "2" && input != "3")
	{
		cout << "\nInvalid entry:\n" << endl;
		cout << "1. Calculate Days Between Dates (- operator)\n"
			<< "2. Demonstrate Prefix and PostFix Increment Operator (++)\n"
			<< "3. Demonstrate Prefix and PostFix Decrement Operator (--)\n"
			<< endl;
		cout << "Please Enter a Menu Option: (Enter 1, 2, 3) ";
		getline(cin, input);
	}

	//clear the screen
	system("CLS");

	//return choices as an integer
	return stoi(input);
}

//calculate days
void calculateDays() {
	Date date1;		//date object to hold date 1
	Date date2;		//date object to hold date 2
	
	//header
	cout << "Days Between Dates\n" << endl;
	//ask user for two dates
	cout << "Please enter two dates to calculate the days between.\n\n";
	cin >> date1;

	cout << endl;

	cin >> date2;

	//display results	
	cout << "\nDays between " << date1 << " and " << date2
		 << ":  " << date1 - date2 << endl;
	
}

//demonstrate ++ operator (prefix and post fix)
void demoIncrementOperator() {
	int times;		// integer for times to increment

    //create default month object
	Date overloadedCin;

	//header
	cout << "Demonstration of Prefix And Postfix Increment Operator (++)\n\n";
	
	//ask user for a number
	cout << "How many times would you like to increment the date?\n\n";
	times = getNumberOfTimes();
	
	cout << endl;
	//ask user for a date
	cin >> overloadedCin;

	//set dates to new variables
	Date preInc = overloadedCin;
	Date postInc = overloadedCin;

	//preincrement
	cout << "\nThe date " << preInc << " will be incremented " << times << " times using ++date." << endl;
	
	//loop through number of times
	for (int index = 0; index < times; index++)
	{
		cout  << ++preInc << endl;
	}
	
	//post increment
	cout << "\nThe date " << postInc << " will be incremented " << times << " times using date++." << endl;
	
	//loop through number of times
	for (int index = 0; index < times; index++)
	{
		cout << postInc++ << endl;
	}
}

//demonstrate ++ operator (prefix and post fix)
void demoDecrementOperator() {
	int times;		// integer for times to increment
	
	//create default month object
	Date overloadedCin;

	//header
	cout << "Demonstration of Prefix And Postfix Increment Operator (--)\n\n";

	//ask user for a number
	cout << "How many times would you like to decrement the date?\n\n";
	times = getNumberOfTimes();

	cout << endl;
	//ask user for a date
	cin >> overloadedCin;

	//set dates to new variables
	Date preDe = overloadedCin;
	Date postDe = overloadedCin;

	//preincrement
	cout << "\nThe date " << preDe << " will be decremented " << times << " times using --date." << endl;

	//loop through number of times
	for (int index = 0; index < times; index++)
	{
		cout << --preDe << endl;
	}

	//post increment
	cout << "\nThe date " << postDe << " will be decremented " << times << " times using date--." << endl;

	//loop through number of times
	for (int index = 0; index < times; index++)
	{
		cout << postDe-- << endl;
	}
}

int getNumberOfTimes() {
	string input;			//variable for string input from user
	int num;				//variable for times
	bool isValid = false;	//boolean for valid input from user
	
	//input validation
	while (!isValid)
	{

		cout << "Enter a whole positive number: ";

		getline(cin, input);

		//try catch - catches illegal argument, out of range, and Invalid input
		try
		{
			for (int index = 0; index < int(input.length()); index++)
			{
				if (!isdigit(input[index]))
					throw InvalidInput();
			}

			//try to convert to integer
			num = (stoi(input));

			//check for positive and greater than one
			if (num <= 0)
			{
				throw InvalidInput();
			}

			isValid = true;

		}

		catch (invalid_argument)
		{
			isValid = false;
			cout << "\nInvalid Entry. Input must be whole numbers only.\n" << endl;
		}

		catch (out_of_range)
		{
			isValid = false;
			cout << "\nNumber is too large, please enter a smaller number.\n" << endl;
		}


		catch (InvalidInput)
		{
			isValid = false;
			cout << "\nInput must be whole numbers only and greater than 0.\n" << endl;
		}

	}

	//return number
	return num;
}