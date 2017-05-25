# include "headFile.h"

void BuildDoubleEndedHeap(StudentNumberNode *array, int size)  // build double ended heap function
{
	int i; // loop variable
	for(i = size - 1; i >= 1; i--) // adjust double ended heap from the last leaf node
	{
		AdjustDoubleEndedHeap(array, i, size);
	}
}
