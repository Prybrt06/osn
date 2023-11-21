#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    int check = fork();

    if (check == -1)
    {
        cout << "Process creation failed";
    }
    else if (check == 0)
    {
        cout << "Child process\n";

        char *program = "/Users/priyabrat/Desktop/C++ programming/Operating System/week6/even";
        char *args = NULL;

        int a = execl(program, args);

        cout << a << endl;

        if (a < 0)
        {
            cout << "Code can't be executed";
        }
        else
        {
            cout << "Child process ends";
        }
    }
    else
    {
        wait(NULL);
        cout << "Parent process\n";
    }
    return 0;
}
