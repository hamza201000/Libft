


void bzero(void *s, size_t n) {
    while(n>=0){
        *(char *)s=0;
        s++;
        n--;
    }
}