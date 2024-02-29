#include <math.h>
#include <stdio.h>
#include <string.h>
#define NPOINTS 100
float* linspace(float* x, float start, float end, const int npoints){
    
    float step = (end - start) / npoints;
    for(int i = 1; i < npoints; i++){
        x[i] = x[i - 1] + step;
    }

    return x;
}

void L_J_potential(float* x, float* y, float epsilon, float sigma, float start, float end, int npoints){

    memset(x, 0, npoints);
    linspace(x, start, end, npoints);
    for(int i = 0; i < npoints; i++){
        y[i] = 4 * epsilon * (pow(sigma / x[i], 12) - pow(sigma / x[i], 6));
    }

    return;
}



int main(void){
    float epsilon = 0;
    float sigma = 0;
    printf("This is a program calculating L-J potential.\n");
    printf("To start, please enter two floats for epsilon and sigma:\n");
    scanf("%f %f\n", &epsilon, &sigma);

    float x[NPOINTS];
    float y[NPOINTS];
    L_J_potential(x, y, epsilon, sigma, 0, 10, NPOINTS);

    FILE *fp = fopen("output.txt", "w+");
    for(int i = 0; i < NPOINTS; i++){
        fprintf(fp, "%f     %f     \n", x[i], y[i]);
    }
    fclose(fp);

    return 0;
}