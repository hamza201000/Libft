

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char  *new_dest;
    const unsigned char *new_src;
    size_t i;

    new_dest=dest;
    new_src=src;
    i=0;
    while(i<n){
        new_dest[i]=new_src[i];
        i++;
    }
    return dest;
}
