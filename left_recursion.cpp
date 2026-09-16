#include <iostream>
#include <string>
using namespace std;

int main()
{
    string p;

    cout << "Enter a production: ";
    cin >> p;

    // Find the position of ->
    int pos = p.find("->");

    // Check whether -> exists
    /*if (pos == string::npos)
    {
        cout << "Invalid Production";
        return 0;
    }*/
    if (pos == -1)
    {
    cout << "Invalid Production";
    return 0;
    }



    // In CFG, LHS must contain exactly one Non-Terminal
    if (pos != 1 || p[0] < 'A' || p[0] >'Z')
    {
        cout << "Invalid CFG Production";
        return 0;
    }

    char left = p[0];

    // Check whether RHS exists
    if (pos + 2 >= p.length())
    {
        cout << "Invalid Production";
        return 0;
    }

    bool leftRecursive = false;

    // Check every alternative in RHS
    for (int i = pos + 2; i < p.length(); i++)
    {
        // If current symbol is same as LHS
        // and it is the first symbol of an alternative
        if (p[i] == left && (i == pos + 2 || p[i - 1] == '|'))
        {
            leftRecursive = true;
            break;
        }
    }

    if (leftRecursive)
        cout << "Left Recursive";
    else
        cout << "Not Left Recursive";

    return 0;
}

