

#include <unistd.h>
void ft_putstr_fd(char *s, int fd)
{
    while(*s){
        write(fd,s,1);
        s++;
    }
}



// int main(void)
// {
//     ft_putstr_fd("Hello", 1);
//     ft_putstr_fd("\n", 1);

//     ft_putstr_fd("", 1);
//     ft_putstr_fd("42 School\n", 1);

//     ft_putstr_fd("Hello World!\n", 1);
//     ft_putstr_fd("123456789\n", 1);
//     ft_putstr_fd("!@#$%^&*()\n", 1);

//     ft_putstr_fd("This is an error message\n", 2);

//     return (0);
// }