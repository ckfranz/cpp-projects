/* SYDE 121
 * Assignment 2, Question 2
 * Curtis Franz
 * 
 * Some of the values for drone height and freefall time, that I used to test the program 
 * include: -5, 0, 1, 5, 50, 123, 1000, 6755, 35000 and 100000. By using this program with a 
 * wide range of test cases, I was able to determine the valid range of values for each variable. 
 * 
 * I was able to determine that the function will only work properly when the drone height is an 
 * integer of zero or greater. When the drone height is an integer value with 6+ digits, the
 * efficiency of the program decreases significantly, as it takes several seconds/ minutes to run
 * the program.
 * 
 * Likewise, the function will only work properly when the freefall time is an integer/double value
 * of zero or greater. When the drone height is an integer value with 4+ digits, the efficiency 
 * of the program decreases significantly, as it takes several seconds/ minutes to run the program.
 * 
 * By comparing the results of this program (with the valid test cases above as well as the default
 * values (15000m, 30sec)) with those of an online calculator I was able to verify that the program 
 * works properly.
 * 
 * 
 * Step (2) output results:
 * 
 * Part 2: 
 * Time (sec):	Distance duration interval (m): 	Total distance (m): 
 * 0.000			0.000							0.000
 * 1.000			4.903							4.903
 * 2.000			14.710							19.613
 * 3.000			29.420							44.130
 * 4.000			49.033							78.453
 * 5.000			73.550							122.583
 * 6.000			102.970							176.520
 * 7.000			137.293							240.263
 * 8.000			176.520							313.813
 * 9.000			220.650							397.169
 * 10.000			269.683							490.332
 * 11.000			323.619							593.302
 * 12.000			382.459							706.079
 * 13.000			446.203							828.662
 * 14.000			514.849							961.052
 * 15.000			588.399							1103.248
 * ... (Condensed)
 * 53.000			7016.658						13773.440
 * 54.000			7281.438						14298.096
 * 54.100			7069.663						14351.101
 * 54.200			7334.541						14404.204
 * 54.300			7122.864						14457.405
 * 54.400			7387.840						14510.704
 * 54.500			7176.261						14564.101
 * 54.600			7441.335						14617.596
 * 54.700			7229.855						14671.190
 * 54.800			7495.026						14724.881
 * 54.900			7283.644						14778.671
 * 55.000			7548.914						14832.558
 * 55.100			7337.630						14886.544
 * 55.200			7602.998						14940.627
 * 55.300			7391.811						14994.809
 * 55.400			7657.277						15049.089
 * 
 * Note: the final row of the chart represents the interval right after the ball would
 * have hit the ground. By taking a value for time beween the final two elements, an
 * approximation for the 'time of impact' can be made.
 */
 
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void compute_distance(double time, double& total_distance, double& interval_distance,
					  double gravity);
//	PURPOSE: Computes the distance per second and total distance fallen by the ball
//			INPUTS: gravity - constant double value
//					time, interval_distance, total_distance - corresponding double values
//			OUTPUTS: nothing; values are returned by reference

void output_stats(double time, double total_distance, double interval_distance);
//	PURPOSE: Outputs computed chart
//			INPUTS: time, total_distance, interval_distance - double values
//			OUTPUTS: Returns nothing; Output is to the console

void compute_part1 (double interval_distance, double total_distance, double time,
					double gravity, int freefall_time);
//	PURPOSE: Computes the distance fallen by a ball over 30 seconds
//			INPUTS: gravity - constant double value
//					interval_distance, total_distance, time - corresponding double values
//					freefall_time - corresponding integer value
//			OUTPUTS: Returns nothing; Output is to the console

void compute_part2(double interval_distance, double total_distance, double time, 
				   int height_drone, double gravity);
//	PURPOSE: Computes the time it takes for a ball to fall 15000m
//			INPUTS: height_drone - constant integer value
//					gravity - constant double value
//					interval_distance, total_distance, time - corresponding double values
//			OUTPUTS: Returns nothing; Output is to the console

void execute_a2_q2();
//	PURPOSE: Runs part1 and part2 of the program


void compute_distance(double time, double& total_distance, double& interval_distance,
					  double gravity) {
	// step1. compute and update the total distance and interval distance
	total_distance = 0.5 * gravity * pow(time, 2); // Note: Eqn is derived from asst. handout
	interval_distance = total_distance - interval_distance;
}

void output_stats(double time, double total_distance, double interval_distance) {
	// step1. output chart with time, interval distance and total distance
	// step1.1. output chart header 
	if (time == 0)
		cout << "Time (sec):\tDistance duration interval (m):\tTotal distance (m): \n";
	// step 1.2. output time, interval distance and total distance
	if (time >= 0) {
		cout << fixed << setprecision(3);
		cout << time << "\t\t\t" << interval_distance << "\t\t\t\t\t\t\t" << 
				total_distance << endl;
	}
}

void compute_part1 (double interval_distance, double total_distance, double time,
					double gravity, int freefall_time) {
	// [setup] step1. declare and initailize variables 
	freefall_time = 30;
	time = 0;
	// step1.2. Display section header (output)
	cout << "Part 1: " << endl;
	// [PROCESSING] step2. compute distance fallen by the ball
	while (time <= freefall_time) {
		compute_distance(time, total_distance, interval_distance, gravity);
		// [OUTPUT] step3. outputs computed chart
		output_stats(time, total_distance, interval_distance);
		time++;
	}
}

void compute_part2 (double interval_distance, double total_distance, double time,
					int height_drone, double gravity) {
	// [setup] step1. declare and initailize variables 
	interval_distance = 0;
	total_distance = 0;
	time = 0;
	// step1.2. Display section header (output)
	cout << "\nPart 2: " << endl;
	// [PROCESSING] step2. compute distance fallen by the ball
	while (total_distance <= height_drone) {
		compute_distance(time, total_distance, interval_distance, gravity);
		// [OUTPUT] step3. outputs computed chart
		output_stats(time, total_distance, interval_distance);
		if (total_distance < height_drone - 1000) // Incresed resolution within 1000m
			time++;
		// step3.1. increase resolution to increments of 0.1 sec when ball is within 
		//			1000m of the ground
		else if (total_distance >= height_drone - 1000) // Incresed resolution within 1000m
			time += 0.1;
	}
}

void execute_a2_q2() {
	// [setup] declare and initialize variables
	const double gravity = 9.80665;
	const int height_drone = 15000;
	int freefall_time = 0;
	double interval_distance = 0, total_distance = 0, time = 0;
	
	//[PROCESSING] & [OUTPUT]
	// step1. invoke part1 function
	compute_part1 (interval_distance, total_distance, time, gravity, freefall_time);
	
	// step2. invoke part2 function
	compute_part2 (interval_distance, total_distance, time, height_drone, gravity);
}

int main() {
	execute_a2_q2(); // invoke the execute function
}