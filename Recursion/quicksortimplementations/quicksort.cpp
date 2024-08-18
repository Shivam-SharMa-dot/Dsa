/* #include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int s, int e)
{
    
   int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    int realindex = s + cnt;
    swap(arr[realindex], arr[s]);
    // sort left and right part
    int i = s;
    int j = e;
    while (i < realindex && j > realindex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < realindex && j > realindex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return realindex;
}
void QuickSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    // sort left side
    QuickSort(arr, s, p - 1);
    // sort right side
    QuickSort(arr, p + 1, e);
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    QuickSort(arr, 0, arr.size() - 1);
    return arr;
}
int main()
{
    vector<int> arr = {5, 3, 2, 6, 4};
    vector<int> ans = quickSort(arr);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
 */
/* C++ implementation QuickSort using Lomuto's partition
Scheme.*/
#include<bits/stdc++.h>
using namespace std;

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element
	for (int j = low; j <= high- 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[] = {10, 7, 8, 5, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
