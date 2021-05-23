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
bool Bankdata::status_check(string s, string p)
{
    ifstream file;
    file.open("user_info.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            string _id, _pass;
            int status;
            file >> _id >> _pass;
            file >> status;
            if (_id == s && _pass == p)
            {
                if (status == 1)
                    return false;
                return true;
            }
        }
    }
    file.close();
    return true;
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
bool Bankdata::ques_check(string ques, string ans, const char *filename) {
    ifstream file;
    file.open(filename);
    if(file.is_open()) {
        string data1 , data2 ;
        getline(file,data1,'\n');
        getline(file,data2);
        if(data1 == ques && data2 == ans){
            file.close();
            return true;
        }
    }
    //capnhatlaitrangthai
    file.close();
    return false;
}
void Bankdata::khoa_tai_khoan(string s)
{
    ofstream file_out;
    file_out.open("temp.txt", ios::app | ios::out);
    ifstream file_in;
    file_in.open("user_info.txt");
    if (file_in.is_open())
    {
        while (!file_in.eof())
        {
            string _id, _pass;
            int status;
            file_in >> _id >> _pass >> status;
            if (_id == s)
            {
                status = 1;
            }
            file_out << _id << ' ' << _pass << ' ' << status << '\n';
        }
        file_out.close();
        file_in.close();
        remove("user_info.txt");
        rename("temp.txt", "user_info.txt");
    }
}
void Bankdata::mo_tai_khoan(string s)
{
    ofstream file_out;
    file_out.open("temp.txt", ios::app | ios::out);
    ifstream file_in;
    file_in.open("user_info.txt");
    if (file_in.is_open())
    {
        while (!file_in.eof())
        {
            string _id, _pass;
            int status;
            file_in >> _id >> _pass >> status;
            if (_id == s)
            {
                status = 0;
            }
            file_out << _id << ' ' << _pass << ' ' << status << '\n';
        }
        file_out.close();
        file_in.close();
        remove("user_info.txt");
        rename("temp.txt", "user_info.txt");
    }
}