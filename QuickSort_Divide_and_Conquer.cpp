#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

#define SIZE 25600000

using namespace std;

vector<int> Range;

void partition(int low, int high, int* pivot) {
	int i, j;	// i = left , j = right
	int pivot_item;
	int temp;
	pivot_item = Range.at(low);	// pivot 맨 처음 요소 
	
	i = low;
	for (j = low + 1; j <= high; j++) {
		if (Range.at(j) < pivot_item) {

			++i;

			temp = Range.at(i);
			Range.at(i) = Range.at(j);
			Range.at(j) = temp;

		}
	}

	*pivot = i;	

	temp = Range.at(low);
	Range.at(low) = Range.at(*pivot);
	Range.at(*pivot) = temp;

}

void quicksort(int low, int high) {
	int pivot = 0;

	if (high > low) {
		partition(low, high, &pivot);
		quicksort(low, pivot - 1);
		quicksort(pivot + 1, high);
	}
}


int main() {
	int f = 0;
	int startTime, endTime;


	while(f < SIZE)
		Range.insert(Range.end(), f++);

	random_shuffle(Range.begin(), Range.end());	//shuffle data

	cout << "---------Not Sorted---------\n\n";

	f = 0;					                   	//////////////	
	cout << "First 50nd..\n\n";			   	////
	while (f < SIZE) {					        ////
		if (f == 50) {			             	////
			cout << "\nLast 50nd..\n\n";	  ////
			f = SIZE - 50;		            	// PRINTING //
			continue;			                	// RESULT   //
		}				                        	// BEFORE   //
		cout << Range.at(f++) << "  ";		// SORTING  //
		if (f % 10 == 0)		          		////
			cout << "\n";		              	////
	}						                        /////////////

	startTime = clock();		///////////////////
	quicksort(0, SIZE-1);		///QUICK SORTING///
	endTime = clock();			///////////////////

	cout << "\n\n---------Sorted---------\n\n";

	f = 0;					                   	//////////////	
	cout << "First 50nd..\n\n";				  ////
	while (f < SIZE) {					        ////
		if (f == 50) {				            ////
			cout << "\nLast 50nd..\n\n";	  ////
			f = SIZE-50;			              // PRINTING //
			continue;				                // RESULT//
		}				                        	// AFTER	//
		cout << Range.at(f++) <<"  ";		  // SORTING//
		if (f % 10 == 0)			           	////
			cout << "\n";		              	////
	}						                        //////////////

	cout << "\n\nSIZE = " << SIZE;
	cout << "\nSORTING TIME : " << (double)(endTime - startTime) / 1000.0 << "ms\n";

}
