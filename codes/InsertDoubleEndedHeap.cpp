# include "headFile.h"

void InsertDoubleEndedHeap(StudentNumberNode *array, StudentNumberNode insertElement, int size) // size is the array[] actually size 
{
	if(size <= 0) // if the double ended heap is null
	{
		// make the root of double ended heap always not null
		// array[1] = insertElement;
		// size += 2;
		printf("error, the double ended heap at least contains one element in its root node\n");
		exit(-1);
	}else{
		array[size] = insertElement;
		size += 1; // the total elements in array[] plus one after inserted the insertElement
		//BuildDoubleEndedHeap(array, size);
		AdjustDoubleEndedHeap(array, size - 1, size);
	}
}
