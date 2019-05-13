#define led 4
#define boton 5


int estadoBoton;
int estadoLed;
void setup()
 
{
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  //digitalWrite (led, LOW);
}

void loop()
{
  estadoBoton = digitalRead(boton);
  delay(100);
  
  if(estadoBoton == LOW)
  {
	estadoLed= 1- estadoLed;
    digitalWrite(led, estadoLed);
    delay(100);
   } 
  if(estadoLed == 1)
  {digitalWrite(led, HIGH);
  }
 
  
  /*digitalWrite(led, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(led, LOW);
  delay(1000); // Wait for 1000 millisecond(s)*/
}