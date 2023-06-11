#define FETPIN 34
#define FREQUENCY 117000
hw_timer_t * timerX = NULL;
volatile bool squareState = false;

void IRAM_ATTR tim_callback() {
  squareState = !squareState;
}

void 
setup() {
  timerX = timerBegin(0, 80, true);
  timerAttachInterrupt(timerX, &tim_callback, true);
  timerAlarmWrite(timerX, 1000000 / FREQUENCY/2, true);
  timerAlarmEnable(timerX);
}

void 
loop() {
  if (squareState) { digitalWrite(FETPIN, HIGH); } 
  else             { digitalWrite(FETPIN, LOW);  }         
}