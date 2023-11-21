#include <iostream>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    int offset = lseek(fd, -5, SEEK_END);
    if (offset == -1)
    {
        perror("Error seeking in file");
        close(fd);
        return 1;
    }

    // Now the file pointer is at 10 bytes from the beginning.

    char buffer[100];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1)
    {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    std::cout << "Read " << bytesRead << " bytes: " << buffer << std::endl;

    close(fd);

    return 0;
}
