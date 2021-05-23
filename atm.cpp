#include "atm_h.h"
#include "account.h"
#include "guitien.h"
#include "display.h"
#include "bankdata.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <stdlib.h>
#include<string>
using namespace std;
class Account;
class Display;
/* class Gui_tien; */

int value[5] ={500000,200000,100000,50000,10000};
int count[5]={0,0,0,0,0};
void hoptien_update(int arr[]) {
    ifstream f;
    f.open("hoptien.txt");
    ofstream file;
    file.open("_newhoptien.txt",ios::app|ios::out);
    if(f.is_open() ) {
        int i = 0;
        while(!f.eof()) {
        int data ,count;
        f >> data >> count;
        count = arr[i];
        if(data == value[i] ){
            file<<data<<' '<<count<<'\n';
            i++;
        }
        }
        file.close();
        f.close();
        remove("hoptien.txt");
        rename("_newhoptien.txt","hoptien.txt");
    }
}
int laysoluong(int n) {
    ifstream f;
    f.open("hoptien.txt");
    if(f.is_open()) {
        while(!f.eof()) {
            int data , soluong;
            f >> data >> soluong;
            if(data == n ) return soluong;
        }
    }
    return 0;
}
void greedy(int n){
    int sl[5]={0,0,0,0,0};
    for(int i = 0 ; i< 5;i++) {
        sl[i] = laysoluong(value[i]);
        //cout<<sl[i] <<" ";
    }
    if(sl[0]!= 0){
        int _count = 0;
        while(sl[0] != 0 && n >= value[0]) {
            _count++;
            n = n - value[0];
            sl[0] -= 1;
            if(sl[0] == 0) break;
        }
        //cout<<sl[0];
        count[0] = _count;
    }
    if(sl[1]!= 0){
        int _count = 0;
        while(sl[1]!= 0 && n >= value[1]) {
            _count++;
            n = n - value[1];
            sl[1]-= 1;
            if(sl[1]== 0) break;
        }
        count[1] = _count;
    }
    if(sl[2]!= 0){
        int _count = 0;
        while(sl[2] != 0 && n >= value[2]) {
            _count++;
            n = n - value[2];
            sl[2] -= 1;
            if(sl[2] == 0) break;
        }
        count[2] = _count;
    }
    if(sl[3]!= 0){
        int _count = 0;
        while(sl[3] != 0 && n >= value[3]) {
            _count++;
            n = n - value[3];
            sl[3] -= 1;
            if(sl[3] == 0) break;
        }
        count[3] = _count;
    }
    if(sl[4]!= 0){
        int _count = 0;
        while(sl[4] != 0 && n >= value[4]) {
            _count++;
            n = n - value[4];
            sl[3] -= 1;
            if(sl[3] == 0) break;
        }
        count[3] = _count;
    }
    cout<<"\n";
    if(n != 0 ) cout<<" none";
    else {
    for(int i = 0; i<5;i++){
        if(i==0)cout<<"so to 500.000: "<<count[i]<<"\n";
        if(i==1)cout<<"so to 200.000: "<<count[i]<<"\n";
        if(i==2)cout<<"so to 100.000: "<<count[i]<<"\n";
        if(i==3)cout<<"so to 50.000: "<<count[i]<<"\n";
        if(i==4)cout<<"so to 10.000: "<<count[i]<<"\n";
    }
    }    hoptien_update(sl);
    //cout<<"\n"<<sl[4];
}
bool atm::check_acc(string acc,string pass){
    ifstream file;
    file.open("user_info.txt");
    /* string s;
    getline(file,s); */
    if(file.is_open()){
        while(!file.eof()){
            string _id,_pass;
            int status;
            file >> _id >>_pass;
            if(_id == acc && _pass == pass){ 
                file.close();
                return true;
            }
            file >> status;
        }
    }
    file.close();
    return false;
}
//check status;
bool atm::status_check(string s,string p) {
    ifstream file;
    file.open("user_info.txt");
    if(file.is_open()){
        while(!file.eof()){
            string _id,_pass;
            int status;
            file >> _id >>_pass;
            file >> status;
            if(_id == s && _pass == p){ 
                if(status == 1) return false;
                return true;
            }
        }
    }
    file.close();
    return true;
}
void atm::khoa_tai_khoan(string s){
    ofstream file_out;
    file_out.open("temp.txt",ios::app|ios::out);
    ifstream file_in;
    file_in.open("user_info.txt");
    if(file_in.is_open()) {
        while(!file_in.eof()) {
            string _id,_pass;
            int status;
            file_in>>_id >> _pass >> status;
            if(_id == s) {
                status = 1;
            }
            file_out<<_id<<' '<<_pass<<' '<<status<<'\n';
        }
        file_out.close();
        file_in.close();
        remove("user_info.txt");
        rename("temp.txt","user_info.txt");
    }
}
//Truyen vao account de thao tac voi cai account
void atm::login_screens(){
    Display D;
    int option = D.login_or_signin();
    if(option == 1) {
        system("clear");
        atm_working();
    }
    else if(option == 2) {
        D.signup_screen();
        system("clear");
        cout<<"Dang ki thanh cong!\nBam phim bat ki de tro lai man hinh lam viec\n";
        char c; 
        c =cin.get();
        cin.ignore();
        system("clear");
        login_screens();
    }

}
void atm::menu(Account _a) {
    //window
    //system("CLS");
        // linux
        system("clear");
        Display d;
        d.options_display();
        int n ;
        cin >> n;
        switch(n){
            case 1:
                //window
                //system("CLS");
                    // linux
                //system("clear");
                menu_sodu(_a);
                tiep_tuc_giao_dich(_a);
                break;
            case 2:
                guitien_display(_a);
                tiep_tuc_giao_dich(_a);
                break;
            case 3:
                _rut_tien(_a);
                tiep_tuc_giao_dich(_a);
                break;
            case 4:
                history_show(_a);
                tiep_tuc_giao_dich(_a);
                break;
            case 5:
                //window
                //system("CLS");
                    // linux
                    system("clear");
                login_screens();
            break;
        };
}
void atm::menu_sodu(Account _a){
    system("clear");
    cout<<"so du cua ban la:"<<fixed<<int(get_Balance(_a)); 
}
// kiem tra so du
double atm::get_Balance(Account _a){
    ifstream  file;
    file.open("user_balance.txt");
    if(file.is_open()){
        string id;
        double n;
        string s =_a.get_Id();
        while(!file.eof()){
            file >> id >>n;
            if(id == s) return n;
        }
    }
    file.close();
    return -1;
}
//gui tien
void atm::guitien_display(Account _a){
    //window
    //system("CLS");
        // linux
        system("clear");
    //guitien.h
    Display d;
    d.menh_gia_display();
    int money = nhap_so_tien();
    string _money = stringConvert(money);
    while(moneyCheck(money,_money) != true ) history_Update(_a,_money,"gui_tien","that_bai");
    //guitien.h
    //lay id de kiem tra so du cua id day
    string s = _a.get_Id();
    history_Update(_a,_money,"gui_tien","thanh_cong");
    //hoptien(money);
    _a.gui_tien(money,s);
}
//So tien co trong cay atm
void atm::_rut_tien(Account _a){
    // viet lai rut tien
    system("clear");
    Display d;
    d.rut_tien_menh_gia();
    int money = 0;
    cin >> money;
    string _money = stringConvert(money);
    if (money < 10000  || check_boi_so(money) == false) {
        {
            cout << "so tien vua nhap khong hop le vui long nhap lai!\n"
                 << "so tien ban muon gui la:";
            cin >> money;
        } while (money < 10000 || check_boi_so(money) == false);
    }
    string s = _a.get_Id();
    if(_a.rut_tien(money,s)==true) {
        cout<<"Rut tien thanh cong!\n";
        greedy(money);
        cout<<"so du con lai cua ban la:"<<fixed<<int(get_Balance(_a));
        history_Update(_a,_money,"rut_tien","thanh_cong");
        //menu_sodu(_a);
    }
    else{
        cout<<"Xin loi so du con lai khong the thuc hien dao dich nay!";
        history_Update(_a,_money,"rut_tien","that_bai");
    }
}
//check point
void atm::tiep_tuc_giao_dich(Account _a){
    cout<<"\nTiep tuc dao dich nhap? [Y]/[N] \n";
    char c ;
    cin >> c;
    if(c == 'Y'){
        menu(_a);
    }
    else{
        cout<<"Cam on quy khach!";
        c = cin.get();
        cin.ignore();
        //system("CLS");
        system("clear");
        login_screens();
    }
}
void atm::history_Update(Account _a,string money,string func,string status) {
    string s = _a.get_Id();
    string file_name = s+"_lichsugiaodich.txt";
    const char* fileDes = &file_name[0];
    ofstream file;
    file.open("lichsu.txt",ios::app | ios::out);
    ifstream  f;
    f.open(fileDes);
    if ( f.is_open() ) {
        file << money<<' '<<func<<' '<<status<<'\n';
        while (!f.eof()) {
            string data1,data2,data3;
            f >> data1 >> data2 >> data3;
            file <<data1<<' '<<data2<<' '<<data3<<'\n';
        }
    f.close();
    file.close();
    remove(fileDes);
    rename("lichsu.txt",fileDes);
    }
    else 
        cout<<"Loi khong khong mo duoc file!";
    //khong cap phat new nen khong can giai phong
        //delete fileDes;
}
void atm::history_show(Account _a) {
    system("clear");
    Display d;
    string s = _a.get_Id();
    string fileDes = s+"_lichsugiaodich.txt";
    const char* fileName = &fileDes[0];
    d.history_display(fileName);
}
void atm::atm_working() {
    int solannhapsai = 0, flag = 0;
    string _id;
    string _password;
    cout << "id:";
    cin >> _id;
    cout << "password:";
    cin >> _password;
    if (status_check(_id, _password) == false)
    {
        cout << "Tai khoan nay da bi khoa!";
        flag = 1;
        cout << "\nbam phim bat ki de tiep tuc giao dich!";
        char c;
        c = cin.get();
        cin.ignore();
    }
    else
    {
        while (solannhapsai <= 5)
        {
            if (check_acc(_id, _password) == true)
            {
                break;
            }
            else
            {
                if (solannhapsai == 5)
                {
                    khoa_tai_khoan(_id);
                    cout << "tai khoan cua ban da bi khoa!"
                         << "\nbam phim bat ki de tiep tuc giao dich!";
                    char c;
                    c = cin.get();
                    cin.ignore();
                    flag = 1;
                    break;
                }
                else
                {
                    system("clear");
                    cout << "mat khau nhap sai, vui long nhap lai!\n";
                    cout << "bam phim bat ki de nhap lai\n";
                    char c;
                    c = cin.get();
                    cin.ignore();
                    system("clear");
                    cout << "id:";
                    cin >> _id;
                    cout << "password:";
                    cin >> _password;
                    /* string _id_check = atm::get_id(_id);
                    string _password_check = atm::get_pass(_password); */
                    if (atm::check_acc(_id, _password) == true)
                    {
                        solannhapsai = 0;
                        break;
                    }
                    solannhapsai++;
                }
            }
        }
    }
    if (flag == 0)
    {
        Account _a(_id);
        atm::menu(_a);
        solannhapsai = 0;
    }
    else
    {
        system("clear");
        login_screens();
    }
}
