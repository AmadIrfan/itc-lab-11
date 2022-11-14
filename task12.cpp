#include <fstream>
#include <iostream>
// #include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    string lines;
    int count = 0;
    fstream newfile;
    newfile.open("english1.txt", ios::in);
    while (!newfile.eof())
    {
        getline(newfile, lines);
        count++;
    }
    cout << "total lines are " << count;
    newfile.close();
    return 0;
}