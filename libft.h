#ifndef LIBFT_H
#define LIBFT_H

int ft_isalpha(int c);
int ft_isdigit(int c);
size_t ft_strlen(char *c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strtrim(char const *s1, char const *set);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
char *ft_itoa(int n);

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;

#endif