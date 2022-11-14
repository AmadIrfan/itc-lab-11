#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main()
{
    int count = 0;
    char che;
    fstream newfile;
    newfile.open("english1.txt", ios::in);
    while (!newfile.eof())
    {
        newfile >> che;
        cout << che << endl;
        count++;
    }
    cout << "total characters are " << count;
    newfile.close();
    return 0;
}