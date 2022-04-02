#!bin/bash
echo "Compilando... \n"
gcc Inserción.c tiempo.c -o Inserción.out

echo "Creando directorio de salidas... \n"
mkdir Salidas -p

echo "Ejecutando para n=500,000... \n"
./Inserción.out 500000 < numeros10M.txt > Salidas/salida500000.txt

echo Iniciando pruebas con diferentes n...
echo "Ejecutando para n=100... \n"
./Inserción.out 100 < numeros10M.txt > Salidas/salida100.txt
echo "Ejecutando para n=1000... \n"
./Inserción.out 1000 < numeros10M.txt > Salidas/salida1000.txt
echo "Ejecutando para n=5000... \n"
./Inserción.out 5000 < numeros10M.txt > Salidas/salida5000.txt
echo "Ejecutando para n=10000... \n"
./Inserción.out 10000 < numeros10M.txt > Salidas/salida10000.txt
echo "Ejecutando para n=50000... \n"
./Inserción.out 50000 < numeros10M.txt > Salidas/salida50000.txt
echo "Ejecutando para n=100000... \n"
./Inserción.out 100000 < numeros10M.txt > Salidas/salida100000.txt
echo "Ejecutando para n=200000... \n"
./Inserción.out 200000 < numeros10M.txt > Salidas/salida200000.txt
echo "Ejecutando para n=300000... \n"
./Inserción.out 300000 < numeros10M.txt > Salidas/salida300000.txt
echo "Ejecutando para n=400000... \n"
./Inserción.out 400000 < numeros10M.txt > Salidas/salida400000.txt
echo "Ejecutando para n=600000... \n"
./Inserción.out 600000 < numeros10M.txt > Salidas/salida600000.txt
echo "Ejecutando para n=700000... \n"
./Inserción.out 700000 < numeros10M.txt > Salidas/salida700000.txt
echo "Ejecutando para n=800000... \n"
./Inserción.out 800000 < numeros10M.txt > Salidas/salida800000.txt
echo "Ejecutando para n=900000... \n"
./Inserción.out 900000 < numeros10M.txt > Salidas/salida900000.txt
echo "Ejecutando para n=1000000... \n"
./Inserción.out 1000000 < numeros10M.txt > Salidas/salida1000000.txt
echo "Ejecutando para n=2000000... \n"
./Inserción.out 2000000 < numeros10M.txt > Salidas/salida2000000.txt
echo "Ejecutando para n=3000000... \n"
./Inserción.out 3000000 < numeros10M.txt > Salidas/salida3000000.txt
echo "Ejecutando para n=4000000... \n"
./Inserción.out 4000000 < numeros10M.txt > Salidas/salida4000000.txt
echo "Ejecutando para n=5000000... \n"
./Inserción.out 5000000 < numeros10M.txt > Salidas/salida5000000.txt
echo "Ejecutando para n=6000000... \n"


echo "El proceso ha terminado...\n"
