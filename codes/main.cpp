#include "headFile.h"

#define NODE_ARRAY_SIZE 1300

int main() { 
	StudentNumberNode nodeArray[NODE_ARRAY_SIZE]; // nodeArray array
	StudentNumberNode tempNodeArray; // temporary nodeArray 
	int i,j; // loop variable
	srand(time(NULL));
	
	j=1;
	for(i = 19; i >= 13; i--)
	{
		tempNodeArray.serialNumber = i;
		tempNodeArray.studentNumber = rand() * 100;
		//tempNodeArray.studentNumber = i * 100;
		
		//nodeArray[i] = tempNodeArray;
		InsertDoubleEndedHeap(nodeArray, tempNodeArray, j++);
	} 
	
	
		StudentNumberNode tempNode;
		int size = 8; 
		int count = 0;
		for(count = 0; count < 3; count ++){
			tempNode = nodeArray[1];
			nodeArray[1] = nodeArray[size-count-1];
			nodeArray[size-count-1] = tempNode;
			
			BuildDoubleEndedHeap(nodeArray, size-count-1);
		}
	
    //BuildDoubleEndedHeap(nodeArray, i);
	//BuildMinimumHeap(nodeArray, i);
	//BuildMaximumHeap(nodeArray, i);
		
	return 0;
}
