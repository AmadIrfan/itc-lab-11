#include <fstream>
// #include <conio.h>
// #include <cmath>
using namespace std;
int main()
{
    string line = "Welcome in uet ";
    fstream newfile;
    newfile.open("My_text.txt", ios::out);
    newfile << line;
    newfile.close();
    return 0;
}