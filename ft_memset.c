
#include <stdio.h>

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
void printArray(int arr[], int n)
{
   for (int i=0; i<n; i++)
      printf("%d ", arr[i]);
}
int main()
{
    char str[50] = "GeeksForGeeks is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    memset(str + 13, '.', 8*sizeof(char));

    printf("After memset():  %s", str);
    return 0;
}