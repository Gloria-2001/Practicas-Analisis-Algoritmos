const mostrar = document.getElementById("mostrar");
let lista1 = document.getElementById("listaValoresPol1");
let lista2 = document.getElementById("listaValoresPol2");

mostrar.addEventListener("click",e=>{
    e.preventDefault();
    Array.from(document.querySelectorAll(".polinomio1")).forEach(elemento=>{
        let li = document.createElement('a');
        lista1.appendChild(li);
        li.innerHTML+=elemento.value;      
    })  

    Array.from(document.querySelectorAll(".polinomio2")).forEach(elemento=>{
        let li = document.createElement('a');
        lista2.appendChild(li);
        li.innerHTML+=elemento.value;      
    })
})