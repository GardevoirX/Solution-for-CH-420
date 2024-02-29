#include <stdio.h>

int main(void){
    printf("Please enter an integer: \n");
    int x;
    fscanf(stdin, "%d", &x);
    for (int i = 1; i <= x; i++){
        printf("XU\n");
    }
    return 0;
}