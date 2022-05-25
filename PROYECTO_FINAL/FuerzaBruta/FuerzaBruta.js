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

  
function elementos(){

     var elementosPol1 =[] ;
     var elementosPol2 =[] ;
        
        for(let i = 1 ; i <= 5 ; i++){
            if(i=1){
                elementosPol1 [i]=document.getElementById("cfe0Pol1").value;
            }
           
            if(i=2){
                elementosPol1 [i]=document.getElementById("cfe1Pol1").value;
            }
            if(i=3){
                elementosPol1 [i]=document.getElementById("cfe2Pol1").value;
            }
            if(i=4){
                elementosPol1 [i]=document.getElementById("cfe3Pol1").value;
            }
            if(i=5){
                elementosPol1 [i]=document.getElementById("cfe4Pol1").value;
            }
            
        }
    
    
       
    
    }

// document.ready = document.getElementById("Polinomio1").value = '0';

// let valor1 = document.getElementById("Polinomio1");
// const collection = document.getElementsByClassName("textbox");


// let refresh = document.getElementById('refresh');
// refresh.addEventListener('click', _ => {
//         location.reload();
// })



// function FuncPolinomio1() {

//     valor1 = document.getElementById("Polinomio1").value;

//     if (valor1==1) {

//     document.getElementById("cfe0Pol1").style.visibility = "visible";

//     document.getElementById("sum1Pol1").style.visibility = "hidden";
//     document.getElementById("cfe1Pol1").style.visibility = "hidden";
//     document.getElementById("incog1Pol1").style.visibility = "hidden";
    
//     document.getElementById("sum2Pol1").style.visibility = "hidden";
//     document.getElementById("cfe2Pol1").style.visibility = "hidden";
//     document.getElementById("incog2Pol1").style.visibility = "hidden";
 

//     document.getElementById("sum3Pol1").style.visibility = "hidden";
//     document.getElementById("cfe3Pol1").style.visibility = "hidden";
//     document.getElementById("incog3Pol1").style.visibility = "hidden";
    
//     document.getElementById("sum4Pol1").style.visibility = "hidden";
//     document.getElementById("cfe4Pol1").style.visibility = "hidden";
//     document.getElementById("incog4Pol1").style.visibility = "hidden";
    
// }
// if (valor1==2) {

//     document.getElementById("cfe0Pol1").style.visibility = "visible";

//     document.getElementById("2").style.visibility = "visible";
//     document.getElementById("x²").style.visibility = "visible";
//     document.getElementById("+").style.visibility = "visible";

//     document.getElementById("3").style.visibility = "hidden";
//     document.getElementById("x³").style.visibility = "hidden";
//     document.getElementById("++").style.visibility = "hidden";
    
//     document.getElementById("4").style.visibility = "hidden";
//     document.getElementById("x⁴").style.visibility = "hidden";
//     document.getElementById("+++").style.visibility = "hidden";
    
//     document.getElementById("5").style.visibility = "hidden";
//     document.getElementById("x⁵").style.visibility = "hidden";
//     document.getElementById("++++").style.visibility = "hidden";
// }
// if (valor1==3) {
//     document.getElementById("1").style.visibility = "visible";
//     document.getElementById("x").style.visibility = "visible";

//     document.getElementById("2").style.visibility = "visible";
//     document.getElementById("x²").style.visibility ="visible";
//     document.getElementById("+").style.visibility = "visible";

//     document.getElementById("3").style.visibility = "visible";
//     document.getElementById("x³").style.visibility ="visible";
//     document.getElementById("++").style.visibility = "visible";

//     document.getElementById("4").style.visibility = "hidden";
//     document.getElementById("x⁴").style.visibility = "hidden";
//     document.getElementById("+++").style.visibility = "hidden";

//     document.getElementById("5").style.visibility = "hidden";
//     document.getElementById("x⁵").style.visibility = "hidden";
//     document.getElementById("++++").style.visibility = "hidden";
// }
// if (valor1==4) {
    
//     document.getElementById("1").style.visibility = "visible";
//     document.getElementById("x").style.visibility ="visible";

//     document.getElementById("2").style.visibility = "visible";
//     document.getElementById("x²").style.visibility ="visible";
//     document.getElementById("+").style.visibility = "visible";

//     document.getElementById("3").style.visibility = "visible";
//     document.getElementById("x³").style.visibility ="visible";
//     document.getElementById("++").style.visibility = "visible";

//     document.getElementById("4").style.visibility = "visible";
//     document.getElementById("x⁴").style.visibility ="visible";
//     document.getElementById("+++").style.visibility = "visible";

//     document.getElementById("5").style.visibility = "hidden";
//     document.getElementById("x⁵").style.visibility = "hidden";
//     document.getElementById("++++").style.visibility = "hidden";
// }
// if (valor1==5) {
//     document.getElementById("1").style.visibility = "visible";
//     document.getElementById("x").style.visibility ="visible";

//     document.getElementById("2").style.visibility = "visible";
//     document.getElementById("x²").style.visibility ="visible";
//     document.getElementById("+").style.visibility = "visible";

//     document.getElementById("3").style.visibility = "visible";
//     document.getElementById("x³").style.visibility ="visible";
//     document.getElementById("++").style.visibility = "visible";

//     document.getElementById("4").style.visibility = "visible";
//     document.getElementById("x⁴").style.visibility ="visible";
//     document.getElementById("+++").style.visibility = "visible";

//     document.getElementById("5").style.visibility = "visible";
//     document.getElementById("x⁵").style.visibility = "visible";
//     document.getElementById("++++").style.visibility = "visible";
// }
// }
