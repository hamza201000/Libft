
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t dest_len;
    size_t i;

    dest_len=0;
    i=0;
    while (dst[dest_len])
    {
        dest_len++;
    }
    if (size>0){
        while (src[i]&&dest_len<size-1){
            dst[dest_len]=src[i];
            dest_len++;
            i++;
        }
        dst[dest_len]=0;
        while (src[i]!=0){
            dest_len++;
            i++;
        }
    }
    return dest_len;
}
