clc
close all
%%VALORES DE X 
x=[100 
1000
5000
10000
50000
100000
200000
400000
600000
800000
1000000
];
 
%%VALORES DE Y = F(x) en Milisegundos
y=[0.2069473
0.5970001
3.8108826
5.8128834
34.8770618
71.7039108
195.3759193
296.1168289
548.7711430
896.3379860
772.4988461
];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n=1; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,y,n)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,1000000,1000);      %%ESPACIO DE PUNTOS PARA Xi
z=polyval(p,xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,y,'o',xi,z,'-'),grid;
%%plot(x,y,'o',xi,z,xi,z2,xi,z3,xi,z4),grid;
ylabel('F(n)');
xlabel('n');