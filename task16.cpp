#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main()
{
    string input;
    fstream newfile;
    newfile.open("english1.txt", ios::app);
    cout << "enter a line: ";
    getline(cin, input);
    newfile << input;
    newfile.close();
    return 0;
}