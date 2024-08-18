#include<bits/stdc++.h>
using namespace std;
class person{
    public:
     string name;
     int age;

     person(string name,int age){
        this->name=name;
        this->age=age;
        // cout<<"person class constructor" <<endl;
     }

     void display(){
        cout<<"name -" <<name <<endl;
     }
};

class student : public person{
    public:
    float cgpa;

    // student(){
    //     cout<<"this is child constructor" <<endl;
    //     // this->cgpa = cgpa;
    // }

    student(string name , int age, float cgpa) : person(name,age){
        this->cgpa=cgpa;
    }

    void getinfo(){
        cout<<"name "<<name << " "<<endl;
        cout<<"age "<<age << " "<<endl;
        cout<<"cgpa "<<cgpa << " "<<endl;
         
    }
};


int main(){
    student s1("shivam",21,8.7);
    s1.getinfo();
    person p1("rahul" ,25);
    p1.display();   

    return 0;
}