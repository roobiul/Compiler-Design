#include <iostream>
#include <string>
#include <set>
using namespace std;

string production[20];
int n;

set<char> first(char symbol)
{
    set<char> result;

    // If symbol is terminal
    if (!isupper(symbol))
    {
        result.insert(symbol);
        return result;
    }

    // Find production
    for (int i = 0; i < n; i++)
    {
        if (production[i][0] == symbol)
        {
            string rhs = production[i].substr(2);

            // Split by |
            string part = "";

            for (int j = 0; j <= rhs.length(); j++)
            {
                if (j == rhs.length() || rhs[j] == '|')
                {
                    if (part.length() > 0)
                    {
                        char firstSymbol = part[0];

                        set<char> temp = first(firstSymbol);

                        for (char c : temp)
                        {
                            result.insert(c);
                        }
                    }

                    part = "";
                }
                else
                {
                    part += rhs[j];
                }
            }
        }
    }

    return result;
}

int main()
{
    cout << "Enter number of production rules: ";
    cin >> n;

    cout << "Enter production rules:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> production[i];
    }

    cout << "\nFIRST Sets:\n";

    for (int i = 0; i < n; i++)
    {
        char symbol = production[i][0];

        // Avoid duplicate output
        bool found = false;

        for (int j = 0; j < i; j++)
        {
            if (production[j][0] == symbol)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            set<char> result = first(symbol);

            cout << "FIRST(" << symbol << ") = { ";

            for (char c : result)
            {
                cout << c << " ";
            }

            cout << "}\n";
        }
    }

    return 0;
}
