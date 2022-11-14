#include <fstream>
// #include <iostream>
// #include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    double value = 2.9;
    fstream newfile;
    newfile.open("my_double.txt", ios::out);
    newfile << value;
    newfile.close();
    return 0;
}