#include <stdio.h>

int main(void){
    // Read data
    FILE *fp = fopen("numbers.dat", "r");
    int a[10] = {0};
    for(int i = 0; i < 10; i++){
        fscanf(fp, "%d ", &a[i]);
    }
    fclose(fp);

    // Calculate average
    float sum = 0;
    for(int i = 0; i < 10; i++){
        sum += a[i];
    }
    printf("The average of input data is %f \n", sum / 10);

    return 0;
}