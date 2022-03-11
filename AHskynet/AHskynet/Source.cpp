#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


int main() {
	srand(time(0));
	bool locationFound = false;
	int searchHigh;
	int searchTarget;
	int searchLow;

	int location = (rand() % 64) + 1; // establishes our enemy's location
	cout << location << endl;
	int grid[8][8];
	int idx = 0;
	for (int x = 0; x < 8; x++) { //these for loops eastablish the grid postions and the values asscoiated with them 
		for (int y = 0; y < 8; y++) { //both the grid postions and values are printed out as a guide
			idx++;
			grid[x][y] = idx;//assigns the grid values 1-64
			cout << grid[x][y] << " "; 
			cout << "(" << x << "," << y << ")" << " ";
		}
		cout << endl;
	}
	cout << endl;

	searchHigh = grid[7][7];//assigns the highest search parameter
	searchLow = grid[0][0]; //assigns the lowest search parameter
	int a = 0;
	while (locationFound == false) {
		a++;
		cout << a << " " << endl;
		cout << " search perameters " << searchLow << "-" << searchHigh << endl;
		if (((location < searchHigh) && (location > searchLow)) && locationFound == false) { //checking whether or not the algorithm is working
			cout << "enemy detected" << endl;
			searchTarget = ((searchHigh - searchLow) / 2) + searchLow; //changes the median based on the the search parameters 

			if (location == searchTarget) {//breaks the loop if the median of our current search parameters
					locationFound = true;  // is equal to the enemy's location
			}
			else if (location > searchTarget) { //if the enemy's location is greater than the median
					searchLow = searchTarget;   // change the lowest paramether to the current median
					//locationFound = false;
			}
			else if (location < searchTarget) { //if the enemy's location is less than the meadian
					searchHigh = searchTarget;  //change the highest parameter to the current median
					//locationFound = false;
			}
								
		}
		else { //algorithim failed
			cout << "enemy lost" << endl;
		}
	
	}

	if (locationFound == true) { //when the loop is broken the most recent searchtarget is printed
		cout << " location found: " << searchTarget;
	}

		return 0;
	}