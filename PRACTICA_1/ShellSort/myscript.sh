#!/bin/bash
gcc main.c  tiempo.c -o main
#./main 50 
./main 500000<numero10millones.txt > saln500000.txt
./main 100 < numero10millones.txt > saln100.txt
./main 1000 < numero10millones.txt > saln1000.txt
./main 5000<numero10millones.txt > saln5000.txt
./main 10000<numero10millones.txt > saln10000.txt
./main 15000<numero10millones.txt > saln15000.txt
./main 50000<numero10millones.txt > saln50000.txt
./main 100000<numero10millones.txt > saln100000.txt
./main 200000<numero10millones.txt > saln200000.txt
./main 300000<numero10millones.txt > saln300000.txt
./main 400000<numero10millones.txt > saln400000.txt
./main 600000<numero10millones.txt > saln600000.txt
./main 800000<numero10millones.txt > saln800000.txt
./main 1000000<numero10millones.txt > saln1000000.txt
./main 150000<numero10millones.txt > saln150k.txt
./main 250000<numero10millones.txt > saln250k.txt
./main 275000<numero10millones.txt > saln275k.txt
./main 320000<numero10millones.txt > saln320k.txt
./main 80000<numero10millones.txt > saln80k.txt
./main 375000<numero10millones.txt > saln375k.txt


#./main 51000 >> sal.txt

