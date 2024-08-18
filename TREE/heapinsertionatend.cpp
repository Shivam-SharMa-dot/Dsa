#include <iostream>
using namespace std;
// indexing of tree in this example is done from 0
 
#define MAX 1000 
// of size n following a Bottom-up approach
void heapify(int arr[], int n, int i)
{
	int parent = (i - 1) / 2;

	if (arr[parent] > 0) {
		if (arr[i] > arr[parent]) {
			swap(arr[i], arr[parent]);
			// Recursively heapify the parent node
			heapify(arr, n, parent);
		}
	}
}
void insertNode(int arr[], int& n, int Key)
{
	// Increase the size of Heap by 1
	n = n + 1;

	// Insert the element at end of Heap
	arr[n - 1] = Key;

	// Heapify the new node following a
	// Bottom-up approach
	heapify(arr, n, n - 1);
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	cout << "\n";
}

// Driver Code
int main()
{
	// Array representation of Max-Heap
	// 10
	// / \
	// 5 3
	// / \
	// 2 4
	int arr[MAX] = { 10, 5, 3, 2, 4 };

	int n = 5;

	int key = 15;

	insertNode(arr, n, key);

	printArray(arr, n);
	// Final Heap will be:
	// 15
	// / \
	// 5	 10
	// / \ /
	// 2 4 3
	return 0;
}
