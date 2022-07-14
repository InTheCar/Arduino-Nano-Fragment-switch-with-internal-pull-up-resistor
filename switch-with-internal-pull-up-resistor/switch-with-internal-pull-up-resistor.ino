

// bridge or switch between this digital pin and GND. If the bridge is detected the serial (UART) will be initialized
int Switch_PIN = 4;

#define Serial_Speed 38400
//9600, 38400, 115200

void setup() {
  Serial.begin(Serial_Speed);
  
  pinMode(Switch_PIN, INPUT_PULLUP); //initial PIN for debug switch with internal pullup resistant
}
//----------------------------------------------------------------------------------------------------
// start loop
void loop() {
  static int StoredSwitchState = digitalRead(Switch_PIN);
  static int ActualSwitchState = StoredSwitchState;
  ActualSwitchState = digitalRead(Switch_PIN);
  if(ActualSwitchState != StoredSwitchState){
    StoredSwitchState = ActualSwitchState;
    Serial.println("Switch changed");
    
  }
}
