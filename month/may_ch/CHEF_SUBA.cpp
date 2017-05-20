// C program to show segment tree operations like construction, query
// and update
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }


int minVal(int x, int y) { return (x > y)? x: y; }

// A utility function to get the middle index from corner indexes.
// int getMid(int s, int e) { return s + (e -s)/2; }

/* A recursive function to get the minimum value in a given range
	of array indexes. The following are parameters for this function.

	st --> Pointer to segment tree
	index --> Index of current node in the segment tree. Initially
			0 is passed as root is always at index 0
	ss & se --> Starting and ending indexes of the segment represented
				by current node, i.e., st[index]
	qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	// If segment of this node is a part of given range, then return
	// the min of the segment
	if (qs <= ss && qe >= se)
		return st[index];

	// If segment of this node is outside the given range
	if (se < qs || ss > qe)
		return INT_MIN;

	// If a part of this segment overlaps with the given range
	int mid = getMid(ss, se);
	return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
				RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

// Return minimum of elements in range from index qs (quey start) to
// qe (query end). It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		printf("Invalid Input");
		return -1;
	}

	return RMQUtil(st, 0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	// If there is one element in array, store it in current node of
	// segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements, then recur for left and
	// right subtrees and store the minimum of two values in this node
	int mid = getMid(ss, se);
	st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
					constructSTUtil(arr, mid+1, se, st, si*2+2));
	return st[si];
}

/* Function to construct segment tree from given array. This function
allocates memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[], int n)
{
	// Allocate memory for segment tree

	//Height of segment tree
	int x = (int)(ceil(log2(n))); 

	// Maximum size of segment tree
	int max_size = 2*(int)pow(2, x) - 1; 

	int *st = new int[max_size]; 

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n-1, st, 0);

	// Return the constructed segment tree
	return st;
}


 
/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range */
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (qs <= ss && qe >= se)
        return st[si];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes which have the given 
   index in their range. The following are parameters
    st, si, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is 
             in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
    // Base Case: If the input index lies outside the range of 
    // this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update 
    // the value of the node and its children
    st[si] = st[si] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start)
// to qe (query end).  It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int construct_STUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(ss, se);
    st[si] =  construct_STUtil(arr, ss, mid, st, si*2+1) +
              construct_STUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls construct_STUtil() to
   fill the allocated memory */
int *construct_ST(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    // Allocate memory
    int *st = new int[max_size];
 
    // Fill the allocated memory st
    construct_STUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
 
// Driver program to test above functions
int main()
{
	int n,p,k;
	cin>>n>>k>>p;
    int *arr=(int*)calloc(2*n,sizeof(int));
    // int n = sizeof(arr)/sizeof(arr[0]);
 	for (int i = 0; i < n; ++i)
 	{
 		cin>>arr[i];
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		arr[i+n]=arr[i];
 	}
    // Build segment tree from given array
    int *st = construct_ST(arr, n*2);

    // Print sum of values in array from index 1 to 3
    // printf("Sum of values in given range = %d\n",getSum(st, 2*n, 1, 3));
 	int start=n, end=2*n-1;
 	if (k>=n)
 	{
 		char ch;
 		int sum=getSum(st, 2*n, 0, n-1 );
 		for (int i = 0; i < p; ++i)
 		{
 			cin>>ch;
 			if (ch=='?')
 			{
 				cout<<sum<<endl;
 			}
 		}
 		return 0;
 	}
 	// int array[2*n-k+1];
	int array[2*n-k+1];
	for (int i = 0; i <= 2*n-k; ++i)
	{
		array[i]=getSum(st, 2*n, i, i+k-1 );
		// cout<<array[i]<<" ";	/* code */
	}
	// for (int i = 0; i < v.size(); ++i)
 	// {
 	// 	cout<<v[i];
 	// }
 	int *segtree = constructST(array, 2*n-k+1);
 	int qe = 2*n-k; // Starting index of query range
	int qs = n;// Ending index of query range
 	// int index=0;
 	for (int i = 0; i < p; ++i)
 	{
 		char ch;
 		cin>>ch;
 		//I am done//
 		if (ch=='!')
 		{
 			qs--;
 			qe--;
 			if (qs<0)
 			{
 				qs+=n;/////////////////////////////////////////////////////////////////////////////////TO BE EDITED 
 				qe+=n;/////////////////////////////////////////////////////////////////////////////////TO BE EDITED 
 			}
 		}
 		if (ch=='?')
 		{
 			cout/*<<qs<<" "<<qe<<" "<<*/<<RMQ(segtree, 2*n-k+1, qs, qe)<<endl;
 		}
 	}
 	
    // Find sum after the value is updated
    return 0;
}