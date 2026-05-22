#ifndef STUDENTFILE_H
#define STUDENTFILE_H
#include "student.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
vector<student> data;
class fstudent{
    private:
    fstream file;
    public:
    fstudent(){
        file.open("student.txt",ios::binary|ios::in);
        if(!file){
            cout<<"file not found"<<endl;
        }
        else{
            student s;
            while(file.read((char*)&s,sizeof(s))){
                data.push_back(s);
            }
        }
        file.close();
    }
    void insert(){
        file.open("student.txt",ios::binary|ios::out);
        if(file){
            cout<<"writing to file..."<<endl;
        
        for(int i=0;i<data.size();i++){
            file.write((char*)&data[i],sizeof(data[i]));
        }
        file.close();
    }
    }
};
#endif