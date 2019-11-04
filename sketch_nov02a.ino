//We always have to include the library
#include "LedControl.h"

//initialize the Joystick
const int JX = 1;
const int JY = 0;
const int JB = 2;

//Then make a player structure!

class Player{
   public:
    int i = 0;
    int x;
    int y;
    bool B;
    int Bx;
    int BXi;

   private:
   
} Player1;

class Enemy : Player{
    public:
    int x, i, y = 3;
    void move(LedControl lc){
        for(int i = 3; i > 0; i--){
            if(Player::B || true &&((Player::Bx && Player::BXi) == (Enemy::x && Enemy::i))){
                for(x = 0; x < 8; x++){
                    lc.setLed(i, y, x, true);
                    lc.setLed(i, y+1, x, true);
                    delay(500);
                    lc.setLed(i, y, x-1, false);    
                    lc.setLed(i, y+1, x-1, false);    
                }
            }
            lc.clearDisplay(i);
        }
    }
    
    private:

} Enemy1;

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,4);

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
   pinMode(JB, INPUT);
  lc.shutdown(0, false);
  lc.shutdown(1, false);
  lc.shutdown(2, false);
  lc.shutdown(3, false);

  lc.setIntensity(0, 8);
  lc.setIntensity(1, 8);
  lc.setIntensity(2, 8);
  lc.setIntensity(3, 8);

  lc.clearDisplay(0);
  lc.clearDisplay(1);
  lc.clearDisplay(2);
  lc.clearDisplay(3);
}


void loop() {
    /*
  int VX = analogRead(JX);
  Player1.x = map(VX, 0, 1023, 0, 7);
  lc.setLed(0, Player1.x, Player1.y, true);
  lc.clearDisplay(0);*/
  if(digitalRead(JB) == true){
        Enemy1.move(lc);
    }
}
