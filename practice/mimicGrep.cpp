#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename = "example.txt";
    string pattern = "ds;p";

    // Get filename and pattern from the user

    // Open the file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    // Search for the pattern in each line of the file
    string line;
    while (getline(file, line))
    {
        int found = line.find(pattern);
        if (found != ULONG_MAX)
        {
            cout << "Pattern found in line: " << line << endl;
        }
        else
        {
            cout << "Pattern not matched" << endl;
        }
    }

    // Close the file
    file.close();

    return 0;
}
