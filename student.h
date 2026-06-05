#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
struct s_details{
    int age;
    float cgpa;
    char name[30];
};
extern bool checksave;
extern map<int,s_details> studentmap;

                   //check if name is valid

string checkalpa(string name){
    for(int i=0;i<name.length();i++){
        if(!isalpha(name[i])){
            cout<<"invalid name, only alphabets allowed"<<endl;
            return "";
        }
    }
    return name;
}
class student{
    private:
    s_details details;

    public:
    static int count;
    student(){}
    
    student(bool input) {
        if(input){
            try{
            cin.ignore();
            nameinput();
            ageinput();
            markinput();
            idinput();
            checksave = false;
            }catch(const int e){
            cout<<e<<endl;
            cout<<"returning to main menu..."<<endl;
            return;
            }catch(const invalid_argument& e){
                cout<<"invalid input, please enter valid data"<<endl;
                cout<<"returning to main menu..."<<endl;
                return;
            }
            catch(...){
                cout<<"unexpected error occurred"<<endl;
                cout<<"returning to main menu..."<<endl;
                return;
            }
        }
        count++;
    }
    static void studentdisplay(int sid){
        if(sid==-1) return;
        cout<<"------------------------------"<<endl;
        auto temp = studentmap[sid];
            cout<<"Id: "<<sid<<endl;
            cout<<"Name: "<<temp.name<<endl;
            cout<<"Age: "<<temp.age<<endl;
            cout<<"CGPA: "<<temp.cgpa<<endl;
        cout<<"------------------------------"<<endl;
    }
    void nameinput(){
       string name;
       cout<<"Name: ";
       getline(cin,name);
       if(checkalpa(name)!=""){
           strcpy(details.name,name.c_str());
           return;
       }
       nameinput();
    }

    void ageinput(){
        string age;
        cout<<"Age: ";
        cin>>age;
        details.age = stoi(age);
        if(details.age<1 || details.age>120){
            cout<<"invalid age, please enter a valid age"<<endl;
            ageinput();
            return;
        }
        
    }

    void markinput(){
            string cgpa;
        cout<<"CGPA: ";
        cin>>cgpa;
        details.cgpa = stof(cgpa);
        if(details.cgpa<0 || details.cgpa>10){
            cout<<"invalid cgpa, please enter a valid cgpa"<<endl;
            markinput();
            return;
        }
    }
    void idinput(){
        int id;
        string idstr;
        cout<<"id: ";
        cin>>idstr;
        id = stoi(idstr);
        if(studentmap.count(id)!=0){
            cout<<"id already exists, please enter a unique id"<<endl;
            idinput();
            return;
        }
        studentmap[id] = details;
        cout<<"student added successfully"<<endl;
    }
    void editstudent(int sid){
        cout<<"editing student details..."<<endl;
        try{
            nameinput();
            ageinput();
            markinput();
        }catch(const std::exception& e){
            cout<<"unexpected error occurred"<<endl;
            cout<<"returning to main menu..."<<endl;
            return;
        }
        studentmap[sid] = details;
        checksave = false;
        cout<<"student details updated successfully"<<endl;
    }


    
    
};

#endif
