/* SYDE121
 * a3_q1.cpp
 * Assignment 3, Question 1
 * 10/30/20
 * Curtis Franz
 * ID: 20831938
 * 
 * The purpose of this program is to display a soccer game simulation to the console.
 * 
 * Verification/testing:
 * In order to verify that this program works correctly, it was ran 30 times. The console results were
 * manually checked to ensure that the statistics displayed were accurate. The results were also compared 
 * to make sure that games were not repeated (very high improbability of this occurance).
 * Additionally, the results were checked to make sure each statistic produces a integer value greater
 * than zero at least once and the same statistics were not frequently repeated. Finally, the event type, 
 * card type and shot type were initailized manually and compared to results displayed, as verification.
 * 
 * Limitations to this simulation:
 * This program does not account for the possibility of a game with 0 events, or more than 20 events.
 * It is limited to keeping track of only the seven statistics (goals, shots on goal, shots off goal, 
 * blocked shots, fouls, yellow cards and red cards).
 * Also, in reality, events in soccer games have unique corresponding probabilites which program does
 * not account for. (In this program, event types, shot types and card types are randomly generated)
 * 
 * 
 * Sample output results (1):
 * 
 * Start Game!
 * Team A commits a foul and recieves a yellow Card. Team B is awarded a free kick.
 * Team B Scores! What a goal!
 * Team B shoots, but the shot is blocked!
 * Team B Scores! What a goal!
 * Team B commits a foul and recieves a yellow Card. Team A is awarded a penalty kick.
 * Team A Scores! What a goal!
 * Team A commits a foul and recieves a yellow Card. Team B is awarded a free kick.
 * Team B shoots, but the shot is blocked!
 * Team A commits a foul, but no card was given. Team B is awarded a penalty kick.
 * Team B shoots wide of the goal!
 * Team B Scores! What a goal!
 * Team A commits a foul and recieves a red Card. Team B is awarded a penalty kick.
 * Team B Scores! What a goal!
 * Team A commits a foul, but no card was given. Team B is awarded a penalty kick.
 * Team B shoots but is denied by the goalkeeper!
 * 
 * Halftime!
 * Game Statistics:
 * 				Team A	Team B
 * Score			1		4
 * Shots on Goal	1		5
 * Shots off Goal	0		1
 * Blocked Shots	2		0
 * Fouls			5		1
 * Yellow Cards		2		1
 * Red Cards		1		0
 * 
 * Team A shoots but is denied by the goalkeeper!
 * Team A commits a foul, but no card was given. Team B is awarded a free kick.
 * Team B Scores! What a goal!
 * 
 * Game Over!
 * Game Statistics:
 * 				Team A	Team B
 * Score			1		5
 * Shots on Goal	2		6
 * Shots off Goal	0		1
 * Blocked Shots	2		0
 * Fouls			6		1
 * Yellow Cards		2		1
 * Red Cards		1		0
 * 
 * 
 * Sample output results (2):
 * 
 * Start Game!
 * Team B commits a foul and recieves a red Card. Team A is awarded a penalty kick.
 * Team A shoots but is denied by the goalkeeper!
 * Team B commits a foul and recieves a yellow Card. Team A is awarded a free kick.
 * Team A shoots wide of the goal!
 * Team A commits a foul and recieves a red Card. Team B is awarded a free kick.
 * Team B shoots wide of the goal!
 * 
 * Halftime!
 * Game Statistics:
 * 				Team A	Team B
 * Score			0		0
 * Shots on Goal	1		0
 * Shots off Goal	1		1
 * Blocked Shots	0		0
 * Fouls			1		2
 * Yellow Cards		0		1
 * Red Cards		1		1
 * 
 * Team B commits a foul and recieves a red Card. Team A is awarded a penalty kick.
 * Team A Scores! What a goal!
 * Team B shoots but is denied by the goalkeeper!
 * 
 * Game Over!
 * Game Statistics:
 * 				Team A	Team B
 * Score			1		0
 * Shots on Goal	2		1
 * Shots off Goal	1		1
 * Blocked Shots	0		0
 * Fouls			1		3
 * Yellow Cards		0		1
 * Red Cards		1		2
 * 
 */

#include <iostream>
#include <string>
// directives below may be included for optional time delay betweeen events
// Sourced from: https://en.cppreference.com/w/cpp/chrono
// #include <chrono>
// #include <thread>

using namespace std;

void shot (int event_type, int foul_type, int stats_a[], int stats_b[]);
//PURPOSE: Generates a message for and keeps track of goals, shots on goal, shots off goal 
//		   and shots blocked
//		INPUT: event_type, foul type - corresponding integer values
//			   stats_a, stats_b - arrays containing stats for team a and b respectively
//		RETURN: outputs message to the console according to the event type

void foul (int event_type, int foul_type, int stats_a[], int stats_b[]);
//PURPOSE: Generates a message for and keeps track of fouls, red cards and yellow cards
//		INPUT: event_type, foul type - corresponding integer values
//			   stats_a, stats_b - arrays containing stats for team a and b respectively
//		RETURN: outputs message to the console according to the foul type

void stats (int stats_a[], int stats_b[]);
//PURPOSE: Display a table containing the game statistics for team a and team b
//		INPUT: stats_a, stats_b - arrays contining stats for team a and b respectively
//		RETURN: outputs the stats for team a and b in a table

void execute_a3_q1 ();
//PURPOSE: Runs the steps of the specified program

void shot (int event_type, int shot_type, int stats_a[], int stats_b[]) {
	
	// Team A event if event number is odd
	if (event_type % 2 == 1) {
		// display approriate message to the console according to the event number
		if (event_type == 3)
			cout << " Team A is awarded a free kick." << endl;
		if (event_type == 5)
			cout << " Team A is awarded a penalty kick." << endl;
			// display approriate message to the console according to shot type
		switch (shot_type) { 
			case 0:
				cout << "Team A Scores! What a goal!" << endl;
				stats_a[0]++; // inc goals
				stats_a[1]++; // inc shots on goal
				break; 
			case 1:
				cout << "Team A shoots but is denied by the goalkeeper!" << endl;
				stats_a[1]++; // inc shots on goal
				break; 
			case 2:
				cout << "Team A shoots wide of the goal!" << endl;
				stats_a[2]++; // inc shots off goal
				break;
			case 3:
				cout << "Team A shoots, but the shot is blocked!" << endl;
				stats_b[3]++; // inc shots blocked (opposite team)
				break;
		}
	}
	// Team B event if event number is even
	else if (event_type % 2 == 0) {
		// display approriate message to the console according to event number
		if (event_type == 4)
			cout << " Team B is awarded a free kick." << endl;
		if (event_type == 6)
			cout << " Team B is awarded a penalty kick." << endl;
			// display approriate message to the console according to shot type
		switch (shot_type) { 
			case 0:
				cout << "Team B Scores! What a goal!" << endl;
				stats_b[0]++; // inc goals
				stats_b[1]++; // inc shots on goal
				break; 
			case 1:
				cout << "Team B shoots but is denied by the goalkeeper!" << endl;
				stats_b[1]++; // inc shots on goal
				break; 
			case 2:
				cout << "Team B shoots wide of the goal!" << endl;
				stats_b[2]++; // inc shots off goal
				break;
			case 3:
				cout << "Team B shoots, but the shot is blocked!" << endl;
				stats_a[3]++; // inc shots blocked (opposite team)
				break;
		}
	}
}

void foul (int event_type, int foul_type, int stats_a[], int stats_b[]) {
	// Team A foul if event number is even
	if (event_type % 2 == 0) {
		// display approriate message to the console based on event number
		switch (foul_type) {
			case 0: 
				cout << "Team A commits a foul, but no card was given.";
				stats_a[4]++; // inc fouls
				break; 
			case 1: 
				cout << "Team A commits a foul and recieves a yellow Card." ;
				stats_a[4]++; // inc fouls
				stats_a[5]++; // inc yellow cards
				break; 
			case 2:
				cout << "Team A commits a foul and recieves a red Card.";
				stats_a[4]++; // inc fouls
				stats_a[6]++; // inc red cards
				break;
		}
	} 
	// Team B foul if event number is odd
	else {
		// display approriate messages to the console based on event number
		switch (foul_type) {
			case 0: 
				cout << "Team B commits a foul, but no card was given."; 
				stats_b[4]++; // inc fouls
				break; 
			case 1: 
				cout << "Team B commits a foul and recieves a yellow Card."; 
				stats_b[4]++; // inc fouls
				stats_b[5]++; // inc yellow cards
				break; 
			case 2:
				cout << "Team B commits a foul and recieves a red Card."; 
				stats_b[4]++; // inc fouls
				stats_b[6]++; // inc red cards
				break;
		}
	}
}

void stats (int stats_a[], int stats_b[]) {
	
	// output the game statistics in a table
	cout << "Game Statistics:" << endl;
	cout << "\t\t\t\t" << "Team A" << "\t" << "Team B" << endl;
	cout << "Score" << "\t\t\t" << stats_a[0] << "\t\t" << stats_b[0] << endl;
	cout << "Shots on Goal" << "\t" << stats_a[1] << "\t\t" << stats_b[1] << endl; 
	cout << "Shots off Goal" << "\t" << stats_a[2] << "\t\t" << stats_b[2] << endl;
	cout << "Blocked Shots" << "\t" << stats_a[3] << "\t\t" << stats_b[3] << endl;
	cout << "Fouls" << "\t\t\t" << stats_a[4] << "\t\t" << stats_b[4] << endl;
	cout << "Yellow Cards" << "\t\t" << stats_a[5] << "\t\t" << stats_b[5] << endl;
	cout << "Red Cards" << "\t\t" << stats_a[6] << "\t\t" << stats_b[6] << "\n" << endl;
}

void execute_a3_q1 () {
	// [SETUP] declare and initlialize variables
	int num_events = 0;
	int events_first_half = 0;
	int event_type = 0;
	int shot_type = 0;
	int foul_type = 0;
	
	// declare and initialize arrays to store the seven stats for team a and b repectively
	// stats in order of elements are: goals, shots on goal, shots off goal, blocked
	//								  shots, fouls, yellow cards and red cards
	const int num_stats = 7;
	int stats_a[num_stats] = {0};
	int stats_b[num_stats] = {0};
	
	// [INPUT] set the randomization seed
	srand(time(0));
	// initialize the number of events in the game to be a random number between 1 and 20
	num_events = rand() % 20 + 1;
	
	// initialize the numer of events in the first half to be a random number
	// the number of events in the second half will be (num_events - events_first_half)
	// between 0 and 'num_events'
	events_first_half = rand() % num_events;
	
	// [PROCESSING] and [OUPTUT]
	// messgae to indicate the start of the simulation
	cout << "Start Game!" << endl; 
	
	// iterate through each event
	for (int index = 0; index < num_events; index++) {
		
		// Generate a random event type (integer value 1-6)
		event_type = rand() % 6 + 1;
		
		// optional time dely between events
		// Sourced from: https://en.cppreference.com/w/cpp/chrono
		// int n = 500; // 0.5 second time delay between events
		// this_thread::sleep_for(chrono::milliseconds(n));
		
		// event type 1,2: Shot at target
		if (event_type == 1 || event_type == 2) {
			// generate a possible shot type (goal, save, miss, block)
			shot_type = rand() % 4;
			// generate a message for the shot type and stores statistics
			shot(event_type, shot_type, stats_a, stats_b);
		}
		// event type 3,4: foul
		else if (event_type == 3 || event_type == 4) {
			// generate a possible foul type (no card, yellow card, red card)
			// generate a possible shot type (goal, save, miss, block)
			foul_type = rand() % 3;
			shot_type = rand() % 4;
			// generate a message for the shot/foul type and stores statistics
			foul (event_type, foul_type, stats_a, stats_b);
			shot (event_type, shot_type, stats_a, stats_b);
		} 
		// event type 5,6: penalty kick
		else {
			// generate a possible foul type (no card, yellow card, red card)
			// generate a possible shot type (goal, save, miss, block)
			foul_type = rand() % 3;
			shot_type = rand() % 3;
			// generate a message for the shot/foul type and stores statistics
			foul (event_type, foul_type, stats_a, stats_b);
			shot (event_type, shot_type, stats_a, stats_b);
		}
		// display statistics at halftime
		if (index == events_first_half) {
			cout << "\nHalftime!" << endl;
			stats (stats_a, stats_b);
		}
		// display statistics at the end of the game
		if (index == num_events - 1) {
			cout << "\nGame Over!" << endl;
			stats (stats_a, stats_b);
		}
	}
}

int main() {
	execute_a3_q1 ();
}