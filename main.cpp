#include "studentfile.h"
#include "student.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int student::count=0;
void saveandexit(student& obj){
    insert(obj);
    checksave = true;
    cout<<"studentdata saved successfully"<<endl;
}
int search(std::string name,student& obj){
    try{
        int id = stoi(name);
        if(obj.getdetail().count(id)){
            return id;
        } else{
            cout<<"id not found"<<endl;
            return -1;
        }
    }catch(const std::invalid_argument& e){
            name = checkalpa(name);
            if(name!=""){
                for(auto it:obj.getdetail()){
                    if(name == it.second.name){
                        return it.first;
                    }
                }
                cout<<"not found"<<endl;
                return -1;
            }
        return -1;
    }catch(const std::exception& e){
        cout<<"unexpected error"<<endl;
        return -1;
    }
    return -1;
}
void sortbyname(student& obj){
    vector<pair<int,s_details>> v;
    for(auto it:obj.getdetail()){
        v.push_back(it);
    }
    sort(v.begin(),v.end(),[](pair<int,s_details> a,pair<int,s_details> b){
        return strcmp(a.second.name,b.second.name)<0;
    });
    for(auto it:v){
        obj.studentdisplay(it.first);
    }
}
void sortbycgpa(student& obj){
    vector<pair<int,s_details>> v;
    for(auto it:obj.getdetail()){
        v.push_back(it);
    }
    sort(v.begin(),v.end(),[](pair<int,s_details> a,pair<int,s_details> b){
        return a.second.cgpa > b.second.cgpa;
    });
    for(auto it:v){
        obj.studentdisplay(it.first);
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
    cout<<"\t\t9. save file"<<endl;
    cout<<"\t\t0. exit"<<endl;
}
int main(){
    menu();
    student s;
    s.load();
    while (true)
    {
        int choi;
        try{
            string cho;
            cout<<"\tenter:";
            cin>>cho;
        choi = std::stoi(cho);
        }
        catch(const std::exception& e){
            cout<<"invalid input, please enter a number"<<endl;
            continue;
        }
        switch (choi)
        {
        case 1:
            s.addstudent();
            break;
        case 2:
            if(s.isempty()) break;
            s.displayall();
        break;
        case 3:
            if(s.isempty()) break;
            sortbyname(s);
            break;
        case 4:
            if(s.isempty()) break;
            sortbycgpa(s);
            break;
            case 5:
            {
            if(s.isempty()) break;
            std::string name;
            cout<<"enter name or unique id: ";
            cin>>name;
            s.studentdisplay(search(name,s));
            }
            break;
            case 6:
        {
            string name;
            cout<<"enter name or unique id: ";
            cin>>name;
            if(s.isempty()) break;
            s.deleteStudent(name);
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
            if(s.isempty()) break;
            int id = search(name,s);
            if(id != -1){
                s.editstudent(id);
            }
        }
        break;
        case 9:
        saveandexit(s);
        break;
        
        case 0:
        if(!checksave){
            char choice;
            cout<<"you have unsaved changes, do you want to save before exiting? (y/n): ";
            cin>>choice;
            if(choice == 'y' || choice == 'Y'){
                saveandexit(s);
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
