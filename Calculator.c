/*
Filename: ITT-310 C Calculator Final program
Author: Brody Hicks
Date: 4/22/2022
Version: 4.0
Purpose for release: This is the final release in developing a command-interface C Calculator. The purpose of this program is to incorporate the use of File I/O in which copies files from one file
to another, in addition to performing the mathematical computation for addition, subtraction, multiplication, division and the sum of 10 numbers. The beggining with provide a introduction to
the program with the developers name, date, time and a general informational description to the calculator!!!
*/

//Preprocessor header files for the compiler execution 
#include <stdlib.h>
#include <stdio.h> // Main C library preprocessor header  //The use of secure versions for library functions
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS //Use for security in the deprecation of functions and variables

void calc(); // Define my modularity for the user-defined function

//User-function for the use of a delay time before clearing the screen
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
	delay(2); //Time delay for system clear screen
	system("cls"); //Call for system clear screen for restart
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
		//If loop for error-handlings and compiler correction for invalid user-input
		if (a == 0) {
			printf("Thats boring, pick something other then 0, jeeeez haha!!\n");
			printf("This is an invalid choice!!You can't do any math with 0\n");
			calc(); //Restarts the program at the top
		}
		printf("Please enter your second number: \n"); //Asks user for second number and sets to memory
		scanf_s("%d", &b);
		//If loop for error-handlings and compiler correction for invalid user-input
		if (b == 0) {
			printf("Thats boring, pick something other then 0, jeeeez haha!!\n");
			printf("This is an invalid choice!!You can't do any math with 0\n");
			calc();
		}
		printf("\nMultiply(1), Divide(2), Subract(3), Add(4), Sum(5):  \n"); //Prompts user to choose an operator to perform calculation
		// with the addition of the arrary for the sum of 10 numbers
		scanf_s("%d", &choice);
		//If loop for error-handlings and compiler correction for invalid user-input for the choice selection for math solutions
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
//User function to perform the copying of the input to output test files with a string
void copy_files(FILE* in, FILE* out)
{
	int c; //Declare the integer C

	//Copy all the characters from the input file to the output file
	while ((c = getc(in)) != EOF)
		putc(c, out);
}

// Main function for the program for the execution and calling of the defined function for the calculator
int main(int argc, char* argv[]) {
//Define my loop variable set to 1
	int d = 1;
	calc(); // Call the user-defined function

	FILE* in, * out; //Input/output file pointers
	errno_t err; //Declare error and debugging scenarios for test cases

	//Check for program input arguments: Program name, input filename and output filename
	if (argc != 3)
	{
		fprintf(stderr, "Please enter two file names.\n");
		return 1;
	}

	//Open input file for reading
	if ((err = fopen_s(&in, argv[1], "r")) != 0)
	{
		fprintf(stderr, "Can't read from input file %s.\n", argv[1]);
		return 2;
	}

	//Open output file for writing
	if ((err = fopen_s(&out, argv[2], "w")) != 0)
	{
		fprintf(stderr, "Can't write to output file %s.\n", argv[2]);
		return 3;
	}

	//Copy all the characters from the input file to the output file
	copy_files(in, out);
	printf("File has been copied.\n");

	//Cleanup and close all the open files
	fclose(in);
	fclose(out);

	while (d == 1) { // While loop for the recursive operation for the user to restart the program
		printf("\nWould you like to try again (1 for yes, all other numbers for No):  \n");
		scanf_s("%d", &d);
		if (d == 1) { // If user inputs #1 1 the program will restart, else the program will end.
			calc(); //If selected 1, recall the user-defined function 
		}
	}
	return 0; //Else, the program will end
}