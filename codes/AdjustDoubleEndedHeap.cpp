# include "headFile.h"

//void AdjustDoubleEndedHeap(StudentNumberNode *array, int i, int size) // i represents the position in the array, size means the double ended heap actually contains node number
int AdjustDoubleEndedHeap(StudentNumberNode *array, int i, int size) // i represents the position in the array, size means the double ended heap actually contains node number
{
	//int i = size - 1; // i represents the node number in array[] of the current operation
	int layer = (int)( log(i + 1) / log(2) );  // caculate which layer of the node is currently operating, round down
	int distanceOfBrothers = (int)pow(2, layer - 1);
	int boundryOfMinimum_MaximumHeap = (int)3 * pow(2, layer - 1) - 2 ; // to judge i position in minimum heap of maximum heap
	int tempNum; // a temporary variable for swap two integer number
	StudentNumberNode tempNode; //  a temporary struct for wap two node
	int parentNode; // the position of parent node
	int j; // loop variable
	int reallyAdjusted; // to determine whether the heap was really adjusted
	
	if(i <= boundryOfMinimum_MaximumHeap)  // if the current node belongs to the minimum heap
	{
		if(i + distanceOfBrothers <= size - 1)	// if the current node's brother node exist
		{
			// if the value of the current node is greater than the value of its brother node
			if(array[i].studentNumber > array[i + distanceOfBrothers].studentNumber) 
			{
				// swap the current node and its brother node
				/*   
					big fault, I did not exchange the node, but only the studentNumber
				
				tempNum = array[i].studentNumber;
				array[i].studentNumber = array[i + distanceOfBrothers].studentNumber;
				array[i + distanceOfBrothers].studentNumber = tempNum;
				*/
				tempNode = array[i];
				array[i] = array[i + distanceOfBrothers];
				array[i + distanceOfBrothers] = tempNode;
				
				
				// after swap, we just need to adjust the Heap which the brother node belongs to
				parentNode = ( (i + distanceOfBrothers) - 1) / 2; // calulate the parentNode position of the brother node
				for(; parentNode >= 2; parentNode = (parentNode - 1) / 2 ) // the value of the root node of the maximum heap is 2
				{
					reallyAdjusted = AdjustMaximumHeap(array, parentNode, size);
					if(reallyAdjusted == 0)  // if the heap need not to continue adjust
					{
						// really adjust
						return 0;
						//break;
					}
				}
				// really adjust
				return 1;	
			}else{
				parentNode = (i - 1) / 2; // calulate the parentNode position of the brother node
				for(; parentNode >= 1; parentNode = (parentNode - 1) / 2 ) // the value of the root node of the minimum heap is 2
				{
					reallyAdjusted = AdjustMinimumHeap(array, parentNode, size);
					if(reallyAdjusted == 0){  // if the heap need not to continue adjust
						// really adjust
						return 0;	
					//	break;
					}
				}
				// really adjust
				return 1;	
			}
			
		 }else{ // if the current node's brother node exist, compare the not exist brother's parent node
		 	// if the value of the current node is greater than the value of its brother node
		 	// i > 1 , debug this !!!! i == 1 is the root node of minimum heap 
			if(i > 1 && array[i].studentNumber > array[(i + distanceOfBrothers - 1) / 2].studentNumber) 
			{
				// swap the current node and its brother node
				/*
					big fault, I did not exchange the node, but only the studentNumber
				
				
				tempNum = array[i].studentNumber;
				array[i].studentNumber = array[(i + distanceOfBrothers - 1) / 2].studentNumber;
				array[(i + distanceOfBrothers - 1) / 2].studentNumber = tempNum;
				*/
				/*** 	I debug here, the current node exchange the brother's parent node, so I must exchange current node and the brother's parent node   ***/
				tempNode = array[i];
				array[i] = array[(i + distanceOfBrothers - 1) / 2];
				array[(i + distanceOfBrothers - 1) / 2]= tempNode;
				
				// after swap, we just need to adjust the Heap which the brother node belongs to
				parentNode = ( ((i + distanceOfBrothers - 1) / 2) - 1) / 2; // calulate the parentNode position of the brother node
				for(; parentNode >= 2; parentNode = (parentNode - 1) / 2 ) // the value of the root node of the maximum heap is 2
				{
					reallyAdjusted = AdjustMaximumHeap(array, parentNode, size);
					if(reallyAdjusted == 0){  // if the heap need not to continue adjust
						// really adjust
						return 0;	
						//break;
					}
				}
				// really adjust
					return 1;	
			}else{
				parentNode = (i - 1) / 2; // calulate the parentNode position of the brother node
				for(; parentNode >= 1; parentNode = (parentNode - 1) / 2 ) // the value of the root node of the minimum heap is 2
				{
					reallyAdjusted = AdjustMinimumHeap(array, parentNode, size);
					if(reallyAdjusted == 0){  // if the heap need not to continue adjust
						// really adjust
						return 0;	
						//break;
					}
				}
				// really adjust
				return 1;	
			}	
		 }
	}else{  // if the current node belongs to the maximum heap
			// if the value of the current node is smaller than the value of its brother node
			// i > 2 , debug this !!!! i == 2 is the root node of maximum heap
			if(i > 2 && array[i].studentNumber < array[i - distanceOfBrothers].studentNumber) 
			{
				// swap the current node and its brother node
				/*
					big fault, I did not exchange the node, but only the studentNumber
				tempNum = array[i].studentNumber;
				array[i].studentNumber = array[i - distanceOfBrothers].studentNumber;
				array[i - distanceOfBrothers].studentNumber = tempNum;
				*/
				
				/*** 	I debug here, the current node exchange the brother node, the current node should minus the distanceOfBrothers to get the brother node  ***/
				tempNode = array[i];
				array[i] = array[i - distanceOfBrothers];
				array[i - distanceOfBrothers] = tempNode;
				
				// after swap, we just need to adjust the Heap which the brother node belongs to
				parentNode = ( (i - distanceOfBrothers) - 1) / 2; // calulate the parentNode position of the brother node
				for(; parentNode >= 1; parentNode = (parentNode - 1) / 2 ) // the value of the root node of the minimum heap is 1
				{
					reallyAdjusted = AdjustMinimumHeap(array, parentNode, size);
					if(reallyAdjusted == 0){  // if the heap need not to continue adjust
						return 0;
						break;
					}
				}
				// really adjust
				return 1;	
			}else{
				parentNode = (i - 1) / 2; // calulate the parentNode position of the brother node
				for(; parentNode >= 2; parentNode = (parentNode - 1) / 2 ) // the value of the root node of the maximum heap is 2
				{
					reallyAdjusted = AdjustMaximumHeap(array, parentNode, size);
					if(reallyAdjusted == 0){  // if the heap need not to continue adjust
						// really adjust
						return 0;	
						//break;
					}
				}
				// really adjust
				return 1;	
			}
		  
	}
}
