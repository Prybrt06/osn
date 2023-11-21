#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
    int x = 20;
    int check = fork();
    fork();

    if (check == 0)
    {
        cout << "Child process and the value of x is : " << x << endl;
    }
    else
    {
        cout << "Parent process and the value of x is : " << x << endl;
    }
    return 0;
}