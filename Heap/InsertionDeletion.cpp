// this code is for max heap
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
    void insert(int val)
    {
        size = size + 1;
        int i = size;
        arr[i] = val;
        
        while (i > 1)
        {
            // checking if parent is smaller than the child or not
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
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    // we are deleting from root not element wise
    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "Heap is empty nothing to delete" << endl;
            return;
        }
        // step1 put last element to root
        arr[1] = arr[size];
        // step2 remove last element
        size--;

        // step3 check if root is at his proper place or not if not then do operation
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);     
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
};
int main()
{
    Heap obj;
    obj.insert(50);
    obj.insert(55);
    obj.insert(53);
    obj.insert(52);
    obj.insert(54);
    obj.print();
    obj.deletefromHeap();
    obj.print();

    return 0;
}


