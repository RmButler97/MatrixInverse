// Ryan Butler
// This program will find the inverse of a given square matrix using Gaussian Elimination

#include <iostream>
using namespace std;

int main()
{
	// Declare variable
    // Array can be no larger than 10x10
	double array[10][20];
	double x;
    // Varible used to store size of square array
    int size;
    // Variables used in for loops
	int a, b, c;
    
	
	// Take user input for size and elemnts of array
	cout << "Input size of square array: ";
	cin >> size;
	
	// Create user defined matrix
    cout << "Enter values for matrix:" << endl;
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			cin >> array[a][b];
		}
	}
	
	// Create adjacent identity matrix of user inputed size
	for (a = 0; a < size; a++)
	{
		for (b = size; b < 2 * size; b++)
		{
			if (a == b-size)
				array[a][b] = 1;
			else
				array[a][b] = 0;
		}
	}
	
	// Gaussian Elimination
	for (a = 0; a < size; a++)
	{
		x = array[a][a];
		for (b = a; b < 2 * size; b++)
		{
			array[a][b] = array[a][b] / x;
		}
		for (b = 0; b < size; b++)
		{
			if (a != b)
			{
				x = array[b][a];
				for (c = 0; c < 2 * size; c++)
				{
					array[b][c] = array[b][c] - x * array[a][c];
				}
			}
		}
	}
	
	// Output inverse array
	cout << "Inverse array:" << endl;
	for (a = 0; a < size; a++)
	{
		for (b = size; b < 2 * size; b++)
		{
			cout << "\t" << array[a][b];
		}
		cout << endl;
	}
}


