#include<bits/stdc++.h>
using namespace std;
void selectionsort(vector<int > arr,int n){
    for(int i=0;i<n ;i++){
        int minindex=i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] <arr[minindex]){
                minindex=j;
            }
        }
        swap(arr[i],arr[minindex]);
    }
}
int main(){


    return 0;
}