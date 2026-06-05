#include "student.h"
#include "studentfile.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int student::count=0;
fstudent f(false);
void load(){
    studentmap.clear();
    fstudent f;
}
int isempty(){
    if(studentmap.empty()){
        cout<<"student file is empty"<<endl;
        return 1;
    }
    return 0;
}
void saveandexit(){
    f.insert();
    checksave = true;
    cout<<"studentdata saved successfully"<<endl;
}
                                 //search

int search(string name){
    if(studentmap.empty()){
        cout<<"student file is empty"<<endl;
        return -1;
    }
    try{
        int id=std::stoi(name.c_str());
        if(studentmap.count(id)==0){
            cout<<"student not found"<<endl;
            return -1;
        }
        return id;
    }catch(const std::invalid_argument& e){
            name = checkalpa(name);
            if(name!=""){
                for(auto it:studentmap){
                    if(name == it.second.name){
                        student::studentdisplay(it.first);
                        return it.first;
                    }
                }
                cout<<"student not found"<<endl;
                return -1;
        }
        return -1;
    }catch(const std::exception& e){
        cout<<"student not found"<<endl;
        return -1;
    }
}

                     //delete student

void deleteStudent(string name){
    int id = search(name);
    if(id != -1){
        studentmap.erase(id);
        cout<<"student deleted successfully"<<endl;
        student::count--;
        checksave = false;
    }
}
void menu(){
    cout<<"\tWelcome to student management system"<<endl;
    cout<<"\t\t1. create new student"<<endl;
    cout<<"\t\t2. display all students"<<endl;
    cout<<"\t\t3. sort by name"<<endl;
    cout<<"\t\t4. sort by CGPA"<<endl;
    cout<<"\t\t5. search student"<<endl;
    cout<<"\t\t6. delete student"<<endl;
    cout<<"\t\t7. total student count"<<endl;
    cout<<"\t\t8. edit student details"<<endl;
    cout<<"\t\t0. exit"<<endl;
}
int main(){
    load();
    menu();
    while (true)
    {
        int choi ;
        try{
            string cho;
            cout<<"\tenter:";
            cin>>cho;
        choi = stoi(cho);
        }
        catch(const std::exception& e){
            cout<<"invalid input, please enter a number"<<endl;
            continue;
        }
        switch (choi)
        {
        case 1:
        {
             student s1(true);
        }
            break;
        case 2:
            if(isempty()) break;
            for(auto it:studentmap){
                student::studentdisplay(it.first);
            }
        break;
        case 3:
            break;
        case 4:
        
            break;
            case 5:
            {
            string name;
            cout<<"enter name or unique id: ";
            cin>>name;
            if(isempty()) break;
            student::studentdisplay(search(name));
        }
            break;
            case 6:
        {
            string name;
            cout<<"enter name or unique id: ";
            cin>>name;
            if(isempty()) break;
            deleteStudent(name);
        }
        break;
        case 7:
        cout<<"number of students: "<<student::count<<endl;
        break;
        case 8:
        {
            string name;
            cout<<"enter name or unique id: ";
            cin>>name;
            if(isempty()) break;
            int id = search(name);
            if(id != -1){
                student s;
                s.editstudent(id);
            }
        }
        break;
        case 9:
        saveandexit();
        break;
        
        case 0:
        if(!checksave){
            char choice;
            cout<<"you have unsaved changes, do you want to save before exiting? (y/n): ";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                saveandexit();
            }
            else
                cout<<"exiting without saving..."<<endl;
            
        }
        exit(0);
        
        default:
        cout<<"invalid input"<<endl;
        break;
    }
    }
    return 0;
}