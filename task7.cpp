#include <fstream>
#include <iostream>
#include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    char che;
    fstream newfile;
    newfile.open("my_char.txt", ios::in);
    newfile >> che;
    newfile.close();
    cout << che;

    return 0;
}