#include <string>
#include <iostream>
using namespace std;
int main() {
string password;
char c;
// loop condition: get a character, while it isn't a newline (end of password), then...
while (cin >> c && c != '\n')
{
        password+=c;
        cin.ignore();
}

cout<<password;
}