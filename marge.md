# Compiler Design Lab — All Programs (C++)

Combined README for all 10 lab source files, with sample input/output for each.

**Compile any program with:**
```
g++ filename.cpp -o output
./output
```

---

## 1. Binary Search — `BINARY.cpp`

```cpp
#include <iostream>
using namespace std;
int main()
{
int n;
cin >> n;
int arr[n];
for(int i = 0; i < n; i++)
cin >> arr[i];
int target;
cout << "Enter Target: ";
cin >> target;
int low = 0;
int high = n - 1;
int mid;
while(low <= high)
{
mid = low + (high - low) / 2;
if(arr[mid] == target)
{
cout << "Element found at index " << mid << endl;
return 0;
}
else if(arr[mid] < target)
{
low = mid + 1;
}
else
{
high = mid - 1;
}
}
cout << "Element not found" << endl;
return 0;
}
```

**Sample Input:**
```
6
2 4 6 8 10 12
Enter Target: 8
```

**Sample Output:**
```
Element found at index 3
```

---

## 2. FIRST Sets — `first.cpp`

```cpp
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
```

**Note on input format:** each production is entered as ONE token (no spaces), where the first character is the non-terminal, the second character is a separator (e.g. `=`), and the rest is the RHS with alternatives separated by `|`. Example: `E=TX` means `E -> TX`.

**Sample Input:**
```
Enter number of production rules: 3
Enter production rules:
E=TX
T=id
X=+TX|#
```

**Sample Output:**
```
FIRST Sets:
FIRST(E) = { i }
FIRST(T) = { i }
FIRST(X) = { # + }
```

---

## 3. Identifier Validation — `identifier.cpp`

⚠️ **This file was uploaded empty** — no code was in it. Here's a simple version you can drop in, matching the style of your other files:

```cpp
#include <iostream>
using namespace std;

int main()
{
    string id;
    cin >> id;

    bool valid = true;

    if(!(isalpha(id[0]) || id[0] == '_'))
        valid = false;

    for(int i = 1; i < id.length(); i++)
    {
        if(!isalnum(id[i]) && id[i] != '_')
        {
            valid = false;
            break;
        }
    }

    if(valid)
        cout << "Valid Identifier";
    else
        cout << "Invalid Identifier";

    return 0;
}
```

**Sample Input:**
```
_total_count
```

**Sample Output:**
```
Valid Identifier
```

**Sample Input:**
```
2value
```

**Sample Output:**
```
Invalid Identifier
```

---

## 4. Left Recursion Detection — `left_recursion.cpp`

```cpp
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
```

**Note:** the production must be entered as ONE token with no spaces (e.g. `A->Ab|c`).

**Sample Input:**
```
Enter a production: A->Ab|c
```

**Sample Output:**
```
Left Recursive
```

**Sample Input:**
```
Enter a production: B->aB|b
```

**Sample Output:**
```
Not Left Recursive
```

---

## 5. Matrix Multiplication — `matrix_multiplication.cpp`

```cpp
#include <iostream>
using namespace std;

int main()
{
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of the first matrix: ";
    cin >> r1 >> c1;

    int A[10][10];
    cout << "Enter elements of the first matrix:" << endl;
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c1; j++)
            cin >> A[i][j];
    }

    cout << "Enter rows and columns of the second matrix: ";
    cin >> r2 >> c2;

    int B[10][10];
    cout << "Enter elements of the second matrix:" << endl;
    for(int i = 0; i < r2; i++)
    {
        for(int j = 0; j < c2; j++)
            cin >> B[i][j];
    }

    if(c1 != r2)
    {
        cout << "Matrix multiplication is not possible." << endl;
        return 0;
    }

    int result[10][10];

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResult Matrix:" << endl;
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
            cout << result[i][j] << " ";

        cout << endl;
    }

    return 0;
}
```

**Sample Input:**
```
Enter rows and columns of the first matrix: 2 2
Enter elements of the first matrix: 1 2 3 4
Enter rows and columns of the second matrix: 2 2
Enter elements of the second matrix: 5 6 7 8
```

**Sample Output:**
```
Result Matrix:
19 22
43 50
```

---

## 6. Postfix Expression Evaluation — `postfix.cpp`

```cpp
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

    for(int i = 0; i<n; i++)
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

            int b = stack[top--];
            int a = stack[top--];

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
```

**Sample Input:**
```
2 3 + 4 *
```

**Sample Output:**
```
20
```

---

## 7. Prefix Expression Evaluation — `prefix.cpp`

```cpp
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
```

**Sample Input:**
```
* + 2 3 4
```

**Sample Output:**
```
20
```

---

## 8. Selection Sort — `selection_sort.cpp`

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    cout << "Sorted Array:" << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

**Sample Input:**
```
5
29 10 14 37 13
```

**Sample Output:**
```
Sorted Array:
10 13 14 29 37
```

---

## 9. Single/Multi-Line Comment Detection — `single_multiple_line_cmnt.cpp`

```cpp
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
```

**Note:** this checks whether the ENTIRE line is a comment (starts with `//`, or starts with `/*` and ends with `*/`) — it does not scan for a comment within a larger line of code.

**Sample Input:**
```
Enter a string: // this is a comment
```
**Sample Output:**
```
Single Line Comment
```

**Sample Input:**
```
Enter a string: /* this is a comment */
```
**Sample Output:**
```
Multi Line Comment
```

**Sample Input:**
```
Enter a string: int x = 5;
```
**Sample Output:**
```
Not a Comment
```

---

## 10. Tokenization — `tokenization.cpp`

```cpp
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
```

**Note:** the first input line is `n` — how many strings/lines follow. This makes it work for both single-line and multi-line tokenization (set `n=1` for a single line, or higher for multiple lines).

**Sample Input (single line, n=1):**
```
1
int a = 5 + b
```

**Sample Output:**
```
String 1
Token 1 int
Token 2 a
Token 3 =
Token 4 5
Token 5 +
Token 6 b
```

**Sample Input (multiple lines, n=2):**
```
2
int a = 5
int b = 10
```

**Sample Output:**
```
String 1
Token 1 int
Token 2 a
Token 3 =
Token 4 5

String 2
Token 1 int
Token 2 b
Token 3 =
Token 4 10
```

---

## Notes

- Compile each program with `g++ filename.cpp -o output` and run with `./output`.
- Several programs (`BINARY.cpp`, `postfix.cpp`, `prefix.cpp`, `first.cpp`, `left_recursion.cpp`, `tokenization.cpp`) expect input in a specific single-token or single-line format as shown above — check the sample input before testing your own.
- `identifier.cpp` was empty in your upload; a placeholder implementation is included above.
