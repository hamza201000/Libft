

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
void ft_putchar_fd(char c, int fd)
{
    write(fd,&c,1);
}



// int main(void)
// {
//     int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

//     if (fd == -1)
//         return (1);
//     printf("fd:%d\n",fd);
//     ft_putchar_fd('H', fd);
//     ft_putchar_fd('i', fd);
//     ft_putchar_fd('!', fd);

//     close(fd);
//     return (0);
// }

