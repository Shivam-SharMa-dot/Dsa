/*#include <bits/stdc++.h>
using namespace std;
int main()
{
     double arr[7] = {54, 34, 23, 23, 23, 34, 54};
    cout<<arr<<endl;
    cout<<*arr<<endl;
    cout<<arr+1<<endl;
    cout<<*(arr+1)<<endl;

    int temp[10];
    cout<<(&temp[1])<<endl;
    cout<<sizeof(temp)<<endl;
    cout<<"1st"<<sizeof(*temp)<<endl;//The size of any pointer is always 4/8  on your platform, so it's platform dependent.
    cout<<"2nd"<<sizeof(&temp)<<endl;

    int *ptr=&temp[0];
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;

   // char ch[6]="abcde";
   // char ch[6]={'r','t'};
   // cout<<ch<<endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
void calculate(int *p)
{
    cout << *p << endl;
}
void update(int *p)
{
    //  p=p+1;
    //  cout<<p<<endl;//address of p will be updated in function but not in main function
    // value can be updated
    *p = *p + 1;
    cout << *p << endl; // output 6
}

int main()
{
    int a = 5;
    int *s = &a;
    // calculate(s);
    // cout<<"before"<<s<<endl;    output same for both
    // update(s);
    // cout<<"after"<<s<<endl;
    /*   cout<<"before"<<*s<<endl; //outeput differnert because values can be updated
      update(s);
      cout<<"after"<<*s<<endl; */
    /*   int i = 5;
      int *ptr = &i;
      cout << &i << endl;
      cout << &(*ptr) << endl;
      cout << ptr << endl;


      int **ptr1 = &ptr;

      cout << **ptr1 << endl;
      cout << &(**ptr1) << endl;
      cout << ptr1 << endl; */
    // many mcq comes  in interview related to pointer
    /* int *ptr;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    int arr[10]={21,23,45,66};
    int *p=arr;
    cout<<p[2]<<endl; */

    /* float f=10.5;
    float p=2.5;
    float *ptr=&f;
    (*ptr)++;
    *ptr=p;
    cout<<*ptr<<" "<<f<<" "<<p<<endl; */

    /* char ch='a';
    char*ptr=&ch;
    ch++;
    cout<<*ptr<<endl; */

    /* int arr[]={4,5,6,7};
    //int *n=arr++;//gives error
    //int *p=(arr+1); //no error
    cout<<*arr+9; */

    char ch[] = "abcd";
    for (int i = 0; ch[i] != '\0'; i++)
    {
        cout << ch[i] << (*ch) + i << *(i + ch) << i[ch];
    }
}