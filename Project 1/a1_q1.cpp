/* SYDE 121
 * Assignment 1, Question 1
 * Curtis Franz
 * 09/25/20
 *
 * Some of the values I used to test the program include: 5, 30, 50, 100 and 1234.
 * By using these values as test cases, I was able to test each weight type. 
 * By manually computing the cases above with my calculator, using the modulo
 * function, I was able to verify that the program works properly.
 * 
 * I also used the following as test cases: -1, 0, 5.5,2147483647, 2147483648,
 * 'a' and 'Hello'. By testing my program with these unexpected/outlying inputs,
 * I was able to determine the valid input range.
 * 
 * What I concluded is that the program will only work properly for all 
 * integers between 1 and 2147483647.
 * (For example, this program will not work properly if the user inputs a 
 * negative value, a decimal, the value 2147483648, a character or a string.) 
 * 
 * Step (1) output results:
 * 
 * Please enter a weight in pounds: 2048
 * You entered: 2048lb
 * 125lb weights: 16
 * 2lb weights: 1
 * 1lb weights: 6
 * 
 */
 
#include <iostream>

using namespace std;

void weight_calculator() {
	
	// declare and initialize variables for the number of each weight
	// and the weight to be entered by the user
	int weights125 = 0, weights75 = 0, weights42 = 0, weights15 = 0, weights1 = 0;
	int weight_given = 0;
	
	// accept and eacho the user input (weight_given)
	cout << "Please enter a weight in pounds: ";
	cin >> weight_given;
	cout << "You entered: " << weight_given << "lb" << endl;
	
	// compute the number of each weight
	weights125 = weight_given / 125;
	weight_given %= 125;
	
	weights75 = weight_given / 75;
	weight_given %= 75;
	
	weights42 = weight_given / 42;
	weight_given %= 42;
	
	weights15 = weight_given / 15;
	weight_given %= 15;
	
	weights1 = weight_given / 1;
	
	// output the number of each weight to the user
	// note: only weights used will be displayed
	cout << "\nWeights Required: " << endl;
	
	if (weights125 > 0)
		cout << "125lb weights: " << weights125;
	
	if (weights75 > 0)
		cout << "\n75lb weights: " << weights75;
	
	if (weights42 > 0)
		cout << "\n42lb weights: " << weights42;
	
	if (weights15 > 0)
		cout << "\n15lb weights: " << weights15;
	
	if (weights1 > 0)
		cout << "\n1lb weights: " << weights1;
}

int main() {
	
	weight_calculator();
	return 0;
}
