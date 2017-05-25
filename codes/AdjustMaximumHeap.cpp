#include "headFile.h"

int AdjustMaximumHeap(StudentNumberNode *array, int i, int size) // size is the array size, i represents the position in the array
{
	int leftChild = 2 * i + 1;	 // the left child node is twice the value of the parent node 
	int rightChild = 2 * i + 2; // the right child node is equal to twice the value of the parent node plus one
	int max = i;  // the temporary location of the largest node
	StudentNumberNode temp;		 // exchange two node
	
	if(i <= size / 2 - 1)  // starting from the last none-leaf node
	{  
		if(leftChild <= size - 1 && array[leftChild].studentNumber > array[max].studentNumber)	
			max = leftChild;
		if(rightChild <= size - 1 && array[rightChild].studentNumber > array[max].studentNumber)
			max = rightChild;
		if(max != i)
		{
			/*
			array[i] = array[i]^array[max];
			array[i] = array[i]^array[max];
			array[i] = array[i]^array[max];
			*/
			
			// exchange two numbers
			temp = array[i];
			array[i] = array[max];
			array[max] = temp;
										  // 避免調整以後以 max 為父節點的子樹不滿足最大堆 
			AdjustMaximumHeap(array, max, size); // Avoid the adjustment of the parent tree with max as the parent does not satisfy the maximum heap
			
			return 1;  // if it is really adjusted , return 1
		}
		return 0;	// if it is not adjusted, return 0 
	}
	return 0;  // if it is not adjusted
}	
