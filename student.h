#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class student{
    public:
    int age;
    int roll;
    float cgpa;
    int id;
    char name[30];
    static int count;
    student (){}
    student(bool input){
        if(input){
            nameinput();
            ageinput();
            markinput();
            idinput();
        }
        count++;
        roll=count;
    }
    
    void display(){
        cout<<"------------------------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"CGPA: "<<cgpa<<endl;
        cout<<"Roll: "<<roll<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"------------------------------"<<endl;
    }
    void nameinput(){
        cout<<"Name: ";
        string sname;
        getline(cin,sname);
        cin.ignore();
        char cname[30];
        strcpy(cname,sname.c_str());
        for(int i=0;i<strlen(cname);i++){
            if(!isalpha(cname[i]))
                cout<<"invalid name, only alphabets allowed"<<endl;
            else
            name[i] = toupper(cname[i]);
        }
    }
    void ageinput(){
        cout<<"Age: ";
        cin>>age;
    }
    void markinput(){
        cout<<"CGPA: ";
        cin>>cgpa;
    }
    void idinput(){
        cout<<"id: ";
        cin>>id;
    }


    
    
};
extern vector<student> data;

#endif
