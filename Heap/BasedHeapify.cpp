// heapify means converting an array of eleement into heap tree
// here i am converting into max heap
#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        // max heap of size 100 can be created
        // arr[100];
        size = 0;
    }
};
// converting an array into heap tree
// see carefully here indexing is starting from 0 so if start from 1 then we have to do changes as left<=n or right<=n and in indexing also
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void HeapSort(int arr[], int n)
{
      // Step 1: Build max heap from the array
    for (int i = (n - 2) / 2; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements from the heap one by one
    for (int size = n - 1; size > 0; size--) {
        // Swap the root (maximum element) with the last element of the heap
        swap(arr[size], arr[0]);

        // Heapify the reduced heap
        heapify(arr, size, 0);
    }
}
int main()
{
    int arr[6] = {20, 15, 26, 2, 98, 6};
    int n = 6;
    // here we are processing only nodes from i=1 to n-2/2 ; leaving leaf nodes in zero based indexing
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "printing tree after heapifying" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    HeapSort(arr, n);
    cout << "printing tree after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}