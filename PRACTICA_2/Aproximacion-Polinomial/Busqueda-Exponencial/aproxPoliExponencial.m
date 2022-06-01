clc
close all
x=[1000000
2000000
3000000
4000000
5000000
6000000
7000000
8000000
9000000
10000000
];

y=[0.0023961
0.0025272
0.0025868
0.0029921
0.0026703
0.0027180
0.0028491
0.0031233
0.0029802
0.0030040
];

n=1; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,y,n)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,1000000,1000);     %%ESPACIO DE PUNTOS PARA Xi
z=polyval(p,xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
aux = figure(1);
plot(x,y,'o',"linewidth", 3,xi,z,'-',"linewidth", 3),grid;
ylabel('F(n)');
xlabel('n');
title('Aproximación Búsqueda Exponencial');

%% print(aux, "plot.jpg", "-djpg");