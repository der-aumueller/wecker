int Abstand;
int ir_sensor=A0;// Sensor an Pin A0
int button=8;// Taster an Pin 8
int buttonstate=0;// Taster in Ruhemodus;
int richtungA           =12;// richtungA an Pin 12
int pwmA                =3;// pwmA an Pin 3
int bremseA             =9;// bremseA an Pin 9
int geschwindigkeit     =250;// Maximalgeschwindigkeit
  
void setup(){
  pinMode(ir_sensor,INPUT);// IR-Sensor als Input
  pinMode(richtungA, OUTPUT);// richtungA als Output
  pinMode(bremseA, OUTPUT);// bremseA als Output
  analogWrite(pwmA, geschwindigkeit);// Geschwindigkeit auf Pin 3 
  digitalWrite(bremseA, HIGH);// Motor stopp
  }

void loop() {
  Abstand=analogRead(ir_sensor);
   delay(10);
  if (Abstand > 100){// Wenn Abstandswert kleiner als 
    digitalWrite(bremseA, HIGH);// Motor stopp
    }
  buttonstate=digitalRead(button);
   if (buttonstate==HIGH){// Wenn Taster betätigt
    digitalWrite(bremseA, LOW);// Bremse aus
    digitalWrite(richtungA, HIGH);// Motor an
   }
   }
