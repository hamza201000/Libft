

#include <unistd.h>


void ft_putendl_fd(char *s, int fd)
{

    while(*s){
        write(fd,s,1);
        s++;
    }
     write(fd,"\n",1);
}

// int main(void)
// {
//     ft_putendl_fd("Hello", 1);
//     ft_putendl_fd("", 1);
//     ft_putendl_fd("A", 1);
//     ft_putendl_fd("Hello World", 1);
//     ft_putendl_fd("12345", 1);
//     ft_putendl_fd("!@#$%", 1);
//     ft_putendl_fd("Hello\nWorld", 1);
//     ft_putendl_fd("Error message", 2);

//     return (0);
// }