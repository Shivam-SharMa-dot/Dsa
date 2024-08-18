// minheap formation inser using heapify function

#include <iostream>
#include <vector>

using namespace std;
class MinHeap
{
    vector<int> heap;

    void heapifyUp(int index)
    {
        // if parent is 
        while (index > 0 && heap[(index - 1) / 2] > heap[index])
        {
            // Swap the element with its parent if parent is smaller than it's childs
            swap(heap[(index - 1) / 2], heap[index]);
            // Move to the parent's index
            index = (index - 1) / 2;
        }
    }
// Deletion
    void heapifyDown(int index)
    {
        int smallest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // Compare with left child
        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;

        // Compare with right child
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        // If the smallest is not the current index, swap and continue
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            // Recursively heapify the affected sub-tree
            heapifyDown(smallest);
        }
    }

public:
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void remove()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getMin()
    {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    void printHeap()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap h;
    h.insert(3);
    h.insert(2);
    h.insert(15);
    h.insert(5);
    h.insert(4);
    h.insert(45);
    h.printHeap();
    cout << "Min value: " << h.getMin() << endl;
    h.remove();
    h.printHeap();
    return 0;
}
