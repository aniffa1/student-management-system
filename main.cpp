#include "student.h"
#include "studentfile.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int age,mark,id;
int student::count=0;
string name;
void deleteStudent(string name);
int search(string name);
void studentInput(){
    cout<<"Name: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    cout<<"mark: ";
    cin>>mark;
    cout<<"id: ";
    cin>>id;
}
void display(int i){
        cout<<"------------------------------"<<endl;
        cout<<"Name: "<<data[i].s.name<<endl;
        cout<<"Age: "<<data[i].s.age<<endl;
        cout<<"Mark: "<<data[i].s.mark<<endl;
        cout<<"Roll: "<<data[i].s.roll<<endl;
        cout<<"ID: "<<data[i].s.id<<endl;
        cout<<"------------------------------"<<endl;
    
}
void changeroll(){
    for(int i=0;i<data.size();i++){
        data[i].s.roll=i+1;
    }
}
fstudent f;
void saveandexit(){
    f.insert();
    cout<<"exiting..."<<endl;
}
int main(){
    cout<<"Welcome to student management system"<<endl;
    cout<<"dislplay(d), create(c), sort by name(n), sort by mark(m), search(s), delete(r), exit(e)"<<endl;
    while (true)
    {
        char cho;
        cout<<"enter:";
        cin>>cho;
        switch (cho)
        {
        case 'c':
        studentInput();
            {
                student s1(age,name,mark,id);
                data.push_back(s1);
            }
            break;
        case 'd':
        for(int i=0;i<data.size();i++){
            display(i);
        }
            break;
        case 'n':
        {
            cout<<"sorting by name"<<endl;
            sort(data.begin(),data.end(),[](const student& a, const student& b){
                return a.s.name < b.s.name;
            });
            changeroll();
        }
            break;
        case 'm':
        {
            cout<<"sorting by mark"<<endl;
            sort(data.begin(),data.end(),[](const student& a, const student& b){
                return a.s.mark > b.s.mark;
            });
        }
            break;
        case 's':
        {
            cout<<"enter name or roll number: ";
            cin>>name;
            int index = search(name);
            if(index != -1){
                display(index);
            }
        }
            break;
        case 'r':
        {
            cout<<"enter name or roll number: ";
            cin>>name;
            deleteStudent(name);
        }
            break;
        case 'e':
        saveandexit();
            exit(0);
        
        default:
        cout<<"invalid input"<<endl;
            break;
        }
    }
    return 0;
}
int search(string name){
    try{
        int roll=stoi(name);
        sort(data.begin(),data.end(),[](const student& a, const student& b){
            return a.s.roll < b.s.roll;
        });
        changeroll();
        return roll-1;
    }catch(const std::invalid_argument& e){
        for(int i=0;i<data.size();i++){
            if(strcmp(data[i].s.name,name.c_str())==0){
                return i;
            }
        }
        cout<<"student not found or invalid input"<<endl;
        return -1;
    }catch(const std::exception& e){
        cout<<"student not found"<<endl;
        return -1;
    }
}
void deleteStudent(string name){
    int index = search(name);
    if(index != -1){
        data.erase(data.begin()+index);
        changeroll();
        cout<<"student deleted successfully"<<endl;
    }
}