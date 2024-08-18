#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    float cgpa;
    int *rollptr;
    student(string name,float cgpa,int roll){
        this->name=name;
        this->cgpa = cgpa;

        rollptr = new int;
        *rollptr= roll;
    }
    ~student(){
        cout<<"hi i am deleting everythin and will be called at last" <<endl;
        delete rollptr;
    }
    // copty constructor written manually
    // student (student &obj){
    //     this->name=obj.name;
    //     this->cgpa=obj.cgpa;
    //     this->rollptr=obj.rollptr;
    // }

    // copy constructor for deep copy
    student (student &obj){
        this->name=obj.name;
        this->cgpa=obj.cgpa;
        rollptr = new int;
        *rollptr=*obj.rollptr;
    }

    void getinfo(){
        cout<<name << " "<<endl;
        cout<<cgpa <<" "<<endl; 
        cout<<*rollptr<<" "<<endl;
    }
};


int main(){
    student s1("rahul",8.9,100);
    // s1.getinfo();
 // copy constructor called automatically we can write manually in class also
    // student s2(s1);
    // *(s2.rollptr) = 200;  // changed value of s2 roll but shallow copy so changes will be done in s1 also 
    // s1.getinfo();
    // s2.getinfo();

    // now deep copy 
    // s1 roll number is 100 and we are updating this with 200 so see only visible in second student
    student s2(s1);
    *(s2.rollptr) = 200;
    s1.getinfo();
    s2.getinfo();


    return 0;
}