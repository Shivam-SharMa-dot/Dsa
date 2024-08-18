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
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main()
{
    int arr[7] = {-1,20, 15, 26, 2, 98, 6};
    int n = 6;
    // here we are processing only nodes from i=1 to n/2 ; leaving leaf nodes
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    //  for (int i = n ; i > 0; i--)
    // {
    //     heapify(arr, n, i);
    // }
    cout << "printing tree after heapifying" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}