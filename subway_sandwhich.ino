#include <LiquidCrystal_I2C.h>

//pins
const int button_left = 8; // vim reference
const int button_crouch = 9;
const int button_jump = 10;
const int button_right = 11;

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

//chars
const char player_characters[3] = {'+', '>', '='};
const char enemy_characters[4] = {'}', ']', ')', 'X'};

const char enemys_left[] = " " + " " + enemy_characters[random(1,5)] + " " + " " + " " + enemy_characters[random(1,5)] + " " + " " + " " + enemy_characters[random(1,5)] + " " + " " + " " + enemy_characters[random(1,5)] + " " + " " + " " + enemy_characters[random(1,5)];
//ERROR ^
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |
//ERROR |

char character = player_characters[STATE_RUN];

int state = STATE_RUN; // q // STATE_CROUCH, STATE_RUN, STATE_JUMP
int position = POSTION_LEFT; // POSTION_LEFT, POSTION_RIGHT

//points
int score = 0;

//delay
int delay_state = 0;

int enemy_delay = 400;
const int ENEMY_DELAY_DEFAULT = 200;

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(button_left,INPUT_PULLUP);
  pinMode(button_right,INPUT_PULLUP);
  pinMode(button_jump,INPUT_PULLUP);
  pinMode(button_crouch,INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.backlight();
  main_menu();
  // Serial.begin(9600);
}

void loop() {

// String x = "X   X      X ";
// Serial.print(x.substring(4));

  if (!digitalRead(button_jump)) {
    lcd.clear();
    while (true) {
      if (!digitalRead(button_jump)) {
        delay_state = 500;
        character = player_characters[STATE_JUMP];
      } else if (!digitalRead(button_crouch)) {
        delay_state = 500;
        break;
        character = player_characters[STATE_CROUCH];
      } else if (delay_state == 0) {
        character = player_characters[STATE_RUN];
      }

      if (!digitalRead(button_left)) {
        position = POSTION_LEFT;
      } else if (!digitalRead(button_right)) {
        position = POSTION_RIGHT; 
      }

      render();

      delay(50);
      if (delay_state > 0) {
        delay_state -= 50;
      }
    }
    score_screen();
    main_menu();
  }
}


void main_menu() {
  lcd.setCursor(0, 0);
  lcd.print("Subway sandwhich");
  lcd.setCursor(0, 1);
  lcd.print("   Press Jump   ");
}

void score_screen() {
  lcd.setCursor(0, 0);
  lcd.print("Subway sandwhich");
  lcd.setCursor(0, 1);
  lcd.print(score);
}

void render() {

  //enemy render
  if (enemy_delay == 0) {
    //set and death
    lcd.setCursor(0, POSTION_RIGHT);
    lcd.print(" ");
    lcd.setCursor(0, POSTION_LEFT);
    lcd.print(" ");


    enemy_delay = ENEMY_DELAY_DEFAULT;
  } else {
    enemy_delay -= 50;
  }
  // enemy render
  
  

  //player render
  lcd.setCursor(0, position);
  lcd.print(character);
  lcd.setCursor(0, (position + 1) % 2);
  lcd.print(' ');
}







