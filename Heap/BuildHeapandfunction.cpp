// this code is for max heap
#include <iostream>
using namespace std;
class Heap
{
public:
    int capacity;  // max heap size
    int heap_size; // Current number of elements in max heap
    int *arr;
    Heap(int cap)
    {
       // arr[0]=-1;    // from this there will be no garbage value at first index
        capacity = cap;
        heap_size = 0;
        arr = new int[cap];
    }
    int getMax() { return arr[1]; }
    void insert(int val)
    {
        if (heap_size == capacity)
        {
            cout << "cannot insert more capacity of heap is full" << endl;
            return;
        }
        heap_size = heap_size + 1;
        int i = heap_size;
        arr[i] = val;
        while (i > 1)
        {
            int parent = i / 2;
            if (arr[i] > arr[parent])
            {
                swap(arr[i], arr[parent]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= heap_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap obj(20);
    obj.insert(50);
    // obj.insert(55);
    // obj.insert(53);
    // obj.insert(52);
    // obj.insert(54);
    obj.print();
   cout << obj.getMax();

    return 0;
}