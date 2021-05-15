#include<iostream>
#include <fstream>
#include<sstream>
#include "atm_h.h"



using namespace std;
bool check_boi_so(int a)
{
    if (a % 10000 == 0)
        return true;
    return false;
}
bool flag() {
    
    return true;
}
int nhap_so_tien() {
    int money;
    cin >> money;
    return money;
}
string stringConvert(int n){
    stringstream ss;
    string _money ="";
    ss << n;
    ss>>_money;
    _money='+'+_money;
    ss.clear();
    return _money;
}
bool moneyCheck(int& money,string& s) {
    if(money >= 10000 && money <= 500000 && check_boi_so(money) == true) {
        s = stringConvert(money);
        return true;
    }
    else {
            cout << "so tien vua nhap khong hop le vui long nhap lai!\n"
                 << "so tien ban muon gui la:";
            int n = nhap_so_tien();
            money = n;
            moneyCheck(money,s);
    }
    return true;
}

