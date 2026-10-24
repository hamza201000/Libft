

#include <unistd.h>
#include <limits.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
ft_putstr_fd(ft_itoa(n),fd);

}




int main(void)
{
    ft_putnbr_fd(0, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(1, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-1, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(42, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-42, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(123456789, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-123456789, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(1000000000, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(-1000000000, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(INT_MAX, 1);
    write(1, "\n", 1);

    ft_putnbr_fd(INT_MIN, 1);
    write(1, "\n", 1);

    return (0);
}
