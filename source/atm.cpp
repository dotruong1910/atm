#include "atm_h.h"
#include "account.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <stdlib.h>
using namespace std;
class Account;
//Truyen vao account de thao tac voi cai account
bool check_boi_so(int a)
{
    if (a % 10000 == 0)
        return true;
    return false;
}
//https://www.oreilly.com/library/view/c-cookbook/0596007612/ch03s06.html
double sciToDouble(const string &str)
{

    stringstream ss(str);
    double d = 0;
    ss >> d;

    if (ss.fail())
    {
        string s = "Unable to format ";
        s += str;
        s += " as a number!";
        throw(s);
    }

    return (d);
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

}
void atm::menu(Account _a){
    system("CLS");

    cout << "Vui long chon:\n"
         << "1. hien so du\n"
         << "2. gui tien vao tai khoan\n"
         << "3. rut tien\n"
         << "4. lich su giao dich\n"
         << "5. thoat\n"
         << "vui nhap lua chon: ";
        int n ;
        cin >> n;
        switch(n){
            case 1:
                system("CLS");
                menu_sodu(_a);
                break;
            case 2:
                guitien_display(_a);
                break;
            case 3:
                _rut_tien(_a);
                break;
        };
};
/* int atm::getInput(Account _a){
    int input;
    cin >> input;
    if (input >= 1 && input <= 5)
        return input;
    else
    {
        system("CLS");
        cout << "khong hop le nhan phim bat ki de nhap lai!\n";
        cin.get();
        menu(_a);
        getInput(_a);
    }
};
 */
void atm::menu_sodu(Account _a){
    
    string s = _a.check_so_du();
    double res = sciToDouble(s);

    cout<<"so du cua ban la:"<<fixed<<int(res);   
}
// phai viet nhu nay vi trong file la dinh dang scientific
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
    system("CLS");
    int money;
    cout<<"menh gia nho nhat: 10.000 VND\n"
        <<"menh gio lon nhat: 500.000 VND\n"
        <<"so tien ban muon gui phai la boi so cua 10.000\n"
        <<"so tien ban muon gui la:";
    cin >> money;
    if (money < 10000 || money >500000 || check_boi_so(money) == false){
        do
        {
            cout << "so tien vua nhap khong hop le vui long nhap lai!\n"
                 << "so tien ban muon gui la:";
            cin >> money;
        } while (money < 10000 || money > 500000 || check_boi_so(money) == false);
    }
    string s = _a.get_Id();
    //lay id de kiem tra so du cua id day
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
void atm::_rut_tien(Account _a){
    system("CLS");
    int money ;
    cout << "menh gia nho nhat: 10.000 VND\n"
         << "menh gio lon nhat: 500.000 VND\n"
         << "so tien ban muon rut phai la boi so cua 10.000\n"
         << "so tien ban muon rut la:";
    cin >> money;
    if (money < 10000 || money > 500000 || check_boi_so(money) == false)
    {
        do
        {
            cout << "so tien vua nhap khong hop le vui long nhap lai!\n"
                 << "so tien ban muon gui la:";
            cin >> money;
        } while (money < 10000 || money > 500000 || check_boi_so(money) == false);
    }
    string s = _a.get_Id();
    if(_a.rut_tien(money,s)==true){
        cout<<"Rut tien thanh cong!\n"
            <<"so du con lai cua ban la:"<<fixed<<int(get_Balance(_a));
        //menu_sodu(_a);
    }
    else{
        cout<<"Xin loi so du con lai khong the thuc hien dao dich nay!";
    }
}



