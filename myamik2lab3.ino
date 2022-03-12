/*
 * Madhava Sai Yamike - 675652145
 * Lab 3 - Scrolling output
 * We need to display our name on the first line and our favorite quote on the second line, these both are need appear on the 16x2 display. Our code should work in a way that our name should not scroll and our quote needs to be scroll.  
 * I assumed that we need to use the loops to scroll the quote on the LCD Screen. 
 * References: https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
 * In person demonstration to TA - Huma (2/21) 4:00 p.m lab
*/
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  // To set the pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String quote = "In God we believe";  // Statement to print the quote.
void setup() {  //To set up the LCD's number of columns and rows.
  lcd.begin(16, 2);
}
// This loop displays the name and Intilized cursor
void loop()
{
  int i = 15;
  while(i >= 0){
    lcd.setCursor(0,0);
    lcd.print("Madhava Sai.Y");  // To display the name in LCD
    lcd.setCursor(i,1);
    lcd.print(quote);  // To print he quote.
    delay(300);
    lcd.clear();
    i--;
  }
  i = 1;
  while(i < quote.length()){  // loop for quote to display character up to 16 
    lcd.setCursor(0,0);
    lcd.print("Madhava Sai.Y");
    String quote1 = &quote[i];
    lcd.setCursor(0,1);
    lcd.print(quote1);
    delay(300);
    lcd.clear();
    i++;
  }
}
