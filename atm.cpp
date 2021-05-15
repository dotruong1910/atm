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
/* bool check_boi_so(int a)
{
    if (a % 10000 == 0)
        return true;
    return false;
} */

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
void atm::hoptien(int money){
    ofstream f;
    ifstream  file;
    file.open("hoptien.txt");
    f.open("hoptien.txt",ios::app);
    if(file.is_open()){
        int a;
        a = money;
        stringstream s;
        s << a;
        string newline;
        s >> newline;
        s.clear();
        f <<newline<<endl;
    }
    f.close();
    file.close();
}
//rut tien khoi cay atm
    // chua hoan can phai check them la atm co the tra duoc so tien can rut hay khong
// giai thuat tham lam --> chua cai dat
    // return ve so to it nhat
        //check hop tien cua ngan hang
void atm::_rut_tien(Account _a){
    // viet lai rut tien
    system("CLS");
    rut_tien_menh_gia();
    int money  = nhap_so_tien();
    string _money = stringConvert(money);
    if (money < 10000 || money > 500000 || check_boi_so(money) == false) {
        {
            cout << "so tien vua nhap khong hop le vui long nhap lai!\n"
                 << "so tien ban muon gui la:";
            cin >> money;
        } while (money < 10000 || money > 500000 || check_boi_so(money) == false);
    }
    string s = _a.get_Id();
    if(_a.rut_tien(money,s)==true) {
        cout<<"Rut tien thanh cong!\n"
            <<"so du con lai cua ban la:"<<fixed<<int(get_Balance(_a));
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

