#include<iostream>
#include<fstream>
#include<sstream>
#include "account.h"
using namespace std;
Account::Account(string a){
    ifstream file;
    file.open("user_balance.txt");
    /* string s;
    getline(file, s); */
    if (file.is_open())
    {
            string _id,money;
            int l;
        while(!file.eof())
        {
            file >> _id;
            file >> money;
            if (_id == a )
            {   
                id = _id;
                view_so_du = money;
                file.close();
            }
        }
    }
    
}
string Account::get_Id(){
    return this->id;
};
string Account::check_so_du()
{   
    return this->view_so_du;
};

Account::Account(){
    so_du = 0;
}
bool Account::rut_tien(int tien_rut,string _id){
    ifstream file;
    file.open("user_balance.txt");
    ofstream f;
    f.open("new_user_balance.txt");
    if (file.is_open())
    {
        string _id, n;
        string value;
        double num;
        while (file >> _id >> n)
        {
            if (_id == id)
            {
                stringstream s;
                s << n;
                s >> num;
                s.clear();
                if (num < double(tien_rut))
                    return false;
                else
                {
                    num = num -double(tien_rut);
                    s << num;
                    s >> value;
                    n = value;
                    s.clear();
                }
            }
            n += '\n';
            f << _id << " " << n;
        }
    }
    f.close();
    file.close();
    remove("user_balance.txt");
    rename("new_user_balance.txt", "user_balance.txt");
    return true;
}
// done
void Account::gui_tien(int money,string id){
    ifstream file;
    file.open("user_balance.txt");
    ofstream f;
    f.open("new_user_balance.txt");
    if(file.is_open()){
        string _id, n;
        string value;
        double num;
        while(file >> _id >>n) {
            if(_id == id){
                stringstream s;
                s << n;
                s >> num;
                s.clear();
                num = num + double(money);
                s << num;
                s >> value;
                n = value;
                s.clear();
            }
        n+='\n';
        f<<_id<<" "<<n;
        }
    }
    file.close();
    f.close();
    remove("user_balance.txt");
    rename("new_user_balance.txt","user_balance.txt");
}