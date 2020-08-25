function sells(x){
    calculator.display.value=""+Math.sqrt(x);  
}
function backspace(k){
    var value = k;
    calculator.display.value= value.substr(0, value.length - 1);
}