//Programmer: Jacquelynne Heiman
//Note: This code was created as a programming excersise to refresh on binary search principles
#include <iostream>
#include <string>
using namespace std;

int BinarySearch(int myArray[], int myGuess);

//This function searches through a sorted list using a binary search
int BinarySearch(int myArray[], int target)
{
	//the minium guess
	int min = 0;

	//the maximum guess
	int max = 10 - 1;


	//this while loop runs until the target has been found or max is less than min
	while (min < max)
	{
		//calculate the guess at where the target might be
		int guess = (int)(min + max)/2;

		//if the element at the guess index is less than the target
		if (myArray[guess] < target)
		{
			//reset the min to be one more than the guess
			min = guess + 1;
		}
		//if the element at the guess index is greater than the target
		else if (myArray[guess] > target)
		{
			//set the max to be one less than the guess
			max = guess - 1;
		}
		//if the element at the guess index equals the target
		else
		{
			//You found it!
			return guess;
		}
	}

	//You could not find the target, it is not in the list
	return -1;
}


int main()
{
	//This is the array we will be searching
	int myArray[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };

	string numToFind = "";

	cout << "Please select a number to find in the list: ";
	cin >> numToFind;

	int target = stoi(numToFind);
 
	//this is the integer that will hold the result of the search. 
	//if the search found the target, then it will hold the index of the target
	//if the search could not find the target then it will hold the number -1.
	int search = BinarySearch(myArray, target);

	string index = to_string(search);

	cout << "\n\n Your number was ";

	if (search != -1)
	{
		cout << "found at index " + index;
	}
	else
	{
		cout << "was not found in the list";
	}

	return 0;

}