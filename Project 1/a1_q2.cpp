/* SYDE 121
 * Assignment 1, Question 2
 * Curtis Franz
 * 09/25/20
 
 * Some of the values used to test this program were: {-5,-10},{-5,5},{0,0}, 
 * {5,10}, {10,500}. I chose these test cases, to confirm that the program works
 * properly for a range of expected input values.
 * By manually computing the cases above with my calculator, using the summation
 * function, I was able to verify that the program works properly.
 * 
 * I also tested the program with the input values: {5,-5}, {-10000,10000}.
 * 
 * This program will work correctly for all integers input values such that 
 * the first value is less than the last value. This program is also limited by
 * the size constraint of integers. This means that if any integers declared
 * (int a, int b, int d and int sum) exceed [-2147483648, 147483647] then the
 * program will not work correctly.
 * 
 * Note:  deciamal inputs will be 'rounded down' to the nearest integer.
 * 
 * Step (1) output results:
 * 
 * The sum of the integers from 1 to 500 is 125,250
 * The sum of the integers from 5 to 2,020 is 2,041,200
 * The sum of the integers from 42 tro 32,000 is 512,015,139
 */
 
#include <iostream>

using namespace std;

void summation_calculator () {
	
	// declare and initialize the range of values in the summation
	int first_value{};
	int last_value{};
	
	// accept an entry from the user for the 'first value' of the summation
	cout << "Please enter the first integer value: ";
	cin >> first_value;
	
	// accept an entriy from the user for the 'last value' of the summation
	cout << "Please enter the last integer value: ";
	cin >> last_value;
	
	// declare and initialize the variables used in the computation
	int n {last_value - first_value + 1};
	int a {first_value};
	int d {1};
	
	// compute the sum of the integers from the first value to the last value
    // note: formula is derived from q2 of a1
	int sum = (n / 2.0) * (2 * a + (n - 1) * d);
	
	// output the summation to the user
	cout << "\nThe sum of the integers from " << first_value <<" to " 
		 << last_value << " is " << sum;
}

int main() {
    
	summation_calculator();
	return 0;
}
