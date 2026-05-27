#include "student.h"
#include "studentfile.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int student::count=0;
void deleteStudent(string name);
int search(string name);
void changeroll(){
    for(int i=0;i<data.size();i++){
        data[i].roll=i+1;
    }
}
fstudent f(false);
void load(){
    data.clear();
    fstudent f;
}
void saveandexit(){
    f.insert();
    cout<<"data saved successfully"<<endl;
}
int main(){
    load();
    cout<<"Welcome to student management system"<<endl;
    cout<<"display(d), create(c), sort by name(n), sort by cgpa, search(s), delete(r), exit(e), count(0)"<<endl;
    while (true)
    {
        char cho;
        cout<<"enter:";
        cin>>cho;
        switch (cho)
        {
        case 'c':
            {
                student s1(true);
                data.push_back(s1);
            }
            break;
        case 'd':
        if(data.empty()){
            cout<<"student file is empty"<<endl;
        } else {
            for(int i=0;i<data.size();i++){
                data[i].display();
            }
        }
            break;
        case 'n':
        {
            cout<<"sorting by name"<<endl;
            sort(data.begin(),data.end(),[](const student& a, const student& b){
                return a.name < b.name;
            });
            changeroll();
        }
            break;
        case 'm':
        {
            cout<<"sorting by CGPA"<<endl;
            sort(data.begin(),data.end(),[](const student& a, const student& b){
                return a.cgpa>b.cgpa;
            });
        }
            break;
        case 's':
        {
            string name;
            cout<<"enter name or roll number: ";
            cin>>name;
            int index = search(name);
            if(index != -1){
                data[index].display();
            }
        }
            break;
        case 'r':
        {
            string name;
            cout<<"enter name or roll number: ";
            cin>>name;
            deleteStudent(name);
        }
            break;
        case 'e':
        {
            string name;
            cout<<"enter name or roll number: ";
            cin>>name;
            change(name);
        }
            break;
            case 'l':
            load();
            break;
        case '0':
        cout<<"number of students: "<<student::count<<endl;
            break;
        case '1':
        saveandexit();
            break;

        case 'x':
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
    if(data.empty()){
        cout<<"student file is empty"<<endl;
        return -1;
    }
    try{
        int roll=stoi(name);
        sort(data.begin(),data.end(),[](const student& a, const student& b){
            return a.roll < b.roll;
        });
        changeroll();
        return roll-1;
    }catch(const std::invalid_argument& e){
        for(int i=0;i<data.size();i++){
            if(strcmp(data[i].name,name.c_str())==0){
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
        student::count--;
    }
}
void change(string name){
    int index = search(name);
    if(index != -1){
        data[index].nameinput();
        data[index].ageinput();
        data[index].markinput();
        data[index].idinput();
        cout<<"student record updated successfully"<<endl;
    }
}