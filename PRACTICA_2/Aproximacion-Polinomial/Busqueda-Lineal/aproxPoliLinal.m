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

y=[13.223958
30.387545
39.47228
51.19293
73.11527
71.26689
93.78076
91.87337
100.65819
107.14911
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
title('Aproximación Polinomial, Búsqueda Lineal');

%% print(aux, "plot.jpg", "-djpg");