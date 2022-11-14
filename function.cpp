#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int arrayofnum[50];
int arrayofnum2[50];
int main()
{
    for (int i = 0; i < 50; i++)
    {
        arrayofnum[i] = i + 100;
    }
    for (int n = 0; n < 50; n++)
    {
        cout << arrayofnum[n] << endl;
    }
    fstream file;
    file.open("num.txt", ios::out);
    for (int f = 0; f < 50; f++)
    {
        file << arrayofnum[f] << endl;
    }
    file.close();
    file.open("num.txt", ios::in);
    while ()
    {
        file << arrayofnum2[] << endl;
    }
    file.close();

    return 0;
}