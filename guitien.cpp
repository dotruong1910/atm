#include<iostream>
#include <fstream>
#include<sstream>
#include "atm_h.h"



using namespace std;
int a[5] ={500000,200000,100000,50000,10000};
void guitien_hoptien_update(int arr[]){
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
bool check_boi_so(int a)
{
    if (a % 50000 == 0)
        return true;
    return false;
}
bool flag() {
    
    return true;
}
void nhapsoto(int n,int& tong,int arr[]){
    if(tong == n){
        int count[4];
        for(int i = 0; i< 4;i++){
            count[i] = laysoluong(a[i]);
            arr[i] += count[i];
        }
        guitien_hoptien_update(arr);
        cout<<"Gui tien thanh cong!\n";
    }
    else {
    int number;
    tong = 0;
    cout <<"nhap so to 500.000: ";
    cin >> number;
    tong+=number*a[0];
    arr[0] = number;
    cout<<"nhap so to 200.000: ";
    cin >> number;
    tong+=number*a[1];
    arr[1] = number;
    cout<<"nhap so to 100.000: ";
    cin >> number;
    tong+=number*a[2];
    arr[2] = number;
    cout<<"nhap so to 50.000: ";
    cin >> number;
    tong+=number*a[3];
    arr[3] = number;
    cout<<"nhap so to 10.000: ";
    cin >> number;
    tong+=number*a[4];
    arr[4] = number;
    nhapsoto(n,tong,arr);
    }
}
int nhap_so_tien() {
    int money;
    int tong = 0;
    int soto[4] = {0,0,0,0};
    cin >> money;
    string _money = stringConvert(money);
    moneyCheck(money,_money);
    nhapsoto(money,tong,soto);
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
    if(money >= 10000  && check_boi_so(money) == true) {
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

