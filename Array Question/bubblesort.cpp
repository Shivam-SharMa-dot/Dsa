#include<bits/stdc++.h>
using namespace std;
void Bubblesort(vector<int > arr,int n){
    for(int i=1;i<n;i++){
        bool mark =false;
        for(int j=0;j<n-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                mark=true;
            }   
        }
        if(mark == false){ 
            break;
        }
    }
}

int main(){


    return 0;
}