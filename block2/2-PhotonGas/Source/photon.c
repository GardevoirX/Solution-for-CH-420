#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ran_uniform.h"

#define CycleMultiplication 1000
#define MaxEnergyLevel 100000

int main(void)
{
  int  NumberOfCycles,NumberOfInitializationSteps,New,Old,i,j;
  int maxold=0;
  double Beta,Sum,Count;
  int Distribution[MaxEnergyLevel];
  FILE *FilePtr;

  for (i=0;i<MaxEnergyLevel;i++) Distribution[i]=0;
      
  // initialize the random number generator with the system time
  InitializeRandomNumberGenerator(time(0l));

  // read the input parameters
  printf("How many cycles (x %d)? ",CycleMultiplication);
  fscanf(stdin,"%d",&NumberOfCycles);

  printf("How many initialization cycles (x %d)? ",CycleMultiplication);
  fscanf(stdin,"%d",&NumberOfInitializationSteps);

  if(NumberOfInitializationSteps>=NumberOfCycles)
  {
    printf("Initialisation must be shorter than the run!\n");
  exit(0); 
  } 

  printf("Beta*epsilon (Example: 1.0) ?");
  fscanf(stdin,"%lf",&Beta);

  New=1;
  Old=1;
  Sum=0.0;
  Count=0.0;

  // Loop Over All Cycles
  for(i=0;i<NumberOfCycles;i++)
  {
    for(j=0;j<CycleMultiplication;j++)
    {
      // start modification
      if (RandomNumber()<0.5)
      {
        New = Old + 1;
        // New = Old + floor(RandomNumber() * 6);
        // New = Old + 3;
      }
      else
      {
        New = Old - 1;
        // New = Old - floor(RandomNumber() * 6);
        // New = Old - 3;
      }
      if (New < 0)
      {
        New = 0;
      }

      // end   modification

      // accept or reject
      if(RandomNumber()<exp(-Beta*(New-Old)))
      {  
        Old=New;      if(i>NumberOfInitializationSteps)
      {
        Sum+=Old;
        Count+=1.0;
        if (Old>maxold) maxold=Old;
        Distribution[Old]++;
      }
      }
      // calculate average occupancy result

    }
  }

  // write the final result
  printf( "\nResults:\n" );
  printf("Average Value     : %lf\n",Sum/Count);
  printf("Theoretical Value : %lf\n",1.0/(exp(Beta)-1.0));
  printf("Relative Error    : %lf\n",fabs((exp(Beta)-1.0)*((Sum/Count) - (1.0/(exp(Beta)-1.0)))));

  FilePtr=fopen("distribution.dat","w");

  for(i=0;i<maxold;i++)
  {
    fprintf(FilePtr,"%d, %f\n",i,Distribution[i] / Count);
  }
  fclose(FilePtr);

  return 0;
}
