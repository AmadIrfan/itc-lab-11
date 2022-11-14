#include <fstream>
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main()
{
    int count = 0;
    char input, che;
    fstream newfile;
    cout << "enter a character : ";
    cin >> input;
    newfile.open("english1.txt", ios::in);
    while (!newfile.eof())

    {
        newfile >> che;
        if (che == input)
        {
            cout << " location is :" << count;
            break;
        }
        count++;
    }
    newfile.close();

    return 0;
}