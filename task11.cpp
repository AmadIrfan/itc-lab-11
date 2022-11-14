#include <fstream>
#include <iostream>
// #include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    string lines;
    fstream newfile;
    newfile.open("english1.txt", ios::in);
    while (!newfile.eof())
    {
        getline(newfile, lines);
        cout << lines << endl;
    }
    newfile.close();

    return 0;
}