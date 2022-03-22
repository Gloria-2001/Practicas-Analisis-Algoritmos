#!/bin/bash
gcc main.c  tiempo.c -o main
./main 2550 >> sal.txt < numeros10millones.txt
./main 3000 >> sal.txt < numeros10millones.txt
./main 4500 >> sal.txt < numeros10millones.txt
./main 5600 >> sal.txt < numeros10millones.txt
