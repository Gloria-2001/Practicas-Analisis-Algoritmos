#!/bin/bash
gcc main.c  tiempo.c -o main
#./main 50 
./main 500000 < numero10millones.txt > saln500000.txt
./main 50 < numero10millones.txt > saln50.txt
./main 100 < numero10millones.txt > saln100.txt
./main 250 < numero10millones.txt > saln250.txt
./main 500 < numero10millones.txt > saln500.txt
./main 1000 < numero10millones.txt > saln1000.txt
./main 1500 < numero10millones.txt > saln1500.txt
./main 2000 < numero10millones.txt > saln2000.txt
./main 2500 < numero10millones.txt > saln2500.txt
./main 3000 < numero10millones.txt > saln3000.txt
./main 4500 < numero10millones.txt > saln4500.txt
./main 5000 < numero10millones.txt > saln5000.txt
./main 5600 < numero10millones.txt > saln5600.txt
./main 10000 < numero10millones.txt > saln1000.txt
./main 50000 < numero10millones.txt > saln50000.txt
./main 100000 < numero10millones.txt > saln100000.txt
./main 200000 < numero10millones.txt > saln200000.txt
./main 400000 < numero10millones.txt > saln400000.txt
./main 600000 < numero10millones.txt > saln600000.txt
./main 800000 < numero10millones.txt > saln800000.txt
./main 10000000 < numero10millones.txt > saln10000000.txt
#./main 15000<numero10millones.txt > saln15000.txt
#./main 51000 >> sal.txt 

