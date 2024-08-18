#include <bits/stdc++.h>
using namespace std;
int Partition(vector<int> & nums ,int s,int e){
    int pivot = nums[s];
    int cnt =0;
    for(int i=s+1;i<e;i++){
        if(nums[i] < pivot){
            cnt++;
        }
    }
    // place pivot at right index
    int pivotindex=s+cnt;
    swap(nums[s],nums[pivotindex]);

    // now to sort ele on both side of pivot
    int i=s;
    int j=e;

    while(i < pivotindex && j > pivotindex ){
        while(nums[i] <= pivot){
            i++;         
        }
        while( nums[j] > pivot){
            j--;
        }
        // reached here means you swap condition arrived
        if(i <pivotindex && j> pivotindex){
            swap(nums[i++],nums[j--]);
        }
    }
    return pivotindex;
}

void Quicksort(vector<int> &nums, int s, int e)
{
    if(s>=e){
        return;
    }
// to get partition index
    int p=Partition(nums,s,e);

    // sort the left part
    Quicksort(nums,s,p-1);

    // sort right part 
    Quicksort(nums,p+1,e);
}


int main()
{
    vector<int> nums{58, 2, 4, 9, 61};
    int n = nums.size();
    int s = 0;
    int e = n - 1;
    Quicksort(nums, s, e);
    for(int i =0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}