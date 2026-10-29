
void *ft_memmove(void *dest, const void *src, size_t n)
{

    unsigned char *new_dest;
    const unsigned char *new_src;
    size_t i;

    i = 0;
    new_dest = dest;
    new_src = src;

    if (dest > src)
    {
        while (n > 0)
        {
            n--;
            new_dest[n] = new_src[n];
        }
    }
    else
    {
        while (i < n)
        {
            new_dest[i] = new_src[i];
            i++;
        }
    }
    return dest;
}