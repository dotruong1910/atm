#ifndef display 
#define display
#include<iostream>
using namespace std;
class Display {
public:
    Display() {};
    string del_(string s);
    int login_or_signin();
    void menh_gia_display();
    void options_display();
    void rut_tien_menh_gia();
    void history_display(const char* name);
    void signup_screen();
    void mokhoataikhoan();
    
};
#endif