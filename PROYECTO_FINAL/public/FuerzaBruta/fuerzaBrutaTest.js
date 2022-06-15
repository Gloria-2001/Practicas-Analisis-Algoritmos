const mostrar = document.getElementById("mostrar");
let lista1 = document.getElementById("listaValoresPol1");
let lista2 = document.getElementById("listaValoresPol2");
let polinomio1 = document.querySelectorAll(".polinomio1");
let polinomio2 = document.querySelectorAll(".polinomio2");
var mostrar_Polinomio_1 = document.getElementById("show1");
var mostrar_Polinomio_2 = document.getElementById("show2");
var mostrar_matriz_Uno = document.getElementById("show3");
var SumDiagonal = document.getElementById("show4");

let ArregloPolinomio1= [];
let ArregloPolinomio2= [];

let Coefi0 ;
let Coefi1;
let Coefi2;
let Coefi3;
let Coefi4;
let Coefi5;
let Coefi6;
let Coefi7;
let Coefi8;


function Aleatorio(){          
    document.getElementById("cfe0Pol1").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe1Pol1").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe2Pol1").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe3Pol1").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe4Pol1").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe0Pol2").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe1Pol2").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe2Pol2").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe3Pol2").value = Math.floor(Math.random() * (100-1+1)) + 1;
    document.getElementById("cfe4Pol2").value = Math.floor(Math.random() * (100-1+1)) + 1;
 }

 function Ceros(){          
    document.getElementById("cfe0Pol1").value = "0";
    document.getElementById("cfe1Pol1").value = "0";
    document.getElementById("cfe2Pol1").value = "0";
    document.getElementById("cfe3Pol1").value = "0";
    document.getElementById("cfe4Pol1").value = "0";
    document.getElementById("cfe0Pol2").value = "0";
    document.getElementById("cfe1Pol2").value = "0";
    document.getElementById("cfe2Pol2").value = "0";
    document.getElementById("cfe3Pol2").value = "0";
    document.getElementById("cfe4Pol2").value = "0";
 }


mostrar.addEventListener("click",e=>{
    e.preventDefault;
    
    guardar();
    multiplicacion();
    reduccionTerminos();
    mostrarPolinomios();
});

function guardar(){
    polinomio1.forEach(elemento=>{
        ArregloPolinomio1.push(elemento.value);
    })

    polinomio2.forEach(elemento=>{
        ArregloPolinomio2.push(elemento.value);
    })
}

let resultadosPrevios = [];

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
  
    
    
     Coefi0 = parseInt(resultadosPrevios[0]);
     Coefi1 = parseInt(resultadosPrevios[1]) + parseInt(resultadosPrevios[5]);
     Coefi2 = parseInt(resultadosPrevios[2]) +parseInt(resultadosPrevios[6])+parseInt(resultadosPrevios[10]);
    Coefi3 = parseInt(resultadosPrevios[3]) + parseInt(resultadosPrevios[7]) +parseInt(resultadosPrevios[11])+ parseInt(resultadosPrevios[15]);
    Coefi4 =   parseInt(resultadosPrevios[4]) + parseInt(resultadosPrevios[8]) +parseInt(resultadosPrevios[12])+ parseInt(resultadosPrevios[16])+parseInt(resultadosPrevios[20]);
    Coefi5 =parseInt(resultadosPrevios[9]) + parseInt(resultadosPrevios[13]) +parseInt(resultadosPrevios[17])+ parseInt(resultadosPrevios[21]);
    Coefi6 = parseInt(resultadosPrevios[14]) +parseInt(resultadosPrevios[18])+parseInt(resultadosPrevios[22]);
    Coefi7 =  parseInt(resultadosPrevios[19]) + parseInt(resultadosPrevios[23]);
    Coefi8 =parseInt(resultadosPrevios[24]);
    
    console.log(Coefi0);
    console.log(Coefi1);
    console.log(Coefi2);
    console.log(Coefi3);
    console.log(Coefi4);
    console.log(Coefi5);
    console.log(Coefi6);
    console.log(Coefi7);
    console.log(Coefi8);
}

function mostrarPolinomios(){
    
    let my_list1 = `<li id="head1"></li>` 
    polinomio1.forEach(elemento=>{
        my_list1 += `<li class="filaPolinomio1">${elemento.value}</li>`
        setTimeout(cambioColor,7000);
    });
    mostrar_Polinomio_1.innerHTML = my_list1;

    let my_list2 = `<li id="head2"></li>`
    polinomio2.forEach(elemento=>{
        my_list2 += `<li class="filaPolinomio2">${elemento.value}</li>`
    });
    mostrar_Polinomio_2.innerHTML = my_list2

    let my_list3 = `<li id="head3"> </li>`
    for(let i = 0; i < resultadosPrevios.length; i++){

        if(i%5 == 0){
            my_list3 += `<br><br><br>`
        }
       
        my_list3 += `<li class="resultadosPrevios">${resultadosPrevios[i]}</li>`  
  
    }

    mostrar_matriz_Uno.innerHTML = my_list3;


    let my_list4 = `<li id="head4"> </li>`
    my_list4 = `<li id="diagonalCoef0">${Coefi0}</li>
                     <li id="diagonalCoef1">${Coefi1}x</li>
                     <li id="diagonalCoef2">${Coefi2}x²</li>
                     <li id="diagonalCoef3">${Coefi3}x³</li>
                     <li id="diagonalCoef4">${Coefi4}x⁴</li>
                     <li id="diagonalCoef5">${Coefi5}x⁵</li>
                     <li id="diagonalCoef6">${Coefi6}x⁶</li>
                     <li id="diagonalCoef7">${Coefi7}x⁷</li>
                     <li id="diagonalCoef8">${Coefi8}x⁸</li>`  
   SumDiagonal.innerHTML = my_list4;
    
    // let my_list3 = `<li id="head3"> </li>`
    // resultadosPrevios.forEach( elemento =>{
    //     my_list3 += `<li>${ elemento }</li>`
    // }); 
    // mostrar_matriz_Uno.innerHTML = my_list3; 
}

function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

async function cambioColor(){
    var coeficientes1 = document.querySelectorAll(".filaPolinomio1");
    var coeficientes2 = document.querySelectorAll(".filaPolinomio2");

    for(let i=0; i<coeficientes1.length; i++){
        coeficientes1[i].style.backgroundColor="#018abe";
        for(let j=0; j<coeficientes2.length; j++){
            coeficientes2[j].style.backgroundColor="#018abe";
        }
        cambioColorAux();
        await sleep(2000);
        coeficientes1[i].style.backgroundColor="#02457a";
    }
    cambioColorDiagonales();
}

async function cambioColorAux(){
    var resultadosPrevios = document.querySelectorAll(".resultadosPrevios");
    for(let i=0; i<=4; i++){
        resultadosPrevios[i].style.backgroundColor="#018abe";
    }

    await sleep(2000);

    for(let i=5; i<=9; i++){
        resultadosPrevios[i].style.backgroundColor="#018abe";
    }
    
    await sleep(2000);

    for(let i=10; i<=14; i++){
        resultadosPrevios[i].style.backgroundColor="#018abe"; 
    }

    await sleep(2000);

    for(let i=15; i<=19; i++){
        resultadosPrevios[i].style.backgroundColor="#018abe";
    }

    await sleep(2000);

    for(let i=20; i<=24; i++){
        resultadosPrevios[i].style.backgroundColor="#018abe";
    }

    await sleep(2000);
}

async function cambioColorDiagonales(){
    var resultadosPrevios = document.querySelectorAll(".resultadosPrevios");
    let diagonalCoef0 = document.getElementById("diagonalCoef0");
    let diagonalCoef1 = document.getElementById("diagonalCoef1");
    let diagonalCoef2 = document.getElementById("diagonalCoef2");
    let diagonalCoef3 = document.getElementById("diagonalCoef3");
    let diagonalCoef4 = document.getElementById("diagonalCoef4");
    let diagonalCoef5 = document.getElementById("diagonalCoef5");
    let diagonalCoef6 = document.getElementById("diagonalCoef6");
    let diagonalCoef7 = document.getElementById("diagonalCoef7");
    let diagonalCoef8 = document.getElementById("diagonalCoef8");

    resultadosPrevios[0].style.backgroundColor="orange";
    diagonalCoef0.style.backgroundColor="orange";

    await sleep(2000);

    resultadosPrevios[1].style.backgroundColor="red";
    resultadosPrevios[5].style.backgroundColor="red";
    diagonalCoef1.style.backgroundColor="red";

    await sleep(2000);

    resultadosPrevios[2].style.backgroundColor="green";
    resultadosPrevios[6].style.backgroundColor="green";
    resultadosPrevios[10].style.backgroundColor="green";
    diagonalCoef2.style.backgroundColor="green";

    await sleep(2000);

    resultadosPrevios[3].style.backgroundColor="purple";
    resultadosPrevios[7].style.backgroundColor="purple";
    resultadosPrevios[11].style.backgroundColor="purple";    
    resultadosPrevios[15].style.backgroundColor="purple";  
    diagonalCoef3.style.backgroundColor="purple";

    await sleep(2000);

    resultadosPrevios[4].style.backgroundColor="brown";
    resultadosPrevios[8].style.backgroundColor="brown";
    resultadosPrevios[12].style.backgroundColor="brown";    
    resultadosPrevios[16].style.backgroundColor="brown";
    resultadosPrevios[20].style.backgroundColor="brown";
    diagonalCoef4.style.backgroundColor="brown";

    await sleep(2000);

    resultadosPrevios[9].style.backgroundColor="#dc143c";
    resultadosPrevios[13].style.backgroundColor="#dc143c";
    resultadosPrevios[17].style.backgroundColor="#dc143c";    
    resultadosPrevios[21].style.backgroundColor="#dc143c";
    diagonalCoef5.style.backgroundColor="#dc143c";

    await sleep(2000);
    
    resultadosPrevios[14].style.backgroundColor="black";
    resultadosPrevios[18].style.backgroundColor="black";
    resultadosPrevios[22].style.backgroundColor="black";    
    diagonalCoef6.style.backgroundColor="black";

    await sleep(2000);

    resultadosPrevios[19].style.backgroundColor="gray";
    resultadosPrevios[23].style.backgroundColor="gray";    
    diagonalCoef7.style.backgroundColor="gray";

    await sleep(2000);

    resultadosPrevios[24].style.backgroundColor="#FF1493";
    diagonalCoef8.style.backgroundColor="#FF1493"; 
}