# Compiler Design Lab — All Programs (C++)

This README contains all lab programs with source code, compile/run instructions, and sample input/output for each.

**Compile any program with:**
```
g++ filename.cpp -o output
./output
```

---

## 1a. Binary Search (with Debugging)

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int low = 0, high = n - 1, mid;
    bool found = false;

    while (low <= high) {
        mid = (low + high) / 2;

        cout << "DEBUG: low=" << low << " high=" << high
             << " mid=" << mid << " arr[mid]=" << arr[mid] << endl;

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) cout << "Element not found in array.\n";
    return 0;
}
```

**Sample Input:**
```
Enter number of elements: 6
Enter 6 sorted elements: 2 4 6 8 10 12
Enter element to search: 8
```

**Sample Output:**
```
DEBUG: low=0 high=5 mid=2 arr[mid]=6
DEBUG: low=3 high=5 mid=4 arr[mid]=10
DEBUG: low=3 high=3 mid=3 arr[mid]=8
Element found at index 3
```

---

## 1b. Selection Sort (with Debugging)

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }
        swap(arr[i], arr[minIdx]);

        cout << "DEBUG Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```

**Sample Input:**
```
Enter number of elements: 5
Enter 5 elements: 29 10 14 37 13
```

**Sample Output:**
```
DEBUG Pass 1: 10 29 14 37 13
DEBUG Pass 2: 10 13 14 37 29
DEBUG Pass 3: 10 13 14 37 29
DEBUG Pass 4: 10 13 14 29 37
Sorted array: 10 13 14 29 37
```

---

## 1c. Matrix Multiplication (with Debugging)

```cpp
#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;
    int A[r1][c1];
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;
    int B[r2][c2];
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    if (c1 != r2) {
        cout << "DEBUG: Multiplication not possible. Columns of A ("
             << c1 << ") != Rows of B (" << r2 << ")\n";
        return 0;
    }

    int C[r1][c2];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
                cout << "DEBUG: C[" << i << "][" << j << "] += A[" << i << "][" << k
                     << "]*B[" << k << "][" << j << "] = "
                     << A[i][k] << "*" << B[k][j] << " -> C[" << i << "][" << j << "]="
                     << C[i][j] << endl;
            }
        }
    }

    cout << "\nResultant Matrix C:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    return 0;
}
```

**Sample Input:**
```
Enter rows and columns of Matrix A: 2 2
Enter elements of Matrix A: 1 2 3 4
Enter rows and columns of Matrix B: 2 2
Enter elements of Matrix B: 5 6 7 8
```

**Sample Output:**
```
DEBUG: C[0][0] += A[0][0]*B[0][0] = 1*5 -> C[0][0]=5
DEBUG: C[0][0] += A[0][1]*B[1][0] = 2*7 -> C[0][0]=19
DEBUG: C[0][1] += A[0][0]*B[0][1] = 1*6 -> C[0][1]=6
DEBUG: C[0][1] += A[0][1]*B[1][1] = 2*8 -> C[0][1]=22
DEBUG: C[1][0] += A[1][0]*B[0][0] = 3*5 -> C[1][0]=15
DEBUG: C[1][0] += A[1][1]*B[1][0] = 4*7 -> C[1][0]=43
DEBUG: C[1][1] += A[1][0]*B[0][1] = 3*6 -> C[1][1]=18
DEBUG: C[1][1] += A[1][1]*B[1][1] = 4*8 -> C[1][1]=50

Resultant Matrix C:
19 22
43 50
```

---

## 2. Detection of Comments in a Line

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter code line(s), end with 'END':\n";
    string code = "", temp;
    while (getline(cin, temp) && temp != "END") {
        code += temp + "\n";
    }

    int i = 0, n = code.length();
    while (i < n) {
        if (code[i] == '/' && i + 1 < n && code[i + 1] == '/') {
            cout << "Single-line comment found: ";
            while (i < n && code[i] != '\n') cout << code[i++];
            cout << endl;
        }
        else if (code[i] == '/' && i + 1 < n && code[i + 1] == '*') {
            cout << "Multi-line comment found: ";
            while (i < n && !(code[i] == '*' && i + 1 < n && code[i + 1] == '/')) {
                cout << code[i++];
            }
            cout << "*/" << endl;
            i += 2;
        }
        else i++;
    }
    return 0;
}
```

**Sample Input:**
```
int a = 5; // initialize a
/* this is
a multi line comment */
int b = 10;
END
```

**Sample Output:**
```
Single-line comment found: // initialize a
Multi-line comment found: /* this is
a multi line comment */
```

---

## 3. Validation Check of Identifiers

```cpp
#include <iostream>
#include <cctype>
using namespace std;

bool isValidIdentifier(string id) {
    if (!(isalpha(id[0]) || id[0] == '_')) return false;
    for (int i = 1; i < id.length(); i++) {
        if (!isalnum(id[i]) && id[i] != '_') return false;
    }
    return true;
}

int main() {
    string id;
    cout << "Enter identifier: ";
    cin >> id;
    if (isValidIdentifier(id))
        cout << id << " is a VALID identifier.\n";
    else
        cout << id << " is an INVALID identifier.\n";
    return 0;
}
```

**Sample Input:**
```
Enter identifier: 2value
```

**Sample Output:**
```
2value is an INVALID identifier.
```

**Sample Input:**
```
Enter identifier: _total_count
```

**Sample Output:**
```
_total_count is a VALID identifier.
```

---

## 4. Detection of Left Recursion in a Context-Free Grammar

```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string prod;
        cout << "Enter production (format A->Ab | c): ";
        getline(cin, prod);

        int arrow = prod.find("->");
        string lhs = prod.substr(0, arrow);
        string rhs = prod.substr(arrow + 2);

        while (lhs.back() == ' ') lhs.pop_back();

        stringstream ss(rhs);
        string alt;
        bool leftRecursive = false;
        while (getline(ss, alt, '|')) {
            int j = 0;
            while (alt[j] == ' ') j++;
            if (alt.substr(j, lhs.length()) == lhs) {
                leftRecursive = true;
            }
        }
        if (leftRecursive)
            cout << lhs << " has LEFT RECURSION\n";
        else
            cout << lhs << " has NO left recursion\n";
    }
    return 0;
}
```

**Sample Input:**
```
Enter number of productions: 2
Enter production: A->Ab | c
Enter production: B->aB | b
```

**Sample Output:**
```
A has LEFT RECURSION
B has NO left recursion
```

---

## 5. Tokenization of an Input String

```cpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    cout << "Enter text (end with 'END' on its own line):\n";
    string line, fullText = "";
    while (getline(cin, line) && line != "END") {
        fullText += line + " ";
    }

    stringstream ss(fullText);
    string token;
    int count = 1;
    cout << "\nTokens:\n";
    while (ss >> token) {
        cout << count++ << ". " << token << endl;
    }
    return 0;
}
```

**Sample Input (single line):**
```
int a = 5 + b;
END
```

**Sample Output:**
```
Tokens:
1. int
2. a
3. =
4. 5
5. +
6. b;
```

**Sample Input (multiple lines):**
```
int a = 5;
int b = 10;
END
```

**Sample Output:**
```
Tokens:
1. int
2. a
3. =
4. 5;
5. int
6. b
7. =
8. 10;
```

---

## 6. Evaluate Postfix Expression

```cpp
#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

int main() {
    string exp;
    cout << "Enter postfix expression (space-separated, e.g. 2 3 + 4 *): ";
    getline(cin, exp);

    stack<double> st;
    stringstream ss(exp);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.length() > 1)) {
            st.push(stod(token));
        } else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double res;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            st.push(res);
        }
    }
    cout << "Result: " << st.top() << endl;
    return 0;
}
```

**Sample Input:**
```
Enter postfix expression: 2 3 + 4 *
```

**Sample Output:**
```
Result: 20
```

---

## 7. Evaluate Prefix Expression

```cpp
#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string exp;
    cout << "Enter prefix expression (space-separated, e.g. * + 2 3 4): ";
    getline(cin, exp);

    stringstream ss(exp);
    vector<string> tokens;
    string t;
    while (ss >> t) tokens.push_back(t);
    reverse(tokens.begin(), tokens.end());

    stack<double> st;
    for (string token : tokens) {
        if (isdigit(token[0]) || token.length() > 1) {
            st.push(stod(token));
        } else {
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            double res;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            st.push(res);
        }
    }
    cout << "Result: " << st.top() << endl;
    return 0;
}
```

**Sample Input:**
```
Enter prefix expression: * + 2 3 4
```

**Sample Output:**
```
Result: 20
```

---

## 8. Computing FIRST Sets

```cpp
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSet;

void computeFirst(char symbol) {
    if (!firstSet[symbol].empty()) return;

    for (string production : grammar[symbol]) {
        for (int i = 0; i < production.length(); i++) {
            char sym = production[i];
            if (isupper(sym)) {
                computeFirst(sym);
                for (char c : firstSet[sym])
                    if (c != '#') firstSet[symbol].insert(c);
                if (firstSet[sym].count('#') == 0) break;
                if (i == production.length() - 1)
                    firstSet[symbol].insert('#');
            } else {
                firstSet[symbol].insert(sym);
                break;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();
    vector<char> nonTerminals;

    for (int i = 0; i < n; i++) {
        string prod;
        cout << "Enter production (format A->aB | b | #): ";
        getline(cin, prod);
        char lhs = prod[0];
        int arrow = prod.find("->");
        string rhs = prod.substr(arrow + 2);

        stringstream ss(rhs);
        string alt;
        while (getline(ss, alt, '|')) {
            while (alt[0] == ' ') alt = alt.substr(1);
            while (alt.back() == ' ') alt.pop_back();
            grammar[lhs].push_back(alt);
        }
        if (find(nonTerminals.begin(), nonTerminals.end(), lhs) == nonTerminals.end())
            nonTerminals.push_back(lhs);
    }

    for (char nt : nonTerminals) computeFirst(nt);

    cout << "\nFIRST Sets:\n";
    for (char nt : nonTerminals) {
        cout << "FIRST(" << nt << ") = { ";
        for (char c : firstSet[nt]) cout << c << " ";
        cout << "}\n";
    }
    return 0;
}
```

**Sample Input:**
```
Enter number of productions: 2
Enter production: E->TX
Enter production: X->+TX | #
```

**Sample Output:**
```
FIRST Sets:
FIRST(E) = { }
FIRST(X) = { # + }
```
*(Note: FIRST(E) depends on FIRST(T), which must also be defined as a production for a complete result. Add a production for T, e.g. `T->id`, to see FIRST(E) populate fully.)*

---

## Notes

- Use `#` to represent epsilon (ε) in the FIRST set program.
- Compile each program with `g++ filename.cpp -o output` and run with `./output`.
- Test with small inputs first, then scale up.
