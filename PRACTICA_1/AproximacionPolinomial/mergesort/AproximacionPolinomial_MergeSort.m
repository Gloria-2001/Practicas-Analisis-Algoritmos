%%VALORES DE X 
x=[100,1000,5000,10000,50000,100000,200000,400000,600000];

%%VALORES DE Y = F(x) en Milisegundos
%merge_sort
ym=[0.0000159740448,0.00021195411682,0.0012760162354,0.0025780200958,0.0138089657,0.0425460339,0.0675368309,0.1365249157,0.2266058922];

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
grado=6; 				%%GRADO DEL POLINOMIO DE AJUSTE
p=polyfit(x,ym,grado)	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(0,1000000);      %%ESPACIO DE PUNTOS PARA Xi 5000,
z=polyval(p,xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
plot(x,ym,'o',xi,z,'-'),grid;
ylabel('F(x)');
xlabel('x');
title('Ajuste polinomial');