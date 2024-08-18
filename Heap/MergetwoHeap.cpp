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
class Solution{
    public:
    void Heapify(vector<int > &arr,int n,int i){
        int largest = i;
        int left = 2*i+1;
        int right =2*i + 2;
       
            if(left < n  && arr[largest] < arr[left] ){
                largest=left;
            }
            if(right < n && arr[largest]  < arr[right]){
                largest=right;
            }
           
           if(largest !=i){
               swap(arr[largest],arr[i]);
               Heapify(arr,n,largest);
           }
        
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector< int > c;
        for(auto x:a)
        c.push_back(x);
        
        for(auto x:b)
        c.push_back(x); 
        
        int size=c.size();
        
        
        for(int i=size;i>=0;i--){
            Heapify(c,size,i);
        }
        
        return c;
    }
};