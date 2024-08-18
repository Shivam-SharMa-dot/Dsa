// heapify means converting an array of eleement into heap tree
// here i am converting into max heap
#include <iostream>
#include <queue>
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
// converting an array into max heap tree 
// it 
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
void HeapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // step1 
        swap(arr[size], arr[1]);
        size--;

        // step2 put root at his position where he should
        heapify(arr, size, 1);
    }   
}
int main()
{

    /*    int arr[6] = {-1, 54, 53, 55, 52, 50};
       int n = 5;
       /// heap creation
       for (int i = n / 2; i > 0; i--)
       {
           heapify(arr, n, i);
       }
       cout << "printing tree after heapifying" << endl;
       for (int i = 1; i <= n; i++)
       {
           cout << arr[i] << " ";
       }
       cout << endl;
       // heap sort
       HeapSort(arr, n);

       cout << "printing tree after sorting" << endl;
       for (int i = 1; i <= n; i++)
       {
           cout << arr[i] << " ";
       } */
    // priority queue is same as max heap
    cout << "using priority queue " << endl;
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(4); 
    pq.push(9);
    cout << " the top element is " << pq.top() << endl;
    // all stl function can we use
    // now if we want to use min heap using stl
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(10);
    minheap.push(34);
    minheap.push(50);
    minheap.push(90);
    cout << minheap.top();
}
