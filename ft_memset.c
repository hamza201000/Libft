


void    *ft_memset(void *s, int c, size_t n){

    int i;

    i=0; 
    while(i<n){
        *(char *)s=c;
        s++;
        i++;
    }
    return s;
}