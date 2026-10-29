
size_t ft_strlen(char *c){
    size_t coun;

    coun=0;
    while (c[coun]!=0){
        coun++;
    }
    return coun;
}
