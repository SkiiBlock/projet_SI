int enrPos = 5; int pPos1 = 2; int pPos2 = 3; int pPos3 = 4;  //Déclaration variables pin
int pSommierMoins = 6; int pSommierPlus = 7; int pAnalog = A0;
int pMoteurPlus = 0; int pMoteurMoins = 1;
int ePos1; int ePos2; int ePos3; int ePos4; 
int eSommierMoins; int eSommierPlus; int eAnalog;
int rPos1; int rPos2; int rPos3; int rPos4; int eEnrPos;

void setup() {
  pinMode(enrPos,INPUT); pinMode(pPos1,INPUT); pinMode(pPos2,INPUT); pinMode(pPos3,INPUT); //Déclaration entrée/sortie
  pinMode(pSommierMoins,INPUT); pinMode(pSommierPlus,INPUT); pinMode(pAnalog,INPUT);
  pinMode(pMoteurPlus,OUTPUT); pinMode(pMoteurMoins,OUTPUT);

  //Serial.begin(9600);
}

void loop() {

  eEnrPos = digitalRead(enrPos); ePos1 = digitalRead(pPos1); ePos2 = digitalRead(pPos2); ePos3 = digitalRead(pPos3); 
  eSommierMoins = digitalRead(pSommierMoins); eSommierPlus = digitalRead(pSommierPlus); eAnalog = analogRead(pAnalog);

  if (eSommierPlus == HIGH) {             // Commande manuelle sommier +
    digitalWrite(pMoteurPlus, HIGH);
  }else{
    digitalWrite(pMoteurPlus, LOW);
  }

  if (eSommierMoins == HIGH) {            // Commande manuelle sommier -
    digitalWrite(pMoteurMoins, HIGH);
  }else{
    digitalWrite(pMoteurMoins, LOW);
  }

  if (eEnrPos == HIGH && ePos1 == HIGH) {
    rPos1 = enr();
  }

  if (eEnrPos == HIGH && ePos2 == HIGH) {
    rPos2 = enr();
  }

  if (eEnrPos == HIGH && ePos3 == HIGH) {
    rPos3 = enr();
  }

  if (eEnrPos == LOW && ePos1 == HIGH) {
    pos(rPos1);
  }

  if (eEnrPos == LOW && ePos2 == HIGH) {
    pos(rPos2);
  }

  if (eEnrPos == LOW && ePos3 == HIGH) {
    pos(rPos3);
  }

  //Serial.print("rPos1 = ");
  //Serial.println(rPos1);

}

int enr() {
  int x;
  eAnalog = analogRead(pAnalog);
  
  x = eAnalog;
  //Serial.print("fonction enr = ");
  //Serial.println(x);
  return x; 
}

void pos(int x) {
  if (eAnalog < x) {
    while (eAnalog != x) {
      eAnalog = analogRead(pAnalog);
      digitalWrite(pMoteurPlus, HIGH);
    }
  }

  if (eAnalog > x) {
    while (eAnalog != x) {
      eAnalog = analogRead(pAnalog);
      digitalWrite(pMoteurMoins, HIGH);
    }
  }

  if (eAnalog == x) {
    digitalWrite(pMoteurPlus, LOW);
    digitalWrite(pMoteurMoins, LOW);
  }
}
