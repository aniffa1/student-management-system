#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
struct info{
    int age;
    int roll;
    int mark,id;
    char name[30];

};
class student{
    private:
    static int count;
    public:
    info s;
    student(){
        cout<<"running student deails constructor"<<endl;
    }
    
    student(int age,string name,int mark,int id){
        s.age=age;
        strcpy(s.name,name.c_str());
        s.mark=mark;
        count++;
        s.roll=count;
        s.id=id;
    }


    
    
};
extern vector<student> data;

#endif
