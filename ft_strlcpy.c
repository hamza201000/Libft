

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t src_len;
    size_t i;

    src_len=0;
    i=0;
    while (src[src_len]!=0)
    {
        src_len++;
    }
    if (size>0){
        while (i<size-1){
            dst[i]=src[i];
            i++;
        }
        dst[i]=0;
    }
    return src_len;
}
