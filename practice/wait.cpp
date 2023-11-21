#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int check = fork();

    if (check == 0)
    {
        cout << "Child process starts" << endl;

        cout << "Child process ends" << endl;
    }
    else
    {
        wait(NULL);
        cout << "Parent process starts" << endl;

        cout << "Parent process ends" << endl;
    }
}