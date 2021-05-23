#include"bankdata.h"
#include<fstream>
#include<iostream>
using namespace std;
class Bankdata;
bool Bankdata::id_is_exist(std::string _id) {
    ifstream file;
    file.open("user_info.txt");
    if(file.is_open()) {
        while(!file.eof()) {
            string data1,data2,data3;
            file >> data1 >> data2 >> data3;
            if(data1 == _id) return true;
        }
        file.close();
        return false;
    }
    file.close();
    return false;
}
void Bankdata::add_account(string _id, string pass, string status) {
    ofstream balance;
    balance.open("user_balance.txt",ios_base::app|ios_base::out);
   /*  ifstream in;
    in.open("user_info.txt"); */
    ofstream file;
    file.open("user_info.txt",ios_base::app|ios_base::out);
    string file_name = _id+"_lichsugiaodich.txt";
    const char* fileDes = &file_name[0];
    ofstream newfile(fileDes);
    if(balance.is_open()) {
        balance << _id<<' '<<"0\n";
    }
    balance.close();
    if(file.is_open()){
        file << _id<<' '<<pass<<' '<<status<<'\n';
    }
    else {
        cout<<"error";
    }
    file.close();
    //in.close();
    //balance.close();
    newfile.close();
}

