#ifndef atm_h
#define atm_h
#include<string>
#include"account.h"
#include"guitien.h"
using namespace std;
class atm
{
    public:   
        string get_id(string _id){
            return _id;
        }
        string get_pass(string _password){
            return _password;
        }
        bool check_acc(string _id,string _pass);
        void xem_so_du();
        void login_screens();
        void menu(Account _a);
        int getInput(Account _a);
        int getTag(string _id,string _pass);
        void menu_sodu(Account _a);
        void guitien_display(Account _a);
        void hoptien(int money);
        void _rut_tien(Account _a);
        double get_Balance(Account _a);
        void tiep_tuc_giao_dich(Account _a);
        void history_Update(Account _a,string money,string func,string sta);
    
    private:
        string id;
        string password;
        Account a;
};
double sciToDouble(const string &str);

#endif