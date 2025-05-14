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
const int button_left;
const int button_right;
const int button_jump;
const int button_crouch;

//chars
const char player_character[3] = {'+', '>', '='};
const char enemy_character[4] = {'}', ']', ')', 'X'};

int state = STATE_RUN; // q // STATE_CROUCH, STATE_RUN, STATE_JUMP
int position = POSTION_LEFT; // POSTION_LEFT, POSTION_RIGHT

//points
int score = 0;

class Enemy {
  
}

void setup() {
  pinMode(button_left,INPUT);
  pinMode(button_right,INPUT);
  pinMode(button_jump,INPUT);
  pinMode(button_crouch,INPUT);
}

void loop() {

}