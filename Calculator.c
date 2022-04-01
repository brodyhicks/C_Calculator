/*
Filename: ITT-310 C Calculator
Author: Brody Hicks
Date: 4/1/2022
Version: 2.0
Purpose for release: This release of the calculator will allow for a multifunctional
interpretation of user input and the choice of mathematica operations including (+,-,* and /)
In addition to the use of an arrary for the sum of 10 numbers and modularizing the code from the main 
as a user-defined function to be called from the main program
*/
#include <stdio.h> // Main C library preprocessor header file
#include <errno.h>

void calc(); // Define my modularity for the user-defined function
 
void calc() //Main function start of the program
{
	int a , b,choice; //Declaring integer variables and data types, as well as choice for decision
	int c[10], i;
	int s = 0;

	{ // While loop used for trying again once the program is complete

		printf("Please enter your first number: "); //Asks user to input first integer and sets to memory
		scanf_s("%d", &a);

		printf("Please enter your second number: "); //Asks user for second number and sets to memory
		scanf_s("%d", &b);


		printf("\nMultiply(1), Divide(2), Subract(3), Add(4), Sum(5): "); //Prompts user to choose an operator to perform calculation
		// with the addition of the arrary for the sum of 10 numbers
		scanf_s("%d", &choice);

		switch (choice) //decision switch choice
		{
		case(1):
			printf("%d * %d = %d\n", a, b, (a * b)); //Will multiply the 2 numbers inputted
			break;
		case(2):
			printf("%d / %d = %d\n", a, b, (a / b));//Will divide 2 numbers inputted
			break;
		case(3):
			printf("%d - %d = %d\n", a, b, (a - b)); //Will subtract 2 numbers inputted
			break;
		case(4):
			printf("%d + %d = %d\n", a, b, (a + b)); //Will add 2 numbers inputted
			break;
		case(5):
			for (i = 0; i < 10; i++) { // For loop for the array starting at 0, with incremental inputs of 10 digits to do the sum
				printf("\nEnter a number"); //Enter 10 digits incrementally
				scanf_s("%d", &c[i]); //Store digits from the array as integers
				s = s + c[i]; //Perform the mathematical sum operation of all 10 integers
			}
			printf("\nSum = %d", s); //Display the sum as "Sum =     "
		}
	
	}
}
// Main function for the program for the execution and calling of the defined function for the calculator
int main() {
	//Define my loop variable set to 1
	int d = 1;
	calc(); // Call the user-defined function
	while (d == 1) { // While loop for the recursive operation for the user to restart the program
		printf("\nWould you like to try again (1 for yes, all other numbers for No): ");
		scanf_s("%d", &d);
		if (d == 1) { // If user inputs #1 1 the program will restart, else the program will end.
			calc(); //If selected 1, recall the user-defined function 
		}
	}
	return 0; //Else, the program will end
}