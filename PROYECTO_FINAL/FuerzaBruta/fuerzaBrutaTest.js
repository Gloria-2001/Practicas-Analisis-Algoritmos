const mostrar = document.getElementById("mostrar");
let lista1 = document.getElementById("listaValoresPol1");
let lista2 = document.getElementById("listaValoresPol2");
var polinomio1 = document.querySelectorAll(".polinomio1");
var polinomio2 = document.querySelectorAll(".polinomio2");

var ArregloPolinomio1= [];
var ArregloPolinomio2= [];



mostrar.addEventListener("click",e=>{
    e.preventDefault;
    guardar();
    multiplicacion();
    reduccionTerminos();
});

function guardar(){
    polinomio1.forEach(elemento=>{
        ArregloPolinomio1.push(elemento.value);
    })

    polinomio2.forEach(elemento=>{
        ArregloPolinomio2.push(elemento.value);
    })
}

var resultadosPrevios = [];

function multiplicacion(){
    let i = 0, j = 0;
    for (i = 0; i < ArregloPolinomio1.length; i++) {
        for (j = 0; j < ArregloPolinomio2.length; j++) {
            let coeficiente = (ArregloPolinomio1[i]) * (ArregloPolinomio2[j]);
            resultadosPrevios.push([coeficiente]);
        }
    }
    console.log(resultadosPrevios);
}

let resultado = [];

function reduccionTerminos(){
   var  diagonal0=resultadosPrevios[0]
    // var diagonal1=resultadosPrevios[1]+resultadosPrevios[5];
    // var diagonal2=resultadosPrevios[2]+resultadosPrevios[6]+resultadosPrevios[10];
    // var diagonal3=resultadosPrevios[3]+resultadosPrevios[7]+resultadosPrevios[11]+resultadosPrevios[15];
    // var diagonal4=resultadosPrevios[4]+resultadosPrevios[8]+resultadosPrevios[12]+resultadosPrevios[16]+resultadosPrevios[20];
    // var diagonal5=resultadosPrevios[9]+resultadosPrevios[13]+resultadosPrevios[17]+resultadosPrevios[21];
    // var diagonal6=resultadosPrevios[14]+resultadosPrevios[18]+resultadosPrevios[22]
    // var diagonal7=resultadosPrevios[19]+resultadosPrevios[23];
    // var diagonal8=resultadosPrevios[24];

    console.log(diagonal0);
    // console.log(diagonal1); 
    // console.log(diagonal2);
    // console.log(diagonal3);
    // console.log(diagonal4);
    // console.log(diagonal5);
    // console.log(diagonal6);
    // console.log(diagonal7);
    // console.log(diagonal8);
}