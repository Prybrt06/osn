#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    struct stat fileStat;

    if (stat(filename, &fileStat) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("File Information for: %s\n", filename);
    printf("User ID of owner: %d\n", fileStat.st_uid);
    printf("Group ID of owner: %d\n", fileStat.st_gid);
    printf("Block size: %ld bytes\n", (long)fileStat.st_blksize);
    printf("File size: %lld bytes\n", (long long)fileStat.st_size);
    printf("Number of hard links: %lu\n", fileStat.st_nlink);

    char accessTime[20];
    char modifyTime[20];
    strftime(accessTime, sizeof(accessTime), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_atime));
    strftime(modifyTime, sizeof(modifyTime), "%Y-%m-%d %H:%M:%S", localtime(&fileStat.st_mtime));
    printf("Last access time: %s\n", accessTime);
    printf("Last modification time: %s\n", modifyTime);

    printf("File permissions:\n");
    printf("Owner Read: %s\n", (fileStat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf("Owner Write: %s\n", (fileStat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf("Owner Execute: %s\n", (fileStat.st_mode & S_IXUSR) ? "Yes" : "No");
    printf("Group Read: %s\n", (fileStat.st_mode & S_IRGRP) ? "Yes" : "No");
    printf("Group Write: %s\n", (fileStat.st_mode & S_IWGRP) ? "Yes" : "No");
    printf("Group Execute: %s\n", (fileStat.st_mode & S_IXGRP) ? "Yes" : "No");
    printf("Others Read: %s\n", (fileStat.st_mode & S_IROTH) ? "Yes" : "No");
    printf("Others Write: %s\n", (fileStat.st_mode & S_IWOTH) ? "Yes" : "No");
    printf("Others Execute: %s\n", (fileStat.st_mode & S_IXOTH) ? "Yes" : "No");

    return 0;
}