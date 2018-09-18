#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
/**************************************************************************/
void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}//end swap
/**************************************************************************/
void bubbleSort(int numbers[], int size) {
	bool swapped;
	do { //repeat
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (numbers[i] > numbers[i + 1]) {
				swap(numbers[i], numbers[i + 1]);
				swapped = true;
			}//end if
		}//end for
	} while (swapped); //until
}//end sortBubble
/**************************************************************************/
void selectionSort(int numbers[], int size) {
	int j, i; //j indicates the search range
	int min; //finding minimums
	for (j = 0; j < size - 1; j++) {
		min = j;
		for (i = j + 1; i < size; i++) {
			if (numbers[i] < numbers[min]) min = i;
		}//end for
		if (min != j) swap(numbers[j], numbers[min]);
	}//end for
}//end sortSelection
/**************************************************************************/
void insertionSort(int numbers[], int size) {
	int i, j;
	for (i = 1; i < size; i++) {
		j = i;
		while (j>0 && numbers[j - 1] > numbers[j]) {
			swap(numbers[j], numbers[j - 1]);
			j--;
		}//end while
	}//end for
}//end insertionSort
/**************************************************************************/
void mergeSort(int array1[], int array2[], int array3[], int size1, int size2, int size3) {
	int indexA = 0;
	int indexB = 0;
	int indexC = 0;

	while ((indexA < size1) && (indexB < size2)) {
		if (array1[indexA] < array2[indexB]) {
			array3[indexC] = array1[indexA];
			indexA++;    //increase the subscript
		}
		else {
			array3[indexC] = array2[indexB];
			indexB++;      //increase the subscript
		}
		indexC++;      //move to the next position in the new array
	}
	// Move remaining elements to end of new array when one merging array is empty
	while (indexA < size1) {
		array3[indexC] = array1[indexA];
		indexA++;
		indexC++;
	}
	while (indexB < size2) {
		array3[indexC] = array2[indexB];
		indexB++;
		indexC++;
	}
}
/**************************************************************************/
void quickSort(int numbers[], int first, int last) {
	if (first < last) {
		int pivot = numbers[first];
		int leftPtr = first + 1;
		int rightPtr = last;
		while (leftPtr <= rightPtr) {
			while (numbers[leftPtr] < pivot && leftPtr <= rightPtr) {
				leftPtr++;
			}
			while (numbers[rightPtr] > pivot && leftPtr <= rightPtr) {
				rightPtr--;
			}
			if (leftPtr < rightPtr) swap(numbers[leftPtr], numbers[rightPtr]);
		}
		pivot = rightPtr;
		swap(numbers[first], numbers[pivot]);
		quickSort(numbers, first, pivot - 1);
		quickSort(numbers, pivot + 1, last);
	}
}
/**************************************************************************/
void printArray(int numbers[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "| Pos#" << i << " ||| " << numbers[i] << " |" << endl;
	}//end for
}//end printArray
/**************************************************************************/
void checkSort(string typeOfSort, int numbers[], int size) {
	bool sorted = true;
	for (int i = 0; i < size - 1; i++) {
		if (numbers[i] > numbers[i + 1]) {
			sorted = false;
			break;
		}//end if
	}//end for
	if (sorted) cout << typeOfSort << " sort was successful." << endl;
	else cout << typeOfSort << " sort was NOT successful." << endl;
}//end checkSort
/**************************************************************************/
void shuffleArray(int numbers[]) {
	numbers[0] = 5;
	numbers[1] = 1;
	numbers[2] = 4;
	numbers[3] = 2;
	numbers[4] = 3;
}//end shuffleArray
/**************************************************************************/
void main() {
	const int size = 5;
	int numbersGlobal[size] = { 5, 1, 4, 2, 3 };
	/*****MERGE SORT VARIABLES*****/
	int array1_size = 3;  
	int array1[] = { 1, 2, 6 };
	int array2_size = 3;  
	int array2[] = { 3, 4, 5 };
	int size_merged = 6;
	int *combinedArray = new int[size_merged];
	/******************************/
	cout << endl;
	bubbleSort(numbersGlobal, size);
	checkSort("Bubble", numbersGlobal, size);
	shuffleArray(numbersGlobal);
	selectionSort(numbersGlobal, size);
	checkSort("Selection", numbersGlobal, size);
	shuffleArray(numbersGlobal);
	insertionSort(numbersGlobal, size);
	checkSort("Insertion", numbersGlobal, size);
	mergeSort(array1, array2, combinedArray, array1_size, array2_size, size_merged);
	checkSort("Merge", numbersGlobal, size);
	shuffleArray(numbersGlobal);
	quickSort(numbersGlobal, 0, size - 1);
	checkSort("Quick", numbersGlobal, size);
}//end main
/**************************************************************************/