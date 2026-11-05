const int RESET_BUTTON_PIN = 2;
const int TRIGGER_BUTTON_PIN = 3;
const int NOT_Q_PIN = 4;
const int Q_PIN = 5;
const int ERROR_LED_PIN = 7;

const int SERIAL_BAUD_RATE = 9600;
const int LOOP_DELAY_MS = 50;

void setup() {
  pinMode(RESET_BUTTON_PIN, INPUT);
  pinMode(Q_PIN, INPUT);
  pinMode(NOT_Q_PIN, INPUT);

  pinMode(TRIGGER_BUTTON_PIN, OUTPUT);
  digitalWrite(TRIGGER_BUTTON_PIN, LOW);

  pinMode(ERROR_LED_PIN, OUTPUT);
  digitalWrite(ERROR_LED_PIN, LOW);

  Serial.begin(SERIAL_BAUD_RATE);
}

void processResetButton() {
  int resetState = digitalRead(RESET_BUTTON_PIN);
  digitalWrite(TRIGGER_BUTTON_PIN, resetState);
}

void processTriggerState() {
  int qState = digitalRead(Q_PIN);
  int notQState = digitalRead(NOT_Q_PIN);

  bool isError = (qState == LOW && notQState == LOW);
  digitalWrite(ERROR_LED_PIN, isError);

  Serial.print("Q:");
  Serial.print(qState);
  Serial.print(" notQ:");
  Serial.print(notQState);
  Serial.print(" Error:");
  Serial.println(isError);
}

void loop() {
  processResetButton();
  processTriggerState();
  delay(LOOP_DELAY_MS);
}