 #define LED_ROJO
 #define LED_VERDE
 #define LED_AMARILLO
 #define LED_AZUL
 #define BOTON_ROJO
 #define BOTON_VERDE
 #define BOTON_AMARILLO
 #define BOTON_AZUL

 int nivel = 1;
 int secuencia[10];
 int secuenciaUsuario[10];

 void setup()
 {
  pinMode(BOTON_AMARILLO, INPUT);
  pinMode(BOTON_AZUL, INPUT);
  pinMode(BOTON_ROJO, INPUT);
  pinMode(BOTON_VERDE, INPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_AZUL, LOW);
 }

int iniciar = 1;
 void loop()
 {
  if(nivel == 1)
  {
    generarSecuencia();
  }
  if(iniciar == 1 || nivel != 1)
  {
    mostrarSecuencia();
    leerSecuencia();
  }
 }

 void mostrarSecuencia()
 {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_AZUL, LOW);

  
  for(int i = 0; i < nivel; i++)
  {
    
    switch (secuencia[i])
    {
      case (2):
        digitalWrite(LED_ROJO, HIGH);
        delay(1000);
        digitalWrite(LED_ROJO, LOW);
        break;
      case (3):
        digitalWrite(LED_VERDE, HIGH);
        delay(1000);
        digitalWrite(LED_VERDE, LOW);
        break;
      case (4):
        digitalWrite(LED_AMARILLO, HIGH);
        delay(1000);
        digitalWrite(LED_AMARILLO, LOW);
        break;
      case (5):
        digitalWrite(LED_AZUL, HIGH);
        delay(1000);
        digitalWrite(LED_AZUL, LOW);
        break;
    }
  }
 }

void leerSecuencia()
{
  int flag = 0;
  for(int i = 0; i < nivel; i++)
  {
    flag = 0;
    
    while(flag == 0){
      if(digitalRead(BOTON_AZUL) == LOW)
      {
        digitalWrite(LED_AZUL, HIGH);
        secuenciaUsuario[i] = 5;
        flag = 1;
        delay(200);
        
        if (secuenciaUsuario[i] != secuencia[i]) {
          //secuencia erronea
          return;
        }
        digitalWrite(LED_AZUL, LOW);
      }
      if (digitalRead(BOTON_AMARILLO) == LOW)
      {
        digitalWrite(LED_AMARILLO, HIGH);
        secuenciaUsuario[i] = 4;
        flag = 1;
        if (secuenciaUsuario[i] != secuencia[i]) {
          //secuencia erronea
          return;
        }
        digitalWrite(LED_AMARILLO, LOW);
      }
      if (digitalRead(BOTON_VERDE) == LOW)
      {
        digitalWrite(LED_VERDE, HIGH);
        secuenciaUsuario[i] = 3;
        delay(200);
        if(secuenciaUsuario[i] != secuencia[i])
        {
          //secuencia erronea
          return;
        }
        digitalWrite(LED_VERDE, LOW);
      }
      if (digitalRead(BOTON_ROJO) == LOW) {
        digitalWrite(LED_ROJO, HIGH);
        secuenciaUsuario[i] = 2;
        flag = 1;
        if(secuenciaUsuario[i] != secuencia[i])
        {
          // secuencia erronea
          return;
        }
        digitalWrite(LED_ROJO, LOW);
      }
      
    }
  }
  
}

void generarSecuencia()
{
  randomSeed(millis());

  
  for(int i = 0; i < 10; i++)
  {
    secuencia[i] = random(9,10);
  }
}
