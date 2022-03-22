#!/bin/bash
gcc main.c  tiempo.c -o main
./main 100 >> sal.txt < numeros10millones.txt
./main 1000 >> sal.txt < numeros10millones.txt
./main 5000 >> sal.txt < numeros10millones.txt
./main 10000 >> sal.txt < numeros10millones.txt
./main 50000 >> sal.txt < numeros10millones.txt
./main 100000 >> sal.txt < numeros10millones.txt
./main 200000 >> sal.txt < numeros10millones.txt
./main 400000 >> sal.txt < numeros10millones.txt
./main 600000 >> sal.txt < numeros10millones.txt
./main 800000 >> sal.txt < numeros10millones.txt
./main 1000000 >> sal.txt < numeros10millones.txt
./main 2000000 >> sal.txt < numeros10millones.txt
./main 3000000 >> sal.txt < numeros10millones.txt
./main 4000000 >> sal.txt < numeros10millones.txt
./main 5000000 >> sal.txt < numeros10millones.txt
./main 6000000 >> sal.txt < numeros10millones.txt
./main 7000000 >> sal.txt < numeros10millones.txt
./main 8000000 >> sal.txt < numeros10millones.txt
./main 9000000 >> sal.txt < numeros10millones.txt
./main 10000000 >> sal.txt < numeros10millones.txt
