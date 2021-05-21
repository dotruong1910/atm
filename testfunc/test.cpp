#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;
int main() {
     cout<<"_________________________________________\n";
     cout<<"|giao dich   "<<setw(13)<<"|  so tien  |"<<setw(13)<<"   trang thai |"<<endl;
     ifstream file;
    file.open("lichsugiaodich.txt");
       
        if(file.is_open()) {
                while(!file.eof()) {
                        string data1,data2,data3;
                        file >> data1 >> data2 >> data3;
                        cout<< " "<<data2<<setw(7)<<""<<data1<<setw(6)<<""<<data3<<endl;
                }
        }
        else{
                cout<<"-1";
        }
        file.close();
     return 0;
}
