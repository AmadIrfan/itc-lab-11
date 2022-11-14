#include <fstream>
#include <iostream>
#include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    string stg;
    fstream newfile;
    newfile.open("english.txt", ios::out);
    getline(cin, stg);
    newfile << stg;
    newfile.close();

    return 0;
}