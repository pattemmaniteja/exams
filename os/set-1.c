//TASK-1********************************************

//  write from the manual...........




//TASK-2**********************************************

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
void main()
{
    int fd1, fd2, n = 1;
    char *buf;
    fd1 = open("f1", O_RDONLY);
    fd2 = open("f2", O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
    if ((fd1 == -1) || (fd2 == -1))
        printf("error");
    else
    {
        while (n > 0)
        {
            n = read(fd1, &buf, 1);
            write(fd2, &buf, 1);
        }
    }
}

