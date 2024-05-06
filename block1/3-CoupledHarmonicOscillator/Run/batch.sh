#! /bin/bash -f

NCYCLE=100
ENSEMBEL=1
MODE="NVE"
RATIO=10

# NVE
for NOSCI in 4 8 16 32 64 128 256 512 1024
do
    ENERGY=$(awk "BEGIN {print ${NOSCI}*${RATIO}}");
    echo -e "${NOSCI}\n${NCYCLE}\n${ENSEMBEL}\n${ENERGY}\n" | ../Source/harmonic;
    mv results.dat Results/${MODE}/results_${NOSCI}.dat
done

# NVT