#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;

void login();
void registration();

int main()
{
    int c;
    cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    cout << "----------------------------------------------Welcome to our system!------------------------------------------------------\n";
    cout << "----------------------------------------------     Main Menu        ------------------------------------------------------\n";
    cout << "                                                                                                                           \n\n";
    cout << "\t | Press 1 To Login.                      |" << endl;
    cout << "\t | Press 2 To Register.                   |" << endl;
    cout << "\t | Press 3 To Exit.                       |" << endl;
    cout << "\n\t\t\t Please Enter Your Choice: ";
    cin >> c;
    cout << endl;
    if (c == 1)
    {
        login();
    }
    if (c == 2)
    {
        registration();
    }
    if (c == 3)
    {
        exit(0);
    }
}
void login()
{
    int count;
    string username, password, id, pass;
    float age, gpa;
    system("cls");
    cout << "\t\t\t Please Enter The UserName And Password: " << endl;
    cout << "\t\t\t USERNAME :  ";
    cin >> username;
    cout << "\t\t\t PASSWORD :  ";
    cin >> password;
    ifstream input;
    input.open("records.txt", ios::in);
    while (input >> id >> pass >> age >> gpa)
    {
        if (id == username && pass == password)
        {
            count = 1;
            system("cls");
        }
        input.close();
        if (count == 1)
        {
            system("cls");
            cout << username << "\n Your Login Is Successful \n Thnx For Logging In \n";
            system("color 0A");
            if (gpa > 3.5)
            {
                cout << "\nGood work\n";
            }

            main();
        }
        else
        {
            system("cls");
            cout << "\n Logging Error \n Please Check Your Username And Password \n";
            system("color 04");
            main();
        }
    }
}
void registration()
{
    string RuserId, Rpassword, Rid, Rpass;
    float age, gpa;
    system("cls");
    cout << "\t\t\t Please Enter The UserName And Password: " << endl;
    cout << "\t\t\t USERNAME :  ";
    cin >> RuserId;
    cout << "\t\t\t PASSWORD :  ";
    cin >> Rpassword;
    cout << "\t\t\t AGE :  ";
    cin >> age;
    cout << "\t\t\t GPA :  ";
    cin >> gpa;
    ofstream fi("records.txt", ios::app);
    fi << RuserId << " " << Rpassword << " " << age << " " << gpa << endl;
    system("cls");
    cout << "\n\t\t\t Registration Is Successfull  \n";
    main();
}