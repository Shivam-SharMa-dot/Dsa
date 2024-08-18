#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void Merge(vector<int> &nums,int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // copy values
 
    for(int i =0;i<len1;i++){
       first[i] = nums[s + i];
    }
    // mainarrindex=mid+1;
    for(int i =0;i<len2;i++){
          second[i] = nums[mid + 1 + i];
    }
     int mainarrindex=s;
    // now merge two sorted arrays concept
    int i =0;
    int j=0;
    while(i<len1 && j<len2){
        if(first[i] < second[j]){
            nums[mainarrindex++]=first[i++];
        }
        else{
            nums[mainarrindex++]=second[j++];
        }
    }
    while( i < len1){
        nums[mainarrindex++]=first[i++];
    }
    while(j<len2){
        nums[mainarrindex++]=second[j++];
    }
    delete []first;
    delete []second;
}
void mergesort(vector<int> &nums,int s,int e){
     if(s >=e){
        return;
     }
     int mid=(s+e)/2;

     mergesort(nums,s,mid);

     mergesort(nums,mid+1,e);

     Merge(nums,s,e);
}
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
       mergesort(nums,0,n-1);
    return nums;
    }
};