#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        cout << "String " << i + 1 << endl;

        string token = "";
        int count = 1;

        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == ' ')
            {
                cout << "Token " << count++ << " " << token << endl;
                token = "";
            }
            else
            {
                token += s[j];
            }
        }

        if(token != "")
        {
            cout << "Token " << count++ << " " << token << endl;
        }

        cout << endl;
    }

    return 0;
}

