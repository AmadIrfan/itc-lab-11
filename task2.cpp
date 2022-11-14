#include <fstream>
// #include <iostream>
// #include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    int value = 100;
    fstream newfile;
    newfile.open("my_int.txt", ios::out);
    newfile << value;
    newfile.close();
    return 0;
}