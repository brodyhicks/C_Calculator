/*
Filename: ITT-310 C Calculator program
Author: Brody Hicks
Date: 4/8/2022
Version: 3.0
Purpose for release: THis release of the C calulator will allow the defining the use of a union and structure that will 
defined and display the version of the calculator, as well as a character string as my name being the developer. In addition
the structure will be used as a record for storing and displaying today's current date for day, month and year and display
it to the console at the top as a header introduction.
*/
#include <stdlib.h>
#include <stdio.h> // Main C library preprocessor header file
#define _CRT_SECURE_NO_WARNINGS //The use of secure versions for library functions
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <Windows.h> 

void calc(); // Define my modularity for the user-defined function

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds);
}

void calc() //Main function start of the program
{ 
	delay(2);
	system("cls");
	union Data { //Union to display general data information for the version and a defined character string to be displayed
		float version;
		char name[100];
	};

	// A typedef data structure called date to display the current month, day and year as an official date of the program as a header description  
	typedef struct
	{
		int month; //Defined the month integer
		int day; //Defined day integer
		int year; //Defined year integers
	}Date; //Name of the structure
	// A typedef stucture to display the time both hours and minutes inputted
	typedef struct 
	{
		int hour; //Define the hours
		int minute;//Define the minute
	}time;//Time is the name of the structure to be called

	//Create an instance of the date today and the time for the two structures
	Date today;
	time now;

	//Populate the Date Structure with the integers for the month, day and year specified as 04/8/2022
	today.month = 04;
	today.day = 8;
	today.year = 2022;
	//Populate the time structure with the specfied integers for the inputted time for the hour and minutes as 5:09 pm
	now.hour = 5;
	now.minute = 9;

	union Data data; //Call the union for data
	data.version = 1.03; //Define the union data version to be displayed
	printf("version : %1.2f\n", data.version); //Print the Version as 1.03

	strcpy_s(data.name, sizeof data.name, "Brody Rantz Hicks"); //Copy the character string to be my name as the developer
	printf("Developed by : %s\n", data.name); //displays the character string as my full name Brody Rantz Hicks
	strcpy_s(data.name, sizeof data.name, "Welcome to the best calculator for students to learn math operations!!!"); //Copythe data string as 
	//the welcome to the calculator
	printf("General info:  %s\n", data.name); //Display the character string as the welcome banner to the calculator

	// Print the contents of the Data Structure as the full date today, as well as the time
	printf("The date today is %i/%i/%.2i.\n", today.month, today.day, today.year % 100);
	printf("The time this was made was %01d:%02d pm\n\n",now.hour, now.minute % 100);
	
	int a, b, choice;//Declaring integer variables and data types, as well as choice for decision
	int c[10], i;
	int s = 0;

	{ // While loop used for trying again once the program is complete

		printf("Please enter your first number: \n"); //Asks user to input first integer and sets to memory
		scanf_s("%d", &a);
		if (a == 0) {
			printf("Thats boring, pick something other then 0, jeeeez haha!!\n");
			printf("This is an invalid choice!!You can't do any math with 0\n");
			calc();
		}
		printf("Please enter your second number: \n"); //Asks user for second number and sets to memory
		scanf_s("%d", &b);

		if (b == 0) {
			printf("Thats boring, pick something other then 0, jeeeez haha!!\n");
			printf("This is an invalid choice!!You can't do any math with 0\n");
			calc();
		}
		printf("\nMultiply(1), Divide(2), Subract(3), Add(4), Sum(5):  \n"); //Prompts user to choose an operator to perform calculation
		// with the addition of the arrary for the sum of 10 numbers
		scanf_s("%d", &choice);

		if (choice > 5) {
			printf("This is an invalid choice!!Must input a value between 1-5\n");
			calc();
		}
		switch (choice) //decision switch choice
		{
		case(1):
			printf("\n%d * %d = %d\n", a, b, (a * b)); //Will multiply the 2 numbers inputted
			break;
		case(2):
			printf("\n%d / %d = %d\n", a, b, (a / b));//Will divide 2 numbers inputted
			break;
		case(3):
			printf("\n%d - %d = %d\n", a, b, (a - b)); //Will subtract 2 numbers inputted
			break;
		case(4):
			printf("\n%d + %d = %d\n", a, b, (a + b)); //Will add 2 numbers inputted
			break;
		case(5):
			for (i = 0; i < 10; i++) { // For loop for the array starting at 0, with incremental inputs of 10 digits to do the sum
				printf("\nEnter a number"); //Enter 10 digits incrementally
				scanf_s("%d", &c[i]); //Store digits from the array as integers
				s = s + c[i]; //Perform the mathematical sum operation of all 10 integers
			}
			printf("\nSum = %d", s); //Display the sum as "Sum =     "
		default:
			printf("Please input a valid choice from the list\n");

		}
	
	}
}
// Main function for the program for the execution and calling of the defined function for the calculator
int main() {
	//Define my loop variable set to 1
	int d = 1;
	calc(); // Call the user-defined function
	printf("\nGreat Job!! I hoped you enjoyed and got the anwser you were looking for!!!\n");
	while (d == 1) { // While loop for the recursive operation for the user to restart the program
		printf("\nWould you like to try again (1 for yes, all other numbers for No):  \n");
		scanf_s("%d", &d);
		if (d == 1) { // If user inputs #1 1 the program will restart, else the program will end.
			calc(); //If selected 1, recall the user-defined function 
		}
	}
	return 0; //Else, the program will end
}