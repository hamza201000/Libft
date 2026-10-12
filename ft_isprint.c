int ft_isprint(char c){
    if ((c>=0&&c<32)||c==127){
        return 0;
    }
    return 1
}