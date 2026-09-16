#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);

    string token[100];
    int n = 0;

    while(ss >> token[n])
    {
        n++;
    }

    int stack[100];
    int top = -1;

    for(int i = n - 1; i >= 0; i--)
    {
        if(token[i][0] >= '0' && token[i][0] <= '9')
        {
            stack[++top] = stoi(token[i]);
        }
        else
        {
            if(top < 1)
            {
                cout << "Invalid Expression";
                return 0;
            }

            int a = stack[top--];
            int b = stack[top--];

            if(token[i] == "+")
                stack[++top] = a + b;

            else if(token[i] == "-")
                stack[++top] = a - b;

            else if(token[i] == "*")
                stack[++top] = a * b;

            else if(token[i] == "/")
                stack[++top] = a / b;

            else
            {
                cout << "Invalid Expression";
                return 0;
            }
        }
    }

    if(top == 0)
        cout << stack[top];
    else
        cout << "Invalid Expression";

    return 0;
}


