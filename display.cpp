#include<iostream>
#include <fstream>
#include<iomanip>
#include<string>
#include "display.h"

using namespace std;
string del_(string s) {
        for(int i = 0; i<s.length();++i) {
                if(s[i] == '_') s[i] =' ';
        }
        return s;
}
void menh_gia_display() {
    cout<<"menh gia nho nhat: 50.000 VND\n"
        <<"menh gio lon nhat: 500.000 VND\n"
        <<"so tien ban muon gui phai la boi so cua 50.000\n"
        <<"so tien ban muon gui la:";
}
void options_display() {
        cout << "Vui long chon:\n"
         << "1. hien so du\n"
         << "2. gui tien vao tai khoan\n"
         << "3. rut tien\n"
         << "4. lich su giao dich\n"
         << "5. thoat\n"
         << "vui nhap lua chon: ";
}
void rut_tien_menh_gia() {
        cout << "menh gia nho nhat: 50.000 VND\n"
         << "menh gio lon nhat: 500.000 VND\n"
         << "so tien ban muon rut phai la boi so cua 10.000\n"
         << "so tien ban muon rut la:";
}
void history_display(const char* name){
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