#include<iostream>
#include<stdlib.h>
#include <fstream>
#include<iomanip>
#include<string>
#include "display.h"
#include "account.h"
#include "bankdata.h"
using namespace std;
string Display::del_(string s) {
        for(int i = 0; i<s.length();++i) {
                if(s[i] == '_') s[i] =' ';
        }
        return s;
}
void Display::menh_gia_display() {
    cout<<"menh gia nho nhat: 50.000 VND\n"
        <<"menh gio lon nhat: 500.000 VND\n"
        <<"so tien ban muon gui phai la boi so cua 50.000\n"
        <<"so tien ban muon gui la:";
}
void Display::options_display() {
        cout << "Vui long chon:\n"
         << "1. hien so du\n"
         << "2. gui tien vao tai khoan\n"
         << "3. rut tien\n"
         << "4. lich su giao dich\n"
         << "5. thoat\n"
         << "vui nhap lua chon: ";
}
void Display::rut_tien_menh_gia()
{
        cout << "menh gia nho nhat: 50.000 VND\n"
         << "menh gio lon nhat: 500.000 VND\n"
         << "so tien ban muon rut phai la boi so cua 10.000\n"
         << "so tien ban muon rut la:";
}
void Display::history_display(const char *name)
{
        cout<<"_________________________________________\n";
        cout<<"|giao dich   "<<setw(13)<<"|  so tien  |"<<setw(13)<<"   trang thai |"<<endl;
        ifstream file;
        file.open(name);
        if(file.is_open()) {
                while(!file.eof()) {
                        string data1,data2,data3;
                        file >> data1 >> data2 >> data3;
                        cout<< " "<<del_(data2)<<setw(7)<<""<<del_(data1)<<setw(6)<<""<<del_(data3)<<endl;
                }
        }
        else{
                cout<<"-1";
        }
        file.close();
}
int Display::login_or_signin() {
        cout<<"bam '1' de dang nhap\n"
                <<"\nneu chua co tai khoan hay bam '2' de dang ki\n";
        char c; 
        cout<<"\nlua chon cua ban la: ";
        c = cin.get();
        cin.ignore();
        if (c == '1')
                return 1;
        if (c == '2')
                return 2;
        else{
                return 0;
        }
}
void Display::signup_screen() {
        string id ="",password ="";
        Bankdata B;
        //Account a;
        cout<<"id: ";
        cin >> id;
        if(B.id_is_exist(id) == true) {
                system("clear");
                //system("Color B4");
                cout<<"Tai khoan da ton tai vui long chon tai khoan khac\n"
                        <<"id: "; cin >> id;        
        }
        cout<<"password: ";
        cin >> password;
        B.add_account(id,password,"0");
        
}