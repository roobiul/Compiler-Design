#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if(str.length() >= 2 && str.substr(0, 2) == "//")
    {
        cout << "Single Line Comment";
    }
    else if(str.length() >= 4 && str.substr(0, 2) == "/*" && str.substr(str.length() - 2) == "*/")
    {
        cout << "Multi Line Comment";
    }
    else
    {
        cout << "Not a Comment";
    }

    return 0;
}
