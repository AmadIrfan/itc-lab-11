#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;
void signup();
void login();
int main_manu();
string username[50], password[50];
double gpa[50];
int count = 0, pwd = 0, up = 1, update = 0, known;
string now, name, username, user_pass, position;
main()
{

    int option = 0;
    cout << "------------------------------------------------------------" << endl;
    cout << "------------------- Login page/sign up ---------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    while (option < 3)
    {
        option = main_manu();
        if (option == 1)
        {
            login();
        }
        if (option == 2)
        {
            signup();
        }
    }
}

int main_manu()
{
    int option;
    cout << "(1).Log in " << endl;
    cout << "(2).Sign up " << endl;
    cout << "(3).Exit " << endl;
    cout << "your option... ";
    cin >> option;
    return option;
}
void signup()
{
    cout << "Enter user name ";
    cin >> username[count];
    cout << "Enter Password ";
    cin >> password[count];
    cout << "Enter your GPA ";
    cin >> gpa[count];
    fstream file;
    file.open("main.txt", ios::app);
    file << username << "," << password << "," << gpa << endl;
    file.close();
    count++;
}

void login()
{

    cout << "Enter user name ";
    cin >> name;
    cout << "Enter Password ";
    cin >> user_pass;
    fstream file;
    file.open("main.txt", ios::in);
    while (!file.eof())
    {
        file >> now;
        if (up % 3 == 1)
        {
            username[update] = now;
            update++;
        }
        if (up % 3 == 2)
        {
            continue;
        }
        if (up % 3 == 0)
        {
            password[pwd] = user_pass;
            pwd++;
        }
        up++;
    }
    for (int idx = 0; idx < count; idx++)
    {
        if (name == username[idx] && user_pass == password[idx])
        {
            known = idx;
            position = true;
        }
        else
        {
            position = false;
        }
    }
    if (position == true)
    {

        system("color 2");
        cout << "valid " << endl;
        if (gpa[known] > 3.5)
        {
            cout << "access granted" << endl;
        }
    }
    if (position == false)
    {
        system("color 4");
        cout << "Access denied" << endl;
    }
}