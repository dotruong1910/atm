#ifndef bankdata__H_
#define bankdata__H_
#include<string>
class Bankdata
{
    public:
        Bankdata();
        bool password_check(std::string password);
        bool sodu();
        void rutTien();
        bool id_check(std::string id);
        bool account_check(std::string id,std::string password);
        
    
    private:
        std::string id;
        std::string password;
};
 
#endif //bankdata__H_