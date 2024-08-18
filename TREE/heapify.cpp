// heapify code
// usning indexing from 0
#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
    int main()
{
    // Array representation of Max-Heap
    //	5
    // / \
	//10  3
    /// \
	//2  4
    int arr[] = {5, 10, 3, 2, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    printArray(arr, n);

    return 0;
}
