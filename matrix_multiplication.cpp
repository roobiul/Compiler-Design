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

