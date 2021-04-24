#include"bankdata_h.h"
#include<fstream>
#include<iostream>
bool Bankdata::account_check(std::string id, std::string password)
{
    std::fstream file;
    file.open("account.txt");
    std::string tk,mk;
    while(!file.eof()){
        getline(file,tk,',');
        getline(file,mk);
        if(tk==id && mk==password){
            return true;
        }
    }
    return false;
}