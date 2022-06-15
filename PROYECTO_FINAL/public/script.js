var miMenu = document.getElementById("miMenu");
var boton = document.getElementById("boton"); 

boton.onclick=function(){
    if(miMenu.className==="menu"){
        miMenu.className += " responsivo";
    }else{
        miMenu.className = "menu";
    }
}