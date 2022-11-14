#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    fstream newfile;
    int rollno;
    string name, grade;
    double cgpa;
    newfile.open("data.txt", ios::out);
    cout << "Enter Roll no ";
    cin >> rollno;
    cout << "Enter name of students ";
    cin >> name;
    cout << "enter CGPA";
    cin >> cgpa;
    cout << "enter Grade";
    cin >> grade;
    newfile << "roll no\tName \t CGPA \t Grade " << endl;
    newfile << rollno << " \t\t" << name << " \t" << cgpa << " \t" << grade << endl;
    newfile.close();
    return 0;
}