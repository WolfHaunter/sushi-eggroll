/*
 * sp_nim.c
 *
 *      Author: Ariel
 */

#include "sp_nim.h"

int computeStep(int heapArray[], int arrSize, int* objectRemoved) {
	int winnerHeap = 0;
	int losingHeap = 0;
	int nimSum = computeNimSum(heapArray, arrSize);
	printf("DEBUG: Nim sum: %d\n", nimSum);
	if (nimSum != 0) {
		winnerHeap = findWinnerHeap(heapArray, arrSize, nimSum);
		*objectRemoved = heapArray[winnerHeap] ^ nimSum;
		heapArray[winnerHeap] = heapArray[winnerHeap] - *objectRemoved;
		return winnerHeap + 1;
	} else {
		losingHeap = findFirstPositiveHeap(heapArray, arrSize);
		*objectRemoved = 1;
		heapArray[losingHeap] = heapArray[losingHeap] - *objectRemoved;
		return losingHeap + 1;
	}
}

int computeNimSum(int heapArray[], int arrSize) {
	int nimSum = 0;
	int index = 0;
	for (; index < arrSize; index++) {
		nimSum ^= heapArray[index];
	}
	return nimSum;

}

int findWinnerHeap(int heapArray[], int arrSize, int nimSum) {
	int index = 0;
	int heapValue = 0;
	for(; index < arrSize; index++) {
		heapValue = heapArray[index] ^ nimSum;
		if (heapValue < heapArray[index]) {
			return index;
		}
	}
	// Default return value
	return 0;
}

int findFirstPositiveHeap(int heapArray[], int arrSize) {
	int index = 0;
	for(; index < arrSize; index++) {
		if (heapArray[index] > 0) {
			return index;
		}
	}
	// Default return value
	return 0;
}
