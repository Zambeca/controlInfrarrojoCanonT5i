int pinLedIr=10;
int pinBoton=12;
int pinLedEstado=13;

int intervalo=30; //Cada cuantos SEGUNDOS deseas sacar una foto.
bool encendido=false;

void enviaInfrarrojo() {
  for(int i=0; i<16; i++) { 
    digitalWrite(pinLedIr, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinLedIr, LOW);
    delayMicroseconds(10);
   } 
   delayMicroseconds(7160); 
   for(int i=0; i<16; i++) { 
     digitalWrite(pinLedIr, HIGH);
     delayMicroseconds(10);
     digitalWrite(pinLedIr, LOW);
     delayMicroseconds(10);
   }   
}

void setup() {
  Serial.begin(9600);
  pinMode(pinLedIr, OUTPUT);
  pinMode(pinLedEstado, OUTPUT);
  pinMode(pinBoton, INPUT);
}


unsigned long tiempoActual=0;
unsigned long tiempoPasado=0;

void loop() { 

  tiempoActual=millis();

  if (digitalRead(pinBoton) == HIGH) {
    encendido=!encendido;
    if(encendido){
      Serial.println("Prendido");
    }else {
      Serial.println("Apagado");
    }
    delay(500);
  }
  
  if(encendido) {
    digitalWrite(pinLedEstado,HIGH);
  }else {
    digitalWrite(pinLedEstado,LOW);
  }
    

  if(encendido && ((tiempoActual-tiempoPasado)>(unsigned int)(intervalo*1000))){
    enviaInfrarrojo();
    tiempoPasado=tiempoActual;
  }
}

