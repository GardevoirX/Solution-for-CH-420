#! /bin/bash -f
#
# Scriptfile
#
# rho    = density
# lmax   = number of steps
# nequil = number of equilibration steps
# dr     = maximum displacement
# npart  = number of particles

for rho in 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 1.4 1.6 2.0 2.2 2.6 3.0
do
temp=2.0

cat > input  <<endofdata
  ibeg  nequil   lmax  nsamp  
     0  10000    10000      1        
    dr
  0.09 
ndispl
    50  
 npart    temp    rho
   500     ${temp}  ${rho} 
 epsilon sigma  mass  cutoff
 1.0     1.0    1.0   3.5
endofdata

time  ../Source/mc_nvt >> output_${temp}_${rho}.txt
pressure="$(grep "Average Pressure" output_${temp}_${rho}.txt | grep -o '[0-9.]*')"
printf "${rho} ${pressure} \n" >> data_${temp}
rm input
done
exit
