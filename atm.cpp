#include "atm_h.h"
#include "account.h"
#include "guitien.h"
#include "display.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <stdlib.h>
#include<string>
using namespace std;
class Account;
/* class Gui_tien; */

int a[5] ={500000,200000,100000,50000};
int count[5]={0,0,0,0};
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
        if(data == a[i] ){
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
    int sl[5]={0,0,0,0};
    for(int i = 0 ; i< 4;i++) {
        sl[i] = laysoluong(a[i]);
        cout<<sl[i] <<" ";
    }
    if(sl[0]!= 0){
        int _count = 0;
        while(sl[0] != 0 && n >= a[0]) {
            _count++;
            n = n - a[0];
            sl[0] -= 1;
            if(sl[0] == 0) break;
        }
        //cout<<sl[0];
        count[0] = _count;
    }
    if(sl[1]!= 0){
        int _count = 0;
        while(sl[1]!= 0 && n >= a[1]) {
            _count++;
            n = n - a[1];
            sl[1]-= 1;
            if(sl[1]== 0) break;
        }
        count[1] = _count;
    }
    if(sl[2]!= 0){
        int _count = 0;
        while(sl[2] != 0 && n >= a[2]) {
            _count++;
            n = n - a[2];
            sl[2] -= 1;
            if(sl[2] == 0) break;
        }
        count[2] = _count;
    }
    if(sl[3]!= 0){
        int _count = 0;
        while(sl[3] != 0 && n >= a[3]) {
            _count++;
            n = n - a[3];
            sl[3] -= 1;
            if(sl[3] == 0) break;
        }
        count[3] = _count;
    }
    cout<<"\n";
    if(n != 0 ) cout<<" none";
    else {
    for(int i = 0; i<4;i++){
        if(i==0)cout<<count[i]<<"*500 + ";
        if(i==1)cout<<count[i]<<"*200 + ";
        if(i==2)cout<<count[i]<<"*100 + ";
        if(i==3)cout<<count[i]<<"*50 +  ";
    }
    }
    hoptien_update(sl);
    //cout<<"\n"<<sl[4];
}
bool atm::check_acc(string acc,string pass){
    ifstream file;
    file.open("user_info.csv");
    /* string s;
    getline(file,s); */
    if(file.is_open()){
        while(!file.eof()){
            string _id,_pass;
            //int l;
            getline(file,_id,',');
            getline(file,_pass);
            //file >> l;
            if(_id == acc && _pass == pass){ 
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}
//Truyen vao account de thao tac voi cai account
void atm::login_screens(){
    int solannhapsai = 0;
    string _id;
    string _password;
    cout<<"id:";cin >> _id;
    cout<<"password:";
    cin >> _password;
    string _id_check = atm::get_id(_id);
    string _password_check = atm::get_pass(_password);
    if(atm::check_acc(_id_check,_password_check) == true)
    {
        Account _a(_id);
        atm::menu(_a);
    }
    else{
        solannhapsai++;
    }

}
void atm::menu(Account _a) {
    //window
    //system("CLS");
        // linux
        system("clear");
    options_display();
        int n ;
        cin >> n;
        switch(n){
            case 1:
                //window
                //system("CLS");
                    // linux
                system("clear");
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
    menh_gia_display();
    int money = nhap_so_tien();
    string _money = stringConvert(money);
    while(moneyCheck(money,_money) != true ) history_Update(_a,_money,"gui_tien","that_bai");
    //guitien.h
    //lay id de kiem tra so du cua id day
    string s = _a.get_Id();
    history_Update(_a,_money,"gui_tien","thanh_cong");
    hoptien(money);
    _a.gui_tien(money,s);
}
//So tien co trong cay atm
void atm::_rut_tien(Account _a){
    // viet lai rut tien
    system("CLS");
    rut_tien_menh_gia();
    int money  = nhap_so_tien();
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
//update history
    //* add a line
// have a lot of bug
// neu giao dich khong thanh cong thi ko cap nhat lich su 
    // or co cap nhat nhung khong thanh cong
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

