#ifndef bankdata__H_
#define bankdata__H_
#include<string>
using namespace std;
class Bankdata
{
    public:
        Bankdata(){};
        bool id_is_exist(std::string _id);
        bool account_check(std::string id,std::string password);
        bool ques_check(string ques, string ans,const char* filename);
        bool status_check(string s, string p);
        void add_account(string _id, string pass, string status);
        void khoa_tai_khoan(string s) ;
        void mo_tai_khoan(string s);
        private : 
        std::string id;
        std::string password;
};
 
#endif //bankdata__H_