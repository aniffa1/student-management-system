#ifndef STUDENTFILE_H
#define STUDENTFILE_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"student.h"
using namespace std;
bool checksave = true;
class student;
struct s_details;

    void readstudentfile(student& obj){
         fstream file;
        file.open("student.data",ios::binary|ios::in);
        if(!file){
            cout<<"file not found"<<endl;
        }
        else{
           int id;
           s_details s;
            while(file.read((char*)&id,sizeof(id))){
                file.read((char*)&s,sizeof(s));
                obj.studentmap[id] = s;
            }
        }
        file.close();
        student::count=obj.studentmap.size();
    }
    void insert(auto& obj){
        fstream file;
        file.open("student.data",ios::binary|ios::out);
        if(file){
            cout<<"writing to file..."<<endl;
        
        for(auto it:obj.studentmap){
            file.write((char*)&it.first,sizeof(it.first));
            file.write((char*)&it.second,sizeof(it.second));
        }
        file.close();
    }
    }
#endif
