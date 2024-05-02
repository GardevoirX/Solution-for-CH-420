#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "ran_uniform.h"

// attempts to displace a randomly selected particle
void Mcmove(void)
{
  double EnergyNew,VirialNew,EnergyOld,VirialOld;
  VECTOR NewPosition;
  int i;
 
  NumberOfAttempts++;
  /*
  // choose a random particle
  i=NumberOfParticles*RandomNumber();

  // calculate old energy
  EnergyParticle(Positions[i],i,0,&EnergyOld,&VirialOld);

  // give a random displacement
  NewPosition.x=Positions[i].x+(RandomNumber()-0.5)*MaximumDisplacement;
  NewPosition.y=Positions[i].y+(RandomNumber()-0.5)*MaximumDisplacement;
  NewPosition.z=Positions[i].z+(RandomNumber()-0.5)*MaximumDisplacement;

  // calculate new energy
  EnergyParticle(NewPosition,i,0,&EnergyNew,&VirialNew);
  */
  VECTOR NewPositions[NumberOfParticles];
  VECTOR TEMP[NumberOfParticles];
  for(int i=0;i<NumberOfParticles;i++)
   {
      TEMP[i].x=Positions[i].x;
      TEMP[i].y=Positions[i].y;
      TEMP[i].z=Positions[i].z;
   }

  EnergySystem();
  EnergyOld=TotalEnergy;
  VirialOld=TotalVirial;
  for (int j = 0; j < NumberOfParticles; j++)
  {
    NewPositions[j].x = Positions[j].x+(RandomNumber()-0.5)*MaximumDisplacement;
    NewPositions[j].y = Positions[j].y+(RandomNumber()-0.5)*MaximumDisplacement;
    NewPositions[j].z = Positions[j].z+(RandomNumber()-0.5)*MaximumDisplacement;
  }
  for(int i=0;i<NumberOfParticles;i++)
   {
      Positions[i].x=NewPositions[i].x;
      Positions[i].y=NewPositions[i].y;
      Positions[i].z=NewPositions[i].z;
   }
  EnergySystem();
  EnergyNew=TotalEnergy;
  VirialNew=TotalVirial;
  if(RandomNumber()<exp(-Beta*(EnergyNew-EnergyOld)))
  {
    // accept
    NumberOfAcceptedMoves++;
    RunningEnergy+=(EnergyNew-EnergyOld);
    RunningVirial+=(VirialNew-VirialOld);
  }
    // put particle in simulation box
/*
    if(NewPosition.x<0.0)
      NewPosition.x+=Box;
    else if(NewPosition.x>=Box)
      NewPosition.x-=Box;
            
    if(NewPosition.y<0.0)
      NewPosition.y+=Box;
    else if(NewPosition.y>=Box)
      NewPosition.y-=Box;
          
    if(NewPosition.z<0.0)
      NewPosition.z+=Box;
    else if(NewPosition.z>=Box)
      NewPosition.z-=Box;
*/
  else
  {
   // update new position
   for(int i=0;i<NumberOfParticles;i++)
   {
      Positions[i].x=TEMP[i].x;
      Positions[i].y=TEMP[i].y;
      Positions[i].z=TEMP[i].z;
   }

  }
}
