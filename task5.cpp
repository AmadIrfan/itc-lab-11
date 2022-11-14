#include <fstream>
#include <iostream>
// #include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    char value;
    fstream newfile;
    newfile.open("my_value.txt", ios::out);
    cout << "Enter a character ";
    cin >> value;
    newfile << value;
    newfile.close();
    return 0;
}