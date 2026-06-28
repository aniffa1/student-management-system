#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<vector>
#include<map>
using namespace std;
struct s_details{
    int age;
    float cgpa;
    char name[30];
};
extern bool checksave;
class student;
int search(std::string name,student& obj);
//check if name is valid

string checkalpa(string& name){
    string sname;
    for(int i=0;i<name.length();i++){
        if(!isalpha(name[i])||isspace(name[i])){
            cout<<"invalid name, only alphabets allowed"<<endl;
            return "";
        }
        name[i]=toupper(name[i]);
    }
    return name;
}


                     //student class

class student{
    private:
    map<int,s_details> studentmap;
    s_details details;
    
    public:
    friend void readstudentfile(student& obj);
    friend void insert(auto& obj);
    static int count;
    student(){}
    void load(){
        studentmap.clear();
        readstudentfile(*this);
    }
    int isempty(){
    if(studentmap.empty()){
        cout<<"student file is empty"<<endl;
        return 1;
    }
    return 0;
}
    
    void addstudent() {
            try{
            cin.ignore();
            nameinput();
            ageinput();
            markinput();
            idinput();
            checksave = false;
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
        count++;
    }

    void studentdisplay(int sid){
        if(sid == -1) return;
        auto temp = studentmap[sid];
        cout<<"------------------------------"<<endl;
            cout<<"Id: "<<sid<<endl;
            cout<<"Name: "<<temp.name<<endl;
            cout<<"Age: "<<temp.age<<endl;
            cout<<"CGPA: "<<temp.cgpa<<endl;
        cout<<"------------------------------"<<endl;
    }

    void displayall(){
        for(auto it:studentmap){
            studentdisplay(it.first);
        }
    }

    void nameinput(){
       string name;
       cout<<"Name: ";
       getline(cin,name);
       if(name.length()>30){
           cout<<"name too long, please enter a name less than 30 characters"<<endl;
           nameinput();
           return;
       }
       if(name.length()<1){
           cout<<"name cannot be empty, please enter a name"<<endl;
           nameinput();
           return;
       }
       if(checkalpa(name)!=""){
           strcpy(details.name,name.c_str());
           return;
       }
       nameinput();
    }

    void ageinput(){
        while(true){
        string age;
        cout<<"Age: ";
        cin>>age;
        details.age = stoi(age);
        if(details.age<1 || details.age>120){
            cout<<"invalid age, please enter a valid age"<<endl;
        }else break;
    }
    }

    void markinput(){
        while(true){
            string cgpa;
        cout<<"CGPA: ";
        cin>>cgpa;
        details.cgpa = stof(cgpa);
        if(details.cgpa<0 || details.cgpa>10){
            cout<<"invalid cgpa, please enter a valid cgpa"<<endl;
        }else break;
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
    void deleteStudent(string name){
    int id = search(name,*this);
    if(id != -1){
        studentmap.erase(id);
        cout<<"student deleted successfully"<<endl;
        student::count--;
        checksave = false;
    }
}
    void editstudent(int sid){
        cout<<"editing student details..."<<endl;
        try{
            nameinput();
            ageinput();
            markinput();
        }catch(const invalid_argument& e){
            cout<<"Invalid input, returning to main menu..."<<endl;
            return;
        }
        catch(const std::exception& e){
            cout<<"unexpected error occurred"<<endl;
            cout<<"returning to main menu..."<<endl;
            return;
        }
        studentmap[sid] = details;
        checksave = false;
        cout<<"student details updated successfully"<<endl;
    }
    const map<int,s_details> getdetail() const{
        return studentmap;
    }
   
    
    
};

#endif
