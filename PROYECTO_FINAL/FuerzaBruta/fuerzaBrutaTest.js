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
     let Coefi0 ;
     let Coefi1;
     let Coefi2;
     let Coefi3;
    
    
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
        my_list1 += `<li>${elemento.value}</li>`
    });
    mostrar_Polinomio_1.innerHTML = my_list1;

    let my_list2 = `<li id="head2"></li>`
    polinomio2.forEach(elemento=>{
        my_list2 += `<li>${elemento.value}</li>`
    });
    mostrar_Polinomio_2.innerHTML = my_list2

    let my_list3 = `<li id="head3"> </li>`
    for(let i = 0; i < resultadosPrevios.length; i++){

        if(i%5 == 0){
            my_list3 += `<br><br><br>`
        }
       
        my_list3 += `<li>${resultadosPrevios[i]}</li>`  
  
    }

    mostrar_matriz_Uno.innerHTML = my_list3;


    let my_list4 = `<li id="head4"> </li>`
    my_list4 += `<li>${Coefi0}</li>`  
    SumDiagonal.innerHTML = my_list4;
    
    // let my_list3 = `<li id="head3"> </li>`
    // resultadosPrevios.forEach( elemento =>{
    //     my_list3 += `<li>${ elemento }</li>`
    // }); 
    // mostrar_matriz_Uno.innerHTML = my_list3; 
    


}