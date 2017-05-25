# include <stdio.h>
# include <stdlib.h>
# include <math.h>

//debug
#include <time.h>

typedef struct node
{
	int serialNumber; // serial number
	int studentNumber;  // serial number correspond number 
}StudentNumberNode;

int AdjustMinimumHeap(StudentNumberNode *, int, int); // size is the array size, i represents the position in the array
int AdjustMaximumHeap(StudentNumberNode *, int, int); // size is the array size, i represents the position in the array
int AdjustDoubleEndedHeap(StudentNumberNode *, int, int); // i represents the position in the array, size means the double ended heap actually contains node number
void BuildDoubleEndedHeap(StudentNumberNode *, int); // build double ended heap function
void InsertDoubleEndedHeap(StudentNumberNode *, StudentNumberNode, int); // size is the array[] actually size 
