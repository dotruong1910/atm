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
        void add_account(string _id, string pass, string status);
    private:
        std::string id;
        std::string password;
};
 
#endif //bankdata__H_