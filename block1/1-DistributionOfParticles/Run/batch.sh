#! /bin/bash -f

NCYCLE=20
for NPART in 64 128 256 512
do
    for NCOMP in 16 32 64 128 256
    do
        echo "${NPART}\n${NCOMP}\n${NCYCLE}\n"
        echo -e "${NPART}\n${NCOMP}\n${NCYCLE}\n" | ../Source/distribution
        python plot.py
        mv distribution.png ../Results/${NPART}_${NCOMP}.png
    done
done