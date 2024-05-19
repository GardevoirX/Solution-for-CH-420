#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "system.h"
#include "ran_uniform.h"

// integrate the equations of motion for the Andersen thermostat
void IntegrateAndersen(void)
{
  double U,F;

  // start modification
  Position += Tstep * Velocity + SQR(Tstep) * 0.5 * OldF;
  Velocity += 0.5 * Tstep * OldF;
  Force(Position,&U,&F);
  Velocity += 0.5 * Tstep * F;
  if (RandomNumber() < Nu * Tstep)
  {
    Velocity = RandomVelocity(Temperature);
  }
  OldF=F;
  // end modification
}
