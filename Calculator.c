#include <stdio.h>
 
int main() 
{
	int a , b,choice;
	int d = 1;

	while (d == 1) {

		printf("Please enter your first number: ");
		scanf_s("%d", &a);

		printf("Please enter your second number: ");
		scanf_s("%d", &b);
		

		printf("\nMultiply(1), Divide(2), Subract(3), Add(4): ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case(1):
			printf("%d * %d = %d\n", a, b, (a * b));
			break;
		case(2):
			printf("%d / %d = %d\n", a, b, (a / b));
			break;
		case(3):
			printf("%d - %d = %d\n", a, b, (a - b));
			break;
		case(4):
			printf("%d + %d = %d\n", a, b, (a + b));
			break;
		default:
			printf("\nThat is an invalid choice, that is not a displayed options!!!!! :)");
		}
		printf("\nWould you like to try again (1 for yes 2 for no): ");
		scanf_s("%d", &d);
	}
		return 0;
}