#include<iostream>
using namespace std;

class Student{
    public:
    char name[20];
    int age;
    int rollNo;

    //default
    Student(){
        cout<<"Default Constructor called =>"<<'\n';
    }
    Student(int a){
        cout << "Constructor-1 called =>" << '\n';
        age = a;
    }
    Student(int a,int r=510518071){
        cout << "Constructor-2 called =>" << '\n';
        age = a;
        rollNo = r;
    }
    void display(){
        cout << "age = "<<age<<", rollNo = "<<rollNo<<'\n';
    }
    void setRollNo(int r){
        rollNo=r;
    }
};

int main(){
    Student* s1 = new Student;
    s1->display();    
    
    Student s2(10,2345);
    s2.display();

    delete [] s1;
    return 0;
}