#ifndef STUDENTFILE_H
#define STUDENTFILE_H
#include "student.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
map<int,s_details> studentmap;
bool checksave = true;
class fstudent{
    private:
    fstream file;
    public:
    fstudent(bool load){
        file.open("student.data",ios::binary|ios::in);
        if(!file){
            cout<<"file not found"<<endl;
        }
        else{
           int id;
           s_details s;
            while(file.read((char*)&id,sizeof(id))){
                file.read((char*)&s,sizeof(s));
                studentmap[id] = s;
            }
        }
        file.close();
        student::count=studentmap.size();
    }
    fstudent() : fstudent(true){}
    void insert(){
        file.open("student.data",ios::binary|ios::out);
        if(file){
            cout<<"writing to file..."<<endl;
        
        for(auto it:studentmap){
            file.write((char*)&it.first,sizeof(it.first));
            file.write((char*)&it.second,sizeof(it.second));
        }
        file.close();
    }
    }
};
#endif