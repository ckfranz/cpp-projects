/* SYDE 121
 * Assignment 2, Question 1
 * Curtis Franz
 *
 * Some of the values I used to test the program include: -5, 0, 1, 2, 23, 50, 100, 15000 
 * and 100500. By using these values as test cases, I was able to test each function (prime 
 * check, palindrome check, odd sum check, etc.) with a wide range of values. By comparing 
 * the results with those of an online calculator I was able to verify that the program works 
 * properly.
 * 
 * I also used the following as test cases: -1, 0, 5.5, 1000000,'a' and 'Hello'.
 * By testing my program with these unexpected/outlying inputs, I was able to determine that
 * the program will only work properly for all integers greater than -2147483648. For integers
 * with 6+ digits the effeciency of the program decreases significantly, as the output takes 
 * serveral seconds/minutes to output.
 * 
 * 
 * Sample output results:
 * 
 * Please enter an integer greater than one: 
 * 23
 * 
 * Primes less than/including 23 are:
 * 2 (Palindromic Prime)
 * 3 (Palindromic Prime & Odd Sum)
 * 5 (Palindromic Prime & Odd Sum)
 * 7 (Palindromic Prime & Odd Sum)
 * 11 (Palindromic Prime)
 * 13
 * 17
 * 19
 * 23 (Odd Sum)
 */

#include <iostream>
using namespace std;

void set_max_value(int& max_value);
//	PURPOSE: Allows the user to set the maximum value
//		INPUTS: max_value - integer value reference that will contain the maximum value
//		OUTPUTS: nothing; value is returned by reference

void prime_check(int current_value, bool& is_prime);
//	PURPOSE: Determines whether a number is prime
//		INPUTS: current value - integer value that represents the number being checked
//				is_prime - corresponding boolean value
//		OUTPUTS: Nothing; is_prime is returned by reference

void palindrome_check(int current_value, bool& is_palindrome);
//	PURPOSE: Determines whether a number is a palindrome
//		INPUTS: current_value - integer value that represents the number being checked
//				is_palindrome - corresponding boolean value
//		OUTPUTS: Nothing; is_palindrome is returned by reference

void odd_sum_check(int current_value, bool& odd_sum);
//	PURPOSE: Determines whether a number's digits have an odd sum
//		INPUTS: current_value - integer value that represents the number being checked
//				odd_sum - corresponding boolean value
//		OUTPUTS: Nothing; odd_sum is returned by reference

void prime_output (int current_value, int max_value, bool is_palindrome, bool odd_sum);
//	PURPOSE: Outputs the computed results
//		INPUTS: max_value - integer value that represents the inputted entry value
//				current_value - integer value that represents the number being checked
//				is_palindrome, odd_sum - corresponding boolean values
//		OUTPUTS: Nothing is returned; The output is to the console

void execute_a2_q1();
// PURPOSE: Runs the steps of the specified program


void set_max_value(int& max_value) {
	// step1. allow the user to enter the entry value that is greater than zero
	while (max_value <= 1) {
		cout << "Please enter an integer greater than one: \n";
		cin >> max_value;
	}
}

void prime_check(int current_value, bool& is_prime) { 
	// step1. check if 'current_value' is prime
	is_prime = true;
	for (int i = 2; current_value > 2 && i < current_value; i++)
		if (current_value % i == 0)
			is_prime = false;
}

void palindrome_check(int current_value, bool& is_palindrome) {
	// step1. declare and initialize digits of a number between 1-4 digits
	int digit1 = current_value / 1000;
	int digit2 = current_value % 1000 / 100;
	int digit3 = current_value % 100 / 10;
	int digit4 = current_value % 10;
	is_palindrome = false;
	
	// step2. check if 'current_value' is a palindrome
	if (current_value < 10)  // Note: all values less than 10 are palindromes
		is_palindrome = true;
		
	else if (current_value >= 10 && current_value < 100) { 
		if (digit3 == digit4)
			is_palindrome = true;
	}
	
	else if (current_value >= 100 && current_value < 1000) {
		if (digit2 == digit4)
			is_palindrome = true;
	}
	
	else if (current_value >= 1000 && current_value < 10000) {
		if (digit1 == digit4 && digit2 == digit3)
			is_palindrome = true;
	}
}

void odd_sum_check(int current_value, bool& odd_sum) {
	// step1. declare and initialize digits of a number between 1-5 digits
	int digit1 = current_value / 10000;
	int digit2 = current_value % 10000 / 1000;
	int digit3 = current_value % 1000 / 100;
	int digit4 = current_value % 100 / 10;
	int digit5 = current_value % 10;
	odd_sum = false;
	
	// step2. check if 'current_value' digits have an odd sum
	if (current_value < 10) {
		if (digit5 % 2 == 1)
			odd_sum = true;
	}
	else if (current_value >= 10 && current_value < 100) {
		if ((digit4 + digit5) % 2 == 1)
			odd_sum = true;
	}
	else if (current_value >= 100 && current_value < 1000) {
		if ((digit3 + digit4 + digit5) % 2 == 1)
			odd_sum = true;
	}
	else if (current_value >= 1000 && current_value < 10000) {
		if ((digit2 + digit3 + digit4 + digit5) % 2 == 1)
			odd_sum = true;
	}
	else if (current_value >= 10000 && current_value < 100000) {
		if ((digit1 + digit2 + digit3 + digit4 + digit5) % 2 == 1)
			odd_sum = true;
	}
}

void prime_output (int current_value, int max_value, bool is_palindrome, bool odd_sum) {
	// step1. output echo message before the list of primes
	if (current_value == 2)
		cout << "\nPrimes less than/including " << max_value << " are:" << endl;
	
	// step2. output list of primes with a message indicating if it is a palindrom and/or
	//		  the digits have an odd sum
	if (is_palindrome && odd_sum)
				cout << current_value << " (Palindromic Prime & Odd Sum)" << endl;
	else if (is_palindrome)
				cout << current_value << " (Palindromic Prime)" << endl;
	else if (odd_sum)
				cout << current_value << " (Odd Sum)" << endl;
	else
		cout << current_value << endl;
}

void execute_a2_q1() {
	// [SETUP] declare and initailize variables
	int max_value = 0;
	int current_value = 0;
	bool is_prime = true;
	bool is_palindrome = false;
	bool odd_sum = false;
	
	// [INPUT] step 1. allow the user to enter the maximum value
	set_max_value(max_value);
	
	// [PROCESSING] step2.1. checks if each number less than/including the maximum number
	//						 is a prime
	for (int current_value = 2; current_value <= max_value; current_value++) {
		prime_check(current_value, is_prime);
		
		// step2.2 checks if each prime number is a palindrome and/or the digits have an
		//		   odd sum
		if (is_prime) {
			if (current_value < 10000) // Note: Only check for numbers less than 10,000
				palindrome_check(current_value, is_palindrome);
			if (current_value < 100000) // Note: Only check for numbers less than 100,000
				odd_sum_check(current_value, odd_sum);
			
			// [OUTPUT] step3. output computed list of primes
			prime_output (current_value, max_value, is_palindrome, odd_sum);
		}
    } 
}

int main() {
	execute_a2_q1(); // invoke the excecute function
}