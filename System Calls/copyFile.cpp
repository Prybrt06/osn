#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

// int main()
// {
// string line;

// ifstream ini_file("input.txt");
// ofstream out_file("output.txt");

// if (ini_file && out_file)
// {
// while (getline(ini_file, line))
// {
// out_file << line << '\n';
// }
// cout << "Copy finished";
// }
// else
// {
// cout << "Error in file opening";
// }
// }

int main()
{
    char arr[100];

    int fd = open("input.txt", O_RDONLY);
    int fd1 = open("output.txt", O_WRONLY | O_CREAT);

    while (read(fd, arr, 1))
    {
        write(fd1, arr, 1);
    }
}