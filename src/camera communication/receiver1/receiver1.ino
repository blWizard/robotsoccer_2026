int received_number_data = -1000;
String str_received_data = "";

String initial_input;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200); // Teensy pins -> 7 & 8
}

void loop() {
  receive_data_from_uart();
}

void receive_data_from_uart() {
  // Serial.println(Serial2.available());
  if (Serial2.available() >= 1) {
    // NOTE: This method is suppoused to receive: "x,y", where X its a string and Y an integer. This method's behaviour should be modified based on camera's output message!
    initial_input = Serial2.readStringUntil('\n'); // Martu: This method only works with chars between "''"
    int first_comma = initial_input.indexOf(',');
    str_received_data = initial_input.substring(0, first_comma);
    received_number_data = initial_input.substring(first_comma + 1).toInt();
    Serial.printf("Received from input: %s & %d\n", str_received_data.c_str(), received_number_data);
    delay(100);
  }
  else {
    Serial.println("Received no data!!");
  }
}