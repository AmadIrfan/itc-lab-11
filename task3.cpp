#include <fstream>
// #include <conio.h>
// #include <iostream>
// #include <cmath>
using namespace std;
int main()
{
    char ctr = 'D';
    fstream newfile;
    newfile.open("my_char.txt", ios::out);
    newfile << ctr;
    newfile.close();
    return 0;
}