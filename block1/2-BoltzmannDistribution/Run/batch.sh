#! /bin/bash -f

TYPE="rotor"
mkdir -p ../Results/${TYPE}

for NENERGY in 10000
do
    for TEMP in 1 2 4 8 16 32 64 128 256 512
    do
        echo -e "${NENERGY}\n${TEMP}\n" | ../Source/boltzmann
        python plot.py
        mv boltzmann_distribution.png ../Results/${TYPE}/${NENERGY}_${TEMP}.png
    done
done