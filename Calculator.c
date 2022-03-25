/*
Filename: ITT-310 C Calculator
Author: Brody Hicks
Date: 3/25/2022
Version: 1.0
Purpose for release: This release of the calculator will allow for a multifunctional
interpretation of user input and the choice of mathematica operations including (+,-,* and /)
*/

#include <stdio.h>
 
int main() //Main function start of the program
{
	int a , b,choice; //Declaring integer variables and data types, as well as choice for decision
	int d = 1; //Declare value to 1 for loop

	while (d == 1) { // While loop used for trying again once the program is complete

		printf("Please enter your first number: "); //Asks user to input first integer and sets to memory
		scanf_s("%d", &a);

		printf("Please enter your second number: "); //Asks user for second number and sets to memory
		scanf_s("%d", &b);
		

		printf("\nMultiply(1), Divide(2), Subract(3), Add(4): "); //Prompts user to choose an operator to perform calculation
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
		default:
			printf("\nThat is an invalid choice, that is not a displayed options!!!!! :)"); //default statement if error occurs for case input value
		}
		printf("\nWould you like to try again (1 for yes 2 for no): "); //Prompts user to start again or leave the program (1/Y or 2/N)
		scanf_s("%d", &d);
	}
		return 0; //End of program
}