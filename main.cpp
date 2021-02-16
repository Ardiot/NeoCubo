#include <Adafruit_NeoPixel.h>

 // poniendo comentarios skere
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
int N = 8 ; 
int posicion[3]={1,6,4};
int dire ;
int devuelta =0;
  
 void setup(){
Serial.begin(9600);
   m1.setBrightness(5);
    m1.begin();
    m1.show();
    m2.setBrightness(5);
    m2.begin();
    m2.show();
    m3.setBrightness(5);
    m3.begin();
    m3.show();
    m4.setBrightness(5);
    m4.begin();
    m4.show();
    m5.setBrightness(5);
    m5.begin();
    m5.show();
    m6.setBrightness(5);
    m6.begin();
    m6.show();
    
    actualizarTodo(posicion);
   
   

    
   }
   
   
void loop()
{
  
  delay(1000);
  dire =  random(1,5);
  
  Serial.print( "lo movemos en la direccion : " );
  Serial.println(dire);
  Serial.print("despues va el moverPunto \n ");
  moverPunto(posicion,dire);
  
  

    
   }
   
void moverPunto(int posicion[3] ,int  direccion ){
  Serial.print("ahora y ya estoy en mover el punto ");
  int direccionaux = 0 ;
  switch (direccion)
  {
    case 1 : posicion[2]++; //derecha
             direccionaux=1;
          break;
          
    case 2 : posicion[2]--; //izquierda
              direccionaux=2;
          break;
    
    case 3 : posicion[1]++; //arriba
             direccionaux=3;
          break;
          
    case 4 : posicion[1]--; //abajo
             direccionaux=4;
          break;
    
  } // (posicion[1]<N && posicion[1]>= 0 ) &&  (posicion[2]<N && posicion[2]>= 0 )
  
  if( (posicion[1]<N && posicion[1]>= 0 ) &&  (posicion[2]<N && posicion[2]>= 0 ) ) // si NO nos  hemos salido de la cara pues actualizamos 
  {
      switch( posicion[0] )
      {
        case 1 : 
        {
          if( cara1[posicion[1]][posicion[2]] == 1 ) //si esta con un uno , es decir , hay pared 
            {
              switch(direccionaux)
              {
                case 1 : posicion[2]--;
                  break;

                case 2 : posicion[2]++;
                  break;

                case 3 : posicion[1]--;
                  break;

                case 4 : posicion[1]++;
                  break;
                  
              }
              
            }
            else 
            actualizarTodo(posicion);
          
          break ;
        }

        case 2 : 
        {
          if( cara2[posicion[1]][posicion[2]] == 1 ) //si esta con un uno , es decir , hay pared 
            {
              switch(direccionaux)
              {
                case 1 : posicion[2]--;
                  break;

                case 2 : posicion[2]++;
                  break;

                case 3 : posicion[1]--;
                  break;

                case 4 : posicion[1]++;
                  break;
                  
              }
              
            }
            else 
            actualizarTodo(posicion);
          
          break ;
        }

        case 3 : 
        {
          if( cara3[posicion[1]][posicion[2]] == 1 ) //si esta con un uno , es decir , hay pared 
            {
              switch(direccionaux)
              {
                case 1 : posicion[2]--;
                  break;

                case 2 : posicion[2]++;
                  break;

                case 3 : posicion[1]--;
                  break;

                case 4 : posicion[1]++;
                  break;
                  
              }
              
            }
            else 
            actualizarTodo(posicion);
          
          break ;
        }

        case 4 : 
        {
          if( cara4[posicion[1]][posicion[2]] == 1 ) //si esta con un uno , es decir , hay pared 
            {
              switch(direccionaux)
              {
                case 1 : posicion[2]--;
                  break;

                case 2 : posicion[2]++;
                  break;

                case 3 : posicion[1]--;
                  break;

                case 4 : posicion[1]++;
                  break;
                  
              }
              
            }
            else 
            actualizarTodo(posicion);
          
          break ;
        }

        case 5 : 
        {
          if( cara5[posicion[1]][posicion[2]] == 1 ) //si esta con un uno , es decir , hay pared 
            {
              switch(direccionaux)
              {
                case 1 : posicion[2]--;
                  break;

                case 2 : posicion[2]++;
                  break;

                case 3 : posicion[1]--;
                  break;

                case 4 : posicion[1]++;
                  break;
                  
              }
              
            }
            else 
            actualizarTodo(posicion);
          
          break ;
        }

        case 6 : 
        {
          if( cara6[posicion[1]][posicion[2]] == 1 ) //si esta con un uno , es decir , hay pared 
            {
              switch(direccionaux)
              {
                case 1 : posicion[2]--;
                  break;

                case 2 : posicion[2]++;
                  break;

                case 3 : posicion[1]--;
                  break;

                case 4 : posicion[1]++;
                  break;
                  
              }
              
            }
            else 
            actualizarTodo(posicion);
          
          break ;
        }


        
      }//fin del switch posicion 0 
//todo dentro del de si no nos hemos salido 



      
    //actualixamos las matrices y nuesto punto tambien si no esta el punto acupado ws decir , que no haya una pared  
    Serial.print("no nos hemos salido asi que solamente actualizamos ");
    //actualizarTodo(posicion);
    
  }//fin del if 
  else // si no hay que ver por donde nos hemos salido 
  {
    devuelta=devuelveDireccionSalida(posicion) ;
    int cero = posicion[0] ;
    Serial.println(" POR FIN ENTRO AL ELSE " );
    Serial.println(cero);

    
    switch ( cero )  //mirarr  LOS CORCHETES 
      {
        
        Serial.print(" \n\n\n nos hemos metido en el switch de moverPunto ");
        case 1 : //creo que ya bien
        {
          
              Serial.print(" \n case 1 ");
              Serial.print(posicion[0]);
                Serial.print(posicion[1]);
              Serial.println(posicion[2]);

  
            switch (devuelta)
              {
                case 3 : //arriba
                  {
                    if( cara5[posicion[2] ][posicion[1]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=5 ;
                      int aux = posicion[1];
                      
                      posicion[1]=posicion[2] ;
                      posicion[2]=aux ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);


                     break ;
                  }
                  
                case 1 : //derecha
                  {
                  if( cara2[posicion[1]][0] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=2 ;
                      //posicion[1] la mantenemos , las filas  
                      posicion[2]=0 ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                  
                    break;
                  }
                
                case 4 ://abajo
                  {
                    if( cara6[ N - posicion[2] -1 ][0] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=6 ;
                      posicion[1]=N - posicion[2] -1 ;   
                      posicion[2]=0 ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);

                  
                      break;

                  }
                
                case 2 ://izquierda 
                  {
                    if( cara4[posicion[1]][N-1] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=4 ;
                      //posicion[1] se mantiene   
                      posicion[2]=N-1 ; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                    

                    break;
                  }
                          
              }
        break;
        }
              
        case 2 : //creo que ya bien 
        {
          Serial.print(" \n case 2 ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
            switch (devuelta )
              {
                case 3 : //arriba
                  {
                    if( cara5[posicion[N-1] ][posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=5 ;
                      posicion[1]=N-1;
                      //posicion[2] se mantiene
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);

                     break;
                  }
                
                case 1 : //derecha
                  {
                  if( cara3[posicion[1]][0] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=3; //cara 3 
                      //posicion[1] la mantenemos , las filas  
                      posicion[2]=0 ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                  

                    break;
                  }
                
                case 4 ://abajo
                  {
                    if( cara6[0][posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=6 ;
                      posicion[1]=0 ;   
                    //  posicion[2] se mantiene  ;
                      actualizarTodo(posicion);
                    }
                    else
                     // actualizarTodo(posicion);
                  

                break;
                  }
                
                case 2 ://izquierda 
                  {
                    if( cara1[posicion[1]][N-1] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=1 ;
                      //posicion[1] se mantiene   
                      posicion[2]=N-1 ; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                    

                    break;
                  }
                          
              }
        
        break;
        }
        
        case 3 : //creo que ya bien 
        {
          Serial.print(" \n case 3 ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
            switch (devuelta)
              {
                case 3 : //arriba bien 
                  {
                    if( cara5[N-1- posicion[2] ] [ N-1] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=5 ;
                      posicion[1]=N-1 -posicion[2];
                      posicion[2] = N-1; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);


                     break;
                  }
                
                case 1 : //derecha bien 
                  {
                  if( cara4[posicion[1]][0] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=4; //cara 3 
                      //posicion[1] la mantenemos , las filas  
                      posicion[2]=0 ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                  

                    break;
                  }
                
                case 4 ://abajo nien 
                  { 
                    if( cara6[posicion[2]][0] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=6 ;
                      posicion[1]=posicion[2] ;   
                      posicion[2] = 0 ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                  

                break;
                  }
                
                case 2 ://izquierda 
                  {
                    if( cara2[posicion[1]][N-1] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=2 ;
                      //posicion[1] se mantiene   
                      posicion[2]=N-1 ; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                    


                    break;
                  }
                          
              }
        break;
        }
        
        case 4 : // creo que ya bien 
        {
          Serial.print(" \n case 4 ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
          switch (devuelta)
              {
                case 3 : //arriba  bien ya 
                  {
                    if( cara5[0 ] [ N-1-posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=5 ;
                      posicion[1]=0;
                      posicion[2] = N-1 - posicion[2]; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);


                     break;
                  }
                
                case 1 : //derecha   bien ya 
                  {
                  if( cara1[posicion[1]][0] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=1; //cara 1 
                      //posicion[1] la mantenemos , las filas  
                      posicion[2]=0 ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);

                  
                  break;  
                  }
                
                case 4 ://abajo  bien yaa
                  { 
                    if( cara6[N-1][N-1 - posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=6 ;
                      posicion[1]=N-1 ;   
                      posicion[2] = N-1-posicion[2] ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                  

                break;
                  }
                
                case 2 ://izquierda  ya 
                  {
                    if( cara3[posicion[1]][N-1] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=3 ;
                      //posicion[1] se mantiene   
                      posicion[2]=N-1 ; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                    

                    break;
                  }
                          
              }
        
          
          break;
        }
        
        case 5 : 
        {
          Serial.print(" \n case 5 ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
          switch (devuelta)
              {
                case 3 : //arriba    creo que ya bien 
                  {
                    if( cara4[0 ] [ N-1-posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=4 ;
                      posicion[1]=0;
                      posicion[2] = N-1-posicion[2]; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);

                     break;
                  }
                
                case 1 : //derecha   ya bien 
                  {
                  if( cara3[ 0][N-1-posicion[1] ] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=3; //cara 1 
                      posicion[1]=0;   
                      posicion[2]=N-1- posicion[1] ;
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                  
                    break ;
                  }
                
                case 4 ://abajo  ya bien 
                  { 
                    if( cara2[0][posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=2;
                      posicion[1]=0 ;   
                      //posicion[2] las mantenemos ;
                      actualizarTodo(posicion);
                    }
                    else
                     // actualizarTodo(posicion);
                  

                break;
                  }
                
                case 2 ://izquierda ya bien  
                  {
                    if( cara1[0][ posicion[1]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=1 ;
                      posicion[2]=posicion[1]; 
                      
                      posicion[1] = 0 ;   
                      
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                    

                    break;
                  }
                          
              }
        
        
        break;
        }
        
        case 6 : 
        {
          Serial.print(" \n case 6 ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
            switch (devuelta)
              {
                case 3 : //arriba    creo que ya bien 
                  {
                    if( cara2[N-1] [posicion[2] ] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=2 ;
                      posicion[1]=N-1;
                    //  posicion[2] = se mantiene ; 
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);


                     break;
                  }
                
                case 1 : //derecha    ya bien
                  {
                  if( cara3[ N-1][ posicion[1] ] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=3; //cara 1 
                      posicion[2]= posicion[1] ;
                      posicion[1]=N-1;   
                      
                      actualizarTodo(posicion);
                    }
                    else
                     // actualizarTodo(posicion);
                  

                    break;
                  }
                
                case 4 ://abajo  ya bien 
                  { 
                    if( cara4[N-1][N-1-posicion[2]] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=4;
                      posicion[1]=N-1 ;   
                      posicion[2] =N-1-posicion[2];
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);

                  
                break;
                  }
                
                case 2 ://izquierda  ya bien 
                  {
                    if( cara1[ N-1][N-1 - posicion[1] ] != 1 ) // si nos podemos mover 
                    {
                      posicion[0]=1 ;
                      posicion[2]= N-1 - posicion[1]; 
                      
                      posicion[1] = N-1;   
                      
                      actualizarTodo(posicion);
                    }
                    else
                      //actualizarTodo(posicion);
                    

                    break;
                  }
                          
              }
        
          
          break;
        }
        
        
        
      }

    Serial.print(" \n fin del else  ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
    
    
    
    
  }
  
  
}

int devuelveDireccionSalida(int posicion[3]){
  
  if( posicion[2]<0 || posicion[2]>= N)   //si las filas estan mal , o menos 1 o 8 
  {
    if(posicion[2] <0 ) // si se nos ha salido por la izquierda 
    {
       posicion[2]++;
       return 2; 
      
    }
    else 
      {
      posicion[2]--;
       return 1;  // derecha 
        
      }
    
    
  }
  else
  { //mirar esto bien 
    if(posicion[1] <0 ) // si se nos ha salido por la abajo  
    {
       posicion[1]++;
       return 3; //arriba
      
    }
    else 
      {
      posicion[1]--;
       return 4; //abajo 
        
      }
    
    
  }
  Serial.print("\ndevuelve direccion salida  ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);
  
}
//
void actualizarTodobien(int posicion[3],Neopixel m1 )
{
for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 1) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m1.setPixelColor(aux, m1.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara1[i][j] ==0)
                                            //pintar de blanco ese led
                                            m1.setPixelColor(aux, m1.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m1.setPixelColor(aux, m1.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 1) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m1.setPixelColor(aux, m1.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara1[i][j] ==0)
                                            //pintar de blanco ese led
                                            m1.setPixelColor(aux, m1.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m1.setPixelColor(aux, m1.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } // primer for 
    m1.show();
    //TENEMOS EL SUPERPROBLEMON DE CARA1 CARA2 CARA3 ...
}

void actualizarTodo(int posicion[3] )//comentario del carlos de 2021. Si todos los for son iguales, solo cambia el m1 m2 ... m6 meterlo en una funcion y enviarle el objeto 
{
  Serial.print("\nactualizar todo ");
  Serial.print(posicion[0]);
    Serial.print(posicion[1]);
  Serial.println(posicion[2]);

  
  
  for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 1) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m1.setPixelColor(aux, m1.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara1[i][j] ==0)
                                            //pintar de blanco ese led
                                            m1.setPixelColor(aux, m1.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m1.setPixelColor(aux, m1.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 1) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m1.setPixelColor(aux, m1.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara1[i][j] ==0)
                                            //pintar de blanco ese led
                                            m1.setPixelColor(aux, m1.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m1.setPixelColor(aux, m1.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } // primer for 
    m1.show();
    
    for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 2) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m2.setPixelColor(aux, m2.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara2[i][j] ==0)
                                            //pintar de blanco ese led
                                            m2.setPixelColor(aux, m2.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m2.setPixelColor(aux, m2.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 2) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m2.setPixelColor(aux, m2.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara2[i][j] ==0)
                                            //pintar de blanco ese led
                                            m2.setPixelColor(aux, m2.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m2.setPixelColor(aux, m2.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } //segundo for 
    m2.show();
    
    
    for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 3) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m3.setPixelColor(aux, m3.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara3[i][j] ==0)
                                            //pintar de blanco ese led
                                            m3.setPixelColor(aux, m3.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m3.setPixelColor(aux, m3.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 3) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m3.setPixelColor(aux, m3.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara3[i][j] ==0)
                                            //pintar de blanco ese led
                                            m3.setPixelColor(aux, m3.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m3.setPixelColor(aux, m3.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } //tercer for 
    m3.show();
    
    
    for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 4) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m4.setPixelColor(aux, m4.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara4[i][j] ==0)
                                            //pintar de blanco ese led
                                            m4.setPixelColor(aux, m4.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m4.setPixelColor(aux, m4.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 4) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m4.setPixelColor(aux, m4.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara4[i][j] ==0)
                                            //pintar de blanco ese led
                                            m4.setPixelColor(aux, m4.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m4.setPixelColor(aux, m4.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } //cuarto for 
    m4.show();
    
    
    for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 5) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m5.setPixelColor(aux, m5.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara5[i][j] ==0)
                                            //pintar de blanco ese led
                                            m5.setPixelColor(aux, m5.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m5.setPixelColor(aux, m5.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 5) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m5.setPixelColor(aux, m5.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara5[i][j] ==0)
                                            //pintar de blanco ese led
                                            m5.setPixelColor(aux, m5.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m5.setPixelColor(aux, m5.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } //quinto for 
    m5.show();
    
    
    for (int i =0, aux =0 ; i< 8 ; i++ ) 
    {
      //delay(500);
      if(i%2 ==0 ) //si esta en fila par , cero es par 
      {
        
          for(int j =7 ; j>=0 ; j-- ,aux++ )
          {
              if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 6) //if( aux == (pos[1]*8 + pos[2] ))
                                          {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m6.setPixelColor(aux, m6.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                                          }
                                            
                                        else 
                                          {
                                            
                                          if(cara6[i][j] ==0)
                                            //pintar de blanco ese led
                                            m6.setPixelColor(aux, m6.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m6.setPixelColor(aux, m6.Color(150, 50, 150));
                                          }
            
          }
      }
      else 
      {
        
        for(int j =0 ; j<8 ;j++ ,aux++ )
        {
          if( (aux == (posicion[1]*8 + posicion[2] ))  && posicion[0]== 6) //if( aux == (pos[1]*8 + pos[2] ))
                      {
                                            //poner ese punto en rojo , es nuestro jugador 
                                            m6.setPixelColor(aux, m6.Color(150, 0, 0));
                                        Serial.println("el punto aux , encontrado  ");
                        }
                                            
               else 
                                          {
                                            
                                          if(cara6[i][j] ==0)
                                            //pintar de blanco ese led
                                            m6.setPixelColor(aux, m6.Color(0, 0, 0));
                                          else
                                            //pintar de negro ,  es una pared , un 1
                                            m6.setPixelColor(aux, m6.Color(150, 50, 150));
                                          }
          
        }
        
      }
    
      
    } //quinto for 
    m6.show();
    //este es el que ahora mejor funciona , cada cara por separado en un for 
    
    
  
}