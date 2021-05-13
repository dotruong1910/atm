#ifndef account
#define account
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Account
{
    private:
        string id;
        int money;
        string view_so_du;
        double so_du;
    public:
    Account();
    Account(string _id);
    void gui_tien(int a,string _id);
    bool rut_tien(int a,string _id);
    string check_so_du();
    int get_Index();
    string get_Id();
    int get_locked();

};
bool check_boi_so(int a);


#endif