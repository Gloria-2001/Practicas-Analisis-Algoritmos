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

y=[0.00229633
0.00274806
0.00253474
2.81082E-09
2.69787E-09
2.93628E-09
2.78572E-09
2.64767E-09
3.13707E-09
4.21622E-09
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
title('Aproximación Búsqueda Binaria');

%% print(aux, "plot.jpg", "-djpg");