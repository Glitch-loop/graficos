function bresenhamPlotLineLow(x0,y0,x1,y1){
    var dx = x1 - x0;
    var dy = y1 - y0;
    var yi = 1;
  
    var vec = [];

    if(dy < 0){
        yi = -1;
        dy = -dy;
    }

    var D = 2*dy - dx;
    var y = y0;

    for(var x = x0; x < x1; x++){        
        vec.push([x,y]);

        if(D > 0){
            y = y + yi;
            D = D + (2 * (dy - dx));
        } else {
            D = D + 2*dy;         
        }
    }
  
    vec.push([x1,y1]);
    return vec;
}

function bresenhamPlotLineHigh(x0, y0, x1, y1){
    var dx = x1 - x0;
    var dy = y1 - y0;
    var xi = 1;

    var vec = [];

    if(dx < 0){
        xi = -1;
        dx = -dx;
    }

    var D = 2*dx - dy;
    var x = x0;
    
    for(var y = y0; y < y1; y++){
        vec.push([x,y]);
        if(D > 0){
            x = x + xi;
            D = D + (2 * (dx - dy));

        } else {
            D = D + 2*dx;         
        }
    }
    vec.push([x1,y1]);
    return vec;
}

function whichFunctionChoose(px0, py0, px1, py1){
  var lista = [];
  
  if(abs(py1 - py0) < abs(px1 - px0)){
      if(px0 > px1){
          lista = bresenhamPlotLineLow(px1, py1, px0, py0);
      } else {
          lista = bresenhamPlotLineLow(px0, py0, px1, py1);
      }
  } else {
      if(py0 > py1){
          lista = bresenhamPlotLineHigh(px1, py1, px0, py0);
      } else {
          lista = bresenhamPlotLineHigh(px0, py0, px1, py1);
      }
  }      

  return lista;

} 

function setup() {
  createCanvas(400, 400);
}

function imprimirLinea(lista){
  for(var i = 0; i < lista.length; i++){
    noSmooth();
    point(lista[i][0], lista[i][1]);      
  }
}

function draw() {
  background(220);
  
  
  var lista = whichFunctionChoose(1, 2, 100, 20);
  var lista1 = whichFunctionChoose(10, 200, 50, 10);  
  var lista2 = whichFunctionChoose(300, 300, 10, 10);  
  var lista3 = whichFunctionChoose(200, 300, 250, 50);  
  var lista4 = whichFunctionChoose(350, 350, 100, 300);  
  
  imprimirLinea(lista);
  imprimirLinea(lista1);
  imprimirLinea(lista2);
  imprimirLinea(lista3);
  imprimirLinea(lista4);

}