#include <LiquidCrystal_I2C.h>
//states
const int STATE_CROUCH = 0;
const int STATE_RUN = 1;
const int STATE_JUMP = 2;

//enemies
const int ENEMY_CROUCH_FENCE = 0;
const int ENEMY_JUMP = 1;
const int ENEMY_BOTH_FENCE = 2;
const int ENEMY_NEITHER_FENCE = 3;

//postion
const int POSTION_LEFT = 0;
const int POSTION_RIGHT = 1;

//pins
const int button_left = 1;
const int button_right = 2;
const int button_jump = 3;
const int button_crouch = 4;

//chars
const char player_character[3] = {'+', '>', '='};
const char enemy_character[4] = {'}', ']', ')', 'X'};

int state = STATE_RUN; // q // STATE_CROUCH, STATE_RUN, STATE_JUMP
int position = POSTION_LEFT; // POSTION_LEFT, POSTION_RIGHT

//points
int score = 0;


LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(button_left,INPUT);
  pinMode(button_right,INPUT);
  pinMode(button_jump,INPUT);
  pinMode(button_crouch,INPUT);

  lcd.begin(16, 2);
  lcd.backlight();
  
}

void loop() {
  main_menu()
  if (digitalRead(buttton_jump)) {
    while (true) {
      // pass
    }
  }
}


void main_menu() {
  lcd.setCursor(0, 0);
  lcd.print("Subway sandwhich");
  lcd.setCursor(0, 1);
  lcd.print("   Press Jump   ")
}