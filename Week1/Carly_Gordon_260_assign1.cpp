#include <iostream>
using namespace std;

// Constant for the number of columns

const int COLS = 5;

// Function prototypes
int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main()
{
	const int ROWS = 4;  // Constant for the number of rows

	// Array with test data
	int testArray[ROWS][COLS] =
					{ { 1,   2,  3,  4,  5 },
					{   6,   7,  8,  9, 10 },
					{  11,  12, 13, 14, 15 },
					{  16,  17, 18, 19, 20 } };

	// Display the total of the array elements.
	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;

	// Display the average of the array elements.
	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;

	// Display the total of row 0.
	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;

	// Display the total of column 2.
	cout << "The total of col 2 is "
		 << getColumnTotal(testArray, 2, ROWS)
		 << endl;

	// Display the highest value in row 2.
	cout << "The highest value in row 2 is "
		 << getHighestInRow(testArray, 2)
		 << endl;

	// Display the lowest value in row 2.
	cout << "The lowest value in row 2 is "
		 << getLowestInRow(testArray, 2)
		 << endl;

    system("PAUSE");
	return 0;
}

// ********************************************************
// The getTotal function returns the total of all         *
// the elements in the array.                             *
// ********************************************************
int getTotal(int array[][COLS], int rows){
	int total = 0;
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < COLS; col++){
			total += array[row][col];
		}
	}
	return total;
}

// ********************************************************
// The getAverage function returns the averave value      *
// of the elements in the array.                          *
// ********************************************************
double getAverage(int array[][COLS], int rows){
	return float(getTotal(array, rows)) / (rows * COLS);
}

// ********************************************************
// The getRowTotal function returns the total of the      *
// the elements in the specified row of the array.        *
// ********************************************************
int getRowTotal(int array[][COLS], int rowToTotal){
	int rowSum = 0;
	for (int col = 0; col < COLS; col++){
		rowSum += array[rowToTotal][col];
	}
	return rowSum;
}

// ********************************************************
// The getColTotal function returns the total of the      *
// the elements in the specified column of the array.     *
// ********************************************************
int getColumnTotal(int array[][COLS], int colToTotal, int rows){
	int colSum = 0;
	for(int row = 0; row < rows; row++){
		colSum += array[row][colToTotal];
	}
	return colSum;
}

// ********************************************************
// The getHighestInRow function returns the highest       *
// value in the specified row.                            *
// ********************************************************
int getHighestInRow(int array[][COLS], int rowToSearch){
	int rowMax = INT_MIN;
	for(int col = 0; col < COLS; col++){
		rowMax = (array[rowToSearch][col] > rowMax) ? array[rowToSearch][col] : rowMax;
	}
	return rowMax;
}

// ********************************************************
// The getLowestInRow function returns the lowest         *
// value in the specified row.                            *
// ********************************************************
int getLowestInRow(int array[][COLS], int rowToSearch){
	int rowMin = INT_MAX;
	for(int col = 0; col < COLS; col++){
		rowMin = (array[rowToSearch][col] < rowMin) ? array[rowToSearch][col] : rowMin;
	}
	return rowMin;
}
