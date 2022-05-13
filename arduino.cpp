#include <LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5); 

int h=0; 
int m=0; 
int s=0; 
int flag=h; 
int TIME; 

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 5, 4, 3, 2 }; 
byte colPins[COLS] = { 6, 7, 8, 9 }; 
Keypad pad1 = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 

char key;

void setup() 
{
  lcd.begin(16, 2); 
  lcd.setCursor(3,0);
  lcd.print("ANUSHKA'S");
  lcd.setCursor(0,1);
  lcd.print("ARDUINO CLOCK :)"); 
}


void loop() 
{
  if(!key) key = pad1.getKey();
  
  if(key=='A')  
  {
    s=s+1; 
    if (h<=12){ 
      lcd.setCursor(0,0); 
      lcd.print("TIME "); 
      lcd.print(h); 
      lcd.print(":"); 
      lcd.print(m); 
      lcd.print(":"); 
      lcd.print(s); 
      if(flag<12)lcd.print(" AM"); 
      if(flag>=12)lcd.print(" PM"); 
      if(flag==24)flag=0; 
    }
    else if (h>12){ 
      lcd.setCursor(0,0); 
      lcd.print("TIME "); 
      lcd.print(h-12); 
      lcd.print(":"); 
      lcd.print(m); 
      lcd.print(":"); 
      lcd.print(s); 
      if(flag<12)lcd.print(" AM"); 
      if(flag>=12)lcd.print(" PM"); 
      if(flag==24)flag=0;  
    }

    if(s==60){ 
      s=0; 
      m=m+1; 
    } 
    if(m==60){ 
      m=0; 
      h=h+1; 
      flag=flag+1; 
    } 

    
    delay(1000); 
    lcd.clear();
  }
}