//multi switching anode and cathode control edited by varis

#define led1 9
#define led2 8
#define led3 7
#define led4 6
#define led5 5
int mode = 0;
int ry = 10;
void setup() {
  pinMode(ry , OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}
void loop() {

  //cathode
  if (mode == 0) {
    for (int po = 5; po <= 9; po++) {
      digitalWrite(po, HIGH);
      delay(100);
    }
    for (int po = 5; po <= 9; po++) {
      digitalWrite(po, LOW);
      delay(100);
      mode = 1;
    }
  }
  if (mode == 1) {

    for (int po = 5; po <= 9; po++) {
      digitalWrite(po, HIGH);
      delay(100);
      digitalWrite(po, LOW);
      delay(100);
      if (po == 9) {
        mode = 2;
      }
    }
  }

  if (mode == 2) {
    for (int po = 9; po >= 5; po--) {
      digitalWrite(po, HIGH);
      delay(100);
    }
    for (int po = 9; po >= 5; po--) {
      digitalWrite(po, LOW);
      delay(100);
      mode = 3;
    }
  }
  if (mode == 3) {

    for (int po = 9; po >= 5; po--) {
      digitalWrite(po, HIGH);
      delay(100);
      digitalWrite(po, LOW);
      delay(100);
      if (po == 5) {
        mode = 4;
      }
    }


  }




  if (mode == 4) {
    digitalWrite(ry, HIGH);
    for (int po = 5; po <= 9; po++) {
      digitalWrite(po, !HIGH);
      delay(100);
    }
    for (int po = 5; po <= 9; po++) {
      digitalWrite(po, !LOW);
      delay(100);
      mode = 5;
    }
  }
  if (mode == 5) {

    for (int po = 5; po <= 9; po++) {
      digitalWrite(po, !HIGH);
      delay(100);
      digitalWrite(po, !LOW);
      delay(100);
      if (po == 9) {
        mode = 6;
      }
    }
  }

  if (mode == 6) {
    for (int po = 9; po >= 5; po--) {
      digitalWrite(po, !HIGH);
      delay(100);
    }
    for (int po = 9; po >= 5; po--) {
      digitalWrite(po, !LOW);
      delay(100);
      mode = 7;
    }
  }
  if (mode == 7) {

    for (int po = 9; po >= 5; po--) {
      digitalWrite(po, !HIGH);
      delay(100);
      digitalWrite(po, !LOW);
      delay(100);
      if (po == 5) {
        mode = 0;
        digitalWrite(ry, LOW);
      }
    }


  }
}
