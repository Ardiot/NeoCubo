/*
Libreria NeoCubo 
El array de posicion[3], muestra la cara actual, la fila y la columna respectivamente(la cara si o si, lo demás no se)
La direccion dirección puede ser 1:derecha 2:izquierda 3:arriba 4:abajo


Creada por Carlos Ardiot 2018-2021 Github:@Ardiot  Twitter:@Ardiot328
*/



void inicializar(Adafruit_NeoPixel faces[6],uint_t brillo ){

for (size_t i = 0; i < 6; i++)
{
faces[i].setBrightness(5);
faces[i].begin();
faces[i].show();
}

}

void moverPunto(int posicion[3] ,int  direccion ){
  Serial.print("ahora y ya estoy en mover el punto ");
  int direccionaux = 0 ;
  switch (direccion)//No se muy bien que hace, vale si, muevve la posicion de punto arriba,abajo,izq o dere (PARA QUE TENEMOS DIRECCIONAUX???)
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
    
  } 
  
  if( (posicion[1]<N && posicion[1]>= 0 ) &&  (posicion[2]<N && posicion[2]>= 0 ) ) // si NO nos  hemos salido de la cara  actualizamos 
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
     
    actualizarTodo(posicion);//Esto estaba descomentado porque es redundante con el que esta dentro del case de switch pero no se 
    
  }//fin del if 


  else // si no hay que ver por donde nos hemos salido. Son todos del tipo: Si estamos en la cara X y se nos ha salido por Y entonces (con Y siendo arriba,abajo,izq,dere)
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
                    if( cara5[posicion[2]][posicion[1]] != 1 ) // si nos podemos mover 
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

int devuelveDireccionSalida(int posicion[3]){ //Esta funcion solo la llamamos desde dentro de moverPunto, deberia ser privada
  
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

void actualizarTodo(int posicion[3] )//Si lo de caras funciona entonce se puede reducir la funcion. Si todos los for son iguales, solo cambia el m1 m2 ... m6 meterlo en una funcion y enviarle el objeto 
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
//fin de todo