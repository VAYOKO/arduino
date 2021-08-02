// array to store the pin no connected to A, B, C, D, E, F, G and DP
int seven_seg[] = {13,2 , 3, 4, 5, 6, 7, 0};

// array to create binary data map for ten digits (0 to 9)
int num_array[10][7] = {{ 1, 1, 1, 1, 1, 1, 0 },  // 0
                        { 0, 1, 1, 0, 0, 0, 0 },  // 1
                        { 1, 1, 0, 1, 1, 0, 1 },  // 2
                        { 1, 1, 1, 1, 0, 0, 1 },  // 3
                        { 0, 1, 1, 0, 0, 1, 1 },  // 4
                        { 1, 0, 1, 1, 0, 1, 1 },  // 5
                        { 1, 0, 1, 1, 1, 1, 1 },  // 6
                        { 1, 1, 1, 0, 0, 0, 0 },  // 7
                        { 1, 1, 1, 1, 1, 1, 1 },  // 8
                        { 1, 1, 1, 1, 0, 1, 1 }}; // 9

int button1 = 11;
int button2 = 10;
int gled = 9;
int rled = 8;
int seg1 = 0;
int seg2 = 5;
int x = 0;
int y = 0;
void setup() {
  Serial.begin(9600);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(gled,OUTPUT);
pinMode(rled,OUTPUT);
  for (int i = 0; i <= 8; i++) {
    // Defining pin modes
    pinMode(seven_seg[i], OUTPUT);
  }
}

void loop() {
  // print no 7 using the function created below

  if(digitalRead(button1)==HIGH){
    delay(100);
    if(digitalRead(button1)==HIGH){
      x = 1;
      while(x==1){
    seg1+=1;
        printNumber(seg1);
        digitalWrite(gled,1);
        
        delay(100);
        
        digitalWrite(gled,0);
        
        delay(100);
        if(seg1>5){
          break;
          x=0;
          seg1=0;
        }
      }
    }
  
  }



      if(digitalRead(button2)==HIGH){
        delay(100);
        if(digitalRead(button2)==HIGH){
   y = 1;
      while(y==1){
      
         seg2-=1;
        printNumber(seg2);
        Serial.println(seg2);
        digitalWrite(rled,1);
        
        delay(100);
        
        digitalWrite(rled,0);
          delay(100);
        
          if(seg2<2){
          break;
          y=0;
          seg2=0;
        }
        }
      }
      }
      
   seg2=6;
   
   seg1=-1;
      off_seg();
}
// creating a function to print numbers
void printNumber(int number) {
  int pin;
  for (int j = 0; j < 7; j++) {
    pin = seven_seg[j];
    digitalWrite(pin, num_array[number][j]);
  }
}
void off_seg(){
for(int j = 0; j < 7; j++) {
  digitalWrite(seven_seg[j],0);
}
}
