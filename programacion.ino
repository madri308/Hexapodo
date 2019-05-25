/*====================================
||    PROGRAMACION PARA HEXAPODO.   ||
||         Esteban Madrigal.        ||
||            5/24/2018             ||
====================================*/

//PINES DIGITALES DONDE ESTAN CONECTADOS LOS SENSORES.
int soundSensor = 3; 
int lightSensor = 4;          
//VARIABLES QUE GUARDAN EL VALOR DE LOS SENSORES.
int soundValue;               
int lightValue;
//VARIABLES ESPECIFICAS QUE EL PROGRAMA USA.
bool on = false;
//VARIABLES PARA MANEJO DEL MOTOR.
int pinVelDer = 6;
int pinDirIzq = 11;
int pinDirDer = 10;
 
void setup (){
  //SE ESTABLECEN QUE VARIABLES TIENEN COMPONENTES DE SALIDA O DE ENTRADA.
  pinMode (soundSensor, INPUT) ;
  pinMode(lightSensor, INPUT);
  pinMode(pinDirIzq, OUTPUT);
  pinMode(pinDirDer, OUTPUT);
}
 
void loop (){
  //RECIBE LOS VALORES DE LAS VARIABLES.
  lightValue = digitalRead(lightSensor);
  soundValue = digitalRead(soundSensor);
  if(lightValue == 0 && on){                  //Si se alumbra el sensor y ademas esta encendido el motor.
    while(lightValue == 0){                   //Se hace un while en el cual
      motorOperator(LOW,HIGH);                //el motor va en reversa
      lightValue = digitalRead(lightSensor);  //y actualiza para saber si el sensor sigue alumbrado.
    }
    motorOperator(HIGH,LOW);                  //Cuando el sensor deja de ser alumbrado el motor va hacia adelante.
  }
  if(soundValue == 1){                        //Si el sensor de sonido es activado.
    if(on){                                   //Si el motor ya estaba activado
      stop();                 //entonces lo apaga
    }else{                                    //sino
      motorOperator(HIGH,LOW);                //entonces lo prende.
    }
  }
}
// Los parametros de esta funcion indican si el motor 
// va hacia adelante, hacia atras o simplemente se detiene:
//                    LOW       HIGH      = REVERSA.
//                    HIGH      LOW       = ADELANTE.
//                    LOW       LOW       = PARA. 
void motorOperator(int dir1,int dir2){
  on = true;
  digitalWrite(pinDirIzq, dir1);
  digitalWrite(pinDirDer, dir2);
  analogWrite(pinVelDer, 1000);
}
void stop(){
  on = false;
  analogWrite(pinVelDer, 0);
}
