#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <stdio.h>
#include <stdio.h>
 #include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "NeoCubo.h"

#define PIN1   D3 //antes era de 6 a 11
#define PIN2    D4
#define PIN3    D5
#define PIN4    D6
#define PIN5    D7
#define PIN6    D8
// Pin donde tenemos conectado la tira NeoPixel
#define NUMPIXELS 64 // Número de píxeles o LEDs
 
// Declaramos el objeto. El último parámetro dependerá de tu tipo de NeoPixel
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel m1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel m2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel m3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel m4 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel m5 = Adafruit_NeoPixel(NUMPIXELS, PIN5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel m6 = Adafruit_NeoPixel(NUMPIXELS, PIN6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel neofaces[6]={m1,m3,m3,m4,m5,m6};
 
    
int cara1 [8][8]={  {1,1,1,1,1,1,1,1},
          {0,0,0,0,0,0,1,0},
          {0,0,1,1,1,1,0,0},
          {0,0,1,0,0,1,0,0},
          {0,0,1,0,0,1,0,0},
          {0,0,1,1,1,1,0,0},
          {0,1,0,0,0,0,0,0},
          {1,0,0,0,0,0,0,0} };
          
int cara2 [8][8]={  {1,1,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1},
          {0,0,1,1,0,1,0,0},
          {0,0,1,0,0,1,0,0},
          {0,0,1,1,0,1,0,0},
          {0,0,1,0,0,1,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0} };
          
int cara3 [8][8]={  {1,1,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1},
          {0,0,1,0,0,1,0,0},
          {0,0,1,1,0,1,0,0},
          {0,0,1,0,0,1,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0} };
   
int cara4 [8][8]={  {0,1,1,1,1,1,1,1},
          {0,0,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1},
          {0,0,1,1,0,1,0,0},
          {0,0,1,0,0,1,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0} };
           
int cara5 [8][8]={  {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1},
          {0,1,1,1,1,0,0,0} };
           
int cara6 [8][8]={  {0,0,0,0,0,0,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,1,1,0,1,0,0},
          {0,0,0,0,0,0,0,0},
          {0,0,1,1,0,1,0,0},
          {0,0,0,0,0,0,0,0},
          {1,1,1,1,1,1,1,1},
          {1,1,1,1,1,1,1,1} };   

int caras[6][8][8]={cara1,cara2,cara3,cara4,cara5,cara6};
int N = 8; 
int posicion[3]={1,6,4};
int dire;
int devuelta=0;
int brillo=30;

 void setup(){
Serial.begin(9600);
  inicializar(neofaces,brillo);
  actualizarTodo(posicion);
   
}
   
   
void loop()
{//tenemos alguna funcion para poner algun punto en un sitio dado directamente???
//si hacemos una de esas alomejor solo con esa que pone el punto y despues con logica de programacion ya todo aunqeu alomejor lo que estamos haciendo es lo mismo
// es decir solo actuamos sobre las matrices y las vamos pintando, rollo se puede pintar el nuevo punto en la nueva posicion? si pues lo ponemos en la matriz y actualizamos todo ,
//que no se puede pues no hacemos nada y ya, aun asi seguimos necesitando la chuleta de saltos de cara que tenemos en el folio pero solo eso ( yo creo que sería igual en el fondo...)
  
  delay(2000);
  //dire =  random(1,5);
  dire =  1;
  
  //probar esto en vez de poniendolo random poniendolo como entrada por el monitor serial 
  Serial.print( "lo movemos en la direccion : " );
  Serial.println(dire);
  Serial.print("despues va el moverPunto \n ");
  moverPunto(posicion,dire);
  
  

    
   }
   
