#include <bits/stdc++.h>
using namespace std;
int getsum(int *arr, int size)
{
    if ( size == 1)
    {
        return arr[0];
    }
    if(size==0)  return 0;
    
        int ans = getsum(arr + 1, size - 1);
        return ans+arr[0];
    
}
int main()
{

    int arr[5] = {1, 3, 4, 6, 7};
    cout << getsum(arr, 5) << endl;
    return 0;
}