/*
    Dynamic Programming C++ implementation of Binomial Coefficient Calculation
*/

#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

int min(int a, int b);

int binomialCoeff(int n, int k)
{
    int C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, k;

    system("cls");

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    cout << "\nValue of C[" << n << "][" << k << "] is " << binomialCoeff(n,k) << "\n\n";

    system("pause");
    return 0;
}
