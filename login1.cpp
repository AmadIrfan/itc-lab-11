#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
int chose();
void signup();
void login();
void isvalid();
bool flag;
int count = 0, count1 = 1, count2 = 0;
fstream file;
string username[50];
int pass[50];
float cgpa[50];
int idx;
int pass1, count3 = 0;
string user;

main()
{
    int option = chose();
    while (option != 3)
    {
        if (option == 1)
        {

            signup();
            system("cls");
            option = chose();
        }
        if (option == 2)
        {
            login();
            system("cls");
            option = chose();
        }
    }
}

int chose()
{
    int option;
    cout << "Chose Option." << endl;
    cout << "1. SignUp" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Chose Option:";
    cin >> option;
    return option;
}
void signup()
{
    cout << "Enter username:";
    cin >> username[count];
    cout << "Enter password:";
    cin >> pass[count];
    cout << "Enter your CGPA:";
    cin >> cgpa[count];
    file.open("signupapp.txt", ios::app);
    file << username[count];
    file << ",";
    file << pass[count] << endl;
    file.close();
    count++;
}

void login()
{
    string name;
    string names;
    int password;
    cout << "Enter username:";
    cin >> name;
    cout << "Enter password:";
    cin >> password;
    file.open("signupapp.txt", ios::in);

    while (!file.eof())
    {
        file >> names;
        if (count1 % 3 == 1)
        {
            username[count2] = names;
            count2++;
        }
        if (count1 % 3 == 2)
        {
            continue;
        }
        if (count1 % 3 == 0)
        {
            pass[count3] = password;
            count3++;
        }
        count1++;
    }
    for (int i = 0; i < count; i++)
    {
        if (name == username[i] && password == pass[i])
        {
            idx = i;
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    if (flag == true)
    {

        system("color 2");
        cout << "Valid" << endl;
        cout << "Your CGPA is " << cgpa[idx] << endl;
        if (cgpa[idx] > 3.5)
        {
            cout << "Welldone.Keep it up" << endl;
        }
        else
        {
            cout << "Bad!" << endl;
        }
        cout << "Press any key to continue.";
        getch();
    }
    if (flag == false)
    {
        system("color 4");
        cout << "InValid" << endl;
        cout << "Press any key to continue";
        getch();
    }
}
